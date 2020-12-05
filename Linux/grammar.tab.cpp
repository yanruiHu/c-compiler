/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "./lexical/ch.y"

#include <stdio.h>
// #include "hdr.h"
#include <string.h>
#include <fstream>
#include "../grammar/Nodes.h"
#include "../grammar/symbol/symbol.h"

using AST::BaseNode;
class BaseNode;
extern char *yytext;
extern int yylex();
extern FILE * yyin;
void yyerror(const char* s);
BaseNode* root = NULL;
extern int yylineno;

#line 88 "./Linux/grammar.tab.cpp"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_LINUX_GRAMMAR_TAB_H_INCLUDED
# define YY_YY_LINUX_GRAMMAR_TAB_H_INCLUDED
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
    OR = 258,
    AND = 259,
    RELOP = 260,
    LOWER_THAN_ELSE = 261,
    ERRID = 262,
    ID = 263,
    INT = 264,
    VOID = 265,
    STRUCT = 266,
    IF = 267,
    ELSE = 268,
    WHILE = 269,
    FOR = 270,
    CONTINUE = 271,
    RETURN = 272,
    ERRORCHAR = 273,
    GETMEMBER = 274
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 20 "./lexical/ch.y"

    AST::BaseNode* ast;
    // struct symtab *symp;
    char* str;

#line 166 "./Linux/grammar.tab.cpp"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


extern YYSTYPE yylval;
extern YYLTYPE yylloc;
int yyparse (void);

#endif /* !YY_YY_LINUX_GRAMMAR_TAB_H_INCLUDED  */



#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))

/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

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

#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
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

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

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
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE) \
             + YYSIZEOF (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  14
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   493

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  37
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  22
/* YYNRULES -- Number of rules.  */
#define YYNRULES  82
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  173

#define YYUNDEFTOK  2
#define YYMAXUTOK   274


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    13,     2,     2,     2,    11,     2,     2,
      14,    15,     9,     8,    23,     7,    36,    10,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    24,
       2,     3,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    16,     2,    17,    12,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    34,     2,    35,     2,     2,     2,     2,
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
       2,     2,     2,     2,     2,     2,     1,     2,     4,     5,
       6,    18,    19,    20,    21,    22,    25,    26,    27,    28,
      29,    30,    31,    32,    33
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    60,    60,    65,    68,    79,    84,    85,    91,    96,
      97,    99,   100,   108,   109,   110,   111,   114,   117,   118,
     121,   125,   128,   137,   140,   144,   148,   150,   155,   164,
     169,   172,   179,   183,   184,   187,   192,   197,   198,   199,
     204,   208,   214,   223,   230,   235,   239,   245,   252,   260,
     267,   274,   281,   286,   291,   294,   295,   301,   302,   311,
     317,   323,   329,   335,   341,   347,   353,   359,   365,   371,
     374,   379,   384,   389,   392,   395,   398,   405,   406,   409,
     410,   412,   415
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "'='", "OR", "AND", "RELOP", "'-'",
  "'+'", "'*'", "'/'", "'%'", "'^'", "'!'", "'('", "')'", "'['", "']'",
  "LOWER_THAN_ELSE", "ERRID", "ID", "INT", "VOID", "','", "';'", "STRUCT",
  "IF", "ELSE", "WHILE", "FOR", "CONTINUE", "RETURN", "ERRORCHAR",
  "GETMEMBER", "'{'", "'}'", "'.'", "$accept", "program",
  "translation_unit", "external_declaration", "external_declaration_list",
  "specifier", "struct_specifier", "struct_declaration_list",
  "struct_declaration", "direct_declarator", "func_declarator",
  "parameter_list", "parameter_declaration", "compound_statement",
  "block_item_list", "declaration_for", "statement", "defination",
  "declaration_list", "declaration", "expression",
  "argument_expression_list", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,    61,   258,   259,   260,    45,    43,    42,
      47,    37,    94,    33,    40,    41,    91,    93,   261,   262,
     263,   264,   265,    44,    59,   266,   267,   268,   269,   270,
     271,   272,   273,   274,   123,   125,    46
};
# endif

