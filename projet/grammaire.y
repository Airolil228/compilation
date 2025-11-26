%{
#include <stdio.h>
#include <stdlib.h>
#include "include/tab_lexico.h"
#include "include/tab_decl.h"
#include "include/pile_region.h"
#include "include/arbre.h"

int yylex();
int yyerror(char *s); 

extern int yylineno;      // Nécessaire pour afficher le numéro de ligne
extern char *yytext;      // Nécessaire pour afficher le token
extern FILE *yyin;     // IMPORTANT: source du lexer

extern int numregion;
extern pile *pile_region;

%}
%union {
int ival;   /* pour IDF, numéros de type, constantes entières, etc. */
}

%token PROG  
%token POINT_VIRG POINT
%token DEBUT FIN
%token TYPE DEUX_POINTS
%token STRUCT FINSTRUCT
%token TABLEAU DE 
%token CROCHET_OUVRANT CROCHET_FERMANT
%token VIRGULE
%token POINT_POINT
%token ENTIER REEL BOOLEEN CARACTERE CHAINE 
%token VARIABLE 
%token PROCEDURE FONCTION RETOURNE
%token PARENTHESE_OUVRANTE PARENTHESE_FERMANTE
%token VIDE
%token SI ALORS SINON FINSI
%token TANT_QUE FAIRE FINTANT_QUE
%token OPAFF
%token PLUS MOINS MULT DIV
%token ET OU NON
%token EGALE DIFFERENT INFERIEUR INFERIEUR_EGAL SUPERIEUR SUPERIEUR_EGAL 
%token VRAI FAUX
%token <ival> IDF CSTE_ENTIERE CSTE_REEL


%type  <ival> nom_type type_simple
%type <ival> variable
%type <ival> expression
%type <ival> expression1
%type <ival> expression2
%type <ival> expression3
%type <ival> affectation


%%

programme: PROG corps
;

corps:  liste_decl liste_inst   
| liste_inst
;        

liste_decl:  declaration POINT_VIRG   
        | liste_decl declaration POINT_VIRG
;

liste_inst: DEBUT suite_liste_inst FIN
; 

suite_liste_inst: /*vide*/ 
        | suite_liste_inst instruction POINT_VIRG 
        | liste_inst_non_vide POINT_VIRG 
;

declaration:    declaration_variable                                    { printf("Declaration de variable reconnue ! \n");}
        | declaration_fonction                                    { printf("Declaration de fonction reconnue ! \n");}
        | declaration_procedure                                   { printf("Declaration de procedure reconnue ! \n");} 
        | declaration_type                                        { printf("Declaration de type reconnue ! \n");}       
;

declaration_type: TYPE IDF DEUX_POINTS STRUCT liste_champs FINSTRUCT
        {
        inserer_decl($2,TYPE_S,sommet(pile_region),0, -1);
        printf("Type structure reconnu ! \n");
        }
        | TYPE IDF DEUX_POINTS TABLEAU dimension DE nom_type
        {
        inserer_decl($2,TYPE_T,sommet(pile_region),$7,-1);
        printf("Type tableau reconnu ! \n");
        }
        ;

dimension: CROCHET_OUVRANT liste_dimensions CROCHET_FERMANT             
; 

liste_dimensions: une_dimension  
        | liste_dimensions VIRGULE  une_dimension 
; 

une_dimension: CSTE_ENTIERE POINT_POINT CSTE_ENTIERE 
; 

liste_champs: un_champ  
        | liste_champs POINT_VIRG un_champ     
        ;

un_champ: IDF DEUX_POINTS nom_type 
; 

declaration_variable: VARIABLE IDF DEUX_POINTS nom_type 
        { inserer_decl($2,VAR,sommet(pile_region), $4,-1);
        printf("Declaration de variable reconnue ! \n");
        }
        ;  

nom_type: type_simple   { $$ = $1; }
        | IDF         { $$ = $1; }   /* type défini par l’utilisateur (struct, alias, etc.) */
; 

type_simple: ENTIER               { $$ = 1; }    /* code type pour ENTIER */
        | REEL                 { $$ = 2; }    /* code type pour REEL   */
        | BOOLEEN              { $$ = 3; }    /* code type pour BOOL   */
        | CARACTERE            { $$ = 4; }    /* code type pour CHAR   */
        | CHAINE CROCHET_OUVRANT CSTE_ENTIERE CROCHET_FERMANT
                        { $$ = 5; }   /* par ex. type “chaine[n]” */
        ;

declaration_procedure: PROCEDURE { empile(pile_region, numregion);numregion++;} IDF liste_parametres corps    
        {
        inserer_decl($3,PROC,sommet(pile_region),-1,-1 );depile(pile_region);
        printf("Declaration de procedure reconnue ! \n");
        }                  
        ;

declaration_fonction: FONCTION { empile(pile_region, numregion);numregion++;} IDF liste_parametres RETOURNE type_simple corps  
        { inserer_decl($3,FCT, sommet(pile_region),$6, -1 ); 
        depile(pile_region); printf("Declaration de fonction reconnue ! \n");}
        ; 

liste_parametres: /* vide  */
        | PARENTHESE_OUVRANTE liste_param PARENTHESE_FERMANTE 
; 

liste_param: un_param 
        | liste_param POINT_VIRG un_param 
; 

un_param: IDF DEUX_POINTS type_simple 
        {inserer_decl($1,PARAM,sommet(pile_region),$3 , -1);}
        ; 

