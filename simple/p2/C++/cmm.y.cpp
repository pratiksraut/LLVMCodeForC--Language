/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "cmm.y" /* yacc.c:339  */

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

#line 135 "cmm.y.cpp" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "cmm.y.hpp".  */
#ifndef YY_YY_CMM_Y_HPP_INCLUDED
# define YY_YY_CMM_Y_HPP_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    SEMICOLON = 258,
    COMMA = 259,
    MYEOF = 260,
    LBRACE = 261,
    RBRACE = 262,
    LPAREN = 263,
    RPAREN = 264,
    LBRACKET = 265,
    RBRACKET = 266,
    ASSIGN = 267,
    PLUS = 268,
    MINUS = 269,
    STAR = 270,
    DIV = 271,
    MOD = 272,
    LT = 273,
    GT = 274,
    LTE = 275,
    GTE = 276,
    EQ = 277,
    NEQ = 278,
    BITWISE_OR = 279,
    BITWISE_XOR = 280,
    LSHIFT = 281,
    RSHIFT = 282,
    BITWISE_INVERT = 283,
    DOT = 284,
    AMPERSAND = 285,
    FOR = 286,
    WHILE = 287,
    IF = 288,
    ELSE = 289,
    DO = 290,
    RETURN = 291,
    SWITCH = 292,
    BREAK = 293,
    CONTINUE = 294,
    CASE = 295,
    COLON = 296,
    INT = 297,
    VOID = 298,
    BOOL = 299,
    I2P = 300,
    P2I = 301,
    SEXT = 302,
    ZEXT = 303,
    CONSTANT_INTEGER = 304,
    ID = 305
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 72 "cmm.y" /* yacc.c:355  */

  int inum;
  char * id;
  Type*  type;
  Value* value;
  parameter_list *plist;
  vector<Value*> *arglist;

#line 235 "cmm.y.cpp" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_CMM_Y_HPP_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 252 "cmm.y.cpp" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  8
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   641

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  51
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  45
/* YYNRULES -- Number of rules.  */
#define YYNRULES  123
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  249

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   305

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   126,   126,   127,   128,   134,   137,   145,   143,   156,
     155,   166,   171,   179,   179,   182,   186,   194,   197,   205,
     210,   215,   220,   228,   232,   236,   240,   244,   248,   252,
     256,   262,   266,   272,   279,   288,   292,   299,   302,   308,
     314,   308,   323,   326,   332,   336,   342,   349,   355,   363,
     388,   362,   407,   413,   425,   412,   460,   468,   459,   481,
     485,   488,   494,   498,   504,   511,   517,   524,   528,   532,
     536,   540,   544,   548,   554,   560,   566,   572,   576,   580,
     584,   588,   592,   596,   600,   604,   608,   612,   616,   620,
     621,   628,   628,   632,   636,   641,   645,   646,   650,   654,
     665,   672,   676,   683,   697,   701,   708,   715,   722,   729,
     736,   743,   750,   757,   764,   772,   779,   786,   793,   803,
     811,   819,   826,   836
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "SEMICOLON", "COMMA", "MYEOF", "LBRACE",
  "RBRACE", "LPAREN", "RPAREN", "LBRACKET", "RBRACKET", "ASSIGN", "PLUS",
  "MINUS", "STAR", "DIV", "MOD", "LT", "GT", "LTE", "GTE", "EQ", "NEQ",
  "BITWISE_OR", "BITWISE_XOR", "LSHIFT", "RSHIFT", "BITWISE_INVERT", "DOT",
  "AMPERSAND", "FOR", "WHILE", "IF", "ELSE", "DO", "RETURN", "SWITCH",
  "BREAK", "CONTINUE", "CASE", "COLON", "INT", "VOID", "BOOL", "I2P",
  "P2I", "SEXT", "ZEXT", "CONSTANT_INTEGER", "ID", "$accept",
  "translation_unit", "external_declaration", "function_definition", "$@1",
  "$@2", "global_declaration", "opt_initializer", "type_specifier",
  "param_list_opt", "param_list", "statement", "expr_stmt",
  "local_declaration", "local_declaration_list",
  "local_declaration_list_opt", "compound_stmt", "$@3", "$@4",
  "statement_list_opt", "statement_list", "break_stmt", "case_stmt",
  "continue_stmt", "selection_stmt", "$@5", "$@6", "iteration_stmt", "$@7",
  "$@8", "$@9", "$@10", "expr_opt", "return_stmt", "bool_expression",
  "assign_expression", "expression", "argument_list_opt", "argument_list",
  "unary_expression", "primary_expression", "lvalue_location",
  "constant_expression", "unary_constant_expression", "constant", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305
};
# endif

