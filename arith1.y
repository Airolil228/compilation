%{
  #include <stdio.h>
  #include <stdlib.h>
%}


%token PLUS MOINS MULT DIV
%token PO PF
%token ENTIER 

%%
 
e1: e1 PLUS e2
 | e1 MOINS e2
 | e2
 ;

e2 : e2 MULT e3
 | e2 DIV e3
 | e3
;

e3: PO e1 PF
| ENTIER {printf("%s";yytext)}
; 
 
%%

int main(){
    return(yyparse()); 
 }