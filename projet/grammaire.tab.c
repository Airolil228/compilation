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
#line 1 "grammaire.y"

        #include <stdio.h>
        #include <stdlib.h>
        #include "include/semantique.h"
        #include "include/tab_repres.h"

        /*Anas Yaccine Vasily Benedict */
        int yylex();
        int yyerror(char *s); 

        extern int yylineno;      // Nécessaire pour afficher le numéro de ligne
        extern char *yytext;      // Nécessaire pour afficher le token
        extern FILE *yyin;        // IMPORTANT: source du lexer
        
        int nb_champs;                                
        int index_nb_champs ;  // Index de départ pour la structure dans tab_repres
        

#line 90 "grammaire.tab.c"

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

#include "grammaire.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_PROG = 3,                       /* PROG  */
  YYSYMBOL_POINT_VIRG = 4,                 /* POINT_VIRG  */
  YYSYMBOL_POINT = 5,                      /* POINT  */
  YYSYMBOL_DEBUT = 6,                      /* DEBUT  */
  YYSYMBOL_FIN = 7,                        /* FIN  */
  YYSYMBOL_TYPE = 8,                       /* TYPE  */
  YYSYMBOL_DEUX_POINTS = 9,                /* DEUX_POINTS  */
  YYSYMBOL_STRUCT = 10,                    /* STRUCT  */
  YYSYMBOL_FINSTRUCT = 11,                 /* FINSTRUCT  */
  YYSYMBOL_TABLEAU = 12,                   /* TABLEAU  */
  YYSYMBOL_DE = 13,                        /* DE  */
  YYSYMBOL_CROCHET_OUVRANT = 14,           /* CROCHET_OUVRANT  */
  YYSYMBOL_CROCHET_FERMANT = 15,           /* CROCHET_FERMANT  */
  YYSYMBOL_VIRGULE = 16,                   /* VIRGULE  */
  YYSYMBOL_POINT_POINT = 17,               /* POINT_POINT  */
  YYSYMBOL_ENTIER = 18,                    /* ENTIER  */
  YYSYMBOL_REEL = 19,                      /* REEL  */
  YYSYMBOL_BOOLEEN = 20,                   /* BOOLEEN  */
  YYSYMBOL_CARACTERE = 21,                 /* CARACTERE  */
  YYSYMBOL_CHAINE = 22,                    /* CHAINE  */
  YYSYMBOL_VARIABLE = 23,                  /* VARIABLE  */
  YYSYMBOL_PROCEDURE = 24,                 /* PROCEDURE  */
  YYSYMBOL_FONCTION = 25,                  /* FONCTION  */
  YYSYMBOL_RETOURNE = 26,                  /* RETOURNE  */
  YYSYMBOL_PARENTHESE_OUVRANTE = 27,       /* PARENTHESE_OUVRANTE  */
  YYSYMBOL_PARENTHESE_FERMANTE = 28,       /* PARENTHESE_FERMANTE  */
  YYSYMBOL_VIDE = 29,                      /* VIDE  */
  YYSYMBOL_SI = 30,                        /* SI  */
  YYSYMBOL_ALORS = 31,                     /* ALORS  */
  YYSYMBOL_SINON = 32,                     /* SINON  */
  YYSYMBOL_FINSI = 33,                     /* FINSI  */
  YYSYMBOL_TANT_QUE = 34,                  /* TANT_QUE  */
  YYSYMBOL_FAIRE = 35,                     /* FAIRE  */
  YYSYMBOL_FINTANT_QUE = 36,               /* FINTANT_QUE  */
  YYSYMBOL_OPAFF = 37,                     /* OPAFF  */
  YYSYMBOL_PLUS = 38,                      /* PLUS  */
  YYSYMBOL_MOINS = 39,                     /* MOINS  */
  YYSYMBOL_MULT = 40,                      /* MULT  */
  YYSYMBOL_DIV = 41,                       /* DIV  */
  YYSYMBOL_ET = 42,                        /* ET  */
  YYSYMBOL_OU = 43,                        /* OU  */
  YYSYMBOL_NON = 44,                       /* NON  */
  YYSYMBOL_EGALE = 45,                     /* EGALE  */
  YYSYMBOL_DIFFERENT = 46,                 /* DIFFERENT  */
  YYSYMBOL_INFERIEUR = 47,                 /* INFERIEUR  */
  YYSYMBOL_INFERIEUR_EGAL = 48,            /* INFERIEUR_EGAL  */
  YYSYMBOL_SUPERIEUR = 49,                 /* SUPERIEUR  */
  YYSYMBOL_SUPERIEUR_EGAL = 50,            /* SUPERIEUR_EGAL  */
  YYSYMBOL_VRAI = 51,                      /* VRAI  */
  YYSYMBOL_FAUX = 52,                      /* FAUX  */
  YYSYMBOL_IDF = 53,                       /* IDF  */
  YYSYMBOL_CSTE_ENTIERE = 54,              /* CSTE_ENTIERE  */
  YYSYMBOL_CSTE_REEL = 55,                 /* CSTE_REEL  */
  YYSYMBOL_YYACCEPT = 56,                  /* $accept  */
  YYSYMBOL_programme = 57,                 /* programme  */
  YYSYMBOL_corps = 58,                     /* corps  */
  YYSYMBOL_liste_decl = 59,                /* liste_decl  */
  YYSYMBOL_liste_inst = 60,                /* liste_inst  */
  YYSYMBOL_suite_liste_inst = 61,          /* suite_liste_inst  */
  YYSYMBOL_declaration = 62,               /* declaration  */
  YYSYMBOL_declaration_type = 63,          /* declaration_type  */
  YYSYMBOL_64_1 = 64,                      /* $@1  */
  YYSYMBOL_dimension = 65,                 /* dimension  */
  YYSYMBOL_liste_dimensions = 66,          /* liste_dimensions  */
  YYSYMBOL_une_dimension = 67,             /* une_dimension  */
  YYSYMBOL_liste_champs = 68,              /* liste_champs  */
  YYSYMBOL_un_champ = 69,                  /* un_champ  */
  YYSYMBOL_declaration_variable = 70,      /* declaration_variable  */
  YYSYMBOL_nom_type = 71,                  /* nom_type  */
  YYSYMBOL_type_simple = 72,               /* type_simple  */
  YYSYMBOL_declaration_procedure = 73,     /* declaration_procedure  */
  YYSYMBOL_declaration_fonction = 74,      /* declaration_fonction  */
  YYSYMBOL_liste_parametres = 75,          /* liste_parametres  */
  YYSYMBOL_liste_param = 76,               /* liste_param  */
  YYSYMBOL_un_param = 77,                  /* un_param  */
  YYSYMBOL_liste_inst_non_vide = 78,       /* liste_inst_non_vide  */
  YYSYMBOL_suite_liste_inst_non_vide = 79, /* suite_liste_inst_non_vide  */
  YYSYMBOL_instruction = 80,               /* instruction  */
  YYSYMBOL_resultat_retourne = 81,         /* resultat_retourne  */
  YYSYMBOL_appel = 82,                     /* appel  */
  YYSYMBOL_liste_arguments = 83,           /* liste_arguments  */
  YYSYMBOL_liste_args = 84,                /* liste_args  */
  YYSYMBOL_un_arg = 85,                    /* un_arg  */
  YYSYMBOL_condition = 86,                 /* condition  */
  YYSYMBOL_tant_que = 87,                  /* tant_que  */
  YYSYMBOL_affectation = 88,               /* affectation  */
  YYSYMBOL_variable = 89,                  /* variable  */
  YYSYMBOL_expression = 90,                /* expression  */
  YYSYMBOL_expression1 = 91,               /* expression1  */
  YYSYMBOL_expression2 = 92,               /* expression2  */
  YYSYMBOL_expression3 = 93,               /* expression3  */
  YYSYMBOL_expression_booleenne = 94,      /* expression_booleenne  */
  YYSYMBOL_expression_et = 95,             /* expression_et  */
  YYSYMBOL_expression_not = 96,            /* expression_not  */
  YYSYMBOL_expression_comp = 97            /* expression_comp  */
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

