/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
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
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "analyse_syntaxique.y"

#include <stdlib.h>
#include <stdio.h>
#include "arbre_abstrait.h"
#include "analyse_lexicale.h"


//n_programme* yyparse();
int yylex();
int yyerror(const char *s);
n_programme* arbre_abstrait;

#line 84 "analyse_syntaxique.c"

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

#include "symboles.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* FIN  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_IDENTIFIANT = 3,                /* IDENTIFIANT  */
  YYSYMBOL_EGALE = 4,                      /* EGALE  */
  YYSYMBOL_PLUS = 5,                       /* PLUS  */
  YYSYMBOL_MOINS = 6,                      /* MOINS  */
  YYSYMBOL_DIFFERENT = 7,                  /* DIFFERENT  */
  YYSYMBOL_FOIS = 8,                       /* FOIS  */
  YYSYMBOL_TYPE_ENTIER = 9,                /* TYPE_ENTIER  */
  YYSYMBOL_PARENTHESE_OUVRANTE = 10,       /* PARENTHESE_OUVRANTE  */
  YYSYMBOL_PARENTHESE_FERMANTE = 11,       /* PARENTHESE_FERMANTE  */
  YYSYMBOL_POINT_VIRGULE = 12,             /* POINT_VIRGULE  */
  YYSYMBOL_SI = 13,                        /* SI  */
  YYSYMBOL_LE = 14,                        /* LE  */
  YYSYMBOL_GE = 15,                        /* GE  */
  YYSYMBOL_GT = 16,                        /* GT  */
  YYSYMBOL_EQ = 17,                        /* EQ  */
  YYSYMBOL_OU = 18,                        /* OU  */
  YYSYMBOL_ET = 19,                        /* ET  */
  YYSYMBOL_RETOURNER = 20,                 /* RETOURNER  */
  YYSYMBOL_ENTIER = 21,                    /* ENTIER  */
  YYSYMBOL_ECRIRE = 22,                    /* ECRIRE  */
  YYSYMBOL_LIRE = 23,                      /* LIRE  */
  YYSYMBOL_TYPE_BOOLEEN = 24,              /* TYPE_BOOLEEN  */
  YYSYMBOL_VRAI = 25,                      /* VRAI  */
  YYSYMBOL_FAUX = 26,                      /* FAUX  */
  YYSYMBOL_TANTQUE = 27,                   /* TANTQUE  */
  YYSYMBOL_NON = 28,                       /* NON  */
  YYSYMBOL_DIVISER = 29,                   /* DIVISER  */
  YYSYMBOL_MODULO = 30,                    /* MODULO  */
  YYSYMBOL_SINON = 31,                     /* SINON  */
  YYSYMBOL_LT = 32,                        /* LT  */
  YYSYMBOL_BLOC_OUVRANT = 33,              /* BLOC_OUVRANT  */
  YYSYMBOL_BLOC_FERMANT = 34,              /* BLOC_FERMANT  */
  YYSYMBOL_VIRGULE = 35,                   /* VIRGULE  */
  YYSYMBOL_YYACCEPT = 36,                  /* $accept  */
  YYSYMBOL_prog = 37,                      /* prog  */
  YYSYMBOL_listeInstructions = 38,         /* listeInstructions  */
  YYSYMBOL_instruction = 39,               /* instruction  */
  YYSYMBOL_fonction = 40,                  /* fonction  */
  YYSYMBOL_declarationVariable = 41,       /* declarationVariable  */
  YYSYMBOL_parms = 42,                     /* parms  */
  YYSYMBOL_list_parms = 43,                /* list_parms  */
  YYSYMBOL_ecrire = 44,                    /* ecrire  */
  YYSYMBOL_liste_expr = 45,                /* liste_expr  */
  YYSYMBOL_lire = 46,                      /* lire  */
  YYSYMBOL_expr = 47,                      /* expr  */
  YYSYMBOL_logique = 48,                   /* logique  */
  YYSYMBOL_comparaison = 49,               /* comparaison  */
  YYSYMBOL_terme = 50,                     /* terme  */
  YYSYMBOL_produit = 51,                   /* produit  */
  YYSYMBOL_facteur = 52,                   /* facteur  */
  YYSYMBOL_affectation = 53,               /* affectation  */
  YYSYMBOL_conditionSi = 54,               /* conditionSi  */
  YYSYMBOL_cond = 55,                      /* cond  */
  YYSYMBOL_retourner = 56,                 /* retourner  */
  YYSYMBOL_type = 57                       /* type  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




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

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
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
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
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

#if 1

/* The parser invokes alloca or malloc; define the necessary symbols.  */

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
# define YYCOPY_NEEDED 1
#endif /* 1 */

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
#define YYFINAL  47
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   205

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  36
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  22
/* YYNRULES -- Number of rules.  */
#define YYNRULES  67
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  129

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   290


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
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
      35
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,   106,   106,   109,   112,   115,   119,   120,   121,   122,
     123,   124,   125,   128,   132,   133,   137,   141,   142,   143,
     146,   152,   153,   154,   157,   161,   162,   163,   164,   165,
     166,   167,   171,   172,   173,   174,   175,   176,   181,   182,
     183,   184,   185,   186,   187,   191,   192,   193,   197,   198,
     199,   200,   204,   205,   206,   207,   208,   209,   214,   218,
     219,   223,   230,   231,   237,   238,   242,   243
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if 1
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  static const char *const yy_sname[] =
  {
  "FIN", "error", "invalid token", "IDENTIFIANT", "EGALE", "PLUS",
  "MOINS", "DIFFERENT", "FOIS", "TYPE_ENTIER", "PARENTHESE_OUVRANTE",
  "PARENTHESE_FERMANTE", "POINT_VIRGULE", "SI", "LE", "GE", "GT", "EQ",
  "OU", "ET", "RETOURNER", "ENTIER", "ECRIRE", "LIRE", "TYPE_BOOLEEN",
  "VRAI", "FAUX", "TANTQUE", "NON", "DIVISER", "MODULO", "SINON", "LT",
  "BLOC_OUVRANT", "BLOC_FERMANT", "VIRGULE", "$accept", "prog",
  "listeInstructions", "instruction", "fonction", "declarationVariable",
  "parms", "list_parms", "ecrire", "liste_expr", "lire", "expr", "logique",
  "comparaison", "terme", "produit", "facteur", "affectation",
  "conditionSi", "cond", "retourner", "type", YY_NULLPTR
  };
  return yy_sname[yysymbol];
}
#endif

