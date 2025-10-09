%{
 #include "grammaire.tab.h"
 #include <stdio.h>
%}

%% 
"programme"    { return PROG; }
\;             { return POINT_VIRG; }
"debut"        { return DEBUT; }
"fin"          { return FIN; }
"type"         { return TYPE; }
\:             { return DEUX_POINTS; }
"struct"       { return STRUCT; }
"finstruct"    { return FINSTRUCT; }
"tab"          { return TABLEAU; }
\[             { return CROCHET_OUVRANT; }
\]             { return CROCHET_FERMANT; }
\,             { return VIRGULE; }


\+             { return PLUS; }
\-             { return MOINS; }
\*             { return MULT; }
\/             { return DIV; }
\(             { return PARENTHESE_OUVRANTE; }
\)             { return PARENTHESE_FERMANTE; }

"||"           { return OU; }

[1-9][0-9]*                  { return ENTIER; } 
[a-zA-Z][a-zA-Z0-9]*         { return IDF; } /*à ameliorer */

[ \n]+                          { /*ignorer*/ }

.                            { fprintf(stderr,"Invalide: %s\n", yytext); } /*Dans le reste de cas  */


%%

int yywrap(void) { return 1; }