#if !defined yyoverflow

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
#endif /* !defined yyoverflow */

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
#define YYFINAL  16
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   179

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  56
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  42
/* YYNRULES -- Number of rules.  */
#define YYNRULES  89
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  175

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   310


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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    48,    48,    51,    52,    55,    56,    59,    62,    63,
      64,    67,    68,    69,    70,    73,    73,    83,    92,    95,
      96,    99,   102,   103,   106,   114,   124,   125,   128,   129,
     130,   131,   132,   135,   142,   145,   146,   149,   150,   153,
     160,   163,   164,   167,   168,   169,   170,   171,   172,   175,
     176,   179,   182,   183,   186,   187,   190,   193,   194,   197,
     200,   204,   205,   206,   209,   210,   213,   214,   215,   218,
     219,   220,   223,   224,   225,   226,   227,   230,   231,   234,
     235,   238,   239,   242,   243,   244,   245,   246,   247,   248
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "PROG", "POINT_VIRG",
  "POINT", "DEBUT", "FIN", "TYPE", "DEUX_POINTS", "STRUCT", "FINSTRUCT",
  "TABLEAU", "DE", "CROCHET_OUVRANT", "CROCHET_FERMANT", "VIRGULE",
  "POINT_POINT", "ENTIER", "REEL", "BOOLEEN", "CARACTERE", "CHAINE",
  "VARIABLE", "PROCEDURE", "FONCTION", "RETOURNE", "PARENTHESE_OUVRANTE",
  "PARENTHESE_FERMANTE", "VIDE", "SI", "ALORS", "SINON", "FINSI",
  "TANT_QUE", "FAIRE", "FINTANT_QUE", "OPAFF", "PLUS", "MOINS", "MULT",
  "DIV", "ET", "OU", "NON", "EGALE", "DIFFERENT", "INFERIEUR",
  "INFERIEUR_EGAL", "SUPERIEUR", "SUPERIEUR_EGAL", "VRAI", "FAUX", "IDF",
  "CSTE_ENTIERE", "CSTE_REEL", "$accept", "programme", "corps",
  "liste_decl", "liste_inst", "suite_liste_inst", "declaration",
  "declaration_type", "$@1", "dimension", "liste_dimensions",
  "une_dimension", "liste_champs", "un_champ", "declaration_variable",
  "nom_type", "type_simple", "declaration_procedure",
  "declaration_fonction", "liste_parametres", "liste_param", "un_param",
  "liste_inst_non_vide", "suite_liste_inst_non_vide", "instruction",
  "resultat_retourne", "appel", "liste_arguments", "liste_args", "un_arg",
  "condition", "tant_que", "affectation", "variable", "expression",
  "expression1", "expression2", "expression3", "expression_booleenne",
  "expression_et", "expression_not", "expression_comp", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-75)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-53)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      14,    80,    33,    32,     4,     6,    21,    34,   -75,    80,
     -75,    86,   -75,   -75,   -75,   -75,   -75,    49,    -2,   125,
     126,   136,   119,   119,   -75,   143,   -75,   -13,   -75,   -13,
     -13,    12,     0,   145,   -75,   -75,   -75,   -75,     8,   -75,
     146,   -75,    46,   -10,   100,    80,   128,   -75,   -13,   -13,
     129,   -75,   -75,   -75,   111,   -75,    74,    52,   -75,   108,
     110,   -75,   -75,    74,    24,    93,   -13,   -75,   -75,   151,
     -75,   104,     9,   -13,   -75,   -75,   144,   -75,   -75,   -75,
     -75,   147,   -75,   -75,   -75,   150,    19,   -75,   -75,   112,
      61,     7,   -75,   -13,     9,     9,     9,     9,     9,     9,
       9,     9,     9,     9,   -13,   -13,   154,   154,    98,   -75,
     -75,   -75,   -75,     9,    10,   -75,   109,   113,   152,   114,
     112,   100,   -75,    80,   -75,   -75,    99,    52,    52,    79,
      79,    79,    79,    79,    79,   -75,   -75,   110,   -75,   105,
     127,   -13,   -75,    56,   -75,   155,    50,   -75,   149,   124,
     -75,   -10,   156,   -75,   -75,   -75,   -75,   154,   -75,   -75,
     -75,   -10,   109,   -75,   115,   -75,   113,   -75,   -75,   137,
     -75,   -75,   -75,   -75,   -75
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     8,     0,     0,     0,     0,     2,     0,
       4,     0,    14,    11,    13,    12,     1,     0,     0,     0,
       0,     0,    35,    35,     3,     0,     5,    49,    47,     0,
       0,    61,     0,     0,    46,    44,    45,    43,     0,     7,
       0,    10,     0,     0,     0,     0,     0,     6,     0,     0,
      61,    74,    75,    48,    73,    50,    64,    68,    71,    65,
      78,    80,    82,     0,     0,     0,     0,    51,    40,     0,
      41,     0,     0,     0,     9,    15,     0,    28,    29,    30,
      31,     0,    27,    25,    26,     0,     0,    37,    33,     0,
       0,     0,    81,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    54,
      56,    42,    63,     0,     0,    60,     0,     0,     0,     0,
       0,     0,    36,     0,    72,    89,     0,    66,    67,    85,
      88,    83,    86,    84,    87,    69,    70,    77,    79,     0,
       0,     0,    53,     0,    62,     0,     0,    22,     0,     0,
      19,     0,     0,    39,    38,    34,    76,     0,    58,    59,
      55,     0,     0,    16,     0,    18,     0,    17,    32,     0,
      24,    23,    21,    20,    57
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -75,   -75,   -42,   -75,    -9,   -75,   163,   -75,   -75,   -75,
     -75,    11,   -75,    13,   -75,   -60,   -74,   -75,   -75,   153,
     -75,    53,   -75,   -75,    64,   -75,   -75,   -75,    85,    38,
     -75,   -75,   -75,    48,   -21,   -28,    47,    41,   -11,    69,
     -45,   -75
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     2,     8,     9,    10,    18,    11,    12,   116,   118,
     149,   150,   146,   147,    13,    83,    84,    14,    15,    45,
      86,    87,    19,    32,    33,    53,    34,    67,   108,   109,
      35,    36,    37,    54,   110,    56,    57,    58,    59,    60,
      61,    62
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      24,    63,    63,    88,    92,    39,    55,    68,    77,    78,
      79,    80,    81,    71,    48,   123,   -52,     1,    64,    65,
      90,    63,    72,   121,    27,   144,    27,    28,    29,    28,
      29,    49,    30,    16,    30,   125,   113,    91,    17,    66,
      50,    51,    52,    82,   114,    73,   153,   122,    94,    95,
     104,    31,   115,    31,   162,   106,    75,    20,    76,    21,
     138,   163,    50,    51,    52,    38,    38,   104,   129,   130,
     131,   132,   133,   134,    22,    27,    63,    63,    28,    29,
      38,   155,    40,    30,   124,   143,     3,    23,     4,   124,
      26,   167,   102,   103,    94,    95,    69,   139,   140,    94,
      95,   170,    31,     5,     6,     7,    96,    97,    98,    99,
     100,   101,    94,    95,   141,   141,    71,    94,    95,    96,
      97,    98,    99,   100,   101,    72,   142,   156,   107,    41,
      77,    78,    79,    80,    81,    42,   104,   157,   158,   165,
     166,   127,   128,   135,   136,    43,    44,    47,   169,    70,
      74,   104,   105,    85,    89,   111,    93,   112,   117,   120,
       3,   119,   145,   159,   161,   151,   164,   148,   152,   172,
     174,   168,    25,   137,   154,   171,    46,   173,   126,   160
};