#define YYPACT_NINF (-80)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-57)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      57,    52,   -18,   -80,   131,     3,   131,   -80,     8,    31,
     -80,   -80,   -80,    35,   157,     9,   -80,    57,   -80,   -80,
     -80,   -80,    21,    54,   158,     5,    -1,   -80,   -80,    28,
     -80,   -80,    58,   131,   131,   -80,    94,   181,   131,    84,
     131,    76,   131,    59,   131,   -80,    86,   -80,   -80,    65,
      65,   -80,   157,   157,    65,    65,    65,    65,    65,    65,
      65,    65,    65,    65,    65,     1,   167,   110,    83,     0,
     113,   183,   -80,   190,   -80,   192,   131,   194,   -80,   -80,
      46,   -80,    86,    86,    86,    86,    86,    86,    -1,    -1,
     -80,   -80,   -80,    57,    28,   131,     6,   -80,   -80,   132,
     131,    70,    93,    73,   103,   -80,    91,   164,    98,   124,
     133,   -80,    57,   -80,    57,   -80,   -80,   -80,     6,   105,
     -80,   119,   121,   -80,    57,   -80,   -80,   134,   -80
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       5,    53,     0,    66,     0,     0,     0,    52,     0,     0,
      67,    34,    33,     0,     0,     0,     2,     3,     7,     6,
       9,    57,     0,    25,    37,    26,    47,    51,     8,    62,
      11,    10,     0,     0,    23,    54,    29,     0,     0,    65,
       0,     0,     0,    53,     0,    32,    44,     1,     4,     0,
       0,    12,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    21,
      28,     0,    64,     0,    24,     0,    23,     0,    30,    31,
      36,    35,    43,    39,    41,    40,    42,    38,    45,    46,
      48,    49,    50,     5,    60,     0,    19,    15,    58,    27,
      23,     0,     0,     0,     0,    55,     0,     0,    17,     0,
       0,    22,     5,    20,     5,    56,    61,    14,    19,     0,
      16,     0,     0,    18,     5,    59,    63,     0,    13
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -80,   -80,   -17,   -80,   -80,   -80,   -80,    26,   -80,   -75,
     -80,    -2,     2,   -80,    -6,    39,    55,   -80,   101,   -80,
     -80,   -79
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,    15,    16,    17,    18,    19,   108,   109,    20,    68,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      48,   104,    37,    35,    39,    49,    50,    62,    46,    47,
      60,    61,   -44,    38,     5,     3,    45,   110,    40,   -44,
     -44,   -44,   -44,   -44,   -44,   111,    49,    50,    63,    64,
      10,    67,    69,    51,    93,   100,    71,   -44,    73,   110,
      75,    41,    77,    78,    79,    42,    46,    46,    82,    83,
      84,    85,    86,    87,    80,    81,    33,   -29,   -29,    65,
       1,    66,    34,     2,   -29,    53,     3,     4,    43,    76,
       5,     2,    52,    53,    69,    44,   106,     6,     7,     8,
       9,    10,    11,    12,    13,    14,     7,    74,     9,    49,
      50,    60,    61,   107,    99,   121,    72,   122,    69,    88,
      89,   -53,   -53,   112,    34,   113,   114,   127,   -53,   -53,
     -53,   -53,   -53,   -53,   115,    49,    50,    90,    91,    92,
     -55,   -55,    98,   -53,   -53,   116,   -53,   -55,   -55,   -55,
     -55,   -55,   -55,   118,    36,   119,   120,     2,   124,   -56,
     -56,     4,   -55,   -55,   123,   -55,   -56,   -56,   -56,   -56,
     -56,   -56,     7,   125,     9,   126,    11,    12,     0,    14,
      43,   -56,   -56,     2,   -56,    54,    94,    44,   128,    49,
      50,    95,    55,    56,    57,    58,   117,    96,     7,    97,
       9,     0,    11,    12,     0,    14,    49,    50,    49,    50,
      59,     0,    70,     0,   101,    49,    50,    49,    50,    49,
      50,   102,     0,   103,     0,   105
};