liste_inst_non_vide: DEBUT suite_liste_inst_non_vide FIN
;

suite_liste_inst_non_vide: instruction POINT_VIRG
        | suite_liste_inst_non_vide instruction POINT_VIRG
;

instruction: affectation  
        | condition  
        |tant_que    
        |appel      
        | VIDE       
        | RETOURNE resultat_retourne
        ; 

resultat_retourne: /* vide */                                                  
                | expression 
                ; 

appel: IDF liste_arguments                                                   { printf("Appel de fonction reconnue ! \n"); }
        {
        int id = $1;
        int d = association_nom(id, FCT);

        if (d == -1) {
                fprintf(stderr, "[SEM] ERREUR : fonction '%s' non déclarée.\n",
                        tab_lexico[id].lexeme);
                exit(1);
        }
        }
        ; 

liste_arguments: /* vide */
        | PARENTHESE_OUVRANTE liste_args PARENTHESE_FERMANTE  
; 

liste_args: un_arg 
        | liste_args VIRGULE un_arg 
        ;

un_arg: expression 
; 

condition: SI expression_booleenne ALORS liste_inst SINON liste_inst FINSI       { printf("Condition avec sinon reconnue ! \n"); }
        | SI expression_booleenne ALORS liste_inst FINSI                        { printf("Condition sans sinon reconnue ! \n"); }
        ;                    

tant_que: TANT_QUE expression_booleenne FAIRE liste_inst FINTANT_QUE             { printf("Tant que boucle reconnue ! \n"); }
;                       

affectation: variable OPAFF expression                                           { printf("Affectation reconnue ! \n"); } 
        {
        int decl_gauche = $1;            // numéro de déclaration
        int type_gauche = tab_de_dec[decl_gauche].description;
        int type_droite = $3;            // le type retourné par l’expression

        if (type_gauche != type_droite) {
        fprintf(stderr,
                "[SEM] Types incompatibles dans l’affectation.\n");
        exit(1);
        }
        }
        ;                                        

/*** Partie autonomie ***/
variable: IDF  
        {
                int id = $1;
                int d = association_nom(id, VAR);

                if (d == -1) {
                        /* On ne connaît pas encore cet identificateur comme variable,
                        donc ce n’est PAS une variable → on laisse le parser remonter
                        l'erreur dans un autre contexte. */
                        yyerror("Identificateur utilisé comme variable alors qu'il ne l'est pas");
                        exit(1);
                }

                $$ = d;
        }
        | variable CROCHET_OUVRANT expression1 CROCHET_FERMANT                  
        | variable POINT IDF 
        ; 

expression: expression1                                                          { printf("Expression arithmetique reconnue ! \n"); }
        | expression_booleenne                                                   { printf("Expression booleenne reconnue ! \n"); }
        ;

expression1: expression1 PLUS expression2
        | expression1 MOINS expression2
        | expression2
        ;

expression2: expression2 MULT  expression3
        | expression2 DIV expression3
        | expression3
        ;

expression3: variable         { $$ = tab_de_dec[$1].description; }
        | CSTE_ENTIERE     { $$ = 1; }
        | CSTE_REEL        { $$ = 2; }
        | VRAI { $$ = 3; }   
        | FAUX { $$ = 3; }   
        | IDF PARENTHESE_OUVRANTE liste_args PARENTHESE_FERMANTE
        {
                /* Appel de fonction */
                int id = $1;
                int d = association_nom(id, FCT);

                if (d == -1) {
                fprintf(stderr, "[SEM] ERREUR : fonction '%s' non déclarée.\n",
                        tab_lexico[id].lexeme);
                exit(1);
                }

                $$ = tab_de_dec[d].description;  // type de retour
        }
        ;


expression_booleenne: expression_booleenne OU expression_et
        | expression_et
        ;

expression_et: expression_et ET expression_not
        | expression_not
        ;

expression_not: NON expression_not
        | expression_comp
        ;

expression_comp: expression1 INFERIEUR expression1   
        | expression1 SUPERIEUR expression1
        | expression1 EGALE expression1
        | expression1 INFERIEUR_EGAL expression1
        | expression1 SUPERIEUR_EGAL expression1
        | expression1 DIFFERENT expression1
        | PARENTHESE_OUVRANTE expression_booleenne PARENTHESE_FERMANTE
        ;


%%
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

        printf("========================================\n");
        printf("    LECTURE DU FICHIER : %s\n", fichier);
        printf("========================================\n\n");

        yyin = fopen(fichier, "r");
        if (!yyin) {
                perror("Erreur ouverture fichier");
                return 1;
        }

        /* Initialisation des tables */
        init_tab_lexico();      // table des lexèmes
        init_tab_decl();        // table des déclarations
        pile_region = creationPile();
        numregion = 0;
        empile(pile_region, numregion); // région 0 = globale

        /* Lancement de l'analyse syntaxique */
        int result = yyparse();
        fclose(yyin);

        if (result == 0) {
                printf("\n Analyse syntaxique terminée avec succès.\n");
        } else {
                printf("\n Erreurs détectées pendant l'analyse.\n");
        }

        /* Affichage des tables */
        printf("\n========================================\n");
        printf("        TABLES APRES ANALYSE\n");
        printf("========================================\n");
        afficher_tab_lex(NULL);
        afficher_tab_decl(stdout);

        printf("\n========================================\n");
        printf("        FIN DU PROGRAMME\n");
        printf("========================================\n");
        return 0;
}