static const yytype_uint8 yycheck[] =
{
       9,    29,    30,    45,    49,     7,    27,     7,    18,    19,
      20,    21,    22,     5,    27,    89,     4,     3,    29,    30,
      48,    49,    14,     4,    26,    15,    26,    29,    30,    29,
      30,    44,    34,     0,    34,    28,    27,    48,     6,    27,
      53,    54,    55,    53,    72,    37,   120,    28,    38,    39,
      43,    53,    73,    53,     4,    31,    10,    53,    12,    53,
     105,    11,    53,    54,    55,    17,    18,    43,    96,    97,
      98,    99,   100,   101,    53,    26,   104,   105,    29,    30,
      32,   123,    18,    34,    28,   113,     6,    53,     8,    28,
       4,   151,    40,    41,    38,    39,    32,   106,   107,    38,
      39,   161,    53,    23,    24,    25,    45,    46,    47,    48,
      49,    50,    38,    39,    16,    16,     5,    38,    39,    45,
      46,    47,    48,    49,    50,    14,    28,    28,    35,     4,
      18,    19,    20,    21,    22,     9,    43,    32,    33,    15,
      16,    94,    95,   102,   103,     9,    27,     4,   157,     4,
       4,    43,    42,    53,    26,     4,    27,    53,    14,     9,
       6,    14,    53,    36,     9,    13,    17,    54,    54,    54,
      33,    15,     9,   104,   121,   162,    23,   166,    93,   141
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,    57,     6,     8,    23,    24,    25,    58,    59,
      60,    62,    63,    70,    73,    74,     0,     6,    61,    78,
      53,    53,    53,    53,    60,    62,     4,    26,    29,    30,
      34,    53,    79,    80,    82,    86,    87,    88,    89,     7,
      80,     4,     9,     9,    27,    75,    75,     4,    27,    44,
      53,    54,    55,    81,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    91,    94,    94,    27,    83,     7,    80,
       4,     5,    14,    37,     4,    10,    12,    18,    19,    20,
      21,    22,    53,    71,    72,    53,    76,    77,    58,    26,
      91,    94,    96,    27,    38,    39,    45,    46,    47,    48,
      49,    50,    40,    41,    43,    42,    31,    35,    84,    85,
      90,     4,    53,    27,    91,    90,    64,    14,    65,    14,
       9,     4,    28,    72,    28,    28,    84,    92,    92,    91,
      91,    91,    91,    91,    91,    93,    93,    95,    96,    60,
      60,    16,    28,    91,    15,    53,    68,    69,    54,    66,
      67,    13,    54,    72,    77,    58,    28,    32,    33,    36,
      85,     9,     4,    11,    17,    15,    16,    71,    15,    60,
      71,    69,    54,    67,    33
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    56,    57,    58,    58,    59,    59,    60,    61,    61,
      61,    62,    62,    62,    62,    64,    63,    63,    65,    66,
      66,    67,    68,    68,    69,    70,    71,    71,    72,    72,
      72,    72,    72,    73,    74,    75,    75,    76,    76,    77,
      78,    79,    79,    80,    80,    80,    80,    80,    80,    81,
      81,    82,    83,    83,    84,    84,    85,    86,    86,    87,
      88,    89,    89,    89,    90,    90,    91,    91,    91,    92,
      92,    92,    93,    93,    93,    93,    93,    94,    94,    95,
      95,    96,    96,    97,    97,    97,    97,    97,    97,    97
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     2,     1,     2,     3,     3,     0,     3,
       2,     1,     1,     1,     1,     0,     7,     7,     3,     1,
       3,     3,     1,     3,     3,     4,     1,     1,     1,     1,
       1,     1,     4,     4,     6,     0,     3,     1,     3,     3,
       3,     2,     3,     1,     1,     1,     1,     1,     2,     0,
       1,     2,     0,     3,     1,     3,     1,     7,     5,     5,
       3,     1,     4,     3,     1,     1,     3,     3,     1,     3,
       3,     1,     3,     1,     1,     1,     4,     3,     1,     3,
       1,     2,     1,     3,     3,     3,     3,     3,     3,     3
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

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



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

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
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
  case 11: /* declaration: declaration_variable  */
#line 67 "grammaire.y"
                                                                                { printf("Declaration de variable reconnue ! \n");}
#line 1301 "grammaire.tab.c"
    break;

  case 12: /* declaration: declaration_fonction  */
#line 68 "grammaire.y"
                                                                                { printf("Declaration de fonction reconnue ! \n");}
#line 1307 "grammaire.tab.c"
    break;

  case 13: /* declaration: declaration_procedure  */
#line 69 "grammaire.y"
                                                                                { printf("Declaration de procedure reconnue ! \n");}
#line 1313 "grammaire.tab.c"
    break;

  case 14: /* declaration: declaration_type  */
#line 70 "grammaire.y"
                                                                                { printf("Declaration de type reconnue ! \n"); }
#line 1319 "grammaire.tab.c"
    break;

  case 15: /* $@1: %empty  */
#line 73 "grammaire.y"
                                                        { initDepl(); nb_champs = 0; index_nb_champs = taille_tab_repres(); insereTabRepres(0);   }
#line 1325 "grammaire.tab.c"
    break;

  case 16: /* declaration_type: TYPE IDF DEUX_POINTS STRUCT $@1 liste_champs FINSTRUCT  */
#line 74 "grammaire.y"
        {
             
            sem_decl_struct((yyvsp[-5].ival), 0, 0);
            insereNbchampsTabReprese(index_nb_champs,nb_champs); 
            
            printf("Type structure reconnu ! \n");
            
            nb_champs = 0; // réinitialiser pour la prochaine structure   
        }
#line 1339 "grammaire.tab.c"
    break;

  case 17: /* declaration_type: TYPE IDF DEUX_POINTS TABLEAU dimension DE nom_type  */
#line 84 "grammaire.y"
        {
            /* TODO: extraire les bornes de "dimension" si tu les passes en attribut
               Ici on met borne_inf=0, borne_sup=$7 taille symbolique → à améliorer. */
            sem_decl_tab((yyvsp[-5].ival), (yyvsp[0].ival), 0, 0);
            printf("Type tableau reconnu ! \n");
        }
#line 1350 "grammaire.tab.c"
    break;

  case 22: /* liste_champs: un_champ  */
#line 102 "grammaire.y"
                                                   { nb_champs += 1;}
#line 1356 "grammaire.tab.c"
    break;

  case 23: /* liste_champs: liste_champs POINT_VIRG un_champ  */
#line 103 "grammaire.y"
                                                   { nb_champs +=1;}
#line 1362 "grammaire.tab.c"
    break;

  case 24: /* un_champ: IDF DEUX_POINTS nom_type  */
#line 106 "grammaire.y"
                                           { 
                insereTabRepres((yyvsp[-2].ival)); 
                insereTabRepres((yyvsp[0].ival));
                insereTabRepres(deplacer(getTaille((yyvsp[0].ival)))); 
        }
#line 1372 "grammaire.tab.c"
    break;

  case 25: /* declaration_variable: VARIABLE IDF DEUX_POINTS nom_type  */
#line 115 "grammaire.y"
        { 
            /* $2 : identifiant → index lexico (via le scanner)
               $4 : code du type (entier, bool, struct..., grâce à nom_type) */
            sem_decl_var((yyvsp[-2].ival), (yyvsp[0].ival), 1);

            printf("Declaration de variable reconnue \n");
        }
#line 1384 "grammaire.tab.c"
    break;

  case 26: /* nom_type: type_simple  */
#line 124 "grammaire.y"
                                { (yyval.ival) = (yyvsp[0].ival); }
#line 1390 "grammaire.tab.c"
    break;

  case 27: /* nom_type: IDF  */
#line 125 "grammaire.y"
                                { (yyval.ival) = association_nom((yyvsp[0].ival),TYPE_S); }
#line 1396 "grammaire.tab.c"
    break;

  case 28: /* type_simple: ENTIER  */
#line 128 "grammaire.y"
                                       { (yyval.ival) = 1; }
#line 1402 "grammaire.tab.c"
    break;

  case 29: /* type_simple: REEL  */
#line 129 "grammaire.y"
                                       { (yyval.ival) = 2; }
#line 1408 "grammaire.tab.c"
    break;

  case 30: /* type_simple: BOOLEEN  */
#line 130 "grammaire.y"
                                       { (yyval.ival) = 3; }
#line 1414 "grammaire.tab.c"
    break;

  case 31: /* type_simple: CARACTERE  */
#line 131 "grammaire.y"
                                       { (yyval.ival) = 4; }
#line 1420 "grammaire.tab.c"
    break;

  case 32: /* type_simple: CHAINE CROCHET_OUVRANT CSTE_ENTIERE CROCHET_FERMANT  */
#line 132 "grammaire.y"
                                                                      { (yyval.ival) = 5; }
#line 1426 "grammaire.tab.c"
    break;

  case 33: /* declaration_procedure: PROCEDURE IDF liste_parametres corps  */
#line 135 "grammaire.y"
                                                                       {
            /* region_corps = 0 pour l’instant, etiq_exec = 0 (sera l’étiquette de code plus tard) */
            sem_decl_proc((yyvsp[-2].ival), 0, 0);
            printf("Declaration de procedure reconnue ! \n");
        }
#line 1436 "grammaire.tab.c"
    break;

  case 34: /* declaration_fonction: FONCTION IDF liste_parametres RETOURNE type_simple corps  */
#line 142 "grammaire.y"
                                                                                        { sem_decl_fct((yyvsp[-4].ival), (yyvsp[-1].ival), 0, 0); printf("Declaration de fonction reconnue ! \n");}
#line 1442 "grammaire.tab.c"
    break;

  case 39: /* un_param: IDF DEUX_POINTS type_simple  */
#line 154 "grammaire.y"
        {
            /* region = 0 pour l’instant, offset = 0 (à gérer plus tard avec la pile d’activation) */
            sem_decl_param((yyvsp[-2].ival), (yyvsp[0].ival), 0, 0);
        }
#line 1451 "grammaire.tab.c"
    break;

  case 51: /* appel: IDF liste_arguments  */
#line 179 "grammaire.y"
                                                                                         { printf("Appel de fonction reconnue ! \n"); }
#line 1457 "grammaire.tab.c"
    break;

  case 57: /* condition: SI expression_booleenne ALORS liste_inst SINON liste_inst FINSI  */
#line 193 "grammaire.y"
                                                                                         { printf("Condition avec sinon reconnue ! \n"); }
#line 1463 "grammaire.tab.c"
    break;

  case 58: /* condition: SI expression_booleenne ALORS liste_inst FINSI  */
#line 194 "grammaire.y"
                                                                                         { printf("Condition sans sinon reconnue ! \n"); }
#line 1469 "grammaire.tab.c"
    break;

  case 59: /* tant_que: TANT_QUE expression_booleenne FAIRE liste_inst FINTANT_QUE  */
#line 197 "grammaire.y"
                                                                                         { printf("Tant que boucle reconnue ! \n"); }
#line 1475 "grammaire.tab.c"
    break;

  case 60: /* affectation: variable OPAFF expression  */
#line 200 "grammaire.y"
                                                                                         { printf("Affectation reconnue ! \n"); }
#line 1481 "grammaire.tab.c"
    break;

  case 64: /* expression: expression1  */
#line 209 "grammaire.y"
                                                                                         { printf("Expression arithmetique reconnue ! \n"); }
#line 1487 "grammaire.tab.c"
    break;

  case 65: /* expression: expression_booleenne  */
#line 210 "grammaire.y"
                                                                                         { printf("Expression booleenne reconnue ! \n"); }
#line 1493 "grammaire.tab.c"
    break;


#line 1497 "grammaire.tab.c"

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
      yyerror (YY_("syntax error"));
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

  return yyresult;
}

