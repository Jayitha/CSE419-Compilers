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
#line 1 "parser.y" /* yacc.c:339  */

    #include<stdio.h>
    #include "evaluate.h"
    #define YYSTYPE struct ASTNode *
    #include "parser.tab.h"

#line 73 "parser.tab.c" /* yacc.c:339  */

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
   by #include "parser.tab.h".  */
#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
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
    ASSIGN = 258,
    BOOL = 259,
    CALLOUT = 260,
    CHAR = 261,
    CHAR_LITERAL = 262,
    CLOSE_ANG = 263,
    CLOSE_CURLY = 264,
    CLOSE_PARAN = 265,
    COLON = 266,
    COMMA = 267,
    DECLARE = 268,
    ELSE = 269,
    FALSE = 270,
    FOR = 271,
    ID = 272,
    IF = 273,
    INT = 274,
    INT_LITERAL = 275,
    OPEN_ANG = 276,
    OPEN_CURLY = 277,
    OPEN_PARAN = 278,
    PROGRAM = 279,
    QM = 280,
    STRING_LITERAL = 281,
    SEMICOLON = 282,
    TRUE = 283,
    VOID = 284,
    WHILE = 285,
    LOGICAL_OR = 286,
    LOGICAL_AND = 287,
    EQUALITY = 288,
    NONEQUALITY = 289,
    LESSTHAN = 290,
    GREATERTHAN = 291,
    LEQ = 292,
    GEQ = 293,
    SUB = 294,
    ADD = 295,
    MULTIPLY = 296,
    DIVIDE = 297,
    MODULO = 298,
    LOGICAL_NOT = 299
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef  struct ASTNode *  YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 169 "parser.tab.c" /* yacc.c:358  */

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
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   376

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  45
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  19
/* YYNRULES -- Number of rules.  */
#define YYNRULES  64
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  138

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   299

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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    47,    47,    60,    72,    85,    86,    88,    90,    91,
      93,    96,    97,    98,   100,   101,   102,   104,   105,   106,
     108,   109,   111,   112,   113,   114,   115,   116,   117,   119,
     120,   122,   123,   125,   126,   128,   129,   130,   131,   132,
     133,   134,   135,   136,   137,   138,   139,   140,   141,   142,
     143,   144,   145,   147,   148,   149,   152,   153,   154,   155,
     157,   158,   161,   162,   163
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ASSIGN", "BOOL", "CALLOUT", "CHAR",
  "CHAR_LITERAL", "CLOSE_ANG", "CLOSE_CURLY", "CLOSE_PARAN", "COLON",
  "COMMA", "DECLARE", "ELSE", "FALSE", "FOR", "ID", "IF", "INT",
  "INT_LITERAL", "OPEN_ANG", "OPEN_CURLY", "OPEN_PARAN", "PROGRAM", "QM",
  "STRING_LITERAL", "SEMICOLON", "TRUE", "VOID", "WHILE", "LOGICAL_OR",
  "LOGICAL_AND", "EQUALITY", "NONEQUALITY", "LESSTHAN", "GREATERTHAN",
  "LEQ", "GEQ", "SUB", "ADD", "MULTIPLY", "DIVIDE", "MODULO",
  "LOGICAL_NOT", "$accept", "program", "var_decls", "var_decl",
  "method_decls", "method_decl", "method_args", "method_arg", "block",
  "statements", "statement", "if_else_statment", "method_call",
  "callout_args", "expr", "location", "literal", "bool_literal", "type", YY_NULLPTR
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
     295,   296,   297,   298,   299
};
# endif