static const yytype_int8 yycheck[] =
{
      17,    76,     4,    21,     6,     5,     6,     8,    14,     0,
       5,     6,     7,    10,    13,     9,    14,    96,    10,    14,
      15,    16,    17,    18,    19,   100,     5,     6,    29,    30,
      24,    33,    34,    12,    33,    35,    38,    32,    40,   118,
      42,    10,    44,    49,    50,    10,    52,    53,    54,    55,
      56,    57,    58,    59,    52,    53,     4,     5,     6,    31,
       3,     3,    10,     6,    12,    19,     9,    10,     3,    10,
      13,     6,    18,    19,    76,    10,    93,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    21,    11,    23,     5,
       6,     5,     6,    95,    11,   112,    12,   114,   100,    60,
      61,     7,     8,    33,    10,    12,    33,   124,    14,    15,
      16,    17,    18,    19,    11,     5,     6,    62,    63,    64,
       7,     8,    12,    29,    30,    34,    32,    14,    15,    16,
      17,    18,    19,    35,     3,    11,     3,     6,    33,     7,
       8,    10,    29,    30,   118,    32,    14,    15,    16,    17,
      18,    19,    21,    34,    23,    34,    25,    26,    -1,    28,
       3,    29,    30,     6,    32,     7,    65,    10,    34,     5,
       6,     4,    14,    15,    16,    17,    12,    10,    21,    12,
      23,    -1,    25,    26,    -1,    28,     5,     6,     5,     6,
      32,    -1,    11,    -1,    11,     5,     6,     5,     6,     5,
       6,    11,    -1,    11,    -1,    11
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     6,     9,    10,    13,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    37,    38,    39,    40,    41,
      44,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,     4,    10,    21,     3,    47,    10,    47,
      10,    10,    10,     3,    10,    48,    50,     0,    38,     5,
       6,    12,    18,    19,     7,    14,    15,    16,    17,    32,
       5,     6,     8,    29,    30,    31,     3,    47,    45,    47,
      11,    47,    12,    47,    11,    47,    10,    47,    50,    50,
      48,    48,    50,    50,    50,    50,    50,    50,    51,    51,
      52,    52,    52,    33,    54,     4,    10,    12,    12,    11,
      35,    11,    11,    11,    45,    11,    38,    47,    42,    43,
      57,    45,    33,    12,    33,    11,    34,    12,    35,    11,
       3,    38,    38,    43,    33,    34,    34,    38,    34
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    36,    37,    38,    38,    38,    39,    39,    39,    39,
      39,    39,    39,    40,    41,    41,    42,    43,    43,    43,
      44,    45,    45,    45,    46,    47,    47,    47,    47,    47,
      47,    47,    48,    48,    48,    48,    48,    48,    49,    49,
      49,    49,    49,    49,    49,    50,    50,    50,    51,    51,
      51,    51,    52,    52,    52,    52,    52,    52,    53,    54,
      54,    54,    55,    55,    56,    56,    57,    57
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     2,     0,     1,     1,     1,     1,
       1,     1,     2,     8,     5,     3,     2,     1,     3,     0,
       5,     1,     3,     0,     3,     1,     1,     4,     3,     1,
       3,     3,     2,     1,     1,     3,     3,     1,     3,     3,
       3,     3,     3,     3,     1,     3,     3,     1,     3,     3,
       3,     1,     1,     1,     2,     3,     4,     1,     4,     7,
       3,     5,     1,     7,     3,     2,     1,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        YY_LAC_DISCARD ("YYBACKUP");                              \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


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




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
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
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
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
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
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


/* Given a state stack such that *YYBOTTOM is its bottom, such that
   *YYTOP is either its top or is YYTOP_EMPTY to indicate an empty
   stack, and such that *YYCAPACITY is the maximum number of elements it
   can hold without a reallocation, make sure there is enough room to
   store YYADD more elements.  If not, allocate a new stack using
   YYSTACK_ALLOC, copy the existing elements, and adjust *YYBOTTOM,
   *YYTOP, and *YYCAPACITY to reflect the new capacity and memory
   location.  If *YYBOTTOM != YYBOTTOM_NO_FREE, then free the old stack
   using YYSTACK_FREE.  Return 0 if successful or if no reallocation is
   required.  Return YYENOMEM if memory is exhausted.  */
static int
yy_lac_stack_realloc (YYPTRDIFF_T *yycapacity, YYPTRDIFF_T yyadd,
#if YYDEBUG
                      char const *yydebug_prefix,
                      char const *yydebug_suffix,
#endif
                      yy_state_t **yybottom,
                      yy_state_t *yybottom_no_free,
                      yy_state_t **yytop, yy_state_t *yytop_empty)
{
  YYPTRDIFF_T yysize_old =
    *yytop == yytop_empty ? 0 : *yytop - *yybottom + 1;
  YYPTRDIFF_T yysize_new = yysize_old + yyadd;
  if (*yycapacity < yysize_new)
    {
      YYPTRDIFF_T yyalloc = 2 * yysize_new;
      yy_state_t *yybottom_new;
      /* Use YYMAXDEPTH for maximum stack size given that the stack
         should never need to grow larger than the main state stack
         needs to grow without LAC.  */
      if (YYMAXDEPTH < yysize_new)
        {
          YYDPRINTF ((stderr, "%smax size exceeded%s", yydebug_prefix,
                      yydebug_suffix));
          return YYENOMEM;
        }
      if (YYMAXDEPTH < yyalloc)
        yyalloc = YYMAXDEPTH;
      yybottom_new =
        YY_CAST (yy_state_t *,
                 YYSTACK_ALLOC (YY_CAST (YYSIZE_T,
                                         yyalloc * YYSIZEOF (*yybottom_new))));
      if (!yybottom_new)
        {
          YYDPRINTF ((stderr, "%srealloc failed%s", yydebug_prefix,
                      yydebug_suffix));
          return YYENOMEM;
        }
      if (*yytop != yytop_empty)
        {
          YYCOPY (yybottom_new, *yybottom, yysize_old);
          *yytop = yybottom_new + (yysize_old - 1);
        }
      if (*yybottom != yybottom_no_free)
        YYSTACK_FREE (*yybottom);
      *yybottom = yybottom_new;
      *yycapacity = yyalloc;
    }
  return 0;
}

/* Establish the initial context for the current lookahead if no initial
   context is currently established.

   We define a context as a snapshot of the parser stacks.  We define
   the initial context for a lookahead as the context in which the
   parser initially examines that lookahead in order to select a
   syntactic action.  Thus, if the lookahead eventually proves
   syntactically unacceptable (possibly in a later context reached via a
   series of reductions), the initial context can be used to determine
   the exact set of tokens that would be syntactically acceptable in the
   lookahead's place.  Moreover, it is the context after which any
   further semantic actions would be erroneous because they would be
   determined by a syntactically unacceptable token.

   YY_LAC_ESTABLISH should be invoked when a reduction is about to be
   performed in an inconsistent state (which, for the purposes of LAC,
   includes consistent states that don't know they're consistent because
   their default reductions have been disabled).  Iff there is a
   lookahead token, it should also be invoked before reporting a syntax
   error.  This latter case is for the sake of the debugging output.

   For parse.lac=full, the implementation of YY_LAC_ESTABLISH is as
   follows.  If no initial context is currently established for the
   current lookahead, then check if that lookahead can eventually be
   shifted if syntactic actions continue from the current context.
   Report a syntax error if it cannot.  */
#define YY_LAC_ESTABLISH                                                \
do {                                                                    \
  if (!yy_lac_established)                                              \
    {                                                                   \
      YYDPRINTF ((stderr,                                               \
                  "LAC: initial context established for %s\n",          \
                  yysymbol_name (yytoken)));                            \
      yy_lac_established = 1;                                           \
      switch (yy_lac (yyesa, &yyes, &yyes_capacity, yyssp, yytoken))    \
        {                                                               \
        case YYENOMEM:                                                  \
          YYNOMEM;                                                      \
        case 1:                                                         \
          goto yyerrlab;                                                \
        }                                                               \
    }                                                                   \
} while (0)

/* Discard any previous initial lookahead context because of Event,
   which may be a lookahead change or an invalidation of the currently
   established initial context for the current lookahead.

   The most common example of a lookahead change is a shift.  An example
   of both cases is syntax error recovery.  That is, a syntax error
   occurs when the lookahead is syntactically erroneous for the
   currently established initial context, so error recovery manipulates
   the parser stacks to try to find a new initial context in which the
   current lookahead is syntactically acceptable.  If it fails to find
   such a context, it discards the lookahead.  */
#if YYDEBUG
# define YY_LAC_DISCARD(Event)                                           \
do {                                                                     \
  if (yy_lac_established)                                                \
    {                                                                    \
      YYDPRINTF ((stderr, "LAC: initial context discarded due to "       \
                  Event "\n"));                                          \
      yy_lac_established = 0;                                            \
    }                                                                    \
} while (0)
#else
# define YY_LAC_DISCARD(Event) yy_lac_established = 0
#endif

/* Given the stack whose top is *YYSSP, return 0 iff YYTOKEN can
   eventually (after perhaps some reductions) be shifted, return 1 if
   not, or return YYENOMEM if memory is exhausted.  As preconditions and
   postconditions: *YYES_CAPACITY is the allocated size of the array to
   which *YYES points, and either *YYES = YYESA or *YYES points to an
   array allocated with YYSTACK_ALLOC.  yy_lac may overwrite the
   contents of either array, alter *YYES and *YYES_CAPACITY, and free
   any old *YYES other than YYESA.  */
static int
yy_lac (yy_state_t *yyesa, yy_state_t **yyes,
        YYPTRDIFF_T *yyes_capacity, yy_state_t *yyssp, yysymbol_kind_t yytoken)
{
  yy_state_t *yyes_prev = yyssp;
  yy_state_t *yyesp = yyes_prev;
  /* Reduce until we encounter a shift and thereby accept the token.  */
  YYDPRINTF ((stderr, "LAC: checking lookahead %s:", yysymbol_name (yytoken)));
  if (yytoken == YYSYMBOL_YYUNDEF)
    {
      YYDPRINTF ((stderr, " Always Err\n"));
      return 1;
    }
  while (1)
    {
      int yyrule = yypact[+*yyesp];
      if (yypact_value_is_default (yyrule)
          || (yyrule += yytoken) < 0 || YYLAST < yyrule
          || yycheck[yyrule] != yytoken)
        {
          /* Use the default action.  */
          yyrule = yydefact[+*yyesp];
          if (yyrule == 0)
            {
              YYDPRINTF ((stderr, " Err\n"));
              return 1;
            }
        }
      else
        {
          /* Use the action from yytable.  */
          yyrule = yytable[yyrule];
          if (yytable_value_is_error (yyrule))
            {
              YYDPRINTF ((stderr, " Err\n"));
              return 1;
            }
          if (0 < yyrule)
            {
              YYDPRINTF ((stderr, " S%d\n", yyrule));
              return 0;
            }
          yyrule = -yyrule;
        }
      /* By now we know we have to simulate a reduce.  */
      YYDPRINTF ((stderr, " R%d", yyrule - 1));
      {
        /* Pop the corresponding number of values from the stack.  */
        YYPTRDIFF_T yylen = yyr2[yyrule];
        /* First pop from the LAC stack as many tokens as possible.  */
        if (yyesp != yyes_prev)
          {
            YYPTRDIFF_T yysize = yyesp - *yyes + 1;
            if (yylen < yysize)
              {
                yyesp -= yylen;
                yylen = 0;
              }
            else
              {
                yyesp = yyes_prev;
                yylen -= yysize;
              }
          }
        /* Only afterwards look at the main stack.  */
        if (yylen)
          yyesp = yyes_prev -= yylen;
      }
      /* Push the resulting state of the reduction.  */
      {
        yy_state_fast_t yystate;
        {
          const int yylhs = yyr1[yyrule] - YYNTOKENS;
          const int yyi = yypgoto[yylhs] + *yyesp;
          yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyesp
                     ? yytable[yyi]
                     : yydefgoto[yylhs]);
        }
        if (yyesp == yyes_prev)
          {
            yyesp = *yyes;
            YY_IGNORE_USELESS_CAST_BEGIN
            *yyesp = YY_CAST (yy_state_t, yystate);
            YY_IGNORE_USELESS_CAST_END
          }
        else
          {
            if (yy_lac_stack_realloc (yyes_capacity, 1,
#if YYDEBUG
                                      " (", ")",
#endif
                                      yyes, yyesa, &yyesp, yyes_prev))
              {
                YYDPRINTF ((stderr, "\n"));
                return YYENOMEM;
              }
            YY_IGNORE_USELESS_CAST_BEGIN
            *++yyesp = YY_CAST (yy_state_t, yystate);
            YY_IGNORE_USELESS_CAST_END
          }
        YYDPRINTF ((stderr, " G%d", yystate));
      }
    }
}

