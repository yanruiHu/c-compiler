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
#include "../grammar/InterMediate/InterMediate.h"
#include "../grammar/InterMediate/AsmGenerator.h"

using AST::BaseNode;
using SMB::StructTable;
class BaseNode;
extern char *yytext;
extern int yylex();
extern FILE * yyin;
void yyerror(const char* s);
BaseNode* root = NULL;
StructTable *struct_table = NULL;
extern int yylineno;

#line 92 "./Linux/grammar.tab.cpp"

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
#line 24 "./lexical/ch.y"

    AST::BaseNode* ast;
    // struct symtab *symp;
    char* str;

#line 170 "./Linux/grammar.tab.cpp"

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
#define YYLAST   557

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  37
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  24
/* YYNRULES -- Number of rules.  */
#define YYNRULES  87
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  181

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
       2,     2,     2,    14,     2,     2,     2,    12,     6,     2,
      15,    16,    10,     9,    24,     8,     2,    11,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    25,
       2,     3,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    17,     2,    18,    13,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    35,     2,    36,     2,     2,     2,     2,
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
       7,    19,    20,    21,    22,    23,    26,    27,    28,    29,
      30,    31,    32,    33,    34
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    66,    66,    71,    74,    85,    92,    93,    99,   104,
     105,   107,   108,   113,   114,   119,   120,   131,   132,   133,
     134,   137,   147,   148,   153,   160,   163,   172,   175,   179,
     183,   185,   190,   199,   204,   207,   214,   218,   219,   222,
     227,   232,   237,   238,   243,   247,   254,   265,   271,   276,
     281,   286,   291,   296,   301,   306,   311,   316,   326,   329,
     330,   336,   337,   346,   360,   366,   372,   378,   384,   390,
     396,   402,   408,   414,   417,   422,   427,   433,   438,   441,
     444,   447,   454,   462,   465,   471,   473,   476
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "'='", "OR", "AND", "'&'", "RELOP",
  "'-'", "'+'", "'*'", "'/'", "'%'", "'^'", "'!'", "'('", "')'", "'['",
  "']'", "LOWER_THAN_ELSE", "ERRID", "ID", "INT", "VOID", "','", "';'",
  "STRUCT", "IF", "ELSE", "WHILE", "FOR", "CONTINUE", "RETURN",
  "ERRORCHAR", "GETMEMBER", "'{'", "'}'", "$accept", "program",
  "translation_unit", "external_declaration", "external_declaration_list",
  "init_declarator_list", "init_declarator", "specifier",
  "struct_specifier", "struct_declaration_list", "struct_declaration",
  "direct_declarator", "func_declarator", "parameter_list",
  "parameter_declaration", "compound_statement", "block_item_list",
  "declaration_for", "statement", "defination", "declaration_list",
  "declaration", "expression", "argument_expression_list", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,    61,   258,   259,    38,   260,    45,    43,
      42,    47,    37,    94,    33,    40,    41,    91,    93,   261,
     262,   263,   264,   265,    44,    59,   266,   267,   268,   269,
     270,   271,   272,   273,   274,   123,   125
};
# endif