#define YYPACT_NINF -54

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-54)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  (!!((Yytable_value) == (-1)))

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -14,     2,    15,     1,   -54,    -3,    21,    -4,     6,    37,
      30,   -54,   -54,   -54,    31,    36,   -54,    41,   -54,   -54,
     -54,    32,    29,   -54,    48,    47,    44,   -54,    34,   -54,
      42,    36,    49,   -54,   -54,   -54,    34,   -54,   -54,    34,
      34,   162,   -54,   -54,   -54,   105,   -54,   -54,    51,   209,
     -20,   -54,    53,    34,    34,    34,    34,    34,    34,    34,
      34,    34,    34,    34,    34,    34,    52,    56,    57,    58,
     125,   -54,    63,   145,   -54,    55,   288,    80,    76,   -54,
      34,   188,   234,   333,   333,   333,   333,   333,   333,   -20,
     -20,   -54,   -54,   -54,    59,    34,    34,    34,   -54,    77,
     -54,   -54,   -54,    42,    34,    66,   175,    33,   305,   222,
     256,   -54,    79,   322,    68,   -54,   -54,    34,   145,    42,
      42,    42,   -54,    83,    82,   269,    86,    84,   -54,   -54,
     -54,   -54,    34,    42,    42,   -54,   -54,   -54
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     1,     0,     0,     0,     6,     0,
       9,    63,    64,    62,     0,     0,     4,     0,     5,     3,
       8,    53,     0,    11,     0,    13,     0,     2,     0,     7,
       0,     0,    14,    57,    61,    56,     0,    59,    60,     0,
       0,     0,    35,    36,    58,     0,    10,    12,     0,     0,
      50,    51,    54,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    28,     0,    21,    24,     0,     0,    35,     0,    52,
       0,    48,    49,    46,    47,    44,    45,    42,    43,    38,
      37,    39,    40,    41,     0,     0,     0,     0,    19,     0,
      18,    20,    23,     0,     0,    15,     0,     0,     0,     0,
       0,    17,     0,     0,     0,    55,    31,     0,     0,     0,
       0,     0,    22,     0,     0,    34,     0,    29,    26,    25,
      16,    32,     0,     0,     0,    33,    27,    30
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -54,   -54,    -6,   -54,    -1,   -54,    69,   -54,   -26,   -53,
     -21,   -54,   -54,   -33,   -28,    -7,   -54,   -54,    96
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,     7,     8,     9,    10,    24,    25,    71,    72,
      73,    74,    75,   124,    76,    42,    43,    44,    26
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      41,    11,    18,    12,    46,    16,    17,    22,    49,    20,
       1,    50,    51,     6,     5,     4,    13,    99,     6,     5,
     101,    63,    64,    65,     3,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    77,    70,
      11,    33,    12,   116,    15,   117,    19,     6,    21,    34,
      27,    21,   106,    28,    35,    13,    29,    36,    30,    31,
      37,    32,    38,    77,    45,    23,    77,   108,   109,   110,
      48,    78,   100,    39,    80,    94,   113,   112,    40,    95,
      96,    97,   102,   104,   105,   107,   111,   114,   123,   125,
     121,   130,   131,   127,   128,   129,   133,   126,   134,   135,
      47,    14,     0,     0,   125,     0,     0,   136,   137,     0,
      66,    77,    33,     0,     0,     0,     0,     0,     5,     0,
      34,    67,    21,    68,     0,    35,     0,    45,    36,     0,
      66,    37,    33,    38,    98,    69,     0,     0,     0,     0,
      34,    67,    21,    68,    39,    35,     0,    45,    36,    40,
      66,    37,    33,    38,     0,    69,     0,     0,     0,     0,
      34,    67,    21,    68,    39,    35,     0,    45,    36,    40,
      52,    37,     0,    38,     0,    69,     0,     0,     0,     0,
       0,     0,     0,   115,    39,     0,     0,     0,     0,    40,
       0,     0,     0,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    79,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,   119,     0,     0,     0,     0,     0,     0,     0,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,   120,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,     0,     0,
       0,   132,     0,     0,     0,     0,     0,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,   103,     0,     0,     0,     0,     0,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,   118,     0,     0,     0,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,   122,
       0,     0,     0,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    -1,    -1,    -1,    -1,
      -1,    -1,    61,    62,    63,    64,    65
};

