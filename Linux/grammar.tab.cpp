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
#include "../grammar/ASTtree/BaseNode.h"

class BaseNode;
extern char *yytext;
extern int yylex();
extern FILE * yyin;
void yyerror(const char* s);
BaseNode* root;
extern int yylineno;

#line 86 "./Linux/grammar.tab.cpp"

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
# define YYERROR_VERBOSE 0
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
    ERRID = 261,
    ID = 262,
    INT = 263,
    VOID = 264,
    STRUCT = 265,
    IF = 266,
    ELSE = 267,
    WHILE = 268,
    FOR = 269,
    CONTINUE = 270,
    RETURN = 271,
    ERRORCHAR = 272,
    GETMEMBER = 273,
    UMINUS = 274
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 18 "./lexical/ch.y"

    /*maybe a tree strurt ?*/
    BaseNode* ast;
    double dval;
    // struct symtab *symp;
    char* str;

#line 166 "./Linux/grammar.tab.cpp"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

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
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
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
#define YYFINAL  15
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   524

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  37
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  22
/* YYNRULES -- Number of rules.  */
#define YYNRULES  84
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  175

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
      14,    15,     9,     8,    22,     7,    36,    10,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    23,
       2,     3,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    16,     2,    17,    12,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    33,     2,    34,     2,     2,     2,     2,
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
       6,    18,    19,    20,    21,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    35
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    60,    60,    65,    68,    79,    80,    81,    85,    88,
      89,    91,    92,   100,   101,   102,   103,   106,   107,   108,
     111,   112,   115,   119,   124,   130,   135,   141,   145,   147,
     152,   157,   162,   163,   166,   173,   179,   180,   183,   188,
     193,   194,   195,   201,   210,   217,   223,   229,   236,   244,
     251,   258,   265,   270,   274,   279,   282,   285,   286,   292,
     293,   301,   308,   314,   320,   328,   334,   340,   346,   352,
     358,   364,   367,   372,   377,   384,   389,   392,   395,   404,
     405,   410,   411,   413,   416
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "'='", "OR", "AND", "RELOP", "'-'",
  "'+'", "'*'", "'/'", "'%'", "'^'", "'!'", "'('", "')'", "'['", "']'",
  "ERRID", "ID", "INT", "VOID", "','", "';'", "STRUCT", "IF", "ELSE",
  "WHILE", "FOR", "CONTINUE", "RETURN", "ERRORCHAR", "GETMEMBER", "'{'",
  "'}'", "UMINUS", "'.'", "$accept", "program", "translation_unit",
  "external_declaration", "external_declaration_list", "specifier",
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
       0,   256,   257,    61,   258,   259,   260,    45,    43,    42,
      47,    37,    94,    33,    40,    41,    91,    93,   261,   262,
     263,   264,    44,    59,   265,   266,   267,   268,   269,   270,
     271,   272,   273,   123,   125,   274,    46
};
# endif

