%{
    #include "grammaire.tab.y"
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



[1-9][0-9]*  { return ENTIER; }
[a-zA-Z][a-zA-Z0-9]*   { return IDF; }/*A revoir*/


%%

int wrap(void) {
    return 1;
}