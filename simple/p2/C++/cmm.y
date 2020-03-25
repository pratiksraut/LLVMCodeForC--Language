%{
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <iostream>
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/Value.h"
#include "llvm/IR/Function.h"
#include "llvm/IR/GlobalVariable.h"
#include "llvm/IR/Type.h"
#include "llvm/IR/IRBuilder.h"

#include "llvm/Bitcode/BitcodeWriter.h"
#include "llvm/ADT/StringSet.h"
#include "llvm/ADT/StringMap.h"
#include "llvm/IRReader/IRReader.h"
#include "llvm/Support/SystemUtils.h"
#include "llvm/Support/ToolOutputFile.h"
#include <llvm-c/Core.h>
#include <memory>
#include <algorithm>
#include <list>
#include <vector>
#include <utility>
#include <stack>

#include "symbol.h"
#include "list.h" 
using namespace llvm;
using namespace std;
#define DEBUG 1
using parameter = pair<Type*,const char*>;
using parameter_list = std::list<parameter>;

//typedef struct {
  //BasicBlock* expr;
//  BasicBlock* body;
 // BasicBlock* reinit;
  //BasicBlock* exit;
//} loop_info;

stack<loop_info> loop_stack;
 
int num_errors;

extern int yylex();   /* lexical analyzer generated from lex.l */

int yyerror(const char *error);
int parser_error(const char*);

void cmm_abort();
char *get_filename();
int get_lineno();

int loops_found=0;
#define Loop_kind 1
int last_used_kind = 0, last_used_kind_save = 0;
extern Module *M;
extern LLVMContext TheContext;
 
Function *Fun;
IRBuilder<> *Builder;

Value* BuildFunction(Type* RetType, const char *name, 
			   parameter_list *params);

BasicBlock *BBjoin = nullptr;
%}

/* Data structure for tree nodes*/

%union {
  int inum;
  char * id;
  Type*  type;
  Value* value;
  parameter_list *plist;
  vector<Value*> *arglist;
}

/* these tokens are simply their corresponding int values, more terminals*/

%token SEMICOLON COMMA MYEOF
%token LBRACE RBRACE LPAREN RPAREN LBRACKET RBRACKET

%token ASSIGN PLUS MINUS STAR DIV MOD 
%token LT GT LTE GTE EQ NEQ
%token BITWISE_OR BITWISE_XOR LSHIFT RSHIFT BITWISE_INVERT
%token DOT AMPERSAND 

%token FOR WHILE IF ELSE DO RETURN SWITCH
%token BREAK CONTINUE CASE COLON
%token INT VOID BOOL
%token I2P P2I SEXT ZEXT

/* NUMBER and ID have values associated with them returned from lex*/

%token <inum> CONSTANT_INTEGER /*data type of NUMBER is num union*/
%token <id>  ID

%left EQ NEQ LT GT LTE GTE
%left BITWISE_OR
%left BITWISE_XOR
%left AMPERSAND
%left LSHIFT RSHIFT
%left PLUS MINUS
%left MOD DIV STAR 
%nonassoc ELSE

%type <type> type_specifier

%type <value> opt_initializer
%type <value> expression bool_expression
%type <value> lvalue_location primary_expression unary_expression
%type <value> constant constant_expression unary_constant_expression

%type <plist> param_list param_list_opt

%type<value> global_declaration argument_list argument_list_opt assign_expression 
%type<value> return_stmt expr_opt iteration_stmt selection_stmt continue_stmt case_stmt break_stmt statement_list statement_list_opt external_declaration
%type<value> compound_stmt expr_stmt statement  translation_unit function_definition
%type<value> local_declaration  local_declaration_list local_declaration_list_opt 

%%

translation_unit:	  external_declaration
			| translation_unit external_declaration
                        | translation_unit MYEOF
{
  YYACCEPT;
}
;

external_declaration:	  function_definition
{
}
                        | global_declaration 
                        {
              
                        }
;

