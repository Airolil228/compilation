/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_GRAMMAIRE_TAB_H_INCLUDED
# define YY_YY_GRAMMAIRE_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    PROG = 258,                    /* PROG  */
    POINT_VIRG = 259,              /* POINT_VIRG  */
    POINT = 260,                   /* POINT  */
    DEBUT = 261,                   /* DEBUT  */
    FIN = 262,                     /* FIN  */
    TYPE = 263,                    /* TYPE  */
    DEUX_POINTS = 264,             /* DEUX_POINTS  */
    STRUCT = 265,                  /* STRUCT  */
    FINSTRUCT = 266,               /* FINSTRUCT  */
    TABLEAU = 267,                 /* TABLEAU  */
    DE = 268,                      /* DE  */
    CROCHET_OUVRANT = 269,         /* CROCHET_OUVRANT  */
    CROCHET_FERMANT = 270,         /* CROCHET_FERMANT  */
    VIRGULE = 271,                 /* VIRGULE  */
    POINT_POINT = 272,             /* POINT_POINT  */
    ENTIER = 273,                  /* ENTIER  */
    REEL = 274,                    /* REEL  */
    BOOLEEN = 275,                 /* BOOLEEN  */
    CARACTERE = 276,               /* CARACTERE  */
    CHAINE = 277,                  /* CHAINE  */
    VARIABLE = 278,                /* VARIABLE  */
    PROCEDURE = 279,               /* PROCEDURE  */
    FONCTION = 280,                /* FONCTION  */
    RETOURNE = 281,                /* RETOURNE  */
    PARENTHESE_OUVRANTE = 282,     /* PARENTHESE_OUVRANTE  */
    PARENTHESE_FERMANTE = 283,     /* PARENTHESE_FERMANTE  */
    VIDE = 284,                    /* VIDE  */
    SI = 285,                      /* SI  */
    ALORS = 286,                   /* ALORS  */
    SINON = 287,                   /* SINON  */
    FINSI = 288,                   /* FINSI  */
    TANT_QUE = 289,                /* TANT_QUE  */
    FAIRE = 290,                   /* FAIRE  */
    FINTANT_QUE = 291,             /* FINTANT_QUE  */
    OPAFF = 292,                   /* OPAFF  */
    PLUS = 293,                    /* PLUS  */
    MOINS = 294,                   /* MOINS  */
    MULT = 295,                    /* MULT  */
    DIV = 296,                     /* DIV  */
    ET = 297,                      /* ET  */
    OU = 298,                      /* OU  */
    NON = 299,                     /* NON  */
    EGALE = 300,                   /* EGALE  */
    DIFFERENT = 301,               /* DIFFERENT  */
    INFERIEUR = 302,               /* INFERIEUR  */
    INFERIEUR_EGAL = 303,          /* INFERIEUR_EGAL  */
    SUPERIEUR = 304,               /* SUPERIEUR  */
    SUPERIEUR_EGAL = 305,          /* SUPERIEUR_EGAL  */
    VRAI = 306,                    /* VRAI  */
    FAUX = 307,                    /* FAUX  */
    IDF = 308,                     /* IDF  */
    CSTE_ENTIERE = 309,            /* CSTE_ENTIERE  */
    CSTE_REEL = 310                /* CSTE_REEL  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 18 "grammaire.y"

                int ival;   /* pour IDF, numéros de type, constantes entières, etc. */
        

#line 124 "grammaire.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_GRAMMAIRE_TAB_H_INCLUDED  */