#define YYPACT_NINF (-83)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-59)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     145,    12,    43,    67,    46,    87,   140,   -83,   -12,    68,
     -83,   -83,   -83,    59,   -83,   -83,    57,   -83,   -13,    71,
     -83,    93,    34,   -83,    63,    48,    80,    83,   -83,    83,
      91,    81,   -83,   -83,   -83,    95,   -16,   -83,   -83,   107,
      -8,   -83,   113,   117,    71,   -83,   -83,   -83,    97,   111,
     -83,   -83,   -83,   -83,    63,   -83,    40,   121,   351,   124,
     351,   351,    23,    -6,   126,   123,   133,   134,   100,   -83,
      83,   -83,   -83,   128,    14,   -83,   -83,   -83,   132,   -83,
     138,   -83,   206,   -83,   143,   403,   266,   351,   148,   152,
     351,   351,   164,   -83,   223,   172,   -83,   153,   -83,   351,
     351,   351,   351,   351,   351,   351,   351,   351,   351,   351,
     -83,   -83,   -83,   508,    36,   371,   -83,   151,   418,   433,
     -11,   182,   155,   -83,   508,   -83,   351,    83,   508,   519,
     530,   540,   206,   206,    62,    62,    62,   143,   387,   -83,
     351,   -83,   -83,   129,   129,   -83,   283,   234,   200,   508,
     -83,   -83,   508,   154,   -83,   129,   448,   300,   317,   253,
     129,   -83,   129,   129,   463,   129,   478,   334,   -83,   -83,
     -83,   129,   -83,   129,   129,   493,   -83,   -83,   -83,   129,
     -83
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,    17,    18,     0,     0,     0,     3,     0,     0,
      10,    19,    20,     0,     1,     4,    25,     6,     0,    11,
      13,    15,     0,     9,     0,     0,     0,     0,     5,     0,
       0,     0,     8,    36,     7,     0,     0,    22,    28,    32,
       0,    30,     0,    25,    12,    14,    16,    34,     0,     0,
      21,    23,    31,    27,     0,    26,     0,     0,     0,     0,
       0,     0,    80,    83,     0,     0,     0,     0,     0,    33,
       0,    42,    35,     0,     0,    24,    29,    85,    56,    76,
       0,    83,    74,    84,    75,     0,     0,     0,     0,     0,
       0,     0,     0,    44,     0,    61,    57,    59,    40,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      39,    73,    78,    86,     0,     0,    82,     0,     0,     0,
       0,     0,     0,    37,    38,    43,     0,     0,    63,    65,
      64,    66,    68,    67,    69,    70,    71,    72,     0,    77,
       0,    81,    41,     0,     0,    58,     0,     0,     0,    62,
      60,    79,    87,    45,    47,     0,     0,     0,     0,     0,
       0,    48,     0,     0,     0,     0,     0,     0,    46,    51,
      50,     0,    49,     0,     0,     0,    55,    54,    53,     0,
      52
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -83,   -83,   -83,   175,   -83,   157,   162,    30,   -83,   -83,
     158,   -69,   -83,   -83,   139,   173,   -83,   -83,   -82,   106,
      72,   -83,   -58,   -83
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     5,     6,     7,    18,    19,    20,    70,     9,    36,
      37,    21,    22,    40,    41,    71,    48,   122,    72,    73,
      96,    97,    74,   114
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      82,    95,    84,    85,    11,    77,     2,     3,    53,    16,
      94,    27,    28,    17,   145,   -17,    54,    99,   100,   101,
      50,   102,   103,   104,   105,   106,   107,   108,   113,   115,
       8,   109,   118,   119,   124,    31,     8,    10,    86,   110,
      87,   128,   129,   130,   131,   132,   133,   134,   135,   136,
     137,   138,   139,    11,    35,    39,    77,    88,    95,    32,
     140,   153,   154,   147,    38,    78,    35,    13,   149,    33,
       2,     3,    25,   161,    26,   108,    47,    12,   168,   109,
     169,   170,   152,   172,    39,     2,     3,    14,   156,   176,
     159,   177,   178,    23,    24,    29,    30,   180,    56,   164,
     166,    80,    42,    57,    43,    58,    57,    59,    58,   175,
      59,    60,    61,    46,    60,    61,    49,    47,    62,    63,
       3,    62,    81,    64,    65,    93,    66,    67,    52,    68,
      56,    55,    33,    69,    26,    57,    75,    58,    90,    59,
      -2,     1,    79,    60,    61,    83,     1,    89,    91,    92,
      62,    63,     3,    98,    77,    64,    65,   -58,    66,    67,
     109,    68,     2,     3,    33,   120,     4,     2,     3,   116,
      57,     4,    58,   117,    59,   126,   142,   127,    60,    61,
     148,    15,   160,    80,    44,    62,    63,     3,    57,   121,
      58,    45,    59,    76,    51,    34,    60,    61,   123,   150,
       0,    80,     0,    62,    81,     0,    57,   146,    58,     0,
      59,     0,     0,     0,    60,    61,   105,   106,   107,   108,
       0,    62,    81,   109,     0,   158,    99,   100,   101,     0,
     102,   103,   104,   105,   106,   107,   108,    99,   100,   101,
     109,   102,   103,   104,   105,   106,   107,   108,   125,     0,
       0,   109,     0,     0,     0,     0,    99,   100,   101,   157,
     102,   103,   104,   105,   106,   107,   108,    80,     0,     0,
     109,     0,    57,     0,    58,     0,    59,     0,   167,     0,
      60,    61,   112,     0,    80,     0,     0,    62,    81,    57,
       0,    58,     0,    59,     0,     0,     0,    60,    61,   155,
       0,    80,     0,     0,    62,    81,    57,     0,    58,     0,
      59,     0,     0,     0,    60,    61,   163,     0,    80,     0,
       0,    62,    81,    57,     0,    58,     0,    59,     0,     0,
       0,    60,    61,   165,     0,    80,     0,     0,    62,    81,
      57,     0,    58,     0,    59,     0,     0,     0,    60,    61,
     174,     0,    80,     0,     0,    62,    81,    57,     0,    58,
       0,    59,     0,     0,     0,    60,    61,     0,     0,     0,
       0,     0,    62,    81,    99,   100,   101,     0,   102,   103,
     104,   105,   106,   107,   108,     0,     0,     0,   109,   141,
      99,   100,   101,     0,   102,   103,   104,   105,   106,   107,
     108,     0,     0,     0,   109,   151,    99,   100,   101,     0,
     102,   103,   104,   105,   106,   107,   108,     0,     0,   111,
     109,    99,   100,   101,     0,   102,   103,   104,   105,   106,
     107,   108,     0,     0,   143,   109,    99,   100,   101,     0,
     102,   103,   104,   105,   106,   107,   108,     0,     0,   144,
     109,    99,   100,   101,     0,   102,   103,   104,   105,   106,
     107,   108,     0,     0,   162,   109,    99,   100,   101,     0,
     102,   103,   104,   105,   106,   107,   108,     0,     0,   171,
     109,    99,   100,   101,     0,   102,   103,   104,   105,   106,
     107,   108,     0,     0,   173,   109,    99,   100,   101,     0,
     102,   103,   104,   105,   106,   107,   108,     0,     0,   179,
     109,    99,   100,   101,     0,   102,   103,   104,   105,   106,
     107,   108,     0,     0,   101,   109,   102,   103,   104,   105,
     106,   107,   108,     0,     0,     0,   109,   102,   103,   104,
     105,   106,   107,   108,     0,     0,     0,   109,   103,   104,
     105,   106,   107,   108,     0,     0,     0,   109
};