function_definition:	  type_specifier ID LPAREN param_list_opt RPAREN
// NO MODIFICATION NEEDED
{
  symbol_push_scope();
  BuildFunction($1,$2,$4);
}
compound_stmt 
{
  symbol_pop_scope();
}

// NO MODIFICATION NEEDED
| type_specifier STAR ID LPAREN param_list_opt RPAREN
{
  symbol_push_scope();
  BuildFunction(PointerType::get($1,0),$3,$5);
}
compound_stmt
{
  symbol_pop_scope();
}
;

global_declaration:    type_specifier STAR ID opt_initializer SEMICOLON
{
  // Check to make sure global isn't already allocated
  // new GlobalVariable(...)  
}
| type_specifier ID opt_initializer SEMICOLON
{
  // Check to make sure global isn't already allocated
  // new GlobalVariable(...)		
}
;

// YOU MUST FIXME: hacked to prevent segfault on initial testing
opt_initializer:   ASSIGN constant_expression { $$ = $2; } | { $$ = nullptr; } ;

// NO MODIFICATION NEEDED
type_specifier:		  INT
{
  $$ = Type::getInt64Ty(TheContext);
}
| VOID
{
  $$ = Type::getVoidTy(TheContext);
}
;


param_list_opt:           
{
  $$ = nullptr;
}
| param_list
{
  $$ = $1;
}
;

// USED FOR FUNCTION DEFINITION; NO MODIFICATION NEEDED
param_list:	
param_list COMMA type_specifier ID
{
  $$ = $1;
  $$->push_back( parameter($3,$4) );
}
| param_list COMMA type_specifier STAR ID
{
  $$ = $1;
  $$->push_back( parameter(PointerType::get($3,0),$5) );
}
| type_specifier ID
{
  $$ = new parameter_list;
  $$->push_back( parameter($1,$2) );
}
| type_specifier STAR ID
{
  $$ = new parameter_list;
  $$->push_back( parameter(PointerType::get($1,0),$3) );
}
;


statement:		  expr_stmt 
{
  $$=$1;
}           
| compound_stmt 
{
  $$=$1;
}       
| selection_stmt 
{
  $$=$1;
}      
| iteration_stmt 
{
  $$=$1;
}      
| return_stmt
{
  $$=$1;
}            
| break_stmt
{
  $$=$1;
}
| continue_stmt
{
  $$=$1;
}
| case_stmt
{
  $$=$1;
}                
;

expr_stmt:	           SEMICOLON  
{
  $$ = nullptr;
}          
			|  assign_expression SEMICOLON  
      {
      $$=$1;
      }     
;

local_declaration:    type_specifier STAR ID opt_initializer SEMICOLON
{
  Value * ai = Builder->CreateAlloca(PointerType::get($1,0),0,$3);
  if (nullptr != $4)
    Builder->CreateStore($4,ai);
  symbol_insert($3,ai);
}
| type_specifier ID opt_initializer SEMICOLON
{
  Value * ai = Builder->CreateAlloca($1,0,$2);
  if (nullptr != $3)
    Builder->CreateStore($3,ai);
  symbol_insert($2,ai);  
}
;

local_declaration_list:	   local_declaration
{
  $$ = $1;
}
| local_declaration_list local_declaration  
{
  $$= $2;
}
;

local_declaration_list_opt:	
{
  $$=nullptr;
}
| local_declaration_list
{
  $$=$1;
}
;

compound_stmt:		  LBRACE {
  // PUSH SCOPE TO RECORD VARIABLES WITHIN COMPOUND STATEMENT
  symbol_push_scope();
}
local_declaration_list_opt
statement_list_opt 
{
  // POP SCOPE TO REMOVE VARIABLES NO LONGER ACCESSIBLE
  symbol_pop_scope();
}
RBRACE
;


statement_list_opt:	
{
  $$ = nullptr;
}
| statement_list
{
  $$=$1;
}
;

statement_list:		statement
{
  $$=$1;
}
| statement_list statement
{
  $$ = $2;
}
;

break_stmt:               BREAK SEMICOLON
{
  
  $$ = nullptr;
}
;

case_stmt:                CASE constant_expression COLON
{
  $$= $2;
}
;