#define YYPACT_NINF (-58)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-57)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      14,    -9,    13,    27,   -13,    53,     4,   -58,    -6,    33,
     -58,   -58,   -58,    34,   108,   -58,   -58,    36,   -58,   150,
     -58,     0,   -58,   108,    56,    70,   -58,   102,    52,    66,
     -58,    59,   -58,    69,   -58,    93,    64,   -58,   108,   -58,
      77,    40,   -58,    83,    89,   -58,   -58,   -58,   111,   -58,
     -58,   -58,   -58,   108,   -58,    61,   329,    96,   329,   329,
      -7,    -1,   100,    94,   107,   112,   155,   -58,    66,   -58,
     -58,   110,   206,   -58,   -58,   114,   128,   -58,   139,   -58,
     143,   377,   281,   329,   146,   148,   329,   329,    50,   -58,
     227,   167,   -58,   154,   -58,   329,   329,   329,   329,   329,
     329,   329,   329,   329,   329,   329,   -58,   -58,   -58,   475,
      43,   347,   -58,   157,   391,   405,    -4,   170,   158,   -58,
     475,   -58,   329,    66,   475,   487,   498,   508,   139,   139,
      62,    62,    62,   143,   362,   -58,   329,   -58,   -58,   133,
     133,   -58,   290,   248,   185,   475,   -58,   -58,   475,   156,
     -58,   133,   419,   305,   329,   269,   133,   -58,   133,   133,
     433,   447,   314,   -58,   -58,   -58,   133,   133,   133,   461,
     -58,   -58,   -58,   133,   -58
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,    13,    14,     0,     0,     0,     3,     0,     0,
      10,    15,    16,    19,     0,     1,     4,    23,     6,     0,
      11,     0,     9,     0,     0,     0,    20,     0,     0,     0,
       5,     0,     8,    35,     7,     0,     0,    18,    21,    26,
      30,     0,    28,     0,    23,    12,    33,    32,     0,    17,
      22,    29,    25,     0,    24,     0,     0,     0,     0,     0,
      77,    80,     0,     0,     0,     0,     0,    31,     0,    41,
      34,     0,     0,    27,    82,    54,     0,    80,    72,    81,
      73,     0,     0,     0,     0,     0,     0,     0,     0,    53,
       0,    59,    55,    57,    39,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    38,    71,    75,    83,
       0,     0,    79,     0,     0,     0,     0,     0,     0,    36,
      37,    52,     0,     0,    61,    63,    62,    64,    66,    65,
      67,    68,    69,    70,     0,    74,     0,    78,    40,     0,
       0,    56,     0,     0,     0,    60,    58,    76,    84,    42,
      44,     0,     0,     0,     0,     0,     0,    45,     0,     0,
       0,     0,     0,    43,    47,    46,     0,     0,     0,     0,
      51,    50,    49,     0,    48
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -58,   -58,   -58,   179,   -58,    54,   -58,    -2,   -58,     8,
     -58,   -58,   134,   174,   -58,   -58,   -57,   103,    65,   -58,
     -56,   -58
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     5,     6,     7,    19,    68,     9,    38,    26,    91,
      21,    41,    42,    69,    48,   118,    70,    71,    92,    93,
      72,   110
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      78,    31,    80,    81,    -2,     1,    13,    82,    11,    83,
      90,    74,    25,    17,    10,     1,    20,    18,   -13,   141,
      14,    35,    11,    32,     2,     3,   109,   111,     4,    84,
     114,   115,   120,    33,     2,     3,    12,    45,     4,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
      27,   116,    28,    15,     8,    52,    22,    56,   135,    57,
       8,   143,    53,    58,    59,   136,   145,    23,    24,    60,
      61,     3,    43,   117,   104,    36,    74,    24,   105,    24,
     148,    40,   149,   150,    75,    44,   152,    50,   155,    24,
       2,     3,    24,    46,   157,    46,    51,   160,   161,   163,
      54,   164,   165,    47,    37,    28,   169,    40,    86,   170,
     171,   172,    55,     2,     3,    79,   174,    39,    56,    85,
      57,    87,     2,     3,    58,    59,    88,    49,     2,     3,
      60,    61,     3,    94,    55,    62,    63,   -56,    64,    65,
      56,    66,    57,    74,    33,    67,    58,    59,   101,   102,
     103,   104,    60,    61,     3,   105,    76,    62,    63,   105,
      64,    65,    56,    66,    57,   112,    33,   113,    58,    59,
     122,    76,    29,    30,    60,    77,   123,    56,    89,    57,
     138,   144,   156,    58,    59,    16,    76,    73,   146,    60,
      77,   119,    56,   142,    57,    34,     0,     0,    58,    59,
       0,     0,     0,     0,    60,    77,     0,     0,   154,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,     0,
       0,     0,   105,     0,     0,     0,     0,     0,     0,   106,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
       0,     0,     0,   105,     0,     0,     0,     0,     0,     0,
     121,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,     0,     0,     0,   105,     0,     0,     0,     0,     0,
       0,   153,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,    76,     0,     0,   105,     0,     0,    56,     0,
      57,    76,   162,     0,    58,    59,   108,    56,     0,    57,
      60,    77,     0,    58,    59,   151,    76,     0,     0,    60,
      77,     0,    56,     0,    57,    76,     0,     0,    58,    59,
     159,    56,     0,    57,    60,    77,     0,    58,    59,   168,
      76,     0,     0,    60,    77,     0,    56,     0,    57,     0,
       0,     0,    58,    59,     0,     0,     0,     0,    60,    77,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
       0,     0,     0,   105,   137,    95,    96,    97,    98,    99,
     100,   101,   102,   103,   104,     0,     0,     0,   105,   147,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
       0,     0,   107,   105,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,     0,     0,   139,   105,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,     0,     0,
     140,   105,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,     0,     0,   158,   105,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,     0,     0,   166,   105,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
       0,     0,   167,   105,    95,    96,    97,    98,    99,   100,
     101,   102,   103,   104,     0,     0,   173,   105,    95,    96,
      97,    98,    99,   100,   101,   102,   103,   104,     0,     0,
       0,   105,    97,    98,    99,   100,   101,   102,   103,   104,
       0,     0,     0,   105,    98,    99,   100,   101,   102,   103,
     104,     0,     0,     0,   105,    99,   100,   101,   102,   103,
     104,     0,     0,     0,   105
};