/* Context of a parse error.  */
typedef struct
{
  yy_state_t *yyssp;
  yy_state_t *yyesa;
  yy_state_t **yyes;
  YYPTRDIFF_T *yyes_capacity;
  yysymbol_kind_t yytoken;
} yypcontext_t;

/* Put in YYARG at most YYARGN of the expected tokens given the
   current YYCTX, and return the number of tokens stored in YYARG.  If
   YYARG is null, return the number of expected tokens (guaranteed to
   be less than YYNTOKENS).  Return YYENOMEM on memory exhaustion.
   Return 0 if there are more than YYARGN expected tokens, yet fill
   YYARG up to YYARGN. */
static int
yypcontext_expected_tokens (const yypcontext_t *yyctx,
                            yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;

  int yyx;
  for (yyx = 0; yyx < YYNTOKENS; ++yyx)
    {
      yysymbol_kind_t yysym = YY_CAST (yysymbol_kind_t, yyx);
      if (yysym != YYSYMBOL_YYerror && yysym != YYSYMBOL_YYUNDEF)
        switch (yy_lac (yyctx->yyesa, yyctx->yyes, yyctx->yyes_capacity, yyctx->yyssp, yysym))
          {
          case YYENOMEM:
            return YYENOMEM;
          case 1:
            continue;
          default:
            if (!yyarg)
              ++yycount;
            else if (yycount == yyargn)
              return 0;
            else
              yyarg[yycount++] = yysym;
          }
    }
  if (yyarg && yycount == 0 && 0 < yyargn)
    yyarg[0] = YYSYMBOL_YYEMPTY;
  return yycount;
}