continue_stmt:            CONTINUE SEMICOLON
{
  $$=nullptr;
}
;

selection_stmt:		        
IF LPAREN bool_expression RPAREN
{
  printf("if part1 start\n");
  BasicBlock *if_then= BasicBlock::Create(TheContext, "if.then", Fun);
  BasicBlock *if_else= BasicBlock::Create(TheContext, "if.else", Fun);
  BasicBlock *if_join= BasicBlock::Create(TheContext, "if.join", Fun);
  if($3->getType() == Builder->getInt1Ty())
 {
   Builder->CreateCondBr($3, if_then, if_else);   
 }
 else if($3->getType() == Builder->getInt32Ty())
 {
    Builder->CreateCondBr(Builder->CreateICmpNE($3,Builder->getInt32(0)), if_then, if_else);
 }
 else if(PointerType *py = dyn_cast<PointerType>($3->getType()))
 {
      Builder->CreateCondBr(Builder->CreateICmpNE($3, ConstantPointerNull::get(py)),if_then, if_else); 
 }
  printf("if part1 before loop push\n");
  push_loop(if_then, if_then, if_else, if_join);
  //expr, body, reinit, exit
  Builder->SetInsertPoint(if_then);
  BBjoin = if_join;
  printf("if part1 end\n");
}
 statement
{
  printf("if part2 statement\n");
  loop_info info = get_loop();
  //pop_loop(); 
  if(!Builder->GetInsertBlock()->getTerminator())
      Builder->CreateBr(info.exit);    //to join block
  Builder->SetInsertPoint(info.reinit);   //next thing is the join block
  BBjoin = info.exit;
}
ELSE statement
{ 
  printf("if part3 else\n");
  loop_info info = get_loop();
  pop_loop();
  printf("if part3 pop\n"); 
  if(!Builder->GetInsertBlock()->getTerminator())
      Builder->CreateBr(info.exit);    //to join block
  Builder->SetInsertPoint(info.exit);   //next thing is the join block
}
| SWITCH LPAREN expression RPAREN statement 
;


iteration_stmt:
WHILE 
{
 BasicBlock *expr = BasicBlock::Create(M->getContext(), "while.expr", Fun);
 Builder->CreateBr(expr);
 Builder->SetInsertPoint(expr);
 
 push_loop(expr,expr,expr,expr);
	//BasicBlock *expr = BasicBlock::Create(TheContext,"w.expr",Fun);
	//Builder->CreateBr(expr);
	//Builder->SetInsertPoint(expr);
	//BBjoin = expr;
}
LPAREN bool_expression RPAREN 
{
  loop_info info = get_loop();
  pop_loop();  
  
  BasicBlock *body = BasicBlock::Create(M->getContext(), "while.body", Fun); 
  BasicBlock *exit = BasicBlock::Create(M->getContext(), "while.exit", Fun); 
  
  // call push loop to record this loop's important blocks
  push_loop(info.expr, body, body, exit);
  last_used_kind_save = last_used_kind;
  last_used_kind = Loop_kind;

  Builder->CreateCondBr(Builder->CreateICmpNE($4, Builder->getInt64(0)), body,exit);
  Builder->SetInsertPoint(body); 
	//BasicBlock *body = BasicBlock::Create(TheContext,"w.body",Fun);
	//BasicBlock *exit = BasicBlock::Create(TheContext,"w.exit",Fun);
 // //Builder->CreateCondBr($3,body,exit);
	//Builder->CreateCondBr(Builder->CreateICmpSGT($4, Builder->getInt32(0)),body,exit);
 
	//Builder->SetInsertPoint(body);
	//BBjoin= exit;
}
statement
{
  loop_info info = get_loop();
  // insert back edge from body to header
  Builder->CreateBr(info.expr);
  Builder->SetInsertPoint(info.exit);
  
  pop_loop();
  last_used_kind = last_used_kind_save;
	//Builder->CreateBr(BBjoin);
	//Builder->SetInsertPoint(BBjoin);
}
| FOR LPAREN expr_opt SEMICOLON 
{
  //BasicBlock *forcond= BasicBlock::Create(TheContext, "for.cond", Fun);
 // BasicBlock *forbody= BasicBlock::Create(TheContext, "for.body", Fun);
  //BasicBlock *forexit= BasicBlock::Create(TheContext, "for.exit", Fun);
 // Builder->CreateBr(forcond);
  //Builder->SetInsertPoint(forcond);
}
bool_expression SEMICOLON expr_opt RPAREN 
{
  //PHINode *phi_i=Builder->CreatePHI(Builder->getInt64Ty(), 2);
  //Builder->CreateCondBr(Builder->CreateICmpSLT(phi_i,Builder->getInt64($3)), forbody, forexit);
  //Builder.SetInsertPoint(forbody);
  //Value * add = Builder.CreateAdd(phi_i, Builder.getInt64(1), "iplus1");
  //Builder.CreateBr(forcond);
}
statement 
{
  //Builder.SetInsertPoint(forexit);
  //Builder.CreateRetVoid();
  //phi_i->addIncoming(Builder.getInt64(0),entry);
}
| DO statement WHILE LPAREN bool_expression RPAREN SEMICOLON
;