#define YYPACT_NINF (-84)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-55)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     110,   -16,    52,    66,    58,   112,    35,   -84,    71,    69,
     -84,   -84,   -84,    82,   -84,   -84,    -5,   -84,    62,   -84,
       0,   -84,    88,    55,    99,   106,   -84,    98,   -84,   -84,
     -84,   114,    16,   -84,   -84,   119,    43,   -84,   126,   133,
     -84,   -84,    93,   127,   -84,   -84,   -84,   -84,    88,   -84,
      44,    83,   134,    83,    83,   -10,     3,   135,   143,   144,
     152,   155,   -84,   106,   -84,   -84,   146,   195,   -84,   -84,
     -84,   148,   166,   -84,   180,   -84,   151,   358,   273,    83,
     163,   175,    83,    83,   139,   -84,   217,   205,   -84,   186,
     -84,    83,    83,    83,    83,    83,    83,    83,    83,    83,
      83,    83,   -84,   -84,   -84,   456,    50,   328,   -84,   188,
     372,   386,    39,   164,   189,   -84,   456,   -84,    83,   106,
     456,     9,   467,   477,   180,   180,    89,    89,    89,   151,
     343,   -84,    83,   -84,   -84,   116,   116,   -84,   282,   239,
     173,   456,   -84,   -84,   456,   183,   -84,   116,   400,   291,
     300,   261,   116,   -84,   116,   116,   414,   116,   428,   309,
     -84,   -84,   -84,   116,   -84,   116,   116,   442,   -84,   -84,
     -84,   116,   -84
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,    13,    14,     0,     0,     0,     3,     0,     0,
      10,    15,    16,     0,     1,     4,    21,     6,     0,    11,
       0,     9,     0,     0,     0,     0,     5,     0,     8,    32,
       7,     0,     0,    18,    24,    28,     0,    26,     0,    21,
      12,    30,     0,     0,    17,    19,    27,    23,     0,    22,
       0,     0,     0,     0,     0,    75,    78,     0,     0,     0,
       0,     0,    29,     0,    38,    31,     0,     0,    20,    25,
      80,    52,     0,    78,    70,    79,    71,     0,     0,     0,
       0,     0,     0,     0,     0,    40,     0,    57,    53,    55,
      36,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    35,    69,    73,    81,     0,     0,    77,     0,
       0,     0,     0,     0,     0,    33,    34,    39,     0,     0,
      59,    61,    60,    62,    64,    63,    65,    66,    67,    68,
       0,    72,     0,    76,    37,     0,     0,    54,     0,     0,
       0,    58,    56,    74,    82,    41,    43,     0,     0,     0,
       0,     0,     0,    44,     0,     0,     0,     0,     0,     0,
      42,    47,    46,     0,    45,     0,     0,     0,    51,    50,
      49,     0,    48
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -84,   -84,   -84,   208,   -84,     7,   -84,   -84,   184,    -3,
     -84,   -84,   167,   197,   -84,   -84,   -83,   147,   111,   -84,
     -51,   -84
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     5,     6,     7,    18,    63,     9,    32,    33,    87,
      20,    36,    37,    64,    42,   114,    65,    66,    88,    89,
      67,   106
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      74,    27,    76,    77,    78,    19,    79,     8,    10,    23,
      86,    24,    11,     8,    93,    94,    95,    96,    97,    98,
      99,   100,    40,   -13,    28,   101,    80,   105,   107,    31,
      35,   110,   111,   116,    29,    -2,     1,     2,     3,    31,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,    44,   145,   146,    70,    35,     2,     3,    47,    70,
       4,    11,   139,   137,   153,   131,    48,   141,    71,   160,
      34,   161,   162,   132,   164,    12,     2,     3,    13,    41,
     168,   144,   169,   170,    72,    25,    26,   148,   172,   151,
      51,    16,    52,    21,    50,    17,    53,    54,   156,   158,
      51,   100,    52,    55,    73,   101,    53,    54,   167,     2,
       3,     1,    14,    55,    56,     3,    22,    50,    57,    58,
      38,    59,    60,    51,    61,    52,    39,    29,    62,    53,
      54,     2,     3,    41,    43,     4,    55,    56,     3,    46,
     112,    57,    58,    49,    59,    60,    51,    61,    52,    24,
      29,    68,    53,    54,    75,    81,    72,    82,    83,    55,
      56,     3,    51,   113,    52,    72,    84,   101,    53,    54,
      90,    51,   -54,    52,    72,    55,    73,    53,    54,    85,
      51,    70,    52,   108,    55,    73,    53,    54,   138,    97,
      98,    99,   100,    55,    73,   109,   101,   150,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   118,   119,
     152,   101,   134,   140,    15,    69,    45,    30,     0,   102,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     142,   115,     0,   101,     0,     0,     0,     0,     0,     0,
       0,   117,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,     0,     0,     0,   101,     0,     0,     0,     0,
       0,     0,     0,   149,    91,    92,    93,    94,    95,    96,
      97,    98,    99,   100,    72,     0,     0,   101,     0,     0,
      51,     0,    52,    72,     0,   159,    53,    54,   104,    51,
       0,    52,    72,    55,    73,    53,    54,   147,    51,     0,
      52,    72,    55,    73,    53,    54,   155,    51,     0,    52,
      72,    55,    73,    53,    54,   157,    51,     0,    52,     0,
      55,    73,    53,    54,   166,     0,     0,     0,     0,    55,
      73,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,     0,     0,     0,   101,   133,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,     0,     0,     0,   101,
     143,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,     0,     0,   103,   101,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,     0,     0,   135,   101,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,     0,
       0,   136,   101,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,     0,     0,   154,   101,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,     0,     0,   163,
     101,    91,    92,    93,    94,    95,    96,    97,    98,    99,
     100,     0,     0,   165,   101,    91,    92,    93,    94,    95,
      96,    97,    98,    99,   100,     0,     0,   171,   101,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   100,     0,
       0,     0,   101,    94,    95,    96,    97,    98,    99,   100,
       0,     0,     0,   101,    95,    96,    97,    98,    99,   100,
       0,     0,     0,   101
};

