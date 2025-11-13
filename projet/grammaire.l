%{
 #include "grammaire.tab.h"
 #include <stdio.h>
 #include <stdlib.h>

 //#include "include/tab_semantique.h"
 #include "include/tab_lexico.h"
 #include "include/tab_decl.h"

%}

%% 
"programme"     { return PROG; }
"debut"         { return DEBUT; }
"fin"           { return FIN; }
"type"          { return TYPE; }
"struct"        { return STRUCT; }
"finstruct"     { return FINSTRUCT; }
"tab"           { return TABLEAU; }
"de"            { return DE;      } 
"entier"        { return ENTIER;  }
"reel"          { return REEL;     }
"bool"          {return BOOLEEN;   }
"char"          { return CARACTERE; }
"chaine"        { return CHAINE;    }
"var"           { return VARIABLE;  }
"procedure"     { return PROCEDURE; }
"fonction"      { return FONCTION;  }
"retourne"      { return RETOURNE; }
"vide"          { return VIDE; }
"si"            {return SI;}
"alors"         {return ALORS; }
"sinon"         {return SINON; }
"finsi"         {return FINSI; }
"tant_que"      {return TANT_QUE; }
"fintant_que"   {return FINTANT_QUE; }
"faire"         {return FAIRE; }
"non"           {return NON; }
"vrai"          {return VRAI; }
"faux"          {return FAUX;}


\;             { return POINT_VIRG; }
\.             { return POINT; }
\:             { return DEUX_POINTS; }
\[             { return CROCHET_OUVRANT; }
\]             { return CROCHET_FERMANT; }
\,             { return VIRGULE; }
".."           { return POINT_POINT; }
":="           {return OPAFF; }


"<="            { return INFERIEUR_EGAL; }
"<"             { return INFERIEUR; }
">="            { return SUPERIEUR_EGAL; }
">"             { return SUPERIEUR; }
"=="            { return EGALE; }

"<>"            { return DIFFERENT; }

"&&"           { return ET; }
"||"           { return OU; }
"!"            { return NON; }

\+             { return PLUS; }
\-             { return MOINS; }
\/             { return DIV; }
\*             { return MULT; }

\(             { return PARENTHESE_OUVRANTE; }
\)             { return PARENTHESE_FERMANTE; }

\/\*([^*]|\*+[^*/])*\*\/    { /* Ignorer les commentaires */ }

"//".*                        { /* Ignorer les commentaires de ligne */ }

[1-9][0-9]*                  { return CSTE_ENTIERE; } 
[0-9]+\.?[0-9]*              { return CSTE_REEL; }
[a-zA-Z][a-zA-Z0-9]*         { yylval.intval = inserer_lexeme(yytext); 
                               /* printf("Identifiant: %s\n", yytext); */ 
                               return IDF; } 

[ \t\r]+                     { /* ignorer tous les espaces blancs */ }
\n                           {  ++yylineno; }

.                           { fprintf(stderr,"Caractere invalide: '%s' (ASCII: %d)\n", yytext, yytext[0]); } /*Dans le reste de cas  */


%%
int yywrap(void) { return 1; }