expr_opt: 
{
  $$= nullptr;
} 	
	| assign_expression
  {
    $$ = $1;
  }
;

return_stmt:		  RETURN SEMICOLON
{
    Builder->CreateRetVoid();
}
| RETURN expression SEMICOLON
{
    Builder->CreateRet($2);
}
;

bool_expression: expression
{
  $$ = $1;
} 
;

assign_expression:
  lvalue_location ASSIGN expression
{
   //create store 
   $$=Builder->CreateStore($3,$1);
    //Builder.CreateStore($4,addr);
}
| expression
{
  $$ = $1;
}
;

expression:
  unary_expression
  {
    $$ = $1;
  }
| expression BITWISE_OR expression
{
    $$ = Builder->CreateOr($1,$3);
}
| expression BITWISE_XOR expression
{
  $$ = Builder->CreateXor($1, $3);
}
| expression AMPERSAND expression
{
    $$ = Builder->CreateAnd($1, $3);
}
| expression EQ expression
{
    $$ = Builder->CreateICmpEQ($1, $3);
}
| expression NEQ expression
{
  $$ = Builder->CreateICmpNE($1, $3);
}
| expression LT expression
{
    Value *val = Builder->CreateICmpSLT($1, $3);
   // $$ = Builder->CreateSelect(val, $1, $3);
    $$ = Builder->CreateSExt(val, Builder->getInt32Ty());
}
| expression GT expression
{
    Value *val = Builder->CreateICmpSGT($1, $3);
    //$$ = Builder->CreateSelect(val, $1, $3);
    $$ = Builder->CreateSExt(val, Builder->getInt32Ty());
}
| expression LTE expression
{
    Value *val = Builder->CreateICmpSLE($1, $3);
    //$$ = Builder->CreateSelect(val, $1, $3);
    $$ = Builder->CreateSExt(val, Builder->getInt32Ty());
}
| expression GTE expression
{
    Value *val = Builder->CreateICmpSGT($1, $3);
    //$$ = Builder->CreateSelect(val, $1, $3);
    $$ = Builder->CreateSExt(val, Builder->getInt32Ty());
}
| expression LSHIFT expression
{
  $$ = Builder->CreateShl($1,$3);
}
| expression RSHIFT expression
{
  $$ = Builder->CreateLShr($1,$3);
}
| expression PLUS expression
{
      $$ = Builder->CreateAdd($1, $3);
}
| expression MINUS expression
{
  $$ = Builder->CreateSub($1,$3);
}
| expression STAR expression
{
   $$ = Builder->CreateMul($1, $3);
}
| expression DIV expression
{
    $$ = Builder->CreateSDiv($1, $3);
}
| expression MOD expression
{
  $$ = Builder->CreateSRem($1, $3);
}
| BOOL LPAREN expression RPAREN
{
  $$ = Builder->CreateICmpSGT($3, Builder->getInt64(0));
}
| I2P LPAREN expression RPAREN
{
     $$ = Builder->CreateIntToPtr($3,$3->getType(), ""); 
}
| P2I LPAREN expression RPAREN
{
  $$ = Builder->CreatePtrToInt($3,unwrap(LLVMInt32Type()), "");
}
| ZEXT LPAREN expression RPAREN
{
  $$ = Builder->CreateZExt($3,Builder->getInt32Ty());
}
| SEXT LPAREN expression RPAREN
{
  $$ = Builder->CreateSExt($3, Builder->getInt32Ty());
}
| ID LPAREN argument_list_opt RPAREN
| LPAREN expression RPAREN
{
    $$=$2;
}
;