#line 252 "grammaire.y"

        int yyerror(char *s){
        fprintf(stderr, "\n ERREUR DE SYNTAXE à la ligne %d\n", yylineno);
        fprintf(stderr, " le token incorrect: %s\n", yytext);
        return 0;
        }
/*
int main(){
        if(yyparse() == 0) {
                printf("Analyse syntaxique terminée avec succès !\n");
        } else {
                printf("Echec de l'analyse syntaxique.\n");

        };

        return 0;
        }*/
int main(int argc, char **argv) {
        const char *fichier = (argc > 1) ? argv[1] : "fic_test.txt";

        

        yyin = fopen(fichier, "r");
        if (!yyin) {
                perror("Erreur ouverture fichier");
                return 1;
        }

        /* Initialisation des tables */
        init_tab_lexico();
        sem_init();
        init_tab_repres(); 
        
        /* Lancement de l'analyse syntaxique */
        int result = yyparse();
        fclose(yyin);

        if (result == 0) {
                printf("\n Analyse syntaxique terminée avec succès.\n");
        } else {
                printf("\n Erreurs détectées pendant l'analyse.\n");
        }

        /* Affichage des tables */
        
        // printf("\n========================================\n");
        // printf("        TABLES APRES ANALYSE\n");
        // printf("========================================\n");
        // sem_dump();
        afficher_tab_repres();
        // printf("\n========================================\n");
        // printf("        FIN DU PROGRAMME\n");
        // printf("========================================\n");
        return 0;
}