#ifndef yystrlen
# if defined __GLIBC__ && defined _STRING_H
#  define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
# else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
# endif
#endif

#ifndef yystpcpy
# if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#  define yystpcpy stpcpy
# else
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
# endif
#endif



static int
yy_syntax_error_arguments (const yypcontext_t *yyctx,
                           yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
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
       In the first two cases, it might appear that the current syntax
       error should have been detected in the previous state when yy_lac
       was invoked.  However, at that time, there might have been a
       different syntax error that discarded a different initial context
       during error recovery, leaving behind the current lookahead.
  */
  if (yyctx->yytoken != YYSYMBOL_YYEMPTY)
    {
      int yyn;
      YYDPRINTF ((stderr, "Constructing syntax error message\n"));
      if (yyarg)
        yyarg[yycount] = yyctx->yytoken;
      ++yycount;
      yyn = yypcontext_expected_tokens (yyctx,
                                        yyarg ? yyarg + 1 : yyarg, yyargn - 1);
      if (yyn == YYENOMEM)
        return YYENOMEM;
      else if (yyn == 0)
        YYDPRINTF ((stderr, "No expected tokens.\n"));
      else
        yycount += yyn;
    }
  return yycount;
}

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.  In order to see if a particular token T is a
   valid looakhead, invoke yy_lac (YYESA, YYES, YYES_CAPACITY, YYSSP, T).

   Return 0 if *YYMSG was successfully written.  Return -1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return YYENOMEM if the
   required number of bytes is too large to store or if
   yy_lac returned YYENOMEM.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                const yypcontext_t *yyctx)
{
  enum { YYARGS_MAX = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  yysymbol_kind_t yyarg[YYARGS_MAX];
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* Actual size of YYARG. */
  int yycount = yy_syntax_error_arguments (yyctx, yyarg, YYARGS_MAX);
  if (yycount == YYENOMEM)
    return YYENOMEM;

  switch (yycount)
    {
#define YYCASE_(N, S)                       \
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
#undef YYCASE_
    }

  /* Compute error message size.  Don't count the "%s"s, but reserve
     room for the terminator.  */
  yysize = yystrlen (yyformat) - 2 * yycount + 1;
  {
    int yyi;
    for (yyi = 0; yyi < yycount; ++yyi)
      {
        YYPTRDIFF_T yysize1
          = yysize + yystrlen (yysymbol_name (yyarg[yyi]));
        if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
          yysize = yysize1;
        else
          return YYENOMEM;
      }
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return -1;
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
          yyp = yystpcpy (yyp, yysymbol_name (yyarg[yyi++]));
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


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
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
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

    yy_state_t yyesa[20];
    yy_state_t *yyes = yyesa;
    YYPTRDIFF_T yyes_capacity = 20 < YYMAXDEPTH ? 20 : YYMAXDEPTH;

  /* Whether LAC context is established.  A Boolean.  */
  int yy_lac_established = 0;
  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

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
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
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
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
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

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= FIN)
    {
      yychar = FIN;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
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
    {
      YY_LAC_ESTABLISH;
      goto yydefault;
    }
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      YY_LAC_ESTABLISH;
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
  YY_LAC_DISCARD ("shift");
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
  {
    int yychar_backup = yychar;
    switch (yyn)
      {
  case 2: /* prog: listeInstructions  */
#line 106 "analyse_syntaxique.y"
                      { arbre_abstrait = creer_n_programme((yyvsp[0].l_inst)); }
#line 1679 "analyse_syntaxique.c"
    break;

  case 3: /* listeInstructions: instruction  */
#line 109 "analyse_syntaxique.y"
                {
        (yyval.l_inst) =creer_n_l_instructions((yyvsp[0].inst) ,NULL);
    }
#line 1687 "analyse_syntaxique.c"
    break;

  case 4: /* listeInstructions: instruction listeInstructions  */
#line 112 "analyse_syntaxique.y"
                                      {
        (yyval.l_inst) =creer_n_l_instructions((yyvsp[-1].inst) ,(yyvsp[0].l_inst));
    }
#line 1695 "analyse_syntaxique.c"
    break;

  case 5: /* listeInstructions: %empty  */
#line 115 "analyse_syntaxique.y"
        { (yyval.l_inst) = NULL; }
#line 1701 "analyse_syntaxique.c"
    break;

  case 6: /* instruction: declarationVariable  */
#line 119 "analyse_syntaxique.y"
                            { (yyval.inst) = (yyvsp[0].inst); }
#line 1707 "analyse_syntaxique.c"
    break;

  case 7: /* instruction: fonction  */
#line 120 "analyse_syntaxique.y"
                 { (yyval.inst) = (yyvsp[0].inst); }
#line 1713 "analyse_syntaxique.c"
    break;

  case 8: /* instruction: affectation  */
#line 121 "analyse_syntaxique.y"
                    { (yyval.inst) = (yyvsp[0].inst); }
#line 1719 "analyse_syntaxique.c"
    break;

  case 9: /* instruction: ecrire  */
#line 122 "analyse_syntaxique.y"
               { (yyval.inst) =(yyvsp[0].inst); }
#line 1725 "analyse_syntaxique.c"
    break;

  case 10: /* instruction: retourner  */
#line 123 "analyse_syntaxique.y"
                  { (yyval.inst) = (yyvsp[0].inst); }
#line 1731 "analyse_syntaxique.c"
    break;

  case 11: /* instruction: cond  */
#line 124 "analyse_syntaxique.y"
             { (yyval.inst) = (yyvsp[0].inst); }
#line 1737 "analyse_syntaxique.c"
    break;

  case 12: /* instruction: expr POINT_VIRGULE  */
#line 125 "analyse_syntaxique.y"
                           { (yyval.inst) = creer_n_instruction((yyvsp[-1].exp)); }
#line 1743 "analyse_syntaxique.c"
    break;

  case 13: /* fonction: type IDENTIFIANT PARENTHESE_OUVRANTE list_parms PARENTHESE_FERMANTE BLOC_OUVRANT listeInstructions BLOC_FERMANT  */
#line 128 "analyse_syntaxique.y"
                                                                                                                    { (yyval.inst) = creer_n_fonction((yyvsp[-7].string), (yyvsp[-6].string), (yyvsp[-4].l_parm), (yyvsp[-1].l_inst)); }
#line 1749 "analyse_syntaxique.c"
    break;

  case 14: /* declarationVariable: type IDENTIFIANT EGALE expr POINT_VIRGULE  */
#line 132 "analyse_syntaxique.y"
                                                  { (yyval.inst) = creer_n_declaration((yyvsp[-4].string), (yyvsp[-3].string), (yyvsp[-1].exp)); }
#line 1755 "analyse_syntaxique.c"
    break;

  case 15: /* declarationVariable: type IDENTIFIANT POINT_VIRGULE  */
#line 133 "analyse_syntaxique.y"
                                       { (yyval.inst) = creer_n_declaration((yyvsp[-2].string), (yyvsp[-1].string), NULL); }
#line 1761 "analyse_syntaxique.c"
    break;

  case 16: /* parms: type IDENTIFIANT  */
#line 137 "analyse_syntaxique.y"
                     { (yyval.parm) = creer_parm((yyvsp[-1].string), (yyvsp[0].string)); }
#line 1767 "analyse_syntaxique.c"
    break;

  case 17: /* list_parms: parms  */
#line 141 "analyse_syntaxique.y"
              { (yyval.l_parm) = creerListeParm((yyvsp[0].parm)); }
#line 1773 "analyse_syntaxique.c"
    break;

  case 18: /* list_parms: parms VIRGULE list_parms  */
#line 142 "analyse_syntaxique.y"
                                 { (yyval.l_parm) = ajouterListeParm((yyvsp[0].l_parm), (yyvsp[-2].parm)); }
#line 1779 "analyse_syntaxique.c"
    break;

  case 19: /* list_parms: %empty  */
#line 143 "analyse_syntaxique.y"
        { (yyval.l_parm) = NULL; }
#line 1785 "analyse_syntaxique.c"
    break;

  case 20: /* ecrire: ECRIRE PARENTHESE_OUVRANTE expr PARENTHESE_FERMANTE POINT_VIRGULE  */
#line 146 "analyse_syntaxique.y"
                                                                          {
	
	(yyval.inst) =creer_n_ecrire((yyvsp[-2].exp));
}
#line 1794 "analyse_syntaxique.c"
    break;

  case 21: /* liste_expr: expr  */
#line 152 "analyse_syntaxique.y"
                { (yyval.l_exp) = creerListeExpr((yyvsp[0].exp)); }
#line 1800 "analyse_syntaxique.c"
    break;

  case 22: /* liste_expr: expr VIRGULE liste_expr  */
#line 153 "analyse_syntaxique.y"
                                { (yyval.l_exp) = ajouterListe((yyvsp[0].l_exp), (yyvsp[-2].exp)); }
#line 1806 "analyse_syntaxique.c"
    break;

  case 23: /* liste_expr: %empty  */
#line 154 "analyse_syntaxique.y"
        { (yyval.l_exp) = NULL; }
#line 1812 "analyse_syntaxique.c"
    break;

  case 24: /* lire: LIRE PARENTHESE_OUVRANTE PARENTHESE_FERMANTE  */
#line 157 "analyse_syntaxique.y"
                                                    { (yyval.exp) = creer_n_lire(); }
#line 1818 "analyse_syntaxique.c"
    break;

  case 25: /* expr: logique  */
#line 161 "analyse_syntaxique.y"
            { (yyval.exp) = (yyvsp[0].exp); }
#line 1824 "analyse_syntaxique.c"
    break;

  case 26: /* expr: terme  */
#line 162 "analyse_syntaxique.y"
              { (yyval.exp) = (yyvsp[0].exp); }
#line 1830 "analyse_syntaxique.c"
    break;

  case 27: /* expr: IDENTIFIANT PARENTHESE_OUVRANTE liste_expr PARENTHESE_FERMANTE  */
#line 163 "analyse_syntaxique.y"
                                                                       { (yyval.exp) = creer_n_appel_fonction((yyvsp[-3].string), creer_n_liste_expr((yyvsp[-1].l_exp))); }
#line 1836 "analyse_syntaxique.c"
    break;

  case 28: /* expr: PARENTHESE_OUVRANTE expr PARENTHESE_FERMANTE  */
#line 164 "analyse_syntaxique.y"
                                                     { (yyval.exp) = (yyvsp[-1].exp); }
#line 1842 "analyse_syntaxique.c"
    break;

  case 29: /* expr: IDENTIFIANT  */
#line 165 "analyse_syntaxique.y"
                    { (yyval.exp) = creer_n_identifiant((yyvsp[0].string)); }
#line 1848 "analyse_syntaxique.c"
    break;

  case 30: /* expr: expr PLUS terme  */
#line 166 "analyse_syntaxique.y"
                        { (yyval.exp) = creer_n_operation("+", (yyvsp[-2].exp), (yyvsp[0].exp)); }
#line 1854 "analyse_syntaxique.c"
    break;

  case 31: /* expr: expr MOINS terme  */
#line 167 "analyse_syntaxique.y"
                         { (yyval.exp) = creer_n_operation("-", (yyvsp[-2].exp), (yyvsp[0].exp)); }
#line 1860 "analyse_syntaxique.c"
    break;

  case 32: /* logique: NON logique  */
#line 171 "analyse_syntaxique.y"
                { (yyval.exp) = creer_n_non((yyvsp[0].exp)); }
#line 1866 "analyse_syntaxique.c"
    break;

  case 33: /* logique: FAUX  */
#line 172 "analyse_syntaxique.y"
             { (yyval.exp) = creer_n_booleen(0); }
#line 1872 "analyse_syntaxique.c"
    break;

  case 34: /* logique: VRAI  */
#line 173 "analyse_syntaxique.y"
             { (yyval.exp) = creer_n_booleen(1); }
#line 1878 "analyse_syntaxique.c"
    break;

  case 35: /* logique: logique ET logique  */
#line 174 "analyse_syntaxique.y"
                           { (yyval.exp) = creer_n_operation("ET", (yyvsp[-2].exp), (yyvsp[0].exp)); }
#line 1884 "analyse_syntaxique.c"
    break;

  case 36: /* logique: logique OU logique  */
#line 175 "analyse_syntaxique.y"
                           { (yyval.exp) = creer_n_operation("OU", (yyvsp[-2].exp), (yyvsp[0].exp)); }
#line 1890 "analyse_syntaxique.c"
    break;

  case 37: /* logique: comparaison  */
#line 176 "analyse_syntaxique.y"
                    { (yyval.exp) = (yyvsp[0].exp); }
#line 1896 "analyse_syntaxique.c"
    break;

  case 38: /* comparaison: comparaison LT terme  */
#line 181 "analyse_syntaxique.y"
                         { (yyval.exp) = creer_n_operation("<", (yyvsp[-2].exp), (yyvsp[0].exp)); }
#line 1902 "analyse_syntaxique.c"
    break;

  case 39: /* comparaison: comparaison LE terme  */
#line 182 "analyse_syntaxique.y"
                           { (yyval.exp) = creer_n_operation("<=", (yyvsp[-2].exp), (yyvsp[0].exp)); }
#line 1908 "analyse_syntaxique.c"
    break;

  case 40: /* comparaison: comparaison GT terme  */
#line 183 "analyse_syntaxique.y"
                           { (yyval.exp) = creer_n_operation(">", (yyvsp[-2].exp), (yyvsp[0].exp)); }
#line 1914 "analyse_syntaxique.c"
    break;

  case 41: /* comparaison: comparaison GE terme  */
#line 184 "analyse_syntaxique.y"
                           { (yyval.exp) = creer_n_operation(">=", (yyvsp[-2].exp), (yyvsp[0].exp)); }
#line 1920 "analyse_syntaxique.c"
    break;

  case 42: /* comparaison: comparaison EQ terme  */
#line 185 "analyse_syntaxique.y"
                           { (yyval.exp) = creer_n_operation("==", (yyvsp[-2].exp), (yyvsp[0].exp)); }
#line 1926 "analyse_syntaxique.c"
    break;

  case 43: /* comparaison: comparaison DIFFERENT terme  */
#line 186 "analyse_syntaxique.y"
                                  { (yyval.exp) = creer_n_operation("!=", (yyvsp[-2].exp), (yyvsp[0].exp)); }
#line 1932 "analyse_syntaxique.c"
    break;

  case 44: /* comparaison: terme  */
#line 187 "analyse_syntaxique.y"
            { (yyval.exp) = (yyvsp[0].exp); }
#line 1938 "analyse_syntaxique.c"
    break;

  case 45: /* terme: terme PLUS produit  */
#line 191 "analyse_syntaxique.y"
                       { (yyval.exp) = creer_n_operation("+", (yyvsp[-2].exp), (yyvsp[0].exp)); }
#line 1944 "analyse_syntaxique.c"
    break;

  case 46: /* terme: terme MOINS produit  */
#line 192 "analyse_syntaxique.y"
                            { (yyval.exp) = creer_n_operation("-", (yyvsp[-2].exp), (yyvsp[0].exp)); }
#line 1950 "analyse_syntaxique.c"
    break;

  case 47: /* terme: produit  */
#line 193 "analyse_syntaxique.y"
                { (yyval.exp) = (yyvsp[0].exp); }
#line 1956 "analyse_syntaxique.c"
    break;

  case 48: /* produit: produit FOIS facteur  */
#line 197 "analyse_syntaxique.y"
                         { (yyval.exp) = creer_n_operation("*", (yyvsp[-2].exp), (yyvsp[0].exp)); }
#line 1962 "analyse_syntaxique.c"
    break;

  case 49: /* produit: produit DIVISER facteur  */
#line 198 "analyse_syntaxique.y"
                              { (yyval.exp) = creer_n_operation("/", (yyvsp[-2].exp), (yyvsp[0].exp)); }
#line 1968 "analyse_syntaxique.c"
    break;

  case 50: /* produit: produit MODULO facteur  */
#line 199 "analyse_syntaxique.y"
                             { (yyval.exp) = creer_n_operation("%", (yyvsp[-2].exp), (yyvsp[0].exp)); }
#line 1974 "analyse_syntaxique.c"
    break;

  case 51: /* produit: facteur  */
#line 200 "analyse_syntaxique.y"
              { (yyval.exp) = (yyvsp[0].exp); }
#line 1980 "analyse_syntaxique.c"
    break;

  case 52: /* facteur: ENTIER  */
#line 204 "analyse_syntaxique.y"
           { (yyval.exp) = creer_n_entier((yyvsp[0].entier)); }
#line 1986 "analyse_syntaxique.c"
    break;

  case 53: /* facteur: IDENTIFIANT  */
#line 205 "analyse_syntaxique.y"
                  { (yyval.exp) = creer_n_identifiant((yyvsp[0].string)); }
#line 1992 "analyse_syntaxique.c"
    break;

  case 54: /* facteur: MOINS ENTIER  */
#line 206 "analyse_syntaxique.y"
                   { (yyval.exp) = creer_n_entier(-(yyvsp[0].entier)); }
#line 1998 "analyse_syntaxique.c"
    break;

  case 55: /* facteur: PARENTHESE_OUVRANTE expr PARENTHESE_FERMANTE  */
#line 207 "analyse_syntaxique.y"
                                                   { (yyval.exp) = (yyvsp[-1].exp); }
#line 2004 "analyse_syntaxique.c"
    break;

  case 56: /* facteur: IDENTIFIANT PARENTHESE_OUVRANTE liste_expr PARENTHESE_FERMANTE  */
#line 208 "analyse_syntaxique.y"
                                                                     { (yyval.exp) = creer_n_appel_fonction((yyvsp[-3].string), creer_n_liste_expr((yyvsp[-1].l_exp))); }
#line 2010 "analyse_syntaxique.c"
    break;

  case 57: /* facteur: lire  */
#line 209 "analyse_syntaxique.y"
           { (yyval.exp) = (yyvsp[0].exp); }
#line 2016 "analyse_syntaxique.c"
    break;

  case 58: /* affectation: IDENTIFIANT EGALE expr POINT_VIRGULE  */
#line 214 "analyse_syntaxique.y"
                                         { (yyval.inst) = creer_n_affectation((yyvsp[-3].string), (yyvsp[-1].exp)); }
#line 2022 "analyse_syntaxique.c"
    break;

  case 59: /* conditionSi: SI PARENTHESE_OUVRANTE expr PARENTHESE_FERMANTE BLOC_OUVRANT listeInstructions BLOC_FERMANT  */
#line 218 "analyse_syntaxique.y"
                                                                                                    { (yyval.l_exp) = creerListeExpr(creer_n_condition(0, (yyvsp[-4].exp), (yyvsp[-1].l_inst))); }
#line 2028 "analyse_syntaxique.c"
    break;

  case 60: /* conditionSi: conditionSi SINON conditionSi  */
#line 219 "analyse_syntaxique.y"
                                      { 
        (yyvsp[0].l_exp)->value->u.condition->type = 1;  // met le type a 1 pour dire que c'est un sinon si
        (yyval.l_exp) = ajouterListeElementList((yyvsp[0].l_exp), (yyvsp[-2].l_exp)); 
    }
#line 2037 "analyse_syntaxique.c"
    break;

  case 61: /* conditionSi: conditionSi SINON BLOC_OUVRANT listeInstructions BLOC_FERMANT  */
#line 223 "analyse_syntaxique.y"
                                                                       { 
        (yyval.l_exp) = creerListeExpr(creer_n_condition(2, NULL, (yyvsp[-1].l_inst))); // met le type a 2 pour dire que c'est un sinon
        (yyval.l_exp) = ajouterListeElementList((yyval.l_exp), (yyvsp[-4].l_exp));
    }
#line 2046 "analyse_syntaxique.c"
    break;

  case 62: /* cond: conditionSi  */
#line 230 "analyse_syntaxique.y"
                    { (yyval.inst) = creer_n_cond((yyvsp[0].l_exp)); }
#line 2052 "analyse_syntaxique.c"
    break;

  case 63: /* cond: TANTQUE PARENTHESE_OUVRANTE expr PARENTHESE_FERMANTE BLOC_OUVRANT listeInstructions BLOC_FERMANT  */
#line 231 "analyse_syntaxique.y"
                                                                                                         {
        (yyval.inst) = creer_n_cond(creerListeExpr(creer_n_condition(3, (yyvsp[-4].exp), (yyvsp[-1].l_inst))));
    }
#line 2060 "analyse_syntaxique.c"
    break;

  case 64: /* retourner: RETOURNER expr POINT_VIRGULE  */
#line 237 "analyse_syntaxique.y"
                                     { (yyval.inst) = creer_n_retourner((yyvsp[-1].exp)); }
#line 2066 "analyse_syntaxique.c"
    break;

  case 65: /* retourner: RETOURNER expr  */
#line 238 "analyse_syntaxique.y"
                       { (yyval.inst) = creer_n_retourner((yyvsp[0].exp)); }
#line 2072 "analyse_syntaxique.c"
    break;

  case 66: /* type: TYPE_ENTIER  */
#line 242 "analyse_syntaxique.y"
                            { (yyval.string) = "ENTIER"; }
#line 2078 "analyse_syntaxique.c"
    break;

  case 67: /* type: TYPE_BOOLEEN  */
#line 243 "analyse_syntaxique.y"
                        { (yyval.string) = "BOOLEEN"; }
#line 2084 "analyse_syntaxique.c"
    break;


#line 2088 "analyse_syntaxique.c"

        default: break;
      }
    if (yychar_backup != yychar)
      YY_LAC_DISCARD ("yychar change");
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
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

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
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      {
        yypcontext_t yyctx
          = {yyssp, yyesa, &yyes, &yyes_capacity, yytoken};
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        if (yychar != YYEMPTY)
          YY_LAC_ESTABLISH;
        yysyntax_error_status = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == -1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *,
                             YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (yymsg)
              {
                yysyntax_error_status
                  = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
                yymsgp = yymsg;
              }
            else
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = YYENOMEM;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == YYENOMEM)
          YYNOMEM;
      }
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= FIN)
        {
          /* Return failure if at end of input.  */
          if (yychar == FIN)
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
  ++yynerrs;

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

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  /* If the stack popping above didn't lose the initial context for the
     current lookahead token, the shift below will for sure.  */
  YY_LAC_DISCARD ("error recovery");

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
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
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  if (yyes != yyesa)
    YYSTACK_FREE (yyes);
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
  return yyresult;
}

#line 247 "analyse_syntaxique.y"


int yyerror(const char *s) {
    printf("yyerror : %s\n",s);
    return 0;
}