argument_list_opt: | argument_list
;

argument_list:
  expression
  {
  //vector creation 
  }
| argument_list COMMA expression
;


unary_expression:         
primary_expression
{
    $$ = $1;
}
| AMPERSAND primary_expression
| STAR primary_expression
{
    
}
| MINUS unary_expression
{
    $$=Builder->CreateNeg($2);
}
| PLUS unary_expression
{

    if ($2 > Builder->getInt64(0)) 
    {
        $$=$2;
    }
    else
        $$=Builder->CreateNeg($2);
    
}
| BITWISE_INVERT unary_expression
{
    $$ = Builder->CreateNot($2);
}
;

primary_expression:
lvalue_location
{
    $$ = Builder->CreateLoad($1);
}
| constant
{
    $$ = $1;
}
;

lvalue_location:
ID
{
    Value *retVal = NULL;
    retVal = symbol_find($1);
    if(retVal == NULL)
    {
          YYERROR;
    }
    $$ = retVal;

    #ifdef DEBUG
    printf("ID %s\n", $1);
    #endif
}
| lvalue_location LBRACKET expression RBRACKET
{
  
}
| STAR LPAREN expression RPAREN
{
    
}
;

constant_expression:
  unary_constant_expression
{
    $$ = $1;
           #ifdef DEBUG
    printf("unary constant expression\n");
    #endif
}
| constant_expression BITWISE_OR constant_expression
{
    $$ = Builder->CreateOr($1,$3);
           #ifdef DEBUG
    printf("constant expression bitwise or\n");
    #endif
}
| constant_expression BITWISE_XOR constant_expression
{
    $$ = Builder->CreateXor($1, $3);
           #ifdef DEBUG
    printf("constant expression xor\n");
    #endif
}
| constant_expression AMPERSAND constant_expression
{
    $$ = Builder->CreateAnd($1, $3);
           #ifdef DEBUG
    printf("constant expression and\n");
    #endif
}
| constant_expression LSHIFT constant_expression
{
    $$ = Builder->CreateShl($1,$3);
           #ifdef DEBUG
    printf("constant expression leftshift\n");
    #endif
}
| constant_expression RSHIFT constant_expression
{
    $$ = Builder->CreateLShr($1,$3);  
           #ifdef DEBUG
    printf("constant expression rightshift\n");
    #endif
}
| constant_expression PLUS constant_expression
{
    $$ = Builder->CreateAdd($1, $3);
           #ifdef DEBUG
    printf("constant expression add\n");
    #endif
}
| constant_expression MINUS constant_expression
{
    $$ = Builder->CreateSub($1,$3);
           #ifdef DEBUG
    printf("constant expression sub\n");
    #endif
}
| constant_expression STAR constant_expression
{
    $$ = Builder->CreateMul($1, $3);
       #ifdef DEBUG
    printf("constant expression mutiply\n");
    #endif

}
| constant_expression DIV constant_expression
{
    $$ = Builder->CreateSDiv($1, $3);
          #ifdef DEBUG
    printf("constant expression division\n");
    #endif
}
| constant_expression MOD constant_expression
{
    $$ = Builder->CreateSRem($1, $3);
          #ifdef DEBUG
    printf("const expression mod\n");
    #endif
}
| I2P LPAREN constant_expression RPAREN
{
   $$ = Builder->CreateIntToPtr($3,$3->getType(), ""); 
    #ifdef DEBUG
    printf("I2P const expression\n");
    #endif 
}
| P2I LPAREN constant_expression RPAREN
{
    $$ = Builder->CreatePtrToInt($3,unwrap(LLVMInt32Type()), "");
          #ifdef DEBUG
    printf("P@I const expression\n");
    #endif
}
;