#define YYPACT_NINF -176

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-176)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      16,  -176,  -176,     8,  -176,  -176,  -176,    -3,  -176,  -176,
    -176,   -46,     7,    15,    16,    90,    13,    16,    19,     6,
      -2,    21,    -4,    -4,    -4,    20,    35,  -176,   529,  -176,
    -176,  -176,    39,  -176,     2,  -176,  -176,    16,  -176,  -176,
    -176,    90,    90,    90,    90,    90,    90,    90,    90,    90,
      90,    90,    90,  -176,  -176,    62,    77,   456,   475,   129,
     129,  -176,  -176,  -176,   553,   576,   100,   100,   599,    62,
    -176,  -176,    58,  -176,  -176,  -176,  -176,    16,  -176,    84,
    -176,    16,   161,    61,    57,  -176,  -176,   218,    82,    82,
      52,    82,    75,   132,  -176,   139,   161,   210,   140,   149,
     152,    90,   148,   153,   158,   160,   165,   182,  -176,  -176,
    -176,  -176,   161,  -176,  -176,  -176,  -176,  -176,  -176,   192,
     511,  -176,  -176,    88,  -176,    57,   209,   304,   204,  -176,
    -176,  -176,   218,   207,  -176,  -176,  -176,   218,   208,   218,
     131,  -176,   285,   218,  -176,  -176,   256,   218,   218,   218,
     218,   218,   218,   212,  -176,  -176,   218,   218,   218,   218,
     218,   218,   218,   218,   218,   218,   218,   218,   218,   218,
     218,   218,   218,   218,   214,  -176,  -176,   323,   217,  -176,
     218,   213,   511,   219,  -176,   342,  -176,   361,   380,   399,
     418,   437,   511,   220,   224,  -176,   155,   155,  -176,  -176,
    -176,   547,   547,   547,   547,   547,   547,   571,   594,   106,
     106,   614,   493,   511,  -176,  -176,  -176,   221,  -176,   218,
     161,  -176,  -176,  -176,  -176,  -176,  -176,   218,  -176,   218,
    -176,   161,   225,  -176,   511,   232,   161,  -176,   233,   218,
    -176,   187,  -176,   230,   161,  -176,  -176,   161,  -176
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    15,    16,     0,     2,     5,     6,     0,     1,     4,
       3,     0,    14,    14,    17,     0,     0,    17,     0,     0,
       0,    18,     0,     0,     0,     0,     0,   123,    13,   106,
     119,    12,     0,    11,     0,    21,     7,     0,   121,   120,
     122,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     9,    22,     0,     0,     0,     0,   112,
     113,   114,   115,   116,   107,   108,   110,   111,   109,     0,
      39,     8,     0,    19,   117,   118,    10,    37,    20,     0,
      35,    38,    42,     0,    14,    36,    31,     0,     0,     0,
       0,     0,     0,     0,    53,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   103,    44,    23,
      24,    40,    43,    28,    30,    29,    25,    26,    27,     0,
      66,    67,    95,   101,   102,    14,     0,     0,   101,   103,
      99,    98,     0,     0,    97,   100,    96,    60,     0,     0,
       0,    62,     0,     0,    46,    48,     0,     0,     0,     0,
       0,     0,    91,     0,    45,    32,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    34,    90,     0,     0,    61,
       0,     0,    64,     0,    63,     0,    47,     0,     0,     0,
       0,     0,    93,     0,    92,    41,    79,    80,    81,    82,
      83,    73,    74,    75,    76,    71,    72,    68,    69,    77,
      78,    70,     0,    65,    33,   105,    56,     0,    49,     0,
       0,    84,    85,    86,    88,    87,    89,     0,   104,     0,
      54,     0,     0,    52,    94,     0,     0,    50,     0,    60,
      55,     0,    59,     0,     0,    57,    51,     0,    58
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -176,  -176,   238,  -176,  -176,  -176,  -176,     4,    12,   226,
    -176,   -94,  -176,   163,  -176,  -176,   -49,  -176,  -176,  -176,
    -176,  -176,  -176,  -176,  -176,  -176,  -176,  -176,  -176,  -176,
    -176,  -176,     3,  -176,  -175,  -134,   -86,  -176,  -176,    18,
      38,   -82,   -10,   180,   136
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     3,     4,     5,    55,    69,     6,    16,     7,    20,
      21,   108,   109,    80,    81,    82,   110,    77,   153,   111,
     112,   113,   114,   115,   116,   231,   241,   117,   138,   236,
     229,   247,   178,   118,   181,   119,   120,   193,   194,   121,
     122,   128,    28,    29,   124
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
     123,   127,   140,   179,    13,   217,    71,    36,     8,    22,
      23,   142,    11,     9,   123,    14,    31,    18,   154,    15,
      76,    34,    33,    17,    24,    37,    19,    15,    41,    19,
     123,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    42,   232,    27,   177,    12,    53,    56,
       1,     2,    54,   182,   235,   123,    35,   185,     1,     2,
     132,   187,   188,   189,   190,   191,   192,   133,    70,    15,
     196,   197,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,   209,   210,   211,   212,   213,   126,    79,
     133,   146,    72,    79,   182,    88,    89,    90,   172,    83,
     173,    27,   129,    22,    23,   179,   130,   131,    78,   135,
      91,   125,    92,    43,    44,    45,    46,    47,    24,   156,
     157,   158,   159,   160,    27,   129,   233,    73,   134,   174,
     136,    27,   129,   182,    84,    25,    26,   237,   123,    27,
     137,   234,   240,   182,    45,    46,    47,   139,   143,   123,
     246,    30,   144,   248,   123,   145,   147,   123,    30,    30,
      30,   148,   123,   183,    86,   123,   149,    70,   150,    87,
     158,   159,   160,   151,    88,    89,    90,    30,    30,    30,
      30,    30,    30,    30,    30,    30,    30,    30,    30,    91,
     152,    92,    93,    94,    95,   155,    96,    97,    98,    99,
     100,   101,    38,    39,    40,   102,   103,   104,   105,   106,
      27,   107,   175,   141,   172,   132,   180,   214,    87,   195,
     216,   244,   218,    88,    89,    90,    87,   219,   227,   226,
     230,    88,    89,    90,   238,   239,   242,    30,    91,   245,
      92,    10,   243,    32,    85,     0,    91,     0,    92,     0,
       0,     0,     0,     0,   102,   103,   104,   105,   106,    27,
     107,     0,   102,   103,   104,   105,   106,    27,   107,    43,
      44,    45,    46,    47,     0,     0,     0,     0,     0,     0,
      48,    49,    50,    51,     0,     0,    52,     0,   184,     0,
       0,     0,     0,     0,     0,     0,     0,   186,   156,   157,
     158,   159,   160,   161,   162,   163,   164,   165,   166,   167,
     168,   169,   170,   176,     0,   171,     0,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   215,     0,   171,     0,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,   220,     0,   171,     0,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     221,     0,   171,     0,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   222,
       0,   171,     0,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,   166,   167,   168,   169,   170,   223,     0,
     171,     0,   156,   157,   158,   159,   160,   161,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   224,     0,   171,
       0,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   225,     0,   171,     0,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,    74,     0,   171,     0,    43,
      44,    45,    46,    47,     0,     0,     0,     0,     0,     0,
      48,    49,    50,    51,    75,     0,    52,     0,    43,    44,
      45,    46,    47,     0,     0,     0,     0,     0,     0,    48,
      49,    50,    51,     0,   228,    52,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   168,   169,
     170,     0,     0,   171,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,     0,
       0,   171,    43,    44,    45,    46,    47,     0,     0,     0,
       0,     0,     0,    48,    49,    50,    51,     0,     0,    52,
     156,   157,   158,   159,   160,     0,    43,    44,    45,    46,
      47,   167,   168,   169,   170,     0,     0,   171,    49,    50,
      51,     0,     0,    52,   156,   157,   158,   159,   160,    43,
      44,    45,    46,    47,     0,     0,   168,   169,   170,     0,
       0,   171,    50,    51,     0,     0,    52,   156,   157,   158,
     159,   160,    43,    44,    45,    46,    47,     0,     0,     0,
     169,   170,     0,     0,   171,    50,    51,   156,   157,   158,
     159,   160,     0,     0,     0,     0,     0,     0,     0,     0,
     169,   170
};