static const yytype_int16 yycheck[] =
{
      58,    70,    60,    61,    10,    16,    22,    23,    16,    21,
      68,    24,    25,    25,    25,    21,    24,     3,     4,     5,
      36,     7,     8,     9,    10,    11,    12,    13,    86,    87,
       0,    17,    90,    91,    92,     1,     6,    25,    15,    25,
      17,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     108,   109,    16,    10,    24,    25,    16,    34,   127,    25,
      24,   143,   144,   121,    16,    25,    36,    21,   126,    35,
      22,    23,    15,   155,    17,    13,    36,    10,   160,    17,
     162,   163,   140,   165,    54,    22,    23,     0,   146,   171,
     148,   173,   174,    25,    35,    24,     3,   179,     1,   157,
     158,     1,    22,     6,    21,     8,     6,    10,     8,   167,
      10,    14,    15,    22,    14,    15,    21,    36,    21,    22,
      23,    21,    22,    26,    27,    25,    29,    30,    21,    32,
       1,    18,    35,    36,    17,     6,    25,     8,    15,    10,
       0,     1,    21,    14,    15,    21,     1,    21,    15,    15,
      21,    22,    23,    25,    16,    26,    27,    25,    29,    30,
      17,    32,    22,    23,    35,     1,    26,    22,    23,    21,
       6,    26,     8,    21,    10,     3,    25,    24,    14,    15,
      25,     6,    28,     1,    27,    21,    22,    23,     6,    25,
       8,    29,    10,    54,    36,    22,    14,    15,    92,   127,
      -1,     1,    -1,    21,    22,    -1,     6,    25,     8,    -1,
      10,    -1,    -1,    -1,    14,    15,    10,    11,    12,    13,
      -1,    21,    22,    17,    -1,    25,     3,     4,     5,    -1,
       7,     8,     9,    10,    11,    12,    13,     3,     4,     5,
      17,     7,     8,     9,    10,    11,    12,    13,    25,    -1,
      -1,    17,    -1,    -1,    -1,    -1,     3,     4,     5,    25,
       7,     8,     9,    10,    11,    12,    13,     1,    -1,    -1,
      17,    -1,     6,    -1,     8,    -1,    10,    -1,    25,    -1,
      14,    15,    16,    -1,     1,    -1,    -1,    21,    22,     6,
      -1,     8,    -1,    10,    -1,    -1,    -1,    14,    15,    16,
      -1,     1,    -1,    -1,    21,    22,     6,    -1,     8,    -1,
      10,    -1,    -1,    -1,    14,    15,    16,    -1,     1,    -1,
      -1,    21,    22,     6,    -1,     8,    -1,    10,    -1,    -1,
      -1,    14,    15,    16,    -1,     1,    -1,    -1,    21,    22,
       6,    -1,     8,    -1,    10,    -1,    -1,    -1,    14,    15,
      16,    -1,     1,    -1,    -1,    21,    22,     6,    -1,     8,
      -1,    10,    -1,    -1,    -1,    14,    15,    -1,    -1,    -1,
      -1,    -1,    21,    22,     3,     4,     5,    -1,     7,     8,
       9,    10,    11,    12,    13,    -1,    -1,    -1,    17,    18,
       3,     4,     5,    -1,     7,     8,     9,    10,    11,    12,
      13,    -1,    -1,    -1,    17,    18,     3,     4,     5,    -1,
       7,     8,     9,    10,    11,    12,    13,    -1,    -1,    16,
      17,     3,     4,     5,    -1,     7,     8,     9,    10,    11,
      12,    13,    -1,    -1,    16,    17,     3,     4,     5,    -1,
       7,     8,     9,    10,    11,    12,    13,    -1,    -1,    16,
      17,     3,     4,     5,    -1,     7,     8,     9,    10,    11,
      12,    13,    -1,    -1,    16,    17,     3,     4,     5,    -1,
       7,     8,     9,    10,    11,    12,    13,    -1,    -1,    16,
      17,     3,     4,     5,    -1,     7,     8,     9,    10,    11,
      12,    13,    -1,    -1,    16,    17,     3,     4,     5,    -1,
       7,     8,     9,    10,    11,    12,    13,    -1,    -1,    16,
      17,     3,     4,     5,    -1,     7,     8,     9,    10,    11,
      12,    13,    -1,    -1,     5,    17,     7,     8,     9,    10,
      11,    12,    13,    -1,    -1,    -1,    17,     7,     8,     9,
      10,    11,    12,    13,    -1,    -1,    -1,    17,     8,     9,
      10,    11,    12,    13,    -1,    -1,    -1,    17
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     1,    22,    23,    26,    38,    39,    40,    44,    45,
      25,    10,    10,    21,     0,    40,    21,    25,    41,    42,
      43,    48,    49,    25,    35,    15,    17,    24,    25,    24,
       3,     1,    25,    35,    52,    44,    46,    47,    16,    44,
      50,    51,    22,    21,    42,    43,    22,    36,    53,    21,
      36,    47,    21,    16,    24,    18,     1,     6,     8,    10,
      14,    15,    21,    22,    26,    27,    29,    30,    32,    36,
      44,    52,    55,    56,    59,    25,    51,    16,    25,    21,
       1,    22,    59,    21,    59,    59,    15,    17,    34,    21,
      15,    15,    15,    25,    59,    48,    57,    58,    25,     3,
       4,     5,     7,     8,     9,    10,    11,    12,    13,    17,
      25,    16,    16,    59,    60,    59,    21,    21,    59,    59,
       1,    25,    54,    56,    59,    25,     3,    24,    59,    59,
      59,    59,    59,    59,    59,    59,    59,    59,    59,    16,
      24,    18,    25,    16,    16,    25,    25,    59,    25,    59,
      57,    18,    59,    55,    55,    16,    59,    25,    25,    59,
      28,    55,    16,    16,    59,    16,    59,    25,    55,    55,
      55,    16,    55,    16,    16,    59,    55,    55,    55,    16,
      55
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    37,    38,    39,    39,    40,    40,    40,    40,    40,
      40,    41,    41,    42,    42,    43,    43,    44,    44,    44,
      44,    45,    46,    46,    47,    48,    48,    49,    49,    50,
      50,    51,    51,    52,    52,    53,    53,    54,    54,    55,
      55,    55,    55,    55,    55,    55,    55,    55,    55,    55,
      55,    55,    55,    55,    55,    55,    55,    56,    56,    57,
      57,    58,    58,    59,    59,    59,    59,    59,    59,    59,
      59,    59,    59,    59,    59,    59,    59,    59,    59,    59,
      59,    59,    59,    59,    59,    59,    60,    60
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     2,     3,     2,     3,     3,     2,
       2,     1,     3,     1,     3,     1,     3,     1,     1,     2,
       2,     5,     1,     2,     3,     1,     4,     4,     3,     3,
       1,     2,     1,     3,     2,     2,     0,     1,     1,     2,
       2,     4,     1,     3,     2,     5,     7,     5,     6,     7,
       7,     7,     9,     8,     8,     8,     2,     2,     2,     1,
       3,     1,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     2,     2,     2,     4,     3,     4,
       1,     4,     3,     1,     2,     2,     1,     3
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
#line 66 "./lexical/ch.y"
                          { 
        root = new BaseNode("code start!", AST::root);
        root->addChildNode((yyvsp[0].ast));
    }
#line 1654 "./Linux/grammar.tab.cpp"
    break;

  case 3:
#line 71 "./lexical/ch.y"
                                       { 
        (yyval.ast) = (yyvsp[0].ast);
    }
#line 1662 "./Linux/grammar.tab.cpp"
    break;

  case 4:
#line 74 "./lexical/ch.y"
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
#line 1677 "./Linux/grammar.tab.cpp"
    break;

  case 5:
#line 85 "./lexical/ch.y"
                                                              {
        AST::BaseNode* stmt = new AST::StatementNode(AST::defination);
        AST::DefineVarNode* tmp = (AST::DefineVarNode*)(yyvsp[-1].ast);
        tmp->setAllSymbolType((yyvsp[-2].str));
        stmt->addChildNode(tmp);
        (yyval.ast) = stmt;
    }
#line 1689 "./Linux/grammar.tab.cpp"
    break;

  case 6:
#line 92 "./lexical/ch.y"
                    {}
#line 1695 "./Linux/grammar.tab.cpp"
    break;

  case 7:
#line 93 "./lexical/ch.y"
                                                   {
        AST::DefineFuncNode* tmp = (AST::DefineFuncNode*) (yyvsp[-1].ast);
        tmp->addChildNode((yyvsp[0].ast));
        tmp->setReturnSymbolType((yyvsp[-2].str));
        (yyval.ast) = tmp;
    }
#line 1706 "./Linux/grammar.tab.cpp"
    break;

  case 8:
#line 99 "./lexical/ch.y"
                                     {
        AST::DefineFuncNode* tmp = (AST::DefineFuncNode*) (yyvsp[-1].ast);
        tmp->setReturnSymbolType((yyvsp[-2].str));
        (yyval.ast) = tmp;
    }
#line 1716 "./Linux/grammar.tab.cpp"
    break;

  case 9:
#line 104 "./lexical/ch.y"
                           { (yyval.ast) = (yyvsp[-1].ast);}
#line 1722 "./Linux/grammar.tab.cpp"
    break;

  case 10:
#line 105 "./lexical/ch.y"
                { yyerrok; (yyval.ast) = NULL;}
#line 1728 "./Linux/grammar.tab.cpp"
    break;

  case 11:
#line 107 "./lexical/ch.y"
                                                { (yyval.ast) = (yyvsp[0].ast); }
#line 1734 "./Linux/grammar.tab.cpp"
    break;

  case 12:
#line 108 "./lexical/ch.y"
                                                         {
        (yyvsp[-2].ast)->getFinalCousinNode()->addCousinNode((yyvsp[0].ast));
        (yyval.ast) = (yyvsp[-2].ast);
    }
#line 1743 "./Linux/grammar.tab.cpp"
    break;

  case 13:
#line 113 "./lexical/ch.y"
                                     { (yyval.ast) = (yyvsp[0].ast); }
#line 1749 "./Linux/grammar.tab.cpp"
    break;

  case 14:
#line 114 "./lexical/ch.y"
                                               {
        (yyvsp[-2].ast)->getFinalCousinNode()->addCousinNode((yyvsp[0].ast));
        (yyval.ast) = (yyvsp[-2].ast);
    }
#line 1758 "./Linux/grammar.tab.cpp"
    break;

  case 15:
#line 119 "./lexical/ch.y"
                                   { (yyval.ast) = (yyvsp[0].ast); }
#line 1764 "./Linux/grammar.tab.cpp"
    break;

  case 16:
#line 120 "./lexical/ch.y"
                                {
        AST::BaseNode* op = new AST::OperatorNode("=", AST::assign);
        AST::BaseNode* tmp = new AST::LiteralNode((yyvsp[0].str));
        op->addChildNode((yyvsp[-2].ast));
        (yyvsp[-2].ast)->addCousinNode(tmp);
        (yyval.ast) = op;
    }
#line 1776 "./Linux/grammar.tab.cpp"
    break;

  case 17:
#line 131 "./lexical/ch.y"
               { (yyval.str) = strdup("int"); }
#line 1782 "./Linux/grammar.tab.cpp"
    break;

  case 18:
#line 132 "./lexical/ch.y"
           { (yyval.str) = strdup("void"); }
#line 1788 "./Linux/grammar.tab.cpp"
    break;

  case 19:
#line 133 "./lexical/ch.y"
              { (yyval.str) = strdup("int ptr"); }
#line 1794 "./Linux/grammar.tab.cpp"
    break;

  case 20:
#line 134 "./lexical/ch.y"
               { (yyval.str) = strdup("void ptr"); }
#line 1800 "./Linux/grammar.tab.cpp"
    break;

  case 21:
#line 137 "./lexical/ch.y"
                                                            { 
        if(struct_table == NULL){
            struct_table = new SMB::StructTable();
        }
        SMB::StructSymbol* curr_struct = new SMB::StructSymbol((yyvsp[-3].str),(yyvsp[-1].ast));
        struct_table->addStruct(curr_struct);
        (yyval.ast) = NULL;
    }
#line 1813 "./Linux/grammar.tab.cpp"
    break;

  case 22:
#line 147 "./lexical/ch.y"
                                            { (yyval.ast) = (yyvsp[0].ast); }
#line 1819 "./Linux/grammar.tab.cpp"
    break;

  case 23:
#line 148 "./lexical/ch.y"
                                                {
        (yyvsp[-1].ast)->getFinalCousinNode()->addCousinNode((yyvsp[0].ast)); 
        (yyval.ast) = (yyvsp[-1].ast); }
#line 1827 "./Linux/grammar.tab.cpp"
    break;

  case 24:
#line 153 "./lexical/ch.y"
                                     { 
        AST::DefineVarNode* var = new AST::DefineVarNode((yyvsp[-1].str));
        var->setAllSymbolType((yyvsp[-2].str));
        (yyval.ast) = var; }
#line 1836 "./Linux/grammar.tab.cpp"
    break;

  case 25:
#line 160 "./lexical/ch.y"
                      {
        (yyval.ast) = new AST::DefineVarNode((yyvsp[0].str));
    }
#line 1844 "./Linux/grammar.tab.cpp"
    break;

  case 26:
#line 163 "./lexical/ch.y"
                     {
        // std::string s = "array name: ";
        // s = s + $1 + ", length: " + $3;
        AST::DefineVarNode* tmp = new AST::DefineVarNode((yyvsp[-3].str));
        tmp->setAllSymbolType("array");
        tmp->setArrayLength((yyvsp[-1].str));
        (yyval.ast) = tmp;
    }
#line 1857 "./Linux/grammar.tab.cpp"
    break;

  case 27:
#line 172 "./lexical/ch.y"
                                           { 
        (yyval.ast) = new AST::DefineFuncNode((yyvsp[-3].str), (yyvsp[-1].ast));
    }
#line 1865 "./Linux/grammar.tab.cpp"
    break;

  case 28:
#line 175 "./lexical/ch.y"
                 {
        (yyval.ast) = new AST::DefineFuncNode((yyvsp[-2].str));
    }
#line 1873 "./Linux/grammar.tab.cpp"
    break;

  case 29:
#line 179 "./lexical/ch.y"
                                                         {
        (yyvsp[-2].ast)->getFinalCousinNode()->addCousinNode((yyvsp[0].ast));
        (yyval.ast) = (yyvsp[-2].ast);
    }
#line 1882 "./Linux/grammar.tab.cpp"
    break;

  case 30:
#line 183 "./lexical/ch.y"
                            { (yyval.ast) = (yyvsp[0].ast); }
#line 1888 "./Linux/grammar.tab.cpp"
    break;

  case 31:
#line 185 "./lexical/ch.y"
                                    {
        AST::DefineVarNode* tmp = new AST::DefineVarNode((yyvsp[0].str));
        tmp->setAllSymbolType((yyvsp[-1].str));
        (yyval.ast) = tmp;
    }
#line 1898 "./Linux/grammar.tab.cpp"
    break;

  case 32:
#line 190 "./lexical/ch.y"
                {
        AST::DefineVarNode* tmp = new AST::DefineVarNode("");
        tmp->setAllSymbolType((yyvsp[0].str));
        (yyval.ast) = tmp;
    }
#line 1908 "./Linux/grammar.tab.cpp"
    break;

  case 33:
#line 199 "./lexical/ch.y"
                                            {
        BaseNode* temp = new AST::StatementNode(AST::compoundation);
        temp->addChildNode((yyvsp[-1].ast));
        (yyval.ast) = temp;
    }
#line 1918 "./Linux/grammar.tab.cpp"
    break;

  case 34:
#line 204 "./lexical/ch.y"
                { yyerrok; }
#line 1924 "./Linux/grammar.tab.cpp"
    break;

  case 35:
#line 207 "./lexical/ch.y"
                                           {
        if ((yyvsp[-1].ast) == NULL) {
            (yyval.ast) = (yyvsp[0].ast);
        } else {
            (yyvsp[-1].ast)->getFinalCousinNode()->addCousinNode((yyvsp[0].ast));
        }
    }
#line 1936 "./Linux/grammar.tab.cpp"
    break;

  case 36:
#line 214 "./lexical/ch.y"
      { (yyval.ast) = NULL; }
#line 1942 "./Linux/grammar.tab.cpp"
    break;

  case 37:
#line 218 "./lexical/ch.y"
                            { (yyval.ast) = (yyvsp[0].ast); }
#line 1948 "./Linux/grammar.tab.cpp"
    break;

  case 38:
#line 219 "./lexical/ch.y"
                 { (yyval.ast) = (yyvsp[0].ast); }
#line 1954 "./Linux/grammar.tab.cpp"
    break;

  case 39:
#line 222 "./lexical/ch.y"
                          { 
        BaseNode* temp = new AST::StatementNode(AST::expression);
        temp->addChildNode((yyvsp[-1].ast));
        (yyval.ast) = temp;
    }
#line 1964 "./Linux/grammar.tab.cpp"
    break;

  case 40:
#line 227 "./lexical/ch.y"
                     { 
        BaseNode* temp = new AST::StatementNode(AST::defination);
        temp->addChildNode((yyvsp[-1].ast));
        (yyval.ast) = temp;
    }
#line 1974 "./Linux/grammar.tab.cpp"
    break;

  case 41:
#line 232 "./lexical/ch.y"
                       { 
        BaseNode* temp = new AST::StatementNode(AST::defination);
        BaseNode* struct_def = new AST::DefineVarNode((yyvsp[-1].str), (yyvsp[-2].str));
        temp->addChildNode(struct_def);
        (yyval.ast) = temp; }
#line 1984 "./Linux/grammar.tab.cpp"
    break;

  case 42:
#line 237 "./lexical/ch.y"
                         { (yyval.ast)=(yyvsp[0].ast);}
#line 1990 "./Linux/grammar.tab.cpp"
    break;

  case 43:
#line 238 "./lexical/ch.y"
                            {
        BaseNode* temp = new AST::StatementNode(AST::return_stmt);
        temp->addChildNode((yyvsp[-1].ast));
        (yyval.ast) = temp;
    }
#line 2000 "./Linux/grammar.tab.cpp"
    break;

  case 44:
#line 243 "./lexical/ch.y"
                 {
        BaseNode* temp = new AST::StatementNode(AST::return_stmt);
        (yyval.ast) = temp;
    }
#line 2009 "./Linux/grammar.tab.cpp"
    break;

  case 45:
#line 247 "./lexical/ch.y"
                                      {  // ok
        AST::SelectNode* temp = new AST::SelectNode(AST::if_stmt);
        temp->setBodyNode((yyvsp[0].ast));
        // temp->addChildNode($5);
        temp->setCondNode((yyvsp[-2].ast));
        (yyval.ast) = temp;
    }
#line 2021 "./Linux/grammar.tab.cpp"
    break;

  case 46:
#line 254 "./lexical/ch.y"
                                                                          {
        AST::SelectNode* temp = new AST::SelectNode(AST::if_stmt);
        temp->setBodyNode((yyvsp[-2].ast));
        // temp->addChildNode($5);
        temp->setCondNode((yyvsp[-4].ast));
        // AST::SelectNode* else_node = new AST::SelectNode(AST::else_stmt);
        // else_node->addChildNode($7);
        // temp->addCousinNode(else_node);
        temp->setElseNode((yyvsp[0].ast));
        (yyval.ast) = temp;
    }
#line 2037 "./Linux/grammar.tab.cpp"
    break;

  case 47:
#line 265 "./lexical/ch.y"
                                         { //ok
        BaseNode* temp = new AST::LoopNode("", AST::while_loop, (yyvsp[-2].ast));
        temp->addChildNode((yyvsp[0].ast));
        (yyval.ast) = temp;
    }
#line 2047 "./Linux/grammar.tab.cpp"
    break;

  case 48:
#line 271 "./lexical/ch.y"
                                   {
        BaseNode* temp = new AST::LoopNode("", AST::for_loop, NULL, NULL, NULL);
        temp->addChildNode((yyvsp[0].ast));
        (yyval.ast) = temp;
    }
#line 2057 "./Linux/grammar.tab.cpp"
    break;

  case 49:
#line 276 "./lexical/ch.y"
                                                   {
        BaseNode* temp = new AST::LoopNode("", AST::for_loop, NULL, (yyvsp[-4].ast), NULL);
        temp->addChildNode((yyvsp[0].ast));
        (yyval.ast) = temp;
    }
#line 2067 "./Linux/grammar.tab.cpp"
    break;

  case 50:
#line 281 "./lexical/ch.y"
                                              { 
        BaseNode* temp = new AST::LoopNode("", AST::for_loop, (yyvsp[-3].ast), NULL, NULL);
        temp->addChildNode((yyvsp[0].ast));
        (yyval.ast) = temp;
    }
#line 2077 "./Linux/grammar.tab.cpp"
    break;

  case 51:
#line 286 "./lexical/ch.y"
                                              {
        BaseNode* temp = new AST::LoopNode("", AST::for_loop, NULL, NULL, (yyvsp[-2].ast));
        temp->addChildNode((yyvsp[0].ast));
        (yyval.ast) = temp;
    }
#line 2087 "./Linux/grammar.tab.cpp"
    break;

  case 52:
#line 291 "./lexical/ch.y"
                                                                          {
        BaseNode* temp = new AST::LoopNode("", AST::for_loop, (yyvsp[-4].ast), (yyvsp[-6].ast), (yyvsp[-2].ast));
        temp->addChildNode((yyvsp[0].ast));
        (yyval.ast) = temp;
    }
#line 2097 "./Linux/grammar.tab.cpp"
    break;

  case 53:
#line 296 "./lexical/ch.y"
                                                                { //OK
        BaseNode* temp = new AST::LoopNode("", AST::for_loop, (yyvsp[-3].ast), (yyvsp[-5].ast), NULL);
        temp->addChildNode((yyvsp[0].ast));
        (yyval.ast) = temp;
    }
#line 2107 "./Linux/grammar.tab.cpp"
    break;

  case 54:
#line 301 "./lexical/ch.y"
                                                                { //OK
        BaseNode* temp = new AST::LoopNode("", AST::for_loop, NULL, (yyvsp[-5].ast), (yyvsp[-2].ast));
        temp->addChildNode((yyvsp[0].ast));
        (yyval.ast) = temp;
    }
#line 2117 "./Linux/grammar.tab.cpp"
    break;

  case 55:
#line 306 "./lexical/ch.y"
                                                          { //OK
        BaseNode* temp = new AST::LoopNode("", AST::for_loop, (yyvsp[-4].ast), NULL, (yyvsp[-2].ast));
        temp->addChildNode((yyvsp[0].ast));
        (yyval.ast) = temp;
    }
#line 2127 "./Linux/grammar.tab.cpp"
    break;

  case 56:
#line 311 "./lexical/ch.y"
                { yyerrok; }
#line 2133 "./Linux/grammar.tab.cpp"
    break;

  case 57:
#line 316 "./lexical/ch.y"
                                        {
        if ((yyvsp[0].ast)->getASTNodeType() == AST::op) {
            AST::OperatorNode* tmp = (AST::OperatorNode*)(yyvsp[0].ast);
            tmp->setAllSymbolType((yyvsp[-1].str));
        } else {
            AST::DefineVarNode* tmp = (AST::DefineVarNode*)(yyvsp[0].ast);
            tmp->setAllSymbolType((yyvsp[-1].str));
        }
        (yyval.ast) = (yyvsp[0].ast);
    }
#line 2148 "./Linux/grammar.tab.cpp"
    break;

  case 58:
#line 326 "./lexical/ch.y"
                { yyerrok; }
#line 2154 "./Linux/grammar.tab.cpp"
    break;

  case 59:
#line 329 "./lexical/ch.y"
                              { (yyval.ast) = (yyvsp[0].ast); }
#line 2160 "./Linux/grammar.tab.cpp"
    break;

  case 60:
#line 330 "./lexical/ch.y"
                                       {
        (yyvsp[-2].ast)->getFinalCousinNode()->addCousinNode((yyvsp[0].ast));
        (yyval.ast) = (yyvsp[-2].ast);
    }
#line 2169 "./Linux/grammar.tab.cpp"
    break;

  case 61:
#line 336 "./lexical/ch.y"
                               { (yyval.ast) = (yyvsp[0].ast); }
#line 2175 "./Linux/grammar.tab.cpp"
    break;

  case 62:
#line 337 "./lexical/ch.y"
                                       {
        (yyval.ast) = new AST::OperatorNode("=", AST::assign);
        (yyval.ast)->addChildNode((yyvsp[-2].ast));
        (yyvsp[-2].ast)->addCousinNode((yyvsp[0].ast));
    }
#line 2185 "./Linux/grammar.tab.cpp"
    break;

  case 63:
#line 346 "./lexical/ch.y"
                                      {
            AST::OperatorNode* temp = new AST::OperatorNode("=", AST::assign);
            if ((yyvsp[-2].ast)->getASTNodeType() == AST::op) {
                AST::OperatorNode *tmp = (AST::OperatorNode *)(yyvsp[-2].ast);
                if (tmp->getOpType() == AST::get_member) {
                    temp->setOpType(AST::assign_member);
                } else if (tmp->getOpType() == AST::get_arr_var) {
                    temp->setOpType(AST::assign_arr);
                }
            }
            temp->addChildNode((yyvsp[-2].ast));
            (yyvsp[-2].ast)->addCousinNode((yyvsp[0].ast));
            (yyval.ast) = temp;
        }
#line 2204 "./Linux/grammar.tab.cpp"
    break;

  case 64:
#line 360 "./lexical/ch.y"
                                    {
            BaseNode* temp = new AST::OperatorNode("&&", AST::and_op);
            temp->addChildNode((yyvsp[-2].ast));
            (yyvsp[-2].ast)->addCousinNode((yyvsp[0].ast));
            (yyval.ast) = temp;
        }
#line 2215 "./Linux/grammar.tab.cpp"
    break;

  case 65:
#line 366 "./lexical/ch.y"
                                   {
            BaseNode* temp = new AST::OperatorNode("||", AST::or_op);
            temp->addChildNode((yyvsp[-2].ast));
            (yyvsp[-2].ast)->addCousinNode((yyvsp[0].ast));
            (yyval.ast) = temp;
        }
#line 2226 "./Linux/grammar.tab.cpp"
    break;

  case 66:
#line 372 "./lexical/ch.y"
                                      {
            BaseNode* temp = new AST::OperatorNode((yyvsp[-1].str), AST::relop);
            temp->addChildNode((yyvsp[-2].ast));
            (yyvsp[-2].ast)->addCousinNode((yyvsp[0].ast));
            (yyval.ast) = temp;
        }
#line 2237 "./Linux/grammar.tab.cpp"
    break;

  case 67:
#line 378 "./lexical/ch.y"
                                    {
            BaseNode* temp = new AST::OperatorNode("+", AST::add);
            temp->addChildNode((yyvsp[-2].ast));
            (yyvsp[-2].ast)->addCousinNode((yyvsp[0].ast));
            (yyval.ast) = temp;
        }
#line 2248 "./Linux/grammar.tab.cpp"
    break;

  case 68:
#line 384 "./lexical/ch.y"
                                    {
            BaseNode* temp = new AST::OperatorNode("-", AST::minus);
            temp->addChildNode((yyvsp[-2].ast));
            (yyvsp[-2].ast)->addCousinNode((yyvsp[0].ast));
            (yyval.ast) = temp;
        }
#line 2259 "./Linux/grammar.tab.cpp"
    break;

  case 69:
#line 390 "./lexical/ch.y"
                                    {
            BaseNode* temp = new AST::OperatorNode("*", AST::multi);
            temp->addChildNode((yyvsp[-2].ast));
            (yyvsp[-2].ast)->addCousinNode((yyvsp[0].ast));
            (yyval.ast) = temp;
        }
#line 2270 "./Linux/grammar.tab.cpp"
    break;

  case 70:
#line 396 "./lexical/ch.y"
                                    {
            BaseNode* temp = new AST::OperatorNode("/", AST::div);
            temp->addChildNode((yyvsp[-2].ast));
            (yyvsp[-2].ast)->addCousinNode((yyvsp[0].ast));
            (yyval.ast) = temp;
        }
#line 2281 "./Linux/grammar.tab.cpp"
    break;

  case 71:
#line 402 "./lexical/ch.y"
                                    {
            BaseNode* temp = new AST::OperatorNode("%", AST::mod);
            temp->addChildNode((yyvsp[-2].ast));
            (yyvsp[-2].ast)->addCousinNode((yyvsp[0].ast));
            (yyval.ast) = temp;
        }
#line 2292 "./Linux/grammar.tab.cpp"
    break;

  case 72:
#line 408 "./lexical/ch.y"
                                    {
            BaseNode* temp = new AST::OperatorNode("^", AST::pow);
            temp->addChildNode((yyvsp[-2].ast));
            (yyvsp[-2].ast)->addCousinNode((yyvsp[0].ast));
            (yyval.ast) = temp;
        }
#line 2303 "./Linux/grammar.tab.cpp"
    break;

  case 73:
#line 414 "./lexical/ch.y"
                             {
            (yyval.ast) = (yyvsp[-1].ast);
        }
#line 2311 "./Linux/grammar.tab.cpp"
    break;

  case 74:
#line 417 "./lexical/ch.y"
                         {
            BaseNode* temp = new AST::OperatorNode("-", AST::negative);
            temp->addChildNode((yyvsp[0].ast));
            (yyval.ast) = temp;
        }
#line 2321 "./Linux/grammar.tab.cpp"
    break;

  case 75:
#line 422 "./lexical/ch.y"
                         {
            BaseNode* temp = new AST::OperatorNode("!", AST::not_op);
            temp->addChildNode((yyvsp[0].ast));
            (yyval.ast) = temp;
        }
#line 2331 "./Linux/grammar.tab.cpp"
    break;

  case 76:
#line 427 "./lexical/ch.y"
                 {
            BaseNode* op = new AST::OperatorNode("&", AST::get_address);
            BaseNode* temp = new AST::AssignVarNode((yyvsp[0].str));
            (yyval.ast) = op;
            op->addChildNode(temp);
        }
#line 2342 "./Linux/grammar.tab.cpp"
    break;

  case 77:
#line 433 "./lexical/ch.y"
                                              {
            AST::CallFuncNode* temp = new AST::CallFuncNode((yyvsp[-3].str));
            temp->setVarList((yyvsp[-1].ast));
            (yyval.ast) = temp;
        }
#line 2352 "./Linux/grammar.tab.cpp"
    break;

  case 78:
#line 438 "./lexical/ch.y"
                     {
            (yyval.ast) = new AST::CallFuncNode((yyvsp[-2].str));
        }
#line 2360 "./Linux/grammar.tab.cpp"
    break;

  case 79:
#line 441 "./lexical/ch.y"
                                        {
            (yyval.ast) = NULL;
        }
#line 2368 "./Linux/grammar.tab.cpp"
    break;

  case 80:
#line 444 "./lexical/ch.y"
             {
            (yyval.ast) = new AST::AssignVarNode((yyvsp[0].str));
        }
#line 2376 "./Linux/grammar.tab.cpp"
    break;

  case 81:
#line 447 "./lexical/ch.y"
                                {
            BaseNode* op = new AST::OperatorNode("[]", AST::get_arr_var);
            BaseNode* temp = new AST::AssignVarNode((yyvsp[-3].str));
            (yyval.ast) = op;
            op->addChildNode(temp);
            temp->addCousinNode((yyvsp[-1].ast));
        }
#line 2388 "./Linux/grammar.tab.cpp"
    break;

  case 82:
#line 454 "./lexical/ch.y"
                          {
            BaseNode* op = new AST::OperatorNode(".", AST::get_member);
            AST::AssignVarNode * var1 = new AST::AssignVarNode((yyvsp[-2].str));
            AST::AssignVarNode * var2 = new AST::AssignVarNode((yyvsp[0].str));
            op->addChildNode(var1);
            var1->addCousinNode(var2);
            (yyval.ast) = op;
        }
#line 2401 "./Linux/grammar.tab.cpp"
    break;

  case 83:
#line 462 "./lexical/ch.y"
              {
            (yyval.ast) = new AST::LiteralNode((yyvsp[0].str));
        }
#line 2409 "./Linux/grammar.tab.cpp"
    break;

  case 84:
#line 465 "./lexical/ch.y"
                 {
            AST::OperatorNode *star = new AST::OperatorNode("*", AST::get_var);
            AST::AssignVarNode *var = new AST::AssignVarNode((yyvsp[0].str));
            (yyval.ast) = star;
            star->addChildNode(var);
        }
#line 2420 "./Linux/grammar.tab.cpp"
    break;

  case 85:
#line 471 "./lexical/ch.y"
                    {yyerrok;}
#line 2426 "./Linux/grammar.tab.cpp"
    break;

  case 86:
#line 473 "./lexical/ch.y"
                                     {
            (yyval.ast) = (yyvsp[0].ast);
        }
#line 2434 "./Linux/grammar.tab.cpp"
    break;

  case 87:
#line 476 "./lexical/ch.y"
                                                  {
            (yyvsp[-2].ast)->getFinalCousinNode()->addCousinNode((yyvsp[0].ast));
            (yyval.ast) = (yyvsp[-2].ast);
        }
#line 2443 "./Linux/grammar.tab.cpp"
    break;


#line 2447 "./Linux/grammar.tab.cpp"

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
#line 481 "./lexical/ch.y"



void yyerror(const char* s) {
	fprintf(stderr, "Parse error: At line %d. %s\n", yylineno, s);
	exit(1);
}
std::string replaceExtName(char* filename) {
    int dotIndex = 0;
    int nameLength = strlen(filename);
    for (int i = nameLength - 1; i >= 0; i--) {
        if (filename[i] == '.') {
            dotIndex = i;
            break;
        }
    }
    char* buf = new char[dotIndex];
    strncpy(buf, filename, dotIndex);
    std::string rev(buf);
    rev += ".asm";
    return rev;
}
int main(int argc,char * argv[]){  //不确定语法的在哪里输出

    int c,j=0;
    char * filename =NULL;
    filename=argv[1];
    std::cout<<"filename"<<filename<<std::endl;
    yyin=fopen(filename,"r");
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
    // SMB::SymbolTable* root_symbol_table = new SMB::SymbolTable(NULL,false);
    // SMB::tree(root_symbol_table,root,0);
    IM::InterMediate *im = new IM::InterMediate(root, struct_table);
    im->generate(root, im->getTable());
    im->print();
    //add ASM
    ASM::AsmGenerator* asmgenerator = new ASM::AsmGenerator(im->getQuads(), im->getTempVars(), im->getTable());
    asmgenerator->generate();
    // if (flag_print_asm) {
    std::cout << asmgenerator->getAsmCode();
    // }

    std::string outfilename = replaceExtName(filename);
    std::ofstream outasm(outfilename);

    outasm << asmgenerator->getAsmCode();

    if(root) delete root;
    return 0;
}