static const yytype_int16 yycheck[] =
{
      56,     1,    58,    59,     0,     1,    19,    14,     9,    16,
      66,    15,    14,    19,    23,     1,     8,    23,    19,    23,
      33,    23,     9,    23,    20,    21,    82,    83,    24,    36,
      86,    87,    88,    33,    20,    21,     9,    29,    24,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
      14,     1,    16,     0,     0,    15,    23,     7,    15,     9,
       6,   117,    22,    13,    14,    22,   122,    33,    14,    19,
      20,    21,    20,    23,    12,    19,    15,    23,    16,    25,
     136,    27,   139,   140,    23,    19,   142,    23,   144,    35,
      20,    21,    38,    34,   151,    34,    19,   153,   154,   156,
      17,   158,   159,    34,    34,    16,   162,    53,    14,   166,
     167,   168,     1,    20,    21,    19,   173,    15,     7,    19,
       9,    14,    20,    21,    13,    14,    14,    34,    20,    21,
      19,    20,    21,    23,     1,    24,    25,    23,    27,    28,
       7,    30,     9,    15,    33,    34,    13,    14,     9,    10,
      11,    12,    19,    20,    21,    16,     1,    24,    25,    16,
      27,    28,     7,    30,     9,    19,    33,    19,    13,    14,
       3,     1,    22,    23,    19,    20,    22,     7,    23,     9,
      23,    23,    26,    13,    14,     6,     1,    53,   123,    19,
      20,    88,     7,    23,     9,    21,    -1,    -1,    13,    14,
      -1,    -1,    -1,    -1,    19,    20,    -1,    -1,    23,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    -1,
      -1,    -1,    16,    -1,    -1,    -1,    -1,    -1,    -1,    23,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      -1,    -1,    -1,    16,    -1,    -1,    -1,    -1,    -1,    -1,
      23,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    -1,    -1,    -1,    16,    -1,    -1,    -1,    -1,    -1,
      -1,    23,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,     1,    -1,    -1,    16,    -1,    -1,     7,    -1,
       9,     1,    23,    -1,    13,    14,    15,     7,    -1,     9,
      19,    20,    -1,    13,    14,    15,     1,    -1,    -1,    19,
      20,    -1,     7,    -1,     9,     1,    -1,    -1,    13,    14,
      15,     7,    -1,     9,    19,    20,    -1,    13,    14,    15,
       1,    -1,    -1,    19,    20,    -1,     7,    -1,     9,    -1,
      -1,    -1,    13,    14,    -1,    -1,    -1,    -1,    19,    20,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      -1,    -1,    -1,    16,    17,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    -1,    -1,    -1,    16,    17,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      -1,    -1,    15,    16,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    -1,    -1,    15,    16,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    -1,    -1,
      15,    16,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    -1,    -1,    15,    16,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    -1,    -1,    15,    16,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      -1,    -1,    15,    16,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    -1,    -1,    15,    16,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    -1,    -1,
      -1,    16,     5,     6,     7,     8,     9,    10,    11,    12,
      -1,    -1,    -1,    16,     6,     7,     8,     9,    10,    11,
      12,    -1,    -1,    -1,    16,     7,     8,     9,    10,    11,
      12,    -1,    -1,    -1,    16
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     1,    20,    21,    24,    38,    39,    40,    42,    43,
      23,     9,     9,    19,    33,     0,    40,    19,    23,    41,
      46,    47,    23,    33,    42,    44,    45,    14,    16,    22,
      23,     1,    23,    33,    50,    44,    19,    34,    44,    15,
      42,    48,    49,    20,    19,    46,    34,    34,    51,    34,
      23,    19,    15,    22,    17,     1,     7,     9,    13,    14,
      19,    20,    24,    25,    27,    28,    30,    34,    42,    50,
      53,    54,    57,    49,    15,    23,     1,    20,    57,    19,
      57,    57,    14,    16,    36,    19,    14,    14,    14,    23,
      57,    46,    55,    56,    23,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    16,    23,    15,    15,    57,
      58,    57,    19,    19,    57,    57,     1,    23,    52,    54,
      57,    23,     3,    22,    57,    57,    57,    57,    57,    57,
      57,    57,    57,    57,    57,    15,    22,    17,    23,    15,
      15,    23,    23,    57,    23,    57,    55,    17,    57,    53,
      53,    15,    57,    23,    23,    57,    26,    53,    15,    15,
      57,    57,    23,    53,    53,    53,    15,    15,    15,    57,
      53,    53,    53,    15,    53
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    37,    38,    39,    39,    40,    40,    40,    40,    40,
      40,    41,    41,    42,    42,    42,    42,    43,    43,    43,
      44,    44,    45,    46,    46,    47,    47,    48,    48,    49,
      49,    50,    50,    50,    51,    51,    52,    52,    53,    53,
      53,    53,    53,    53,    53,    53,    53,    53,    53,    53,
      53,    53,    53,    53,    53,    54,    54,    55,    55,    56,
      56,    57,    57,    57,    57,    57,    57,    57,    57,    57,
      57,    57,    57,    57,    57,    57,    57,    57,    57,    57,
      57,    57,    57,    58,    58
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     2,     3,     2,     3,     3,     2,
       2,     1,     3,     1,     1,     2,     2,     5,     4,     2,
       1,     2,     3,     1,     4,     4,     3,     3,     1,     2,
       1,     3,     2,     2,     2,     0,     1,     1,     2,     2,
       4,     1,     5,     7,     5,     6,     7,     7,     9,     8,
       8,     8,     3,     2,     2,     2,     2,     1,     3,     1,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     2,     2,     4,     3,     4,     1,     4,     3,
       1,     2,     2,     1,     3
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


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
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
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
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
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

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

    YYPTRDIFF_T yystacksize;

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
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
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

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
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
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

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


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2:
#line 60 "./lexical/ch.y"
                          { 
        root = new BaseNode(root_);
        root->addChildNode((yyvsp[0].ast));
    }
#line 1528 "./Linux/grammar.tab.cpp"
    break;

  case 3:
#line 65 "./lexical/ch.y"
                                       { 
        (yyval.ast) = (yyvsp[0].ast);
    }
#line 1536 "./Linux/grammar.tab.cpp"
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
#line 1551 "./Linux/grammar.tab.cpp"
    break;

  case 5:
#line 79 "./lexical/ch.y"
                                                              {}
#line 1557 "./Linux/grammar.tab.cpp"
    break;

  case 6:
#line 80 "./lexical/ch.y"
                    {}
#line 1563 "./Linux/grammar.tab.cpp"
    break;

  case 7:
#line 81 "./lexical/ch.y"
                                                   {
        (yyvsp[-1].ast)->addChildNode((yyvsp[0].ast));
        (yyval.ast) = (yyvsp[-1].ast);
    }
#line 1572 "./Linux/grammar.tab.cpp"
    break;

  case 8:
#line 85 "./lexical/ch.y"
                                     {
        (yyval.ast) = (yyvsp[-1].ast);
    }
#line 1580 "./Linux/grammar.tab.cpp"
    break;

  case 9:
#line 88 "./lexical/ch.y"
                           {}
#line 1586 "./Linux/grammar.tab.cpp"
    break;

  case 10:
#line 89 "./lexical/ch.y"
                { yyerrok; (yyval.ast) = NULL;}
#line 1592 "./Linux/grammar.tab.cpp"
    break;

  case 11:
#line 91 "./lexical/ch.y"
                                             { (yyval.ast) = (yyvsp[0].ast); }
#line 1598 "./Linux/grammar.tab.cpp"
    break;

  case 12:
#line 92 "./lexical/ch.y"
                                                      {
        (yyvsp[-2].ast)->getFinalCousinNode()->addCousinNode((yyvsp[0].ast));
        (yyval.ast) = (yyvsp[-2].ast);
    }
#line 1607 "./Linux/grammar.tab.cpp"
    break;

  case 13:
#line 100 "./lexical/ch.y"
               { (yyval.str) = (char*)("int"); }
#line 1613 "./Linux/grammar.tab.cpp"
    break;

  case 14:
#line 101 "./lexical/ch.y"
           { (yyval.str) = (char*)("void"); }
#line 1619 "./Linux/grammar.tab.cpp"
    break;

  case 15:
#line 102 "./lexical/ch.y"
              { (yyval.str) = (char*)("int ptr"); }
#line 1625 "./Linux/grammar.tab.cpp"
    break;

  case 16:
#line 103 "./lexical/ch.y"
               { (yyval.str) = (char*)("void ptr"); }
#line 1631 "./Linux/grammar.tab.cpp"
    break;

  case 17:
#line 106 "./lexical/ch.y"
                                                            { (yyval.ast) = NULL; }
#line 1637 "./Linux/grammar.tab.cpp"
    break;

  case 18:
#line 107 "./lexical/ch.y"
                                             { (yyval.ast) = NULL; }
#line 1643 "./Linux/grammar.tab.cpp"
    break;

  case 19:
#line 108 "./lexical/ch.y"
                { (yyval.ast) = NULL; }
#line 1649 "./Linux/grammar.tab.cpp"
    break;

  case 20:
#line 111 "./lexical/ch.y"
                                            { (yyval.ast) = NULL; }
#line 1655 "./Linux/grammar.tab.cpp"
    break;

  case 21:
#line 112 "./lexical/ch.y"
                                                      { (yyval.ast) = NULL; }
#line 1661 "./Linux/grammar.tab.cpp"
    break;

  case 22:
#line 115 "./lexical/ch.y"
                                     { (yyval.ast) = NULL; }
#line 1667 "./Linux/grammar.tab.cpp"
    break;

  case 23:
#line 119 "./lexical/ch.y"
                      {
        char* s = "";
        sprintf(s, "variable defination, name: %s", (yyvsp[0].str));
        (yyval.ast) = new BaseNode(s, dec_var);
    }
#line 1677 "./Linux/grammar.tab.cpp"
    break;

  case 24:
#line 124 "./lexical/ch.y"
                     {
        char* s = "";
        sprintf(s, "variable defination (array), name: %s", (yyvsp[-3].str));
        (yyval.ast) = new BaseNode(s, dec_var);
    }
#line 1687 "./Linux/grammar.tab.cpp"
    break;

  case 25:
#line 130 "./lexical/ch.y"
                                           { 
        char* s = "";
        sprintf(s, "func defination, name: %s", (yyvsp[-3].str));
        (yyval.ast) = new BaseNode(s, dec_func);
    }
#line 1697 "./Linux/grammar.tab.cpp"
    break;

  case 26:
#line 135 "./lexical/ch.y"
                 {
        char* s = "";
        sprintf(s, "func defination, name: %s", (yyvsp[-2].str));
        (yyval.ast) = new BaseNode(s, dec_func);
    }
#line 1707 "./Linux/grammar.tab.cpp"
    break;

  case 27:
#line 141 "./lexical/ch.y"
                                                         {
        (yyvsp[-2].ast)->getFinalCousinNode()->addCousinNode((yyvsp[0].ast));
        (yyval.ast) = (yyvsp[-2].ast);
    }
#line 1716 "./Linux/grammar.tab.cpp"
    break;

  case 28:
#line 145 "./lexical/ch.y"
                            { (yyval.ast) = (yyvsp[0].ast) }
#line 1722 "./Linux/grammar.tab.cpp"
    break;

  case 29:
#line 147 "./lexical/ch.y"
                                    {
        char* s = "";
        sprintf(s, "variable defination, name: %s", (yyvsp[-1].str));
        (yyval.ast) = new BaseNode(s, dec_var);
    }
#line 1732 "./Linux/grammar.tab.cpp"
    break;

  case 30:
#line 152 "./lexical/ch.y"
                {}
#line 1738 "./Linux/grammar.tab.cpp"
    break;

  case 31:
#line 157 "./lexical/ch.y"
                                            {
        BaseNode* temp = new BaseNode("compound statement");
        temp->addChildNode((yyvsp[-1].ast));
        (yyval.ast) = temp;
    }
#line 1748 "./Linux/grammar.tab.cpp"
    break;

  case 32:
#line 162 "./lexical/ch.y"
              {}
#line 1754 "./Linux/grammar.tab.cpp"
    break;

  case 33:
#line 163 "./lexical/ch.y"
                { yyerrok; }
#line 1760 "./Linux/grammar.tab.cpp"
    break;

  case 34:
#line 166 "./lexical/ch.y"
                                           {
        if ((yyvsp[-1].ast) == NULL) {
            (yyval.ast) = (yyvsp[0].ast);
        } else {
            (yyvsp[-1].ast)->getFinalCousinNode()->addCousinNode((yyvsp[0].ast));
        }
    }
#line 1772 "./Linux/grammar.tab.cpp"
    break;

  case 35:
#line 173 "./lexical/ch.y"
      {
        (yyval.ast) = NULL;
    }
#line 1780 "./Linux/grammar.tab.cpp"
    break;

  case 36:
#line 179 "./lexical/ch.y"
                            { (yyval.ast) = (yyvsp[0].ast); }
#line 1786 "./Linux/grammar.tab.cpp"
    break;

  case 37:
#line 180 "./lexical/ch.y"
                 { (yyval.ast) = (yyvsp[0].ast); }
#line 1792 "./Linux/grammar.tab.cpp"
    break;

  case 38:
#line 183 "./lexical/ch.y"
                          { 
        BaseNode* temp = new BaseNode("expression statement");
        temp->addChildNode((yyvsp[-1].ast));
        (yyval.ast) = temp;
    }
#line 1802 "./Linux/grammar.tab.cpp"
    break;

  case 39:
#line 188 "./lexical/ch.y"
                     { 
        BaseNode* temp = new BaseNode("defination statement");
        temp->addChildNode((yyvsp[-1].ast));
        (yyval.ast) = temp;
    }
#line 1812 "./Linux/grammar.tab.cpp"
    break;

  case 40:
#line 193 "./lexical/ch.y"
                       {}
#line 1818 "./Linux/grammar.tab.cpp"
    break;

  case 41:
#line 194 "./lexical/ch.y"
                         { (yyval.ast)=(yyvsp[0].ast);}
#line 1824 "./Linux/grammar.tab.cpp"
    break;

  case 42:
#line 195 "./lexical/ch.y"
                                      { 
        BaseNode* temp = new BaseNode("select statement(if)");
        temp->addChildNode((yyvsp[-2].ast));
        (yyvsp[-2].ast)->addCousinNode((yyvsp[0].ast));
        (yyval.ast) = temp;
    }
#line 1835 "./Linux/grammar.tab.cpp"
    break;

  case 43:
#line 201 "./lexical/ch.y"
                                                     {
        BaseNode* temp = new BaseNode("select statement(if)");
        temp->addChildNode((yyvsp[-4].ast));
        (yyvsp[-4].ast)->addCousinNode((yyvsp[-2].ast));
        BaseNode* else_node = new BaseNode("select statement(else)");
        else_node->addChildNode((yyvsp[0].ast));
        temp->addCousinNode(else_node);
        (yyval.ast) = temp;
    }
#line 1849 "./Linux/grammar.tab.cpp"
    break;

  case 44:
#line 210 "./lexical/ch.y"
                                         {
        BaseNode* temp = new BaseNode("loop statement(while)");
        temp->addChildNode((yyvsp[-2].ast));
        (yyvsp[-2].ast)->addCousinNode((yyvsp[0].ast));
        (yyval.ast) = temp;
    }
#line 1860 "./Linux/grammar.tab.cpp"
    break;

  case 45:
#line 217 "./lexical/ch.y"
                                   {
        BaseNode* temp = new BaseNode("loop statement(for)");
        temp->addChildNode((yyvsp[0].ast));
        (yyval.ast) = temp;
    }
#line 1870 "./Linux/grammar.tab.cpp"
    break;

  case 46:
#line 223 "./lexical/ch.y"
                                              {
        BaseNode* temp = new BaseNode("loop statement(for)");
        temp->addChildNode((yyvsp[-3].ast));
        (yyvsp[-3].ast)->addCousinNode((yyvsp[0].ast));
        (yyval.ast) = temp;
    }
#line 1881 "./Linux/grammar.tab.cpp"
    break;

  case 47:
#line 229 "./lexical/ch.y"
                                              {
        BaseNode* temp = new BaseNode("loop statement(for)");
        temp->addChildNode((yyvsp[-2].ast));
        (yyvsp[-2].ast)->addCousinNode((yyvsp[0].ast));
        (yyval.ast) = temp;

    }
#line 1893 "./Linux/grammar.tab.cpp"
    break;

  case 48:
#line 236 "./lexical/ch.y"
                                                                          {
        BaseNode* temp = new BaseNode("loop statement(for)");
        temp->addChildNode((yyvsp[-6].ast));
        (yyvsp[-6].ast)->addCousinNode((yyvsp[-4].ast));
        (yyvsp[-4].ast)->addCousinNode((yyvsp[-2].ast));
        (yyvsp[-2].ast)->addCousinNode((yyvsp[0].ast));
        (yyval.ast) = temp;
    }
#line 1906 "./Linux/grammar.tab.cpp"
    break;

  case 49:
#line 244 "./lexical/ch.y"
                                                                {
        BaseNode* temp = new BaseNode("loop statement(for)");
        temp->addChildNode((yyvsp[-5].ast));
        (yyvsp[-5].ast)->addCousinNode((yyvsp[-3].ast));
        (yyvsp[-3].ast)->addCousinNode((yyvsp[0].ast));
        (yyval.ast) = temp;
    }
#line 1918 "./Linux/grammar.tab.cpp"
    break;

  case 50:
#line 251 "./lexical/ch.y"
                                                                {
        BaseNode* temp = new BaseNode("loop statement(for)");
        temp->addChildNode((yyvsp[-5].ast));
        (yyvsp[-5].ast)->addCousinNode((yyvsp[-2].ast));
        (yyvsp[-2].ast)->addCousinNode((yyvsp[0].ast));
        (yyval.ast) = temp;
    }
#line 1930 "./Linux/grammar.tab.cpp"
    break;

  case 51:
#line 258 "./lexical/ch.y"
                                                          {
        BaseNode* temp = new BaseNode("loop statement(for)");
        temp->addChildNode((yyvsp[-4].ast));
        (yyvsp[-4].ast)->addCousinNode((yyvsp[-2].ast));
        (yyvsp[-2].ast)->addCousinNode((yyvsp[0].ast));
        (yyval.ast) = temp;
    }
#line 1942 "./Linux/grammar.tab.cpp"
    break;

  case 52:
#line 265 "./lexical/ch.y"
                            {
        BaseNode* temp = new BaseNode("return statement");
        temp->addChildNode((yyvsp[-1].ast));
        (yyval.ast) = temp;
    }
#line 1952 "./Linux/grammar.tab.cpp"
    break;

  case 53:
#line 270 "./lexical/ch.y"
                 {
        BaseNode* temp = new BaseNode("return statement");
        (yyval.ast) = temp;
    }
#line 1961 "./Linux/grammar.tab.cpp"
    break;

  case 54:
#line 274 "./lexical/ch.y"
                { yyerrok; }
#line 1967 "./Linux/grammar.tab.cpp"
    break;

  case 55:
#line 279 "./lexical/ch.y"
                                        {
        (yyval.ast) = (yyvsp[0].ast);
    }
#line 1975 "./Linux/grammar.tab.cpp"
    break;

  case 56:
#line 282 "./lexical/ch.y"
                { yyerrok; }
#line 1981 "./Linux/grammar.tab.cpp"
    break;

  case 57:
#line 285 "./lexical/ch.y"
                              { (yyval.ast) = (yyvsp[0].ast); }
#line 1987 "./Linux/grammar.tab.cpp"
    break;

  case 58:
#line 286 "./lexical/ch.y"
                                       {
        (yyvsp[-2].ast)->getFinalCousinNode()->addCousinNode((yyvsp[0].ast));
        (yyval.ast) = (yyvsp[-2].ast);
    }
#line 1996 "./Linux/grammar.tab.cpp"
    break;

  case 59:
#line 292 "./lexical/ch.y"
                               { (yyval.ast) = (yyvsp[0].ast); }
#line 2002 "./Linux/grammar.tab.cpp"
    break;

  case 60:
#line 293 "./lexical/ch.y"
                                       {
        (yyvsp[-2].ast)->addChildNode((yyvsp[0].ast));
        (yyval.ast) = (yyvsp[-2].ast);
    }
#line 2011 "./Linux/grammar.tab.cpp"
    break;

  case 61:
#line 301 "./lexical/ch.y"
                                      {
            BaseNode* temp = NULL;
            temp = new BaseNode("operator: =", op);
            temp->addChildNode((yyvsp[-2].ast));
            (yyvsp[-2].ast)->addCousinNode((yyvsp[0].ast));
            (yyval.ast) = temp;
        }
#line 2023 "./Linux/grammar.tab.cpp"
    break;

  case 62:
#line 308 "./lexical/ch.y"
                                    {
            BaseNode* temp = new BaseNode("operator: &&", op);
            temp->addChildNode((yyvsp[-2].ast));
            (yyvsp[-2].ast)->addCousinNode((yyvsp[0].ast));
            (yyval.ast) = temp;
        }
#line 2034 "./Linux/grammar.tab.cpp"
    break;

  case 63:
#line 314 "./lexical/ch.y"
                                   {
            BaseNode* temp = new BaseNode("operator: ||", op);
            temp->addChildNode((yyvsp[-2].ast));
            (yyvsp[-2].ast)->addCousinNode((yyvsp[0].ast));
            (yyval.ast) = temp;
        }
#line 2045 "./Linux/grammar.tab.cpp"
    break;

  case 64:
#line 320 "./lexical/ch.y"
                                      {
            char* s = "";
            sprintf(s, "operator: %s", (yyvsp[-1].str));
            BaseNode* temp = new BaseNode(s, op);
            temp->addChildNode((yyvsp[-2].ast));
            (yyvsp[-2].ast)->addCousinNode((yyvsp[0].ast));
            (yyval.ast) = temp;
        }
#line 2058 "./Linux/grammar.tab.cpp"
    break;

  case 65:
#line 328 "./lexical/ch.y"
                                    {
            BaseNode* temp = new BaseNode("operator: +", op);
            temp->addChildNode((yyvsp[-2].ast));
            (yyvsp[-2].ast)->addCousinNode((yyvsp[0].ast));
            (yyval.ast) = temp;
        }
#line 2069 "./Linux/grammar.tab.cpp"
    break;

  case 66:
#line 334 "./lexical/ch.y"
                                    {
            BaseNode* temp = new BaseNode("operator: -", op);
            temp->addChildNode((yyvsp[-2].ast));
            (yyvsp[-2].ast)->addCousinNode((yyvsp[0].ast));
            (yyval.ast) = temp;
        }
#line 2080 "./Linux/grammar.tab.cpp"
    break;

  case 67:
#line 340 "./lexical/ch.y"
                                    {
            BaseNode* temp = new BaseNode("operator: *", op);
            temp->addChildNode((yyvsp[-2].ast));
            (yyvsp[-2].ast)->addCousinNode((yyvsp[0].ast));
            (yyval.ast) = temp;
        }
#line 2091 "./Linux/grammar.tab.cpp"
    break;

  case 68:
#line 346 "./lexical/ch.y"
                                    {
            BaseNode* temp = new BaseNode("operator: /", op);
            temp->addChildNode((yyvsp[-2].ast));
            (yyvsp[-2].ast)->addCousinNode((yyvsp[0].ast));
            (yyval.ast) = temp;
        }
#line 2102 "./Linux/grammar.tab.cpp"
    break;

  case 69:
#line 352 "./lexical/ch.y"
                                    {
            BaseNode* temp = new BaseNode("operator: %", op);
            temp->addChildNode((yyvsp[-2].ast));
            (yyvsp[-2].ast)->addCousinNode((yyvsp[0].ast));
            (yyval.ast) = temp;
        }
#line 2113 "./Linux/grammar.tab.cpp"
    break;

  case 70:
#line 358 "./lexical/ch.y"
                                    {
            BaseNode* temp = new BaseNode("operator: ^", op);
            temp->addChildNode((yyvsp[-2].ast));
            (yyvsp[-2].ast)->addCousinNode((yyvsp[0].ast));
            (yyval.ast) = temp;
        }
#line 2124 "./Linux/grammar.tab.cpp"
    break;

  case 71:
#line 364 "./lexical/ch.y"
                             {
            (yyval.ast) = (yyvsp[-1].ast);
        }
#line 2132 "./Linux/grammar.tab.cpp"
    break;

  case 72:
#line 367 "./lexical/ch.y"
                         {
            BaseNode* temp = new BaseNode("operator: -", op);
            temp->addChildNode((yyvsp[0].ast));
            (yyval.ast) = temp;
        }
#line 2142 "./Linux/grammar.tab.cpp"
    break;

  case 73:
#line 372 "./lexical/ch.y"
                         {
            BaseNode* temp = new BaseNode("operator: !", op);
            temp->addChildNode((yyvsp[0].ast));
            (yyval.ast) = temp;
        }
#line 2152 "./Linux/grammar.tab.cpp"
    break;

  case 74:
#line 377 "./lexical/ch.y"
                                              {
            char* s = "";
            sprintf(s, "call function name: %s", (yyvsp[-3].str));
            BaseNode* temp = new BaseNode(s);
            temp->addChildNode((yyvsp[-1].ast));
            (yyval.ast) = temp;
        }
#line 2164 "./Linux/grammar.tab.cpp"
    break;

  case 75:
#line 384 "./lexical/ch.y"
                     {
            char* s = "";
            sprintf(s, "call function name: %s", (yyvsp[-2].str));
            BaseNode* temp = new BaseNode(s);
        }
#line 2174 "./Linux/grammar.tab.cpp"
    break;

  case 76:
#line 389 "./lexical/ch.y"
                                        {
            (yyval.ast) = NULL;
        }
#line 2182 "./Linux/grammar.tab.cpp"
    break;

  case 77:
#line 392 "./lexical/ch.y"
             {
            (yyval.ast) = new BaseNode((yyvsp[0].str));
        }
#line 2190 "./Linux/grammar.tab.cpp"
    break;

  case 78:
#line 395 "./lexical/ch.y"
                                {
            BaseNode* op = new BaseNode("operator: []");
            char* s = "";
            sprintf(s, "variable: %s", (yyvsp[-3].str));
            BaseNode* temp = new BaseNode(s);
            (yyval.ast) = op;
            op->addChildNode(temp);
            temp->addCousinNode((yyvsp[-1].ast));
        }
#line 2204 "./Linux/grammar.tab.cpp"
    break;

  case 79:
#line 404 "./lexical/ch.y"
                    {}
#line 2210 "./Linux/grammar.tab.cpp"
    break;

  case 80:
#line 405 "./lexical/ch.y"
              {
            char* s = "";
            sprintf(s, "literal: %s", (yyvsp[0].str));
            (yyval.ast) = new BaseNode(s);
        }
#line 2220 "./Linux/grammar.tab.cpp"
    break;

  case 81:
#line 410 "./lexical/ch.y"
                 {}
#line 2226 "./Linux/grammar.tab.cpp"
    break;

  case 82:
#line 411 "./lexical/ch.y"
                    {yyerrok;}
#line 2232 "./Linux/grammar.tab.cpp"
    break;

  case 83:
#line 413 "./lexical/ch.y"
                                     {
            (yyval.ast) = (yyvsp[0].ast);
        }
#line 2240 "./Linux/grammar.tab.cpp"
    break;

  case 84:
#line 416 "./lexical/ch.y"
                                                  {
            (yyvsp[-2].ast)->getFinalCousinNode()->addCousinNode((yyvsp[0].ast));
            (yyval.ast) = (yyvsp[-2].ast);
        }
#line 2249 "./Linux/grammar.tab.cpp"
    break;


#line 2253 "./Linux/grammar.tab.cpp"

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
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[+*yyssp], yyvsp);
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
#line 421 "./lexical/ch.y"


/*
* Editor:Liuyin
* Content: Add main() modify yyerror
* 
*/
void yyerror(char* s) {
	fprintf(stderr, "Parse error: At line %d. %s\n", yylineno, s);
	exit(1);
}

int main(int argc,char * argv[]){  //不确定语法的在哪里输出

    int c,j=0;
    yyin=fopen("./test.txt","r");
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
    root->printTree();
    return 0;
}
