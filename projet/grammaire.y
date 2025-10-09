%{
#include <stdio.h>
#include <stdlib.h>
int yylex();
int yyerror(char *s); 
%}

%token PROG  
%token POINT_VIRG POINT
%token DEBUT FIN
%token TYPE IDF DEUX_POINTS
%token STRUCT FINSTRUCT
%token TABLEAU DE 
%token CROCHET_OUVRANT CROCHET_FERMANT
%token VIRGULE
%token CSTE_ENTIERE POINT_POINT
%token ENTIER REEL BOOLEEN CARACTERE CHAINE 
%token VARIABLE 
%token PROCEDURE FONCTION RETOURNE
%token PARENTHESE_OUVRANTE PARENTHESE_FERMANTE
%token VIDE
%token SI ALORS SINON
%token TANT_QUE FAIRE
%token OPAFF
%token PLUS MOINS MULT DIV
%token ET OU NON
%token EGALE DIFFERENT INFERIEUR INFERIEUR_EGAL SUPERIEUR SUPERIEUR_EGAL
%token VRAI FAUX
%%
    programme: expression  ;

   /*  corps: liste_decl liste_inst  */
   /*          | liste_inst; */

   /*  liste_decl: declaration POINT_VIRG  */
   /*          | liste_decl declaration POINT_VIRG ; */

   /*  liste_inst: DEBUT suite_liste_inst FIN ; */
    
   /*  suite_liste_inst: instruction POINT_VIRG  */
   /*          | suite_liste_inst instruction POINT_VIRG ;  */

   /*  declaration: declaration_type  */
   /*          | declaration_variable  */
   /*          | declaration_fonction  */
   /*          | declaration_procedure ; */
    
   /*  declaration_type: TYPE IDF DEUX_POINTS suite_decl_type ;  */

   /*  suite_decl_type: STRUCT liste_champs FINSTRUCT  */
   /*          | TABLEAU dimension DE nom_type ;  */
    
   /*  dimension: CROCHET_OUVRANT liste_dimensions CROCHET_FERMANT ;  */

   /*  liste_dimensions: une_dimension  */
   /*          | liste_dimensions VIRGULE  une_dimension ; */

   /*  une_dimension: CSTE_ENTIERE POINT_POINT CSTE_ENTIERE ;  */

   /*  liste_champs: un_champ  */
   /*          | liste_champs POINT_VIRG un_champ ;          */

   /*  un_champ: IDF DEUX_POINTS nom_type ; */

   /*  nom_type: type_simple */
   /*          | IDF ; */
    
   /*  type_simple: ENTIER  */
   /*          | REEL  */
   /*          | BOOLEEN  */
   /*          | CARACTERE  */
   /*          | CHAINE  CROCHET_OUVRANT CSTE_ENTIERE CROCHET_FERMANT ; */
    
   /*  declaration_variable: VARIABLE IDF DEUX_POINTS nom_type ;  */

   /*  declaration_procedure: PROCEDURE IDF liste_parametres corps;  */

   /*  declaration_fonction: FONCTION IDF liste_parametres RETOURNE type_simple corps ; */

   /* liste_parametres: /\* vide *\/  */
   /*          | PARENTHESE_OUVRANTE liste_param PARENTHESE_FERMANTE ; */

   /*  liste_param: un_param */
   /*          | liste_param POINT_VIRG un_param ; */

   /*  un_param: IDF DEUX_POINTS type_simple ; */

   /*  instruction: affectation  */
   /*          |condition  */
   /*          |tant_que  */
   /*          |appel */
   /*          |VIDE  */
   /*          |RETOURNE resultat_retourne; */
    
   /*  resultat_retourne: /\* vide *\/  */
   /*          | expression ; */

   /*  appel: IDF liste_arguments ; */

   /*  liste_arguments: /\* vide *\/  */
   /*          | PARENTHESE_OUVRANTE liste_args PARENTHESE_FERMANTE ; */

   /*  liste_args: un_arg */
   /*          | liste_args VIRGULE un_arg ; */

   /*  un_arg: expression ; */

   /*  condition: SI expression_booleenne  */
   /*          ALORS liste_inst */
   /*          SINON liste_inst ; */

   /*  tant_que: TANT_QUE expression_booleenne FAIRE liste_inst ; */

   /*  affectation: variable OPAFF expression ; */

   /*  /\** Partie autonomie **\/ */

   /*  variable: IDF  */
   /*          | IDF CROCHET_OUVRANT expression CROCHET_FERMANT  */
   /*          | IDF POINT expression ; */

expression: expression1             { printf("Expression arithmetique reconnue ! \n"); }
           | expression_booleenne   {printf("Expression booleen reconnue ! \n");}
          ;

expression1: expression1 PLUS expression2
           | expression1 MOINS expression2
           | expression2
           ;

expression2: expression2 MULT  expression3
           | expression2 DIV expression3
           | expression3
           ;

expression3: PARENTHESE_OUVRANTE expression1 PARENTHESE_FERMANTE
           | ENTIER
           ;

expression_booleenne: expression_booleenne OU expression_booleenne1
           | expression_booleenne1
           ;

expression_booleenne1:
           IDF
           ;
    
%%

int yyerror(char *s){
    fprintf(stderr,"Erreur de syntaxte: %s\n",s);
    return 0;
}

int main(){
    yyparse();
    return 0;
}