unary_constant_expression:
constant
{
    //$$ = unwrap(LLVMConstInt(LLVMInt32Type(), $1, 0));
    $$= $1;
          #ifdef DEBUG
    printf("unary constant\n");
    #endif
}
| MINUS unary_constant_expression
{
    //Value* val = unwrap(LLVMConstInt(LLVMInt32Type(), $2, 0));
    $$ = Builder->CreateNeg($2);
        #ifdef DEBUG
    printf("unary const minus\n");
    #endif
}
| PLUS unary_constant_expression
{
    $2 > Builder->getInt64(0) ? $$=$2 : $$=Builder->CreateNeg($2);
        #ifdef DEBUG
    printf("unary const plus\n");
    #endif
}
| BITWISE_INVERT unary_constant_expression
{
    $$ = Builder->CreateNot($2);
    #ifdef DEBUG
    printf("unary const Bitwise invert\n");
    #endif
}
;


constant:	          CONSTANT_INTEGER
{
  $$ = Builder->getInt64($1);
    #ifdef DEBUG
    printf("constant integer %d\n", $1);
    #endif
}

;


%%

Value* BuildFunction(Type* RetType, const char *name, 
			   parameter_list *params)
{
  std::vector<Type*> v;
  std::vector<const char*> vname;

  if (params)
    for(auto ii : *params)
    {
      vname.push_back( ii.second );
      v.push_back( ii.first );      
    }
  
  ArrayRef<Type*> Params(v);

  FunctionType* FunType = FunctionType::get(RetType,Params,false);

  Fun = Function::Create(FunType,GlobalValue::ExternalLinkage,
			 name,M);
  Twine T("entry");
  BasicBlock *BB = BasicBlock::Create(M->getContext(),T,Fun);

  /* Create an Instruction Builder */
  Builder = new IRBuilder<>(M->getContext());
  Builder->SetInsertPoint(BB);

  Function::arg_iterator I = Fun->arg_begin();
  for(int i=0; I!=Fun->arg_end();i++, I++)
    {
      // map args and create allocas!
      AllocaInst *AI = Builder->CreateAlloca(v[i]);
      Builder->CreateStore(&(*I),(Value*)AI);
      symbol_insert(vname[i],(Value*)AI);
    }


  return Fun;
}

extern int verbose;
extern int line_num;
extern char *infile[];
static int   infile_cnt=0;
extern FILE * yyin;
extern int use_stdin;

int parser_error(const char *msg)
{
  if (use_stdin)
    printf("stdin:%d: Error -- %s\n",line_num,msg);
  else
    printf("%s:%d: Error -- %s\n",infile[infile_cnt-1],line_num,msg);
  return 1;
}

int internal_error(const char *msg)
{
  printf("%s:%d Internal Error -- %s\n",infile[infile_cnt-1],line_num,msg);
  return 1;
}

int yywrap() {

  if (use_stdin)
    {
      yyin = stdin;
      return 0;
    }
  
  static FILE * currentFile = NULL;

  if ( (currentFile != 0) ) {
    fclose(yyin);
  }
  
  if(infile[infile_cnt]==NULL)
    return 1;

  currentFile = fopen(infile[infile_cnt],"r");
  if(currentFile!=NULL)
    yyin = currentFile;
  else
    printf("Could not open file: %s",infile[infile_cnt]);

  infile_cnt++;
  
  return (currentFile)?0:1;
}

int yyerror(const char* error)
{
  parser_error("Un-resolved syntax error.");
  return 1;
}

char * get_filename()
{
  return infile[infile_cnt-1];
}

int get_lineno()
{
  return line_num;
}


void cmm_abort()
{
  parser_error("Too many errors to continue.");
  exit(1);
}