static const yytype_int16 yycheck[] =
{
      82,    87,    96,   137,    50,   180,    55,     9,     0,    13,
      14,    97,    15,     5,    96,     8,     3,    13,   112,    12,
      69,    15,     3,     8,    28,     4,    14,    12,     8,    17,
     112,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,     8,   219,    49,   132,    50,     9,    37,
      42,    43,    50,   139,   229,   137,    50,   143,    42,    43,
       8,   147,   148,   149,   150,   151,   152,    15,     6,    12,
     156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,    84,    77,
      15,   101,    15,    81,   180,    13,    14,    15,    10,    15,
      12,    49,    50,    13,    14,   239,    88,    89,    50,    91,
      28,    50,    30,    13,    14,    15,    16,    17,    28,    13,
      14,    15,    16,    17,    49,    50,   220,    50,    90,   125,
      92,    49,    50,   219,    50,    45,    46,   231,   220,    49,
       8,   227,   236,   229,    15,    16,    17,     8,     8,   231,
     244,    15,     3,   247,   236,     3,     8,   239,    22,    23,
      24,     8,   244,    32,     3,   247,     8,     6,     8,     8,
      15,    16,    17,     8,    13,    14,    15,    41,    42,    43,
      44,    45,    46,    47,    48,    49,    50,    51,    52,    28,
       8,    30,    31,    32,    33,     3,    35,    36,    37,    38,
      39,    40,    22,    23,    24,    44,    45,    46,    47,    48,
      49,    50,     3,     3,    10,     8,     8,     3,     8,     7,
       3,    34,     9,    13,    14,    15,     8,     8,     4,     9,
       9,    13,    14,    15,     9,     3,     3,   101,    28,     9,
      30,     3,   239,    17,    81,    -1,    28,    -1,    30,    -1,
      -1,    -1,    -1,    -1,    44,    45,    46,    47,    48,    49,
      50,    -1,    44,    45,    46,    47,    48,    49,    50,    13,
      14,    15,    16,    17,    -1,    -1,    -1,    -1,    -1,    -1,
      24,    25,    26,    27,    -1,    -1,    30,    -1,     3,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    41,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,     9,    -1,    30,    -1,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,     9,    -1,    30,    -1,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,     9,    -1,    30,    -1,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
       9,    -1,    30,    -1,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,     9,
      -1,    30,    -1,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,     9,    -1,
      30,    -1,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,     9,    -1,    30,
      -1,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,     9,    -1,    30,    -1,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,     9,    -1,    30,    -1,    13,
      14,    15,    16,    17,    -1,    -1,    -1,    -1,    -1,    -1,
      24,    25,    26,    27,     9,    -1,    30,    -1,    13,    14,
      15,    16,    17,    -1,    -1,    -1,    -1,    -1,    -1,    24,
      25,    26,    27,    -1,    11,    30,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    -1,    -1,    30,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    -1,
      -1,    30,    13,    14,    15,    16,    17,    -1,    -1,    -1,
      -1,    -1,    -1,    24,    25,    26,    27,    -1,    -1,    30,
      13,    14,    15,    16,    17,    -1,    13,    14,    15,    16,
      17,    24,    25,    26,    27,    -1,    -1,    30,    25,    26,
      27,    -1,    -1,    30,    13,    14,    15,    16,    17,    13,
      14,    15,    16,    17,    -1,    -1,    25,    26,    27,    -1,
      -1,    30,    26,    27,    -1,    -1,    30,    13,    14,    15,
      16,    17,    13,    14,    15,    16,    17,    -1,    -1,    -1,
      26,    27,    -1,    -1,    30,    26,    27,    13,    14,    15,
      16,    17,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      26,    27
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    42,    43,    52,    53,    54,    57,    59,     0,     5,
      53,    15,    50,    50,     8,    12,    58,     8,    58,    59,
      60,    61,    13,    14,    28,    45,    46,    49,    93,    94,
      95,     3,    60,     3,    15,    50,     9,     4,    94,    94,
      94,     8,     8,    13,    14,    15,    16,    17,    24,    25,
      26,    27,    30,     9,    50,    55,    59,    93,    93,    93,
      93,    93,    93,    93,    93,    93,    93,    93,    93,    56,
       6,    67,    15,    50,     9,     9,    67,    68,    50,    59,
      64,    65,    66,    15,    50,    64,     3,     8,    13,    14,
      15,    28,    30,    31,    32,    33,    35,    36,    37,    38,
      39,    40,    44,    45,    46,    47,    48,    50,    62,    63,
      67,    70,    71,    72,    73,    74,    75,    78,    84,    86,
      87,    90,    91,    92,    95,    50,    58,    87,    92,    50,
      90,    90,     8,    15,    91,    90,    91,     8,    79,     8,
      62,     3,    87,     8,     3,     3,    93,     8,     8,     8,
       8,     8,     8,    69,    62,     3,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    30,    10,    12,    58,     3,     9,    87,    83,    86,
       8,    85,    87,    32,     3,    87,    41,    87,    87,    87,
      87,    87,    87,    88,    89,     7,    87,    87,    87,    87,
      87,    87,    87,    87,    87,    87,    87,    87,    87,    87,
      87,    87,    87,    87,     3,     9,     3,    85,     9,     8,
       9,     9,     9,     9,     9,     9,     9,     4,    11,    81,
       9,    76,    85,    62,    87,    85,    80,    62,     9,     3,
      62,    77,     3,    83,    34,     9,    62,    82,    62
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    51,    52,    52,    52,    53,    53,    55,    54,    56,
      54,    57,    57,    58,    58,    59,    59,    60,    60,    61,
      61,    61,    61,    62,    62,    62,    62,    62,    62,    62,
      62,    63,    63,    64,    64,    65,    65,    66,    66,    68,
      69,    67,    70,    70,    71,    71,    72,    73,    74,    76,
      77,    75,    75,    79,    80,    78,    81,    82,    78,    78,
      83,    83,    84,    84,    85,    86,    86,    87,    87,    87,
      87,    87,    87,    87,    87,    87,    87,    87,    87,    87,
      87,    87,    87,    87,    87,    87,    87,    87,    87,    87,
      87,    88,    88,    89,    89,    90,    90,    90,    90,    90,
      90,    91,    91,    92,    92,    92,    93,    93,    93,    93,
      93,    93,    93,    93,    93,    93,    93,    93,    93,    94,
      94,    94,    94,    95
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     2,     1,     1,     0,     7,     0,
       8,     5,     4,     2,     0,     1,     1,     0,     1,     4,
       5,     2,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     5,     4,     1,     2,     0,     1,     0,
       0,     6,     0,     1,     1,     2,     2,     3,     2,     0,
       0,     9,     5,     0,     0,     7,     0,     0,    11,     7,
       0,     1,     2,     3,     1,     3,     1,     1,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     4,     4,     4,     4,     4,     4,
       3,     0,     1,     1,     3,     1,     2,     2,     2,     2,
       2,     1,     1,     1,     4,     4,     1,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     4,     4,     1,
       2,     2,     2,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 4:
#line 129 "cmm.y" /* yacc.c:1646  */
    {
  YYACCEPT;
}
#line 1589 "cmm.y.cpp" /* yacc.c:1646  */
    break;

  case 5:
#line 135 "cmm.y" /* yacc.c:1646  */
    {
}
#line 1596 "cmm.y.cpp" /* yacc.c:1646  */
    break;

  case 6:
#line 138 "cmm.y" /* yacc.c:1646  */
    {
              
                        }
#line 1604 "cmm.y.cpp" /* yacc.c:1646  */
    break;

  case 7:
#line 145 "cmm.y" /* yacc.c:1646  */
    {
  symbol_push_scope();
  BuildFunction((yyvsp[-4].type),(yyvsp[-3].id),(yyvsp[-1].plist));
}
#line 1613 "cmm.y.cpp" /* yacc.c:1646  */
    break;

  case 8:
#line 150 "cmm.y" /* yacc.c:1646  */
    {
  symbol_pop_scope();
}
#line 1621 "cmm.y.cpp" /* yacc.c:1646  */
    break;

  case 9:
#line 156 "cmm.y" /* yacc.c:1646  */
    {
  symbol_push_scope();
  BuildFunction(PointerType::get((yyvsp[-5].type),0),(yyvsp[-3].id),(yyvsp[-1].plist));
}
#line 1630 "cmm.y.cpp" /* yacc.c:1646  */
    break;

  case 10:
#line 161 "cmm.y" /* yacc.c:1646  */
    {
  symbol_pop_scope();
}
#line 1638 "cmm.y.cpp" /* yacc.c:1646  */
    break;

  case 11:
#line 167 "cmm.y" /* yacc.c:1646  */
    {
  // Check to make sure global isn't already allocated
  // new GlobalVariable(...)  
}
#line 1647 "cmm.y.cpp" /* yacc.c:1646  */
    break;

  case 12:
#line 172 "cmm.y" /* yacc.c:1646  */
    {
  // Check to make sure global isn't already allocated
  // new GlobalVariable(...)		
}
#line 1656 "cmm.y.cpp" /* yacc.c:1646  */
    break;

  case 13:
#line 179 "cmm.y" /* yacc.c:1646  */
    { (yyval.value) = (yyvsp[0].value); }
#line 1662 "cmm.y.cpp" /* yacc.c:1646  */
    break;

  case 14:
#line 179 "cmm.y" /* yacc.c:1646  */
    { (yyval.value) = nullptr; }
#line 1668 "cmm.y.cpp" /* yacc.c:1646  */
    break;

  case 15:
#line 183 "cmm.y" /* yacc.c:1646  */
    {
  (yyval.type) = Type::getInt64Ty(TheContext);
}
#line 1676 "cmm.y.cpp" /* yacc.c:1646  */
    break;

  case 16:
#line 187 "cmm.y" /* yacc.c:1646  */
    {
  (yyval.type) = Type::getVoidTy(TheContext);
}
#line 1684 "cmm.y.cpp" /* yacc.c:1646  */
    break;

  case 17:
#line 194 "cmm.y" /* yacc.c:1646  */
    {
  (yyval.plist) = nullptr;
}
#line 1692 "cmm.y.cpp" /* yacc.c:1646  */
    break;

  case 18:
#line 198 "cmm.y" /* yacc.c:1646  */
    {
  (yyval.plist) = (yyvsp[0].plist);
}
#line 1700 "cmm.y.cpp" /* yacc.c:1646  */
    break;

  case 19:
#line 206 "cmm.y" /* yacc.c:1646  */
    {
  (yyval.plist) = (yyvsp[-3].plist);
  (yyval.plist)->push_back( parameter((yyvsp[-1].type),(yyvsp[0].id)) );
}
#line 1709 "cmm.y.cpp" /* yacc.c:1646  */
    break;

  case 20:
#line 211 "cmm.y" /* yacc.c:1646  */
    {
  (yyval.plist) = (yyvsp[-4].plist);
  (yyval.plist)->push_back( parameter(PointerType::get((yyvsp[-2].type),0),(yyvsp[0].id)) );
}
#line 1718 "cmm.y.cpp" /* yacc.c:1646  */
    break;

  case 21:
#line 216 "cmm.y" /* yacc.c:1646  */
    {
  (yyval.plist) = new parameter_list;
  (yyval.plist)->push_back( parameter((yyvsp[-1].type),(yyvsp[0].id)) );
}
#line 1727 "cmm.y.cpp" /* yacc.c:1646  */
    break;

  case 22:
#line 221 "cmm.y" /* yacc.c:1646  */
    {
  (yyval.plist) = new parameter_list;
  (yyval.plist)->push_back( parameter(PointerType::get((yyvsp[-2].type),0),(yyvsp[0].id)) );
}
#line 1736 "cmm.y.cpp" /* yacc.c:1646  */
    break;

  case 23:
#line 229 "cmm.y" /* yacc.c:1646  */
    {
  (yyval.value)=(yyvsp[0].value);
}
#line 1744 "cmm.y.cpp" /* yacc.c:1646  */
    break;

  case 24:
#line 233 "cmm.y" /* yacc.c:1646  */
    {
  (yyval.value)=(yyvsp[0].value);
}
#line 1752 "cmm.y.cpp" /* yacc.c:1646  */
    break;

  case 25:
#line 237 "cmm.y" /* yacc.c:1646  */
    {
  (yyval.value)=(yyvsp[0].value);
}
#line 1760 "cmm.y.cpp" /* yacc.c:1646  */
    break;

  case 26:
#line 241 "cmm.y" /* yacc.c:1646  */
    {
  (yyval.value)=(yyvsp[0].value);
}
#line 1768 "cmm.y.cpp" /* yacc.c:1646  */
    break;

  case 27:
#line 245 "cmm.y" /* yacc.c:1646  */
    {
  (yyval.value)=(yyvsp[0].value);
}
#line 1776 "cmm.y.cpp" /* yacc.c:1646  */
    break;

  case 28:
#line 249 "cmm.y" /* yacc.c:1646  */
    {
  (yyval.value)=(yyvsp[0].value);
}
#line 1784 "cmm.y.cpp" /* yacc.c:1646  */
    break;

  case 29:
#line 253 "cmm.y" /* yacc.c:1646  */
    {
  (yyval.value)=(yyvsp[0].value);
}
#line 1792 "cmm.y.cpp" /* yacc.c:1646  */
    break;

  case 30:
#line 257 "cmm.y" /* yacc.c:1646  */
    {
  (yyval.value)=(yyvsp[0].value);
}
#line 1800 "cmm.y.cpp" /* yacc.c:1646  */
    break;

  case 31:
#line 263 "cmm.y" /* yacc.c:1646  */
    {
  (yyval.value) = nullptr;
}
#line 1808 "cmm.y.cpp" /* yacc.c:1646  */
    break;

  case 32:
#line 267 "cmm.y" /* yacc.c:1646  */
    {
      (yyval.value)=(yyvsp[-1].value);
      }
#line 1816 "cmm.y.cpp" /* yacc.c:1646  */
    break;

  case 33:
#line 273 "cmm.y" /* yacc.c:1646  */
    {
  Value * ai = Builder->CreateAlloca(PointerType::get((yyvsp[-4].type),0),0,(yyvsp[-2].id));
  if (nullptr != (yyvsp[-1].value))
    Builder->CreateStore((yyvsp[-1].value),ai);
  symbol_insert((yyvsp[-2].id),ai);
}
#line 1827 "cmm.y.cpp" /* yacc.c:1646  */
    break;

  case 34:
#line 280 "cmm.y" /* yacc.c:1646  */
    {
  Value * ai = Builder->CreateAlloca((yyvsp[-3].type),0,(yyvsp[-2].id));
  if (nullptr != (yyvsp[-1].value))
    Builder->CreateStore((yyvsp[-1].value),ai);
  symbol_insert((yyvsp[-2].id),ai);  
}
#line 1838 "cmm.y.cpp" /* yacc.c:1646  */
    break;

  case 35:
#line 289 "cmm.y" /* yacc.c:1646  */
    {
  (yyval.value) = (yyvsp[0].value);
}
#line 1846 "cmm.y.cpp" /* yacc.c:1646  */
    break;

  case 36:
#line 293 "cmm.y" /* yacc.c:1646  */
    {
  (yyval.value)= (yyvsp[0].value);
}
#line 1854 "cmm.y.cpp" /* yacc.c:1646  */
    break;

  case 37:
#line 299 "cmm.y" /* yacc.c:1646  */
    {
  (yyval.value)=nullptr;
}
#line 1862 "cmm.y.cpp" /* yacc.c:1646  */
    break;

  case 38:
#line 303 "cmm.y" /* yacc.c:1646  */
    {
  (yyval.value)=(yyvsp[0].value);
}
#line 1870 "cmm.y.cpp" /* yacc.c:1646  */
    break;

  case 39:
#line 308 "cmm.y" /* yacc.c:1646  */
    {
  // PUSH SCOPE TO RECORD VARIABLES WITHIN COMPOUND STATEMENT
  symbol_push_scope();
}
#line 1879 "cmm.y.cpp" /* yacc.c:1646  */
    break;

  case 40:
#line 314 "cmm.y" /* yacc.c:1646  */
    {
  // POP SCOPE TO REMOVE VARIABLES NO LONGER ACCESSIBLE
  symbol_pop_scope();
}
#line 1888 "cmm.y.cpp" /* yacc.c:1646  */
    break;

  case 42:
#line 323 "cmm.y" /* yacc.c:1646  */
    {
  (yyval.value) = nullptr;
}
#line 1896 "cmm.y.cpp" /* yacc.c:1646  */
    break;

  case 43:
#line 327 "cmm.y" /* yacc.c:1646  */
    {
  (yyval.value)=(yyvsp[0].value);
}
#line 1904 "cmm.y.cpp" /* yacc.c:1646  */
    break;

  case 44:
#line 333 "cmm.y" /* yacc.c:1646  */
    {
  (yyval.value)=(yyvsp[0].value);
}
#line 1912 "cmm.y.cpp" /* yacc.c:1646  */
    break;

  case 45:
#line 337 "cmm.y" /* yacc.c:1646  */
    {
  (yyval.value) = (yyvsp[0].value);
}
#line 1920 "cmm.y.cpp" /* yacc.c:1646  */
    break;

  case 46:
#line 343 "cmm.y" /* yacc.c:1646  */
    {
  
  (yyval.value) = nullptr;
}
#line 1929 "cmm.y.cpp" /* yacc.c:1646  */
    break;

  case 47:
#line 350 "cmm.y" /* yacc.c:1646  */
    {
  (yyval.value)= (yyvsp[-1].value);
}
#line 1937 "cmm.y.cpp" /* yacc.c:1646  */
    break;

  case 48:
#line 356 "cmm.y" /* yacc.c:1646  */
    {
  (yyval.value)=nullptr;
}
#line 1945 "cmm.y.cpp" /* yacc.c:1646  */
    break;

  case 49:
#line 363 "cmm.y" /* yacc.c:1646  */
    {
  printf("if part1 start\n");
  BasicBlock *if_then= BasicBlock::Create(TheContext, "if.then", Fun);
  BasicBlock *if_else= BasicBlock::Create(TheContext, "if.else", Fun);
  BasicBlock *if_join= BasicBlock::Create(TheContext, "if.join", Fun);
  if((yyvsp[-1].value)->getType() == Builder->getInt1Ty())
 {
   Builder->CreateCondBr((yyvsp[-1].value), if_then, if_else);   
 }
 else if((yyvsp[-1].value)->getType() == Builder->getInt32Ty())
 {
    Builder->CreateCondBr(Builder->CreateICmpNE((yyvsp[-1].value),Builder->getInt32(0)), if_then, if_else);
 }
 else if(PointerType *py = dyn_cast<PointerType>((yyvsp[-1].value)->getType()))
 {
      Builder->CreateCondBr(Builder->CreateICmpNE((yyvsp[-1].value), ConstantPointerNull::get(py)),if_then, if_else); 
 }
  printf("if part1 before loop push\n");
  push_loop(if_then, if_then, if_else, if_join);
  //expr, body, reinit, exit
  Builder->SetInsertPoint(if_then);
  BBjoin = if_join;
  printf("if part1 end\n");
}
#line 1974 "cmm.y.cpp" /* yacc.c:1646  */
    break;

  case 50:
#line 388 "cmm.y" /* yacc.c:1646  */
    {
  printf("if part2 statement\n");
  loop_info info = get_loop();
  //pop_loop(); 
  if(!Builder->GetInsertBlock()->getTerminator())
      Builder->CreateBr(info.exit);    //to join block
  Builder->SetInsertPoint(info.reinit);   //next thing is the join block
  BBjoin = info.exit;
}
#line 1988 "cmm.y.cpp" /* yacc.c:1646  */
    break;

  case 51:
#line 398 "cmm.y" /* yacc.c:1646  */
    { 
  printf("if part3 else\n");
  loop_info info = get_loop();
  pop_loop();
  printf("if part3 pop\n"); 
  if(!Builder->GetInsertBlock()->getTerminator())
      Builder->CreateBr(info.exit);    //to join block
  Builder->SetInsertPoint(info.exit);   //next thing is the join block
}
#line 2002 "cmm.y.cpp" /* yacc.c:1646  */
    break;

  case 53:
#line 413 "cmm.y" /* yacc.c:1646  */
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
#line 2018 "cmm.y.cpp" /* yacc.c:1646  */
    break;

  case 54:
#line 425 "cmm.y" /* yacc.c:1646  */
    {
  loop_info info = get_loop();
  pop_loop();  
  
  BasicBlock *body = BasicBlock::Create(M->getContext(), "while.body", Fun); 
  BasicBlock *exit = BasicBlock::Create(M->getContext(), "while.exit", Fun); 
  
  // call push loop to record this loop's important blocks
  push_loop(info.expr, body, body, exit);
  last_used_kind_save = last_used_kind;
  last_used_kind = Loop_kind;

  Builder->CreateCondBr(Builder->CreateICmpNE((yyvsp[-1].value), Builder->getInt64(0)), body,exit);
  Builder->SetInsertPoint(body); 
	//BasicBlock *body = BasicBlock::Create(TheContext,"w.body",Fun);
	//BasicBlock *exit = BasicBlock::Create(TheContext,"w.exit",Fun);
 // //Builder->CreateCondBr($3,body,exit);
	//Builder->CreateCondBr(Builder->CreateICmpSGT($4, Builder->getInt32(0)),body,exit);
 
	//Builder->SetInsertPoint(body);
	//BBjoin= exit;
}
#line 2045 "cmm.y.cpp" /* yacc.c:1646  */
    break;

  case 55:
#line 448 "cmm.y" /* yacc.c:1646  */
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
#line 2061 "cmm.y.cpp" /* yacc.c:1646  */
    break;

  case 56:
#line 460 "cmm.y" /* yacc.c:1646  */
    {
  //BasicBlock *forcond= BasicBlock::Create(TheContext, "for.cond", Fun);
 // BasicBlock *forbody= BasicBlock::Create(TheContext, "for.body", Fun);
  //BasicBlock *forexit= BasicBlock::Create(TheContext, "for.exit", Fun);
 // Builder->CreateBr(forcond);
  //Builder->SetInsertPoint(forcond);
}
#line 2073 "cmm.y.cpp" /* yacc.c:1646  */
    break;

  case 57:
#line 468 "cmm.y" /* yacc.c:1646  */
    {
  //PHINode *phi_i=Builder->CreatePHI(Builder->getInt64Ty(), 2);
  //Builder->CreateCondBr(Builder->CreateICmpSLT(phi_i,Builder->getInt64($3)), forbody, forexit);
  //Builder.SetInsertPoint(forbody);
  //Value * add = Builder.CreateAdd(phi_i, Builder.getInt64(1), "iplus1");
  //Builder.CreateBr(forcond);
}
#line 2085 "cmm.y.cpp" /* yacc.c:1646  */
    break;

  case 58:
#line 476 "cmm.y" /* yacc.c:1646  */
    {
  //Builder.SetInsertPoint(forexit);
  //Builder.CreateRetVoid();
  //phi_i->addIncoming(Builder.getInt64(0),entry);
}
#line 2095 "cmm.y.cpp" /* yacc.c:1646  */
    break;

  case 60:
#line 485 "cmm.y" /* yacc.c:1646  */
    {
  (yyval.value)= nullptr;
}
#line 2103 "cmm.y.cpp" /* yacc.c:1646  */
    break;

  case 61:
#line 489 "cmm.y" /* yacc.c:1646  */
    {
    (yyval.value) = (yyvsp[0].value);
  }
#line 2111 "cmm.y.cpp" /* yacc.c:1646  */
    break;

  case 62:
#line 495 "cmm.y" /* yacc.c:1646  */
    {
    Builder->CreateRetVoid();
}
#line 2119 "cmm.y.cpp" /* yacc.c:1646  */
    break;

  case 63:
#line 499 "cmm.y" /* yacc.c:1646  */
    {
    Builder->CreateRet((yyvsp[-1].value));
}
#line 2127 "cmm.y.cpp" /* yacc.c:1646  */
    break;

  case 64:
#line 505 "cmm.y" /* yacc.c:1646  */
    {
  (yyval.value) = (yyvsp[0].value);
}
#line 2135 "cmm.y.cpp" /* yacc.c:1646  */
    break;

  case 65:
#line 512 "cmm.y" /* yacc.c:1646  */
    {
   //create store 
   (yyval.value)=Builder->CreateStore((yyvsp[0].value),(yyvsp[-2].value));
    //Builder.CreateStore($4,addr);
}
#line 2145 "cmm.y.cpp" /* yacc.c:1646  */
    break;

  case 66:
#line 518 "cmm.y" /* yacc.c:1646  */
    {
  (yyval.value) = (yyvsp[0].value);
}
#line 2153 "cmm.y.cpp" /* yacc.c:1646  */
    break;

  case 67:
#line 525 "cmm.y" /* yacc.c:1646  */
    {
    (yyval.value) = (yyvsp[0].value);
  }
#line 2161 "cmm.y.cpp" /* yacc.c:1646  */
    break;

  case 68:
#line 529 "cmm.y" /* yacc.c:1646  */
    {
    (yyval.value) = Builder->CreateOr((yyvsp[-2].value),(yyvsp[0].value));
}
#line 2169 "cmm.y.cpp" /* yacc.c:1646  */
    break;

  case 69:
#line 533 "cmm.y" /* yacc.c:1646  */
    {
  (yyval.value) = Builder->CreateXor((yyvsp[-2].value), (yyvsp[0].value));
}
#line 2177 "cmm.y.cpp" /* yacc.c:1646  */
    break;

  case 70:
#line 537 "cmm.y" /* yacc.c:1646  */
    {
    (yyval.value) = Builder->CreateAnd((yyvsp[-2].value), (yyvsp[0].value));
}
#line 2185 "cmm.y.cpp" /* yacc.c:1646  */
    break;

  case 71:
#line 541 "cmm.y" /* yacc.c:1646  */
    {
    (yyval.value) = Builder->CreateICmpEQ((yyvsp[-2].value), (yyvsp[0].value));
}
#line 2193 "cmm.y.cpp" /* yacc.c:1646  */
    break;

  case 72:
#line 545 "cmm.y" /* yacc.c:1646  */
    {
  (yyval.value) = Builder->CreateICmpNE((yyvsp[-2].value), (yyvsp[0].value));
}
#line 2201 "cmm.y.cpp" /* yacc.c:1646  */
    break;

  case 73:
#line 549 "cmm.y" /* yacc.c:1646  */
    {
    Value *val = Builder->CreateICmpSLT((yyvsp[-2].value), (yyvsp[0].value));
   // $$ = Builder->CreateSelect(val, $1, $3);
    (yyval.value) = Builder->CreateSExt(val, Builder->getInt32Ty());
}
#line 2211 "cmm.y.cpp" /* yacc.c:1646  */
    break;

  case 74:
#line 555 "cmm.y" /* yacc.c:1646  */
    {
    Value *val = Builder->CreateICmpSGT((yyvsp[-2].value), (yyvsp[0].value));
    //$$ = Builder->CreateSelect(val, $1, $3);
    (yyval.value) = Builder->CreateSExt(val, Builder->getInt32Ty());
}
#line 2221 "cmm.y.cpp" /* yacc.c:1646  */
    break;

  case 75:
#line 561 "cmm.y" /* yacc.c:1646  */
    {
    Value *val = Builder->CreateICmpSLE((yyvsp[-2].value), (yyvsp[0].value));
    //$$ = Builder->CreateSelect(val, $1, $3);
    (yyval.value) = Builder->CreateSExt(val, Builder->getInt32Ty());
}
#line 2231 "cmm.y.cpp" /* yacc.c:1646  */
    break;

  case 76:
#line 567 "cmm.y" /* yacc.c:1646  */
    {
    Value *val = Builder->CreateICmpSGT((yyvsp[-2].value), (yyvsp[0].value));
    //$$ = Builder->CreateSelect(val, $1, $3);
    (yyval.value) = Builder->CreateSExt(val, Builder->getInt32Ty());
}
#line 2241 "cmm.y.cpp" /* yacc.c:1646  */
    break;

  case 77:
#line 573 "cmm.y" /* yacc.c:1646  */
    {
  (yyval.value) = Builder->CreateShl((yyvsp[-2].value),(yyvsp[0].value));
}
#line 2249 "cmm.y.cpp" /* yacc.c:1646  */
    break;

  case 78:
#line 577 "cmm.y" /* yacc.c:1646  */
    {
  (yyval.value) = Builder->CreateLShr((yyvsp[-2].value),(yyvsp[0].value));
}
#line 2257 "cmm.y.cpp" /* yacc.c:1646  */
    break;

  case 79:
#line 581 "cmm.y" /* yacc.c:1646  */
    {
      (yyval.value) = Builder->CreateAdd((yyvsp[-2].value), (yyvsp[0].value));
}
#line 2265 "cmm.y.cpp" /* yacc.c:1646  */
    break;

  case 80:
#line 585 "cmm.y" /* yacc.c:1646  */
    {
  (yyval.value) = Builder->CreateSub((yyvsp[-2].value),(yyvsp[0].value));
}
#line 2273 "cmm.y.cpp" /* yacc.c:1646  */
    break;

  case 81:
#line 589 "cmm.y" /* yacc.c:1646  */
    {
   (yyval.value) = Builder->CreateMul((yyvsp[-2].value), (yyvsp[0].value));
}
#line 2281 "cmm.y.cpp" /* yacc.c:1646  */
    break;

  case 82:
#line 593 "cmm.y" /* yacc.c:1646  */
    {
    (yyval.value) = Builder->CreateSDiv((yyvsp[-2].value), (yyvsp[0].value));
}
#line 2289 "cmm.y.cpp" /* yacc.c:1646  */
    break;

  case 83:
#line 597 "cmm.y" /* yacc.c:1646  */
    {
  (yyval.value) = Builder->CreateSRem((yyvsp[-2].value), (yyvsp[0].value));
}
#line 2297 "cmm.y.cpp" /* yacc.c:1646  */
    break;

  case 84:
#line 601 "cmm.y" /* yacc.c:1646  */
    {
  (yyval.value) = Builder->CreateICmpSGT((yyvsp[-1].value), Builder->getInt64(0));
}
#line 2305 "cmm.y.cpp" /* yacc.c:1646  */
    break;

  case 85:
#line 605 "cmm.y" /* yacc.c:1646  */
    {
     (yyval.value) = Builder->CreateIntToPtr((yyvsp[-1].value),(yyvsp[-1].value)->getType(), ""); 
}
#line 2313 "cmm.y.cpp" /* yacc.c:1646  */
    break;

  case 86:
#line 609 "cmm.y" /* yacc.c:1646  */
    {
  (yyval.value) = Builder->CreatePtrToInt((yyvsp[-1].value),unwrap(LLVMInt32Type()), "");
}
#line 2321 "cmm.y.cpp" /* yacc.c:1646  */
    break;

  case 87:
#line 613 "cmm.y" /* yacc.c:1646  */
    {
  (yyval.value) = Builder->CreateZExt((yyvsp[-1].value),Builder->getInt32Ty());
}
#line 2329 "cmm.y.cpp" /* yacc.c:1646  */
    break;

  case 88:
#line 617 "cmm.y" /* yacc.c:1646  */
    {
  (yyval.value) = Builder->CreateSExt((yyvsp[-1].value), Builder->getInt32Ty());
}
#line 2337 "cmm.y.cpp" /* yacc.c:1646  */
    break;

  case 90:
#line 622 "cmm.y" /* yacc.c:1646  */
    {
    (yyval.value)=(yyvsp[-1].value);
}
#line 2345 "cmm.y.cpp" /* yacc.c:1646  */
    break;

  case 93:
#line 633 "cmm.y" /* yacc.c:1646  */
    {
  //vector creation 
  }
#line 2353 "cmm.y.cpp" /* yacc.c:1646  */
    break;

  case 95:
#line 642 "cmm.y" /* yacc.c:1646  */
    {
    (yyval.value) = (yyvsp[0].value);
}
#line 2361 "cmm.y.cpp" /* yacc.c:1646  */
    break;

  case 97:
#line 647 "cmm.y" /* yacc.c:1646  */
    {
    
}
#line 2369 "cmm.y.cpp" /* yacc.c:1646  */
    break;

  case 98:
#line 651 "cmm.y" /* yacc.c:1646  */
    {
    (yyval.value)=Builder->CreateNeg((yyvsp[0].value));
}
#line 2377 "cmm.y.cpp" /* yacc.c:1646  */
    break;

  case 99:
#line 655 "cmm.y" /* yacc.c:1646  */
    {

    if ((yyvsp[0].value) > Builder->getInt64(0)) 
    {
        (yyval.value)=(yyvsp[0].value);
    }
    else
        (yyval.value)=Builder->CreateNeg((yyvsp[0].value));
    
}
#line 2392 "cmm.y.cpp" /* yacc.c:1646  */
    break;

  case 100:
#line 666 "cmm.y" /* yacc.c:1646  */
    {
    (yyval.value) = Builder->CreateNot((yyvsp[0].value));
}
#line 2400 "cmm.y.cpp" /* yacc.c:1646  */
    break;

  case 101:
#line 673 "cmm.y" /* yacc.c:1646  */
    {
    (yyval.value) = Builder->CreateLoad((yyvsp[0].value));
}
#line 2408 "cmm.y.cpp" /* yacc.c:1646  */
    break;

  case 102:
#line 677 "cmm.y" /* yacc.c:1646  */
    {
    (yyval.value) = (yyvsp[0].value);
}
#line 2416 "cmm.y.cpp" /* yacc.c:1646  */
    break;

  case 103:
#line 684 "cmm.y" /* yacc.c:1646  */
    {
    Value *retVal = NULL;
    retVal = symbol_find((yyvsp[0].id));
    if(retVal == NULL)
    {
          YYERROR;
    }
    (yyval.value) = retVal;

    #ifdef DEBUG
    printf("ID %s\n", (yyvsp[0].id));
    #endif
}
#line 2434 "cmm.y.cpp" /* yacc.c:1646  */
    break;

  case 104:
#line 698 "cmm.y" /* yacc.c:1646  */
    {
  
}
#line 2442 "cmm.y.cpp" /* yacc.c:1646  */
    break;

  case 105:
#line 702 "cmm.y" /* yacc.c:1646  */
    {
    
}
#line 2450 "cmm.y.cpp" /* yacc.c:1646  */
    break;

  case 106:
#line 709 "cmm.y" /* yacc.c:1646  */
    {
    (yyval.value) = (yyvsp[0].value);
           #ifdef DEBUG
    printf("unary constant expression\n");
    #endif
}
#line 2461 "cmm.y.cpp" /* yacc.c:1646  */
    break;

  case 107:
#line 716 "cmm.y" /* yacc.c:1646  */
    {
    (yyval.value) = Builder->CreateOr((yyvsp[-2].value),(yyvsp[0].value));
           #ifdef DEBUG
    printf("constant expression bitwise or\n");
    #endif
}
#line 2472 "cmm.y.cpp" /* yacc.c:1646  */
    break;

  case 108:
#line 723 "cmm.y" /* yacc.c:1646  */
    {
    (yyval.value) = Builder->CreateXor((yyvsp[-2].value), (yyvsp[0].value));
           #ifdef DEBUG
    printf("constant expression xor\n");
    #endif
}
#line 2483 "cmm.y.cpp" /* yacc.c:1646  */
    break;

  case 109:
#line 730 "cmm.y" /* yacc.c:1646  */
    {
    (yyval.value) = Builder->CreateAnd((yyvsp[-2].value), (yyvsp[0].value));
           #ifdef DEBUG
    printf("constant expression and\n");
    #endif
}
#line 2494 "cmm.y.cpp" /* yacc.c:1646  */
    break;

  case 110:
#line 737 "cmm.y" /* yacc.c:1646  */
    {
    (yyval.value) = Builder->CreateShl((yyvsp[-2].value),(yyvsp[0].value));
           #ifdef DEBUG
    printf("constant expression leftshift\n");
    #endif
}
#line 2505 "cmm.y.cpp" /* yacc.c:1646  */
    break;

  case 111:
#line 744 "cmm.y" /* yacc.c:1646  */
    {
    (yyval.value) = Builder->CreateLShr((yyvsp[-2].value),(yyvsp[0].value));  
           #ifdef DEBUG
    printf("constant expression rightshift\n");
    #endif
}
#line 2516 "cmm.y.cpp" /* yacc.c:1646  */
    break;

  case 112:
#line 751 "cmm.y" /* yacc.c:1646  */
    {
    (yyval.value) = Builder->CreateAdd((yyvsp[-2].value), (yyvsp[0].value));
           #ifdef DEBUG
    printf("constant expression add\n");
    #endif
}
#line 2527 "cmm.y.cpp" /* yacc.c:1646  */
    break;

  case 113:
#line 758 "cmm.y" /* yacc.c:1646  */
    {
    (yyval.value) = Builder->CreateSub((yyvsp[-2].value),(yyvsp[0].value));
           #ifdef DEBUG
    printf("constant expression sub\n");
    #endif
}
#line 2538 "cmm.y.cpp" /* yacc.c:1646  */
    break;

  case 114:
#line 765 "cmm.y" /* yacc.c:1646  */
    {
    (yyval.value) = Builder->CreateMul((yyvsp[-2].value), (yyvsp[0].value));
       #ifdef DEBUG
    printf("constant expression mutiply\n");
    #endif

}
#line 2550 "cmm.y.cpp" /* yacc.c:1646  */
    break;

  case 115:
#line 773 "cmm.y" /* yacc.c:1646  */
    {
    (yyval.value) = Builder->CreateSDiv((yyvsp[-2].value), (yyvsp[0].value));
          #ifdef DEBUG
    printf("constant expression division\n");
    #endif
}
#line 2561 "cmm.y.cpp" /* yacc.c:1646  */
    break;

  case 116:
#line 780 "cmm.y" /* yacc.c:1646  */
    {
    (yyval.value) = Builder->CreateSRem((yyvsp[-2].value), (yyvsp[0].value));
          #ifdef DEBUG
    printf("const expression mod\n");
    #endif
}
#line 2572 "cmm.y.cpp" /* yacc.c:1646  */
    break;

  case 117:
#line 787 "cmm.y" /* yacc.c:1646  */
    {
   (yyval.value) = Builder->CreateIntToPtr((yyvsp[-1].value),(yyvsp[-1].value)->getType(), ""); 
    #ifdef DEBUG
    printf("I2P const expression\n");
    #endif 
}
#line 2583 "cmm.y.cpp" /* yacc.c:1646  */
    break;

  case 118:
#line 794 "cmm.y" /* yacc.c:1646  */
    {
    (yyval.value) = Builder->CreatePtrToInt((yyvsp[-1].value),unwrap(LLVMInt32Type()), "");
          #ifdef DEBUG
    printf("P@I const expression\n");
    #endif
}
#line 2594 "cmm.y.cpp" /* yacc.c:1646  */
    break;

  case 119:
#line 804 "cmm.y" /* yacc.c:1646  */
    {
    //$$ = unwrap(LLVMConstInt(LLVMInt32Type(), $1, 0));
    (yyval.value)= (yyvsp[0].value);
          #ifdef DEBUG
    printf("unary constant\n");
    #endif
}
#line 2606 "cmm.y.cpp" /* yacc.c:1646  */
    break;

  case 120:
#line 812 "cmm.y" /* yacc.c:1646  */
    {
    //Value* val = unwrap(LLVMConstInt(LLVMInt32Type(), $2, 0));
    (yyval.value) = Builder->CreateNeg((yyvsp[0].value));
        #ifdef DEBUG
    printf("unary const minus\n");
    #endif
}
#line 2618 "cmm.y.cpp" /* yacc.c:1646  */
    break;

  case 121:
#line 820 "cmm.y" /* yacc.c:1646  */
    {
    (yyvsp[0].value) > Builder->getInt64(0) ? (yyval.value)=(yyvsp[0].value) : (yyval.value)=Builder->CreateNeg((yyvsp[0].value));
        #ifdef DEBUG
    printf("unary const plus\n");
    #endif
}
#line 2629 "cmm.y.cpp" /* yacc.c:1646  */
    break;

  case 122:
#line 827 "cmm.y" /* yacc.c:1646  */
    {
    (yyval.value) = Builder->CreateNot((yyvsp[0].value));
    #ifdef DEBUG
    printf("unary const Bitwise invert\n");
    #endif
}
#line 2640 "cmm.y.cpp" /* yacc.c:1646  */
    break;

  case 123:
#line 837 "cmm.y" /* yacc.c:1646  */
    {
  (yyval.value) = Builder->getInt64((yyvsp[0].inum));
    #ifdef DEBUG
    printf("constant integer %d\n", (yyvsp[0].inum));
    #endif
}
#line 2651 "cmm.y.cpp" /* yacc.c:1646  */
    break;


#line 2655 "cmm.y.cpp" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 847 "cmm.y" /* yacc.c:1906  */


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