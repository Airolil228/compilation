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
    IDF = 264,                     /* IDF  */
    DEUX_POINTS = 265,             /* DEUX_POINTS  */
    STRUCT = 266,                  /* STRUCT  */
    FINSTRUCT = 267,               /* FINSTRUCT  */
    TABLEAU = 268,                 /* TABLEAU  */
    DE = 269,                      /* DE  */
    CROCHET_OUVRANT = 270,         /* CROCHET_OUVRANT  */
    CROCHET_FERMANT = 271,         /* CROCHET_FERMANT  */
    VIRGULE = 272,                 /* VIRGULE  */
    CSTE_ENTIERE = 273,            /* CSTE_ENTIERE  */
    CSTE_REEL = 274,               /* CSTE_REEL  */
    POINT_POINT = 275,             /* POINT_POINT  */
    ENTIER = 276,                  /* ENTIER  */
    REEL = 277,                    /* REEL  */
    BOOLEEN = 278,                 /* BOOLEEN  */
    CARACTERE = 279,               /* CARACTERE  */
    CHAINE = 280,                  /* CHAINE  */
    VARIABLE = 281,                /* VARIABLE  */
    PROCEDURE = 282,               /* PROCEDURE  */
    FONCTION = 283,                /* FONCTION  */
    RETOURNE = 284,                /* RETOURNE  */
    PARENTHESE_OUVRANTE = 285,     /* PARENTHESE_OUVRANTE  */
    PARENTHESE_FERMANTE = 286,     /* PARENTHESE_FERMANTE  */
    VIDE = 287,                    /* VIDE  */
    SI = 288,                      /* SI  */
    ALORS = 289,                   /* ALORS  */
    SINON = 290,                   /* SINON  */
    FINSI = 291,                   /* FINSI  */
    TANT_QUE = 292,                /* TANT_QUE  */
    FAIRE = 293,                   /* FAIRE  */
    FINTANT_QUE = 294,             /* FINTANT_QUE  */
    OPAFF = 295,                   /* OPAFF  */
    PLUS = 296,                    /* PLUS  */
    MOINS = 297,                   /* MOINS  */
    MULT = 298,                    /* MULT  */
    DIV = 299,                     /* DIV  */
    ET = 300,                      /* ET  */
    OU = 301,                      /* OU  */
    NON = 302,                     /* NON  */
    EGALE = 303,                   /* EGALE  */
    DIFFERENT = 304,               /* DIFFERENT  */
    INFERIEUR = 305,               /* INFERIEUR  */
    INFERIEUR_EGAL = 306,          /* INFERIEUR_EGAL  */
    SUPERIEUR = 307,               /* SUPERIEUR  */
    SUPERIEUR_EGAL = 308,          /* SUPERIEUR_EGAL  */
    VRAI = 309,                    /* VRAI  */
    FAUX = 310                     /* FAUX  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 35 "grammaire.y"

                int intval;
                //arbre 
        

#line 125 "grammaire.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_GRAMMAIRE_TAB_H_INCLUDED  */