static const yytype_int16 yycheck[] =
{
      51,     1,    53,    54,    14,     8,    16,     0,    24,    14,
      61,    16,     9,     6,     5,     6,     7,     8,     9,    10,
      11,    12,    25,    20,    24,    16,    36,    78,    79,    22,
      23,    82,    83,    84,    34,     0,     1,    21,    22,    32,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,    35,   135,   136,    15,    48,    21,    22,    15,    15,
      25,     9,   113,    24,   147,    15,    23,   118,    24,   152,
      15,   154,   155,    23,   157,     9,    21,    22,    20,    35,
     163,   132,   165,   166,     1,    23,    24,   138,   171,   140,
       7,    20,     9,    24,     1,    24,    13,    14,   149,   150,
       7,    12,     9,    20,    21,    16,    13,    14,   159,    21,
      22,     1,     0,    20,    21,    22,    34,     1,    25,    26,
      21,    28,    29,     7,    31,     9,    20,    34,    35,    13,
      14,    21,    22,    35,    20,    25,    20,    21,    22,    20,
       1,    25,    26,    17,    28,    29,     7,    31,     9,    16,
      34,    24,    13,    14,    20,    20,     1,    14,    14,    20,
      21,    22,     7,    24,     9,     1,    14,    16,    13,    14,
      24,     7,    24,     9,     1,    20,    21,    13,    14,    24,
       7,    15,     9,    20,    20,    21,    13,    14,    24,     9,
      10,    11,    12,    20,    21,    20,    16,    24,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,     3,    23,
      27,    16,    24,    24,     6,    48,    32,    20,    -1,    24,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
     119,    84,    -1,    16,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    24,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    -1,    -1,    -1,    16,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    24,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,     1,    -1,    -1,    16,    -1,    -1,
       7,    -1,     9,     1,    -1,    24,    13,    14,    15,     7,
      -1,     9,     1,    20,    21,    13,    14,    15,     7,    -1,
       9,     1,    20,    21,    13,    14,    15,     7,    -1,     9,
       1,    20,    21,    13,    14,    15,     7,    -1,     9,    -1,
      20,    21,    13,    14,    15,    -1,    -1,    -1,    -1,    20,
      21,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    -1,    -1,    -1,    16,    17,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    -1,    -1,    -1,    16,
      17,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    -1,    -1,    15,    16,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    -1,    -1,    15,    16,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    -1,
      -1,    15,    16,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    -1,    -1,    15,    16,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    -1,    -1,    15,
      16,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    -1,    -1,    15,    16,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    -1,    -1,    15,    16,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    -1,
      -1,    -1,    16,     6,     7,     8,     9,    10,    11,    12,
      -1,    -1,    -1,    16,     7,     8,     9,    10,    11,    12,
      -1,    -1,    -1,    16
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     1,    21,    22,    25,    38,    39,    40,    42,    43,
      24,     9,     9,    20,     0,    40,    20,    24,    41,    46,
      47,    24,    34,    14,    16,    23,    24,     1,    24,    34,
      50,    42,    44,    45,    15,    42,    48,    49,    21,    20,
      46,    35,    51,    20,    35,    45,    20,    15,    23,    17,
       1,     7,     9,    13,    14,    20,    21,    25,    26,    28,
      29,    31,    35,    42,    50,    53,    54,    57,    24,    49,
      15,    24,     1,    21,    57,    20,    57,    57,    14,    16,
      36,    20,    14,    14,    14,    24,    57,    46,    55,    56,
      24,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    16,    24,    15,    15,    57,    58,    57,    20,    20,
      57,    57,     1,    24,    52,    54,    57,    24,     3,    23,
      57,    57,    57,    57,    57,    57,    57,    57,    57,    57,
      57,    15,    23,    17,    24,    15,    15,    24,    24,    57,
      24,    57,    55,    17,    57,    53,    53,    15,    57,    24,
      24,    57,    27,    53,    15,    15,    57,    15,    57,    24,
      53,    53,    53,    15,    53,    15,    15,    57,    53,    53,
      53,    15,    53
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    37,    38,    39,    39,    40,    40,    40,    40,    40,
      40,    41,    41,    42,    42,    42,    42,    43,    44,    44,
      45,    46,    46,    47,    47,    48,    48,    49,    49,    50,
      50,    51,    51,    52,    52,    53,    53,    53,    53,    53,
      53,    53,    53,    53,    53,    53,    53,    53,    53,    53,
      53,    53,    53,    54,    54,    55,    55,    56,    56,    57,
      57,    57,    57,    57,    57,    57,    57,    57,    57,    57,
      57,    57,    57,    57,    57,    57,    57,    57,    57,    57,
      57,    58,    58
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     2,     3,     2,     3,     3,     2,
       2,     1,     3,     1,     1,     2,     2,     5,     1,     2,
       3,     1,     4,     4,     3,     3,     1,     2,     1,     3,
       2,     2,     0,     1,     1,     2,     2,     4,     1,     3,
       2,     5,     7,     5,     6,     7,     7,     7,     9,     8,
       8,     8,     2,     2,     2,     1,     3,     1,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       2,     2,     4,     3,     4,     1,     4,     3,     1,     2,
       2,     1,     3
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
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


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


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


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static int
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  int res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
 }

#  define YY_LOCATION_PRINT(File, Loc)          \
  yy_location_print_ (File, &(Loc))

# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value, Location); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  YYUSE (yylocationp);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  YY_LOCATION_PRINT (yyo, *yylocationp);
  YYFPRINTF (yyo, ": ");
  yy_symbol_value_print (yyo, yytype, yyvaluep, yylocationp);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
                       , &(yylsp[(yyi + 1) - (yynrhs)])                       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule); \
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
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
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
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
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
            else
              goto append;

          append:
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

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
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
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

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
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
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
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
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
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
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
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);
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
/* Location data for the lookahead symbol.  */
YYLTYPE yylloc
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.
       'yyls': related to locations.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    /* The location stack.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls;
    YYLTYPE *yylsp;

    /* The locations where the error started and ended.  */
    YYLTYPE yyerror_range[3];

    YYPTRDIFF_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yylsp = yyls = yylsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  yylsp[0] = yylloc;
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yyls1, yysize * YYSIZEOF (*yylsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
        yyls = yyls1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
        YYSTACK_RELOCATE (yyls_alloc, yyls);
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END
  *++yylsp = yylloc;

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
| yyreduce -- do a reduction.  |
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

  /* Default location. */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  yyerror_range[1] = yyloc;
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2:
#line 60 "./lexical/ch.y"
                          { 
        root = new BaseNode("code start!", AST::root);
        root->addChildNode((yyvsp[0].ast));
    }
#line 1635 "./Linux/grammar.tab.cpp"
    break;

  case 3:
#line 65 "./lexical/ch.y"
                                       { 
        (yyval.ast) = (yyvsp[0].ast);
    }
#line 1643 "./Linux/grammar.tab.cpp"
    break;

  case 4:
#line 68 "./lexical/ch.y"
                                            {
        if ((yyvsp[-1].ast) == NULL) {
            (yyval.ast) = (yyvsp[0].ast);
        } else {
            if ((yyvsp[0].ast) != NULL) {
                (yyvsp[-1].ast)->getFinalCousinNode()->addCousinNode((yyvsp[0].ast));
            }
            (yyval.ast) = (yyvsp[-1].ast);
        }
    }
#line 1658 "./Linux/grammar.tab.cpp"
    break;

  case 5:
#line 79 "./lexical/ch.y"
                                                              {
        AST::DefineVarNode* tmp = (AST::DefineVarNode*)(yyvsp[-1].ast);
        tmp->setAllSymbolType((yyvsp[-2].str));
        (yyval.ast) = tmp;
    }
#line 1668 "./Linux/grammar.tab.cpp"
    break;

  case 6:
#line 84 "./lexical/ch.y"
                    {}
#line 1674 "./Linux/grammar.tab.cpp"
    break;

  case 7:
#line 85 "./lexical/ch.y"
                                                   {
        AST::DefineFuncNode* tmp = (AST::DefineFuncNode*) (yyvsp[-1].ast);
        tmp->addChildNode((yyvsp[0].ast));
        tmp->setReturnSymbolType((yyvsp[-2].str));
        (yyval.ast) = tmp;
    }
#line 1685 "./Linux/grammar.tab.cpp"
    break;

  case 8:
#line 91 "./lexical/ch.y"
                                     {
        AST::DefineFuncNode* tmp = (AST::DefineFuncNode*) (yyvsp[-1].ast);
        tmp->setReturnSymbolType((yyvsp[-2].str));
        (yyval.ast) = tmp;
    }
#line 1695 "./Linux/grammar.tab.cpp"
    break;

  case 9:
#line 96 "./lexical/ch.y"
                           { (yyval.ast) = (yyvsp[-1].ast);}
#line 1701 "./Linux/grammar.tab.cpp"
    break;

  case 10:
#line 97 "./lexical/ch.y"
                { yyerrok; (yyval.ast) = NULL;}
#line 1707 "./Linux/grammar.tab.cpp"
    break;

  case 11:
#line 99 "./lexical/ch.y"
                                             { (yyval.ast) = (yyvsp[0].ast); }
#line 1713 "./Linux/grammar.tab.cpp"
    break;

  case 12:
#line 100 "./lexical/ch.y"
                                                      {
        (yyvsp[-2].ast)->getFinalCousinNode()->addCousinNode((yyvsp[0].ast));
        (yyval.ast) = (yyvsp[-2].ast);
    }
#line 1722 "./Linux/grammar.tab.cpp"
    break;

  case 13:
#line 108 "./lexical/ch.y"
               { (yyval.str) = strdup("int"); }
#line 1728 "./Linux/grammar.tab.cpp"
    break;

  case 14:
#line 109 "./lexical/ch.y"
           { (yyval.str) = strdup("void"); }
#line 1734 "./Linux/grammar.tab.cpp"
    break;

  case 15:
#line 110 "./lexical/ch.y"
              { (yyval.str) = strdup("int ptr"); }
#line 1740 "./Linux/grammar.tab.cpp"
    break;

  case 16:
#line 111 "./lexical/ch.y"
               { (yyval.str) = strdup("void ptr"); }
#line 1746 "./Linux/grammar.tab.cpp"
    break;

  case 17:
#line 114 "./lexical/ch.y"
                                                            { (yyval.ast) = NULL; }
#line 1752 "./Linux/grammar.tab.cpp"
    break;

  case 18:
#line 117 "./lexical/ch.y"
                                            { (yyval.ast) = NULL; }
#line 1758 "./Linux/grammar.tab.cpp"
    break;

  case 19:
#line 118 "./lexical/ch.y"
                                                { (yyval.ast) = NULL; }
#line 1764 "./Linux/grammar.tab.cpp"
    break;

  case 20:
#line 121 "./lexical/ch.y"
                                     { (yyval.ast) = NULL; }
#line 1770 "./Linux/grammar.tab.cpp"
    break;

  case 21:
#line 125 "./lexical/ch.y"
                      {
        (yyval.ast) = new AST::DefineVarNode((yyvsp[0].str));
    }
#line 1778 "./Linux/grammar.tab.cpp"
    break;

  case 22:
#line 128 "./lexical/ch.y"
                     {
        // std::string s = "array name: ";
        // s = s + $1 + ", length: " + $3;
        AST::DefineVarNode* tmp = new AST::DefineVarNode((yyvsp[-3].str));
        tmp->setAllSymbolType("array");
        tmp->setArrayLength((yyvsp[-1].str));
        (yyval.ast) = tmp;
    }
#line 1791 "./Linux/grammar.tab.cpp"
    break;

  case 23:
#line 137 "./lexical/ch.y"
                                           { 
        (yyval.ast) = new AST::DefineFuncNode((yyvsp[-3].str), (yyvsp[-1].ast));
    }
#line 1799 "./Linux/grammar.tab.cpp"
    break;

  case 24:
#line 140 "./lexical/ch.y"
                 {
        (yyval.ast) = new AST::DefineFuncNode((yyvsp[-2].str));
    }
#line 1807 "./Linux/grammar.tab.cpp"
    break;

  case 25:
#line 144 "./lexical/ch.y"
                                                         {
        (yyvsp[-2].ast)->getFinalCousinNode()->addCousinNode((yyvsp[0].ast));
        (yyval.ast) = (yyvsp[-2].ast);
    }
#line 1816 "./Linux/grammar.tab.cpp"
    break;

  case 26:
#line 148 "./lexical/ch.y"
                            { (yyval.ast) = (yyvsp[0].ast); }
#line 1822 "./Linux/grammar.tab.cpp"
    break;

  case 27:
#line 150 "./lexical/ch.y"
                                    {
        AST::DefineVarNode* tmp = new AST::DefineVarNode((yyvsp[0].str));
        tmp->setAllSymbolType((yyvsp[-1].str));
        (yyval.ast) = tmp;
    }
#line 1832 "./Linux/grammar.tab.cpp"
    break;

  case 28:
#line 155 "./lexical/ch.y"
                {
        AST::DefineVarNode* tmp = new AST::DefineVarNode("");
        tmp->setAllSymbolType((yyvsp[0].str));
        (yyval.ast) = tmp;
    }
#line 1842 "./Linux/grammar.tab.cpp"
    break;

  case 29:
#line 164 "./lexical/ch.y"
                                            {
        BaseNode* temp = new AST::StatementNode(AST::compoundation);
        temp->addChildNode((yyvsp[-1].ast));
        (yyval.ast) = temp;
    }
#line 1852 "./Linux/grammar.tab.cpp"
    break;

  case 30:
#line 169 "./lexical/ch.y"
                { yyerrok; }
#line 1858 "./Linux/grammar.tab.cpp"
    break;

  case 31:
#line 172 "./lexical/ch.y"
                                           {
        if ((yyvsp[-1].ast) == NULL) {
            (yyval.ast) = (yyvsp[0].ast);
        } else {
            (yyvsp[-1].ast)->getFinalCousinNode()->addCousinNode((yyvsp[0].ast));
        }
    }
#line 1870 "./Linux/grammar.tab.cpp"
    break;

  case 32:
#line 179 "./lexical/ch.y"
      { (yyval.ast) = NULL; }
#line 1876 "./Linux/grammar.tab.cpp"
    break;

  case 33:
#line 183 "./lexical/ch.y"
                            { (yyval.ast) = (yyvsp[0].ast); }
#line 1882 "./Linux/grammar.tab.cpp"
    break;

  case 34:
#line 184 "./lexical/ch.y"
                 { (yyval.ast) = (yyvsp[0].ast); }
#line 1888 "./Linux/grammar.tab.cpp"
    break;

  case 35:
#line 187 "./lexical/ch.y"
                          { 
        BaseNode* temp = new AST::StatementNode(AST::expression);
        temp->addChildNode((yyvsp[-1].ast));
        (yyval.ast) = temp;
    }
#line 1898 "./Linux/grammar.tab.cpp"
    break;

  case 36:
#line 192 "./lexical/ch.y"
                     { 
        BaseNode* temp = new AST::StatementNode(AST::defination);
        temp->addChildNode((yyvsp[-1].ast));
        (yyval.ast) = temp;
    }
#line 1908 "./Linux/grammar.tab.cpp"
    break;

  case 37:
#line 197 "./lexical/ch.y"
                       { (yyval.ast) =NULL; }
#line 1914 "./Linux/grammar.tab.cpp"
    break;

  case 38:
#line 198 "./lexical/ch.y"
                         { (yyval.ast)=(yyvsp[0].ast);}
#line 1920 "./Linux/grammar.tab.cpp"
    break;

  case 39:
#line 199 "./lexical/ch.y"
                            {
        BaseNode* temp = new AST::StatementNode(AST::return_stmt);
        temp->addChildNode((yyvsp[-1].ast));
        (yyval.ast) = temp;
    }
#line 1930 "./Linux/grammar.tab.cpp"
    break;

  case 40:
#line 204 "./lexical/ch.y"
                 {
        BaseNode* temp = new AST::StatementNode(AST::return_stmt);
        (yyval.ast) = temp;
    }
#line 1939 "./Linux/grammar.tab.cpp"
    break;

  case 41:
#line 208 "./lexical/ch.y"
                                      {  // ok
        BaseNode* temp = new AST::SelectNode(AST::if_stmt);
        temp->addChildNode((yyvsp[-2].ast));
        (yyvsp[-2].ast)->addCousinNode((yyvsp[0].ast));
        (yyval.ast) = temp;
    }
#line 1950 "./Linux/grammar.tab.cpp"
    break;

  case 42:
#line 214 "./lexical/ch.y"
                                                                          {
        BaseNode* temp = new AST::SelectNode(AST::if_stmt);
        temp->addChildNode((yyvsp[-4].ast));
        (yyvsp[-4].ast)->addCousinNode((yyvsp[-2].ast));
        BaseNode* else_node = new AST::SelectNode(AST::else_stmt);
        else_node->addChildNode((yyvsp[0].ast));
        temp->addCousinNode(else_node);
        (yyval.ast) = temp;
    }
#line 1964 "./Linux/grammar.tab.cpp"
    break;

  case 43:
#line 223 "./lexical/ch.y"
                                         { //ok
        BaseNode* temp = new AST::LoopNode(AST::while_loop);
        temp->addChildNode((yyvsp[-2].ast));
        (yyvsp[-2].ast)->addCousinNode((yyvsp[0].ast));
        (yyval.ast) = temp;
    }
#line 1975 "./Linux/grammar.tab.cpp"
    break;

  case 44:
#line 230 "./lexical/ch.y"
                                   { //ok
        BaseNode* temp = new AST::LoopNode(AST::for_loop);
        temp->addChildNode((yyvsp[0].ast));
        (yyval.ast) = temp;
    }
#line 1985 "./Linux/grammar.tab.cpp"
    break;

  case 45:
#line 235 "./lexical/ch.y"
                                                   {
        BaseNode* temp = new AST::LoopNode("", AST::for_loop, NULL, (yyvsp[-4].ast), NULL);
        temp->addChildNode((yyvsp[0].ast));
    }
#line 1994 "./Linux/grammar.tab.cpp"
    break;

  case 46:
#line 239 "./lexical/ch.y"
                                              { //ok
        BaseNode* temp = new AST::LoopNode(AST::for_loop);
        temp->addChildNode((yyvsp[-3].ast));
        (yyvsp[-3].ast)->addCousinNode((yyvsp[0].ast));
        (yyval.ast) = temp;
    }
#line 2005 "./Linux/grammar.tab.cpp"
    break;

  case 47:
#line 245 "./lexical/ch.y"
                                              { //OK
        BaseNode* temp = new AST::LoopNode(AST::for_loop);
        temp->addChildNode((yyvsp[-2].ast));
        (yyvsp[-2].ast)->addCousinNode((yyvsp[0].ast));
        (yyval.ast) = temp;

    }
#line 2017 "./Linux/grammar.tab.cpp"
    break;

  case 48:
#line 252 "./lexical/ch.y"
                                                                          { //OK
        BaseNode* temp = new AST::LoopNode(AST::for_loop);
        temp->addChildNode((yyvsp[-6].ast));
        (yyvsp[-6].ast)->addCousinNode((yyvsp[-4].ast));
        (yyvsp[-4].ast)->addCousinNode((yyvsp[-2].ast));
        (yyvsp[-2].ast)->addCousinNode((yyvsp[0].ast));
        (yyval.ast) = temp;
    }
#line 2030 "./Linux/grammar.tab.cpp"
    break;

  case 49:
#line 260 "./lexical/ch.y"
                                                                { //OK
        BaseNode* temp = new AST::LoopNode(AST::for_loop);
        temp->addChildNode((yyvsp[-5].ast));
        (yyvsp[-5].ast)->addCousinNode((yyvsp[-3].ast));
        (yyvsp[-3].ast)->addCousinNode((yyvsp[0].ast));
        (yyval.ast) = temp;
    }
#line 2042 "./Linux/grammar.tab.cpp"
    break;

  case 50:
#line 267 "./lexical/ch.y"
                                                                { //OK
        BaseNode* temp = new AST::LoopNode(AST::for_loop);
        temp->addChildNode((yyvsp[-5].ast));
        (yyvsp[-5].ast)->addCousinNode((yyvsp[-2].ast));
        (yyvsp[-2].ast)->addCousinNode((yyvsp[0].ast));
        (yyval.ast) = temp;
    }
#line 2054 "./Linux/grammar.tab.cpp"
    break;

  case 51:
#line 274 "./lexical/ch.y"
                                                          { //OK
        BaseNode* temp = new AST::LoopNode(AST::for_loop);
        temp->addChildNode((yyvsp[-4].ast));
        (yyvsp[-4].ast)->addCousinNode((yyvsp[-2].ast));
        (yyvsp[-2].ast)->addCousinNode((yyvsp[0].ast));
        (yyval.ast) = temp;
    }
#line 2066 "./Linux/grammar.tab.cpp"
    break;

  case 52:
#line 281 "./lexical/ch.y"
                { yyerrok; }
#line 2072 "./Linux/grammar.tab.cpp"
    break;

  case 53:
#line 286 "./lexical/ch.y"
                                        {
        AST::DefineVarNode* tmp = (AST::DefineVarNode*)((yyvsp[0].ast)->getChildNode());
        if(tmp) tmp->setAllSymbolType((yyvsp[-1].str));
        (yyval.ast) = (yyvsp[0].ast);
    }
#line 2082 "./Linux/grammar.tab.cpp"
    break;

  case 54:
#line 291 "./lexical/ch.y"
                { yyerrok; }
#line 2088 "./Linux/grammar.tab.cpp"
    break;

  case 55:
#line 294 "./lexical/ch.y"
                              { (yyval.ast) = (yyvsp[0].ast); }
#line 2094 "./Linux/grammar.tab.cpp"
    break;

  case 56:
#line 295 "./lexical/ch.y"
                                       {
        (yyvsp[-2].ast)->getFinalCousinNode()->addCousinNode((yyvsp[0].ast));
        (yyval.ast) = (yyvsp[-2].ast);
    }
#line 2103 "./Linux/grammar.tab.cpp"
    break;

  case 57:
#line 301 "./lexical/ch.y"
                               { (yyval.ast) = (yyvsp[0].ast); }
#line 2109 "./Linux/grammar.tab.cpp"
    break;

  case 58:
#line 302 "./lexical/ch.y"
                                       {
        (yyval.ast) = new AST::OperatorNode("=");
        (yyval.ast)->addChildNode((yyvsp[-2].ast));
        (yyvsp[-2].ast)->addCousinNode((yyvsp[0].ast));
    }
#line 2119 "./Linux/grammar.tab.cpp"
    break;

  case 59:
#line 311 "./lexical/ch.y"
                                      {
            BaseNode* temp = new AST::OperatorNode("=");
            temp->addChildNode((yyvsp[-2].ast));
            (yyvsp[-2].ast)->addCousinNode((yyvsp[0].ast));
            (yyval.ast) = temp;
        }
#line 2130 "./Linux/grammar.tab.cpp"
    break;

  case 60:
#line 317 "./lexical/ch.y"
                                    {
            BaseNode* temp = new AST::OperatorNode("&&");
            temp->addChildNode((yyvsp[-2].ast));
            (yyvsp[-2].ast)->addCousinNode((yyvsp[0].ast));
            (yyval.ast) = temp;
        }
#line 2141 "./Linux/grammar.tab.cpp"
    break;

  case 61:
#line 323 "./lexical/ch.y"
                                   {
            BaseNode* temp = new AST::OperatorNode("||");
            temp->addChildNode((yyvsp[-2].ast));
            (yyvsp[-2].ast)->addCousinNode((yyvsp[0].ast));
            (yyval.ast) = temp;
        }
#line 2152 "./Linux/grammar.tab.cpp"
    break;

  case 62:
#line 329 "./lexical/ch.y"
                                      {
            BaseNode* temp = new AST::OperatorNode((yyvsp[-1].str));
            temp->addChildNode((yyvsp[-2].ast));
            (yyvsp[-2].ast)->addCousinNode((yyvsp[0].ast));
            (yyval.ast) = temp;
        }
#line 2163 "./Linux/grammar.tab.cpp"
    break;

  case 63:
#line 335 "./lexical/ch.y"
                                    {
            BaseNode* temp = new AST::OperatorNode("+");
            temp->addChildNode((yyvsp[-2].ast));
            (yyvsp[-2].ast)->addCousinNode((yyvsp[0].ast));
            (yyval.ast) = temp;
        }
#line 2174 "./Linux/grammar.tab.cpp"
    break;

  case 64:
#line 341 "./lexical/ch.y"
                                    {
            BaseNode* temp = new AST::OperatorNode("-");
            temp->addChildNode((yyvsp[-2].ast));
            (yyvsp[-2].ast)->addCousinNode((yyvsp[0].ast));
            (yyval.ast) = temp;
        }
#line 2185 "./Linux/grammar.tab.cpp"
    break;

  case 65:
#line 347 "./lexical/ch.y"
                                    {
            BaseNode* temp = new AST::OperatorNode("*");
            temp->addChildNode((yyvsp[-2].ast));
            (yyvsp[-2].ast)->addCousinNode((yyvsp[0].ast));
            (yyval.ast) = temp;
        }
#line 2196 "./Linux/grammar.tab.cpp"
    break;

  case 66:
#line 353 "./lexical/ch.y"
                                    {
            BaseNode* temp = new AST::OperatorNode("/");
            temp->addChildNode((yyvsp[-2].ast));
            (yyvsp[-2].ast)->addCousinNode((yyvsp[0].ast));
            (yyval.ast) = temp;
        }
#line 2207 "./Linux/grammar.tab.cpp"
    break;

  case 67:
#line 359 "./lexical/ch.y"
                                    {
            BaseNode* temp = new AST::OperatorNode("%");
            temp->addChildNode((yyvsp[-2].ast));
            (yyvsp[-2].ast)->addCousinNode((yyvsp[0].ast));
            (yyval.ast) = temp;
        }
#line 2218 "./Linux/grammar.tab.cpp"
    break;

  case 68:
#line 365 "./lexical/ch.y"
                                    {
            BaseNode* temp = new AST::OperatorNode("^");
            temp->addChildNode((yyvsp[-2].ast));
            (yyvsp[-2].ast)->addCousinNode((yyvsp[0].ast));
            (yyval.ast) = temp;
        }
#line 2229 "./Linux/grammar.tab.cpp"
    break;

  case 69:
#line 371 "./lexical/ch.y"
                             {
            (yyval.ast) = (yyvsp[-1].ast);
        }
#line 2237 "./Linux/grammar.tab.cpp"
    break;

  case 70:
#line 374 "./lexical/ch.y"
                         {
            BaseNode* temp = new AST::OperatorNode("-");
            temp->addChildNode((yyvsp[0].ast));
            (yyval.ast) = temp;
        }
#line 2247 "./Linux/grammar.tab.cpp"
    break;

  case 71:
#line 379 "./lexical/ch.y"
                         {
            BaseNode* temp = new AST::OperatorNode("!");
            temp->addChildNode((yyvsp[0].ast));
            (yyval.ast) = temp;
        }
#line 2257 "./Linux/grammar.tab.cpp"
    break;

  case 72:
#line 384 "./lexical/ch.y"
                                              {
            BaseNode* temp = new AST::CallFuncNode((yyvsp[-3].str));
            temp->addChildNode((yyvsp[-1].ast));
            (yyval.ast) = temp;
        }
#line 2267 "./Linux/grammar.tab.cpp"
    break;

  case 73:
#line 389 "./lexical/ch.y"
                     {
            (yyval.ast) = new AST::CallFuncNode((yyvsp[-2].str));
        }
#line 2275 "./Linux/grammar.tab.cpp"
    break;

  case 74:
#line 392 "./lexical/ch.y"
                                        {
            (yyval.ast) = NULL;
        }
#line 2283 "./Linux/grammar.tab.cpp"
    break;

  case 75:
#line 395 "./lexical/ch.y"
             {
            (yyval.ast) = new AST::AssignVarNode((yyvsp[0].str));
        }
#line 2291 "./Linux/grammar.tab.cpp"
    break;

  case 76:
#line 398 "./lexical/ch.y"
                                {
            BaseNode* op = new AST::OperatorNode("[]");
            BaseNode* temp = new AST::AssignVarNode((yyvsp[-3].str));
            (yyval.ast) = op;
            op->addChildNode(temp);
            temp->addCousinNode((yyvsp[-1].ast));
        }
#line 2303 "./Linux/grammar.tab.cpp"
    break;

  case 77:
#line 405 "./lexical/ch.y"
                    {}
#line 2309 "./Linux/grammar.tab.cpp"
    break;

  case 78:
#line 406 "./lexical/ch.y"
              {
            (yyval.ast) = new AST::LiteralNode((yyvsp[0].str));
        }
#line 2317 "./Linux/grammar.tab.cpp"
    break;

  case 79:
#line 409 "./lexical/ch.y"
                 {}
#line 2323 "./Linux/grammar.tab.cpp"
    break;

  case 80:
#line 410 "./lexical/ch.y"
                    {yyerrok;}
#line 2329 "./Linux/grammar.tab.cpp"
    break;

  case 81:
#line 412 "./lexical/ch.y"
                                     {
            (yyval.ast) = (yyvsp[0].ast);
        }
#line 2337 "./Linux/grammar.tab.cpp"
    break;

  case 82:
#line 415 "./lexical/ch.y"
                                                  {
            (yyvsp[-2].ast)->getFinalCousinNode()->addCousinNode((yyvsp[0].ast));
            (yyval.ast) = (yyvsp[-2].ast);
        }
#line 2346 "./Linux/grammar.tab.cpp"
    break;


#line 2350 "./Linux/grammar.tab.cpp"

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
  *++yylsp = yyloc;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

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
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
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

  yyerror_range[1] = yylloc;

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
                      yytoken, &yylval, &yylloc);
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

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

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the lookahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, yyerror_range, 2);
  *++yylsp = yyloc;

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


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, &yylloc);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[+*yyssp], yyvsp, yylsp);
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
#line 420 "./lexical/ch.y"



void yyerror(const char* s) {
	fprintf(stderr, "Parse error: At line %d. %s\n", yylineno, s);
	exit(1);
}

int main(int argc,char * argv[]){  //不确定语法的在哪里输出

    int c,j=0;
    yyin=fopen("./test.c","r");
    // if(argc>=2){
    //     if()==NULL){
    //         printf("Can't open file %s\n",argv[1]);
    //         return 1;
    //     }
    // }
    do {
		yyparse();
	} while(!feof(yyin));
    fclose(yyin);
    if(root) root->printTree();
    SMB::SymbolTable* root_symbol_table = new SMB::SymbolTable(NULL);
    SMB::tree(root_symbol_table,root,0);
    if(root) delete root;
    return 0;
}