static const yytype_int16 yycheck[] =
{
      28,     4,     8,     6,    30,     9,     7,    14,    36,    10,
      24,    39,    40,    17,    13,     0,    19,    70,    17,    13,
      73,    41,    42,    43,    22,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    45,    45,
       4,     7,     6,    10,    23,    12,     9,    17,    17,    15,
       9,    17,    80,    21,    20,    19,    27,    23,    10,    12,
      26,    17,    28,    70,    22,    29,    73,    95,    96,    97,
      21,    20,     9,    39,    21,    23,   104,   103,    44,    23,
      23,    23,    27,     3,     8,    26,     9,    21,    20,   117,
      11,     8,    10,   119,   120,   121,    10,   118,    14,   132,
      31,     5,    -1,    -1,   132,    -1,    -1,   133,   134,    -1,
       5,   118,     7,    -1,    -1,    -1,    -1,    -1,    13,    -1,
      15,    16,    17,    18,    -1,    20,    -1,    22,    23,    -1,
       5,    26,     7,    28,     9,    30,    -1,    -1,    -1,    -1,
      15,    16,    17,    18,    39,    20,    -1,    22,    23,    44,
       5,    26,     7,    28,    -1,    30,    -1,    -1,    -1,    -1,
      15,    16,    17,    18,    39,    20,    -1,    22,    23,    44,
       8,    26,    -1,    28,    -1,    30,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     8,    39,    -1,    -1,    -1,    -1,    44,
      -1,    -1,    -1,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    10,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    10,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    10,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    -1,    -1,
      -1,    12,    -1,    -1,    -1,    -1,    -1,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    25,    -1,    -1,    -1,    -1,    -1,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    27,    -1,    -1,    -1,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    27,
      -1,    -1,    -1,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    24,    46,    22,     0,    13,    17,    47,    48,    49,
      50,     4,     6,    19,    63,    23,     9,    49,    47,     9,
      49,    17,    60,    29,    51,    52,    63,     9,    21,    27,
      10,    12,    17,     7,    15,    20,    23,    26,    28,    39,
      44,    59,    60,    61,    62,    22,    53,    51,    21,    59,
      59,    59,     8,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,     5,    16,    18,    30,
      47,    53,    54,    55,    56,    57,    59,    60,    20,    10,
      21,    59,    59,    59,    59,    59,    59,    59,    59,    59,
      59,    59,    59,    59,    23,    23,    23,    23,     9,    54,
       9,    54,    27,    25,     3,     8,    59,    26,    59,    59,
      59,     9,    53,    59,    21,     8,    10,    12,    27,    10,
      10,    11,    27,    20,    58,    59,    55,    53,    53,    53,
       8,    10,    12,    10,    14,    58,    53,    53
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    45,    46,    46,    46,    47,    47,    48,    49,    49,
      50,    51,    51,    51,    52,    52,    52,    53,    53,    53,
      54,    54,    55,    55,    55,    55,    55,    55,    55,    56,
      56,    57,    57,    58,    58,    59,    59,    59,    59,    59,
      59,    59,    59,    59,    59,    59,    59,    59,    59,    59,
      59,    59,    59,    60,    60,    60,    61,    61,    61,    61,
      62,    62,    63,    63,    63
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     5,     4,     4,     2,     1,     4,     2,     1,
       5,     1,     3,     1,     2,     5,     8,     4,     3,     3,
       2,     1,     4,     2,     1,     5,     5,     7,     1,     5,
       7,     4,     6,     3,     1,     1,     1,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       2,     2,     3,     1,     4,     7,     1,     1,     1,     1,
       1,     1,     1,     1,     1
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
        case 2:
#line 47 "parser.y" /* yacc.c:1646  */
    {
           (yyval) = getASTNodeProgram((yyvsp[-2]), (yyvsp[-1]), BOTH_PROGRAM); 
           printf("\n\n\n");
           printf("-------------------------------------------------------------\n");
           printf("                         POSTFIX AST                         \n");
           printf("-------------------------------------------------------------\n");
           printPostFix((yyval));
           printf("\n\n\n");
           printf("-------------------------------------------------------------\n");
           printf("                         INTERPRETER                         \n");
           printf("-------------------------------------------------------------\n");
           evaluate((yyval));
           }
#line 1396 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 60 "parser.y" /* yacc.c:1646  */
    {
           (yyval) = getASTNodeProgram(NULL,(yyvsp[-1]), METHOD_DECLS_ONLY_PROGRAM);
           printf("\n\n\n");
           printf("-------------------------------------------------------------\n");
           printf("                         POSTFIX AST                         \n");
           printf("-------------------------------------------------------------\n"); 
           printPostFix((yyval));
           printf("\n\n\n");
           printf("-------------------------------------------------------------\n");
           printf("                         INTERPRETER                         \n");
           printf("-------------------------------------------------------------\n");
           evaluate((yyval));}
#line 1413 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 72 "parser.y" /* yacc.c:1646  */
    {
           (yyval) = getASTNodeProgram((yyvsp[-1]), NULL, VAR_DECLS_ONLY_PROGRAM);
           printf("\n\n\n");
           printf("-------------------------------------------------------------\n");
           printf("                         POSTFIX AST                         \n");
           printf("-------------------------------------------------------------\n");  
           printPostFix((yyval));
           printf("\n\n\n");
           printf("-------------------------------------------------------------\n");
           printf("                         INTERPRETER                         \n");
           printf("-------------------------------------------------------------\n");
           evaluate((yyval));}
#line 1430 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 85 "parser.y" /* yacc.c:1646  */
    {(yyval) = getASTNodeVarDecls((yyvsp[-1]), (yyvsp[0]));}
#line 1436 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 86 "parser.y" /* yacc.c:1646  */
    {(yyval) = getASTNodeVarDecls((yyvsp[0]), NULL);}
#line 1442 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 88 "parser.y" /* yacc.c:1646  */
    {(yyval) = getASTNodeVarDecl((yyvsp[-2]), (yyvsp[-1]));}
#line 1448 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 90 "parser.y" /* yacc.c:1646  */
    {(yyval) = getASTNodeMethodDecls((yyvsp[-1]), (yyvsp[0]));}
#line 1454 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 91 "parser.y" /* yacc.c:1646  */
    {(yyval) = getASTNodeMethodDecls((yyvsp[0]), NULL);}
#line 1460 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 93 "parser.y" /* yacc.c:1646  */
    {(yyval) = getASTNodeMethodDecl((yyvsp[-4])->stringLiteral, (yyvsp[-2]), (yyvsp[0]));}
#line 1466 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 96 "parser.y" /* yacc.c:1646  */
    {(yyval) = getASTNodeMethodArgs(NULL, NULL, VOID_METHODARGSTYPE);}
#line 1472 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 97 "parser.y" /* yacc.c:1646  */
    {(yyval) = getASTNodeMethodArgs((yyvsp[-2]), (yyvsp[-1]), MULTIPLE_METHODARGSTYPE);}
#line 1478 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 98 "parser.y" /* yacc.c:1646  */
    {(yyval) = getASTNodeMethodArgs((yyvsp[0]), NULL, NONVOID_METHODARGSTYPE);}
#line 1484 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 100 "parser.y" /* yacc.c:1646  */
    {(yyval) = getASTNodeMethodArg((yyvsp[-1]), (yyvsp[0])->stringLiteral, NULL, NULL, SINGLE_METHODARGTYPE);}
#line 1490 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 101 "parser.y" /* yacc.c:1646  */
    {(yyval) = getASTNodeMethodArg((yyvsp[-4]), (yyvsp[-3])->stringLiteral, (yyvsp[-1]), NULL, ARRAY_METHODARGTYPE);}
#line 1496 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 102 "parser.y" /* yacc.c:1646  */
    {(yyval) = getASTNodeMethodArg((yyvsp[-7]), (yyvsp[-6])->stringLiteral, (yyvsp[-4]), (yyvsp[-1]), MATRIX_METHODARGTYPE);}
#line 1502 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 104 "parser.y" /* yacc.c:1646  */
    {(yyval) = getASTNodeBlock((yyvsp[-2]), (yyvsp[-1]), BOTH_BLOCKTYPE);}
#line 1508 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 105 "parser.y" /* yacc.c:1646  */
    {(yyval) = getASTNodeBlock(NULL, (yyvsp[-1]), STATEMENTS_ONLY_BLOCKTYPE);}
#line 1514 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 106 "parser.y" /* yacc.c:1646  */
    {(yyval) = getASTNodeBlock((yyvsp[-1]), NULL, VAR_DECLS_ONLY_BLOCKTYPE);}
#line 1520 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 108 "parser.y" /* yacc.c:1646  */
    {(yyval) = getASTNodeStatements((yyvsp[-1]), (yyvsp[0]));}
#line 1526 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 109 "parser.y" /* yacc.c:1646  */
    {(yyval) = getASTNodeStatements((yyvsp[0]), NULL);}
#line 1532 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 111 "parser.y" /* yacc.c:1646  */
    {(yyval) = getASTNodeStatement((yyvsp[-3]), (yyvsp[-1]), NULL, NULL, NULL, ASSIGNMENT_STATEMENTTYPE);}
#line 1538 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 112 "parser.y" /* yacc.c:1646  */
    {(yyval) = getASTNodeStatement((yyvsp[-1]), NULL, NULL, NULL, NULL, METHOD_CALL_STATEMENTTYPE);}
#line 1544 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 113 "parser.y" /* yacc.c:1646  */
    {(yyval) = getASTNodeStatement((yyvsp[0]), NULL, NULL, NULL, NULL, IFTHENELSE_STATEMENTTYPE);}
#line 1550 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 114 "parser.y" /* yacc.c:1646  */
    {(yyval) = getASTNodeStatement((yyvsp[-4]), (yyvsp[-2]), (yyvsp[0]), NULL, NULL, TERNARY_STATEMENTTYPE);}
#line 1556 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 115 "parser.y" /* yacc.c:1646  */
    {(yyval) = getASTNodeStatement((yyvsp[-2]), (yyvsp[0]), NULL, NULL, NULL, WHILE_STATEMENTTYPE);}
#line 1562 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 116 "parser.y" /* yacc.c:1646  */
    {(yyval) = getASTNodeStatement((yyvsp[-4]), (yyvsp[-2]), (yyvsp[0]), NULL, NULL, FOR_STATEMENTTYPE);}
#line 1568 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 117 "parser.y" /* yacc.c:1646  */
    {(yyval) = getASTNodeStatement((yyvsp[0]), NULL, NULL, NULL, NULL, BLOCK_STATEMENTTYPE);}
#line 1574 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 119 "parser.y" /* yacc.c:1646  */
    {(yyval) = getASTNodeIfElse((yyvsp[-2]), (yyvsp[0]), NULL);}
#line 1580 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 120 "parser.y" /* yacc.c:1646  */
    {(yyval) = getASTNodeIfElse((yyvsp[-4]), (yyvsp[-2]), (yyvsp[0]));}
#line 1586 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 122 "parser.y" /* yacc.c:1646  */
    {(yyval) = getASTNodeMethodCall((yyvsp[-1]), NULL);}
#line 1592 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 123 "parser.y" /* yacc.c:1646  */
    {(yyval) = getASTNodeMethodCall((yyvsp[-3]), (yyvsp[-1]));}
#line 1598 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 125 "parser.y" /* yacc.c:1646  */
    {(yyval) = getASTNodeCalloutArgs((yyvsp[-2]), (yyvsp[0]));}
#line 1604 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 126 "parser.y" /* yacc.c:1646  */
    {(yyval) = getASTNodeCalloutArgs((yyvsp[0]), NULL);}
#line 1610 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 128 "parser.y" /* yacc.c:1646  */
    {(yyval) = getASTNodeExpr((yyvsp[0]), NULL, LOCATION_EXPRTYPE);}
#line 1616 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 129 "parser.y" /* yacc.c:1646  */
    {(yyval) = getASTNodeExpr((yyvsp[0]), NULL, LITERAL_EXPRTYPE);}
#line 1622 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 130 "parser.y" /* yacc.c:1646  */
    {(yyval) = getASTNodeExpr((yyvsp[-2]), (yyvsp[0]), ADD_EXPRTYPE);}
#line 1628 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 131 "parser.y" /* yacc.c:1646  */
    {(yyval) = getASTNodeExpr((yyvsp[-2]), (yyvsp[0]), SUB_EXPRTYPE);}
#line 1634 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 132 "parser.y" /* yacc.c:1646  */
    {(yyval) = getASTNodeExpr((yyvsp[-2]), (yyvsp[0]), MUL_EXPRTYPE);}
#line 1640 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 133 "parser.y" /* yacc.c:1646  */
    {(yyval) = getASTNodeExpr((yyvsp[-2]), (yyvsp[0]), DIV_EXPRTYPE);}
#line 1646 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 134 "parser.y" /* yacc.c:1646  */
    {(yyval) = getASTNodeExpr((yyvsp[-2]), (yyvsp[0]), MOD_EXPRTYPE);}
#line 1652 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 135 "parser.y" /* yacc.c:1646  */
    {(yyval) = getASTNodeExpr((yyvsp[-2]), (yyvsp[0]), LEQ_EXPRTYPE);}
#line 1658 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 136 "parser.y" /* yacc.c:1646  */
    {(yyval) = getASTNodeExpr((yyvsp[-2]), (yyvsp[0]), GEQ_EXPRTYPE);}
#line 1664 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 137 "parser.y" /* yacc.c:1646  */
    {(yyval) = getASTNodeExpr((yyvsp[-2]), (yyvsp[0]), LESSTHAN_EXPRTYPE);}
#line 1670 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 138 "parser.y" /* yacc.c:1646  */
    {(yyval) = getASTNodeExpr((yyvsp[-2]), (yyvsp[0]), GREATERTHAN_EXPRTYPE);}
#line 1676 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 139 "parser.y" /* yacc.c:1646  */
    {(yyval) = getASTNodeExpr((yyvsp[-2]), (yyvsp[0]), EQUALITY_EXPRTYPE);}
#line 1682 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 140 "parser.y" /* yacc.c:1646  */
    {(yyval) = getASTNodeExpr((yyvsp[-2]), (yyvsp[0]), NONEQUALITY_EXPRTYPE);}
#line 1688 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 141 "parser.y" /* yacc.c:1646  */
    {(yyval) = getASTNodeExpr((yyvsp[-2]), (yyvsp[0]), LOGICAL_OR_EXPRTYPE);}
#line 1694 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 142 "parser.y" /* yacc.c:1646  */
    {(yyval) = getASTNodeExpr((yyvsp[-2]), (yyvsp[0]), LOGICAL_AND_EXPRTYPE);}
#line 1700 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 143 "parser.y" /* yacc.c:1646  */
    {(yyval) = getASTNodeExpr((yyvsp[0]), NULL, UNISUB_EXPRTYPE);}
#line 1706 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 144 "parser.y" /* yacc.c:1646  */
    {(yyval) = getASTNodeExpr((yyvsp[0]), NULL, LOGICAL_NOT_EXPRTYPE);}
#line 1712 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 145 "parser.y" /* yacc.c:1646  */
    {(yyval) = getASTNodeExpr((yyvsp[-1]), NULL, EXPR_PARAN_EXPRTYPE);}
#line 1718 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 147 "parser.y" /* yacc.c:1646  */
    {(yyval) = getASTNodeLocation((yyvsp[0])->stringLiteral, NULL, NULL, SINGLE_LOCATIONTYPE);}
#line 1724 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 148 "parser.y" /* yacc.c:1646  */
    {(yyval) = getASTNodeLocation((yyvsp[-3])->stringLiteral, (yyvsp[-1]), NULL, ARRAY_LOCATIONTYPE);}
#line 1730 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 149 "parser.y" /* yacc.c:1646  */
    {(yyval) = getASTNodeLocation((yyvsp[-6])->stringLiteral, (yyvsp[-4]), (yyvsp[-1]), MATRIX_LOCATIONTYPE);}
#line 1736 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 152 "parser.y" /* yacc.c:1646  */
    {(yyval) = getASTNodeINTLiteral((yyvsp[0])->intLiteral);}
#line 1742 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 153 "parser.y" /* yacc.c:1646  */
    {(yyval) = getASTNodeCHARLiteral((yyvsp[0])->charLiteral);}
#line 1748 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 154 "parser.y" /* yacc.c:1646  */
    {(yyval) = (yyvsp[0]);}
#line 1754 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 155 "parser.y" /* yacc.c:1646  */
    {(yyval) = getASTNodeSTRINGLiteral((yyvsp[0])->stringLiteral);}
#line 1760 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 157 "parser.y" /* yacc.c:1646  */
    {(yyval) = getASTNodeBOOLLiteral(TRUE_BOOL);}
#line 1766 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 158 "parser.y" /* yacc.c:1646  */
    {(yyval) = getASTNodeBOOLLiteral(FALSE_BOOL);}
#line 1772 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 161 "parser.y" /* yacc.c:1646  */
    {(yyval) = getASTNodeType(INT_TYPETYPE);}
#line 1778 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 162 "parser.y" /* yacc.c:1646  */
    {(yyval) = getASTNodeType(BOOL_TYPETYPE);}
#line 1784 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 163 "parser.y" /* yacc.c:1646  */
    {(yyval) = getASTNodeType(CHAR_TYPETYPE);}
#line 1790 "parser.tab.c" /* yacc.c:1646  */
    break;


#line 1794 "parser.tab.c" /* yacc.c:1646  */
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
#line 165 "parser.y" /* yacc.c:1906  */

yyerror(char *s)
{
        fprintf(stderr, "error: %s\n", s);
}
main(int argc, char **argv)
{
        printf("-------------------------------------------------------------\n");
        printf("                        SCANNER OUTPUT                       \n");
        printf("-------------------------------------------------------------\n");
        yyparse();
        printf("Parsing Over\n");
}

