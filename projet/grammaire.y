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
        struct noeud *node;
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

%type <node> programme corps
%type <node> liste_inst suite_liste_inst liste_inst_non_vide
%type <node> instruction condition tant_que appel affectation
%type <node> expression expression1 expression2 expression3
%type <node> expression_booleenne expression_et expression_not expression_comp
%type <node> variable
%type <node> liste_arguments liste_args un_arg
%type <node> suite_liste_inst_non_vide
%type <node> resultat_retourne



%%

programme: PROG corps
        {
        $$ = $2;
        printf("\n AST construit :\n");
        afficher_arbre($$);
        }
;

corps:  liste_decl liste_inst   { $$ = $2; }
| liste_inst                    { $$ = $1; }
;        

liste_decl:  declaration POINT_VIRG   
        | liste_decl declaration POINT_VIRG
;

liste_inst: DEBUT suite_liste_inst FIN
        {
          Noeud *n = creer_noeud(A_LISTE, -1, -1);
          ajouter_fils(n, $2);
          $$ = n;
        }
; 

suite_liste_inst: /*vide*/ 
        {
          $$ = NULL;
        }
        | suite_liste_inst instruction POINT_VIRG 
        {
          if ($1 == NULL) {
              $$ = $2;
          } else {
              ajouter_frere($1, $2);  // accroche $2 à la fin de la chaîne $1
              $$ = $1;
          }
        }
        | liste_inst_non_vide POINT_VIRG 
        {
          $$ = $1;        // déjà une liste complète → on la renvoie
        }
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
        {
          $$ = $2;   // la liste construite par suite_liste_inst_non_vide
        }
;

suite_liste_inst_non_vide:
      instruction POINT_VIRG
      {
          $$ = $1;        // une seule instruction → c’est la racine
      }
    | suite_liste_inst_non_vide instruction POINT_VIRG
      {
          ajouter_frere($1, $2); // ajoute l’instruction à la suite
          $$ = $1;               // la racine reste la première instruction
      }
;

instruction: affectation  { $$ = $1; }
        | condition  { $$ = $1; }
        |tant_que    { $$ = $1; }
        |appel      { $$ = $1; }
        | VIDE       { $$ = NULL; }
        | RETOURNE resultat_retourne  
        {
        Noeud *n = creer_noeud(A_RETOURNE, -1, -1);
        if ($2 != NULL)    // return x;
                ajouter_fils(n, $2);
        $$ = n;
        }
        ; 

resultat_retourne: /* vide */  { $$ = NULL; }                                                
                | expression { $$ = $1; }
                ; 

appel: IDF liste_arguments   
        {
                printf("Appel de fonction reconnue ! \n");
                int id = $1;
                int d = association_nom(id, FCT);

                if (d == -1) {
                        fprintf(stderr, "[SEM] ERREUR : fonction '%s' non déclarée.\n",
                                tab_lexico[id].lexeme);
                        exit(1);
                }
                Noeud *n = creer_noeud(A_APPEL_FCT, id, d);
                ajouter_fils(n, $2);    // liste_arguments retourne un nœud liste

                $$ = n;
        }
        ; 

liste_arguments: /* vide */
        {
          $$ = NULL;
        }
        | PARENTHESE_OUVRANTE liste_args PARENTHESE_FERMANTE 
        {
          $$ = $2;
        } 
; 

liste_args: un_arg 
        {
          $$ = creer_noeud(A_LISTE_PARAM, -1, -1);
          ajouter_fils($$, $1);
        }
        | liste_args VIRGULE un_arg 
        {
          ajouter_frere($1->fils_gauche, $3);
          $$ = $1;
        }
        ;

un_arg: expression
        {
          $$ = $1;
        } 
; 

condition:SI expression_booleenne ALORS liste_inst SINON liste_inst FINSI
        {
                Noeud *n = creer_noeud(A_IF_THEN_ELSE, -1, -1);
                ajouter_fils(n, $2);               // condition
                ajouter_frere($2, $4);             // bloc THEN
                ajouter_frere($4, $6);             // bloc ELSE
                $$ = n;
        }
        | SI expression_booleenne ALORS liste_inst FINSI
        {
                Noeud *n = creer_noeud(A_IF_THEN_ELSE, -1, -1);
                ajouter_fils(n, $2);              // condition
                ajouter_frere($2, $4);            // bloc THEN
                // pas de ELSE → rien à ajouter
                $$ = n;
        }
;                    

tant_que: TANT_QUE expression_booleenne FAIRE liste_inst FINTANT_QUE             
        {
        Noeud *n = creer_noeud(A_WHILE, -1, -1);
        ajouter_fils(n, $2);     // condition
        ajouter_frere($2, $4);   // bloc
        $$ = n;
        }
;                       

affectation: variable OPAFF expression 
        {
        printf("Affectation reconnue !\n");
        Noeud *n = creer_noeud(A_OPAFF, -1, -1);
        ajouter_fils(n, $1);      // gauche = variable
        ajouter_frere($1, $3);    // droite = expression
        $$ = n;
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

                $$ = creer_noeud(A_IDF, id, d);
        }
        | variable CROCHET_OUVRANT expression1 CROCHET_FERMANT
        {
        // plus tard : construire un noeud A_LISTE_IND ou A_LISTE_CH
        $$ = $1; // on propage pour le moment
        }                  
        | variable POINT IDF 
        {
        // plus tard : noeud pour champ de struct
        $$ = $1;
        }
        ; 

expression:
      expression1
      {
          printf("Expression arithmetique reconnue !\n");
          $$ = $1;
      }
    | expression_booleenne
      {
          printf("Expression booleenne reconnue !\n");
          $$ = $1;
      }
;

expression1: expression1 PLUS expression2
        {
          Noeud *n = creer_noeud(A_PLUS, -1, -1);
          ajouter_fils(n, $1);             // fils gauche = expression1
          ajouter_frere($1, $3);           // frère droit = expression2
          $$ = n;
        }
        | expression1 MOINS expression2
        {
          Noeud *n = creer_noeud(A_MOINS, -1, -1);
          ajouter_fils(n, $1);
          ajouter_frere($1, $3);
          $$ = n;
        }
        | expression2
        {
         $$ = $1;
        }
        ;

expression2:
        expression2 MULT expression3
        {
        Noeud *n = creer_noeud(A_MULT, -1, -1);
        ajouter_fils(n, $1);
        ajouter_frere($1, $3);
        $$ = n;
        }
        | expression2 DIV expression3
        {
        Noeud *n = creer_noeud(A_DIV, -1, -1);
        ajouter_fils(n, $1);
        ajouter_frere($1, $3);
        $$ = n;
        }
        | expression3
        {
        $$ = $1;
        }
        ;

expression3:
        variable
        {
        $$ = $1;   // la variable est déjà un noeud A_IDF
        }
        | CSTE_ENTIERE
        {
        $$ = creer_noeud(A_CSTE_ENT, $1, -1);
        }
        | CSTE_REEL
        {
        $$ = creer_noeud(A_CSTE_REELLE, $1, -1);
        }
        | VRAI
        {
        $$ = creer_noeud(A_CSTE_BOOL, /*lexnum=*/-1, -1);
        }
        | FAUX
        {
        $$ = creer_noeud(A_CSTE_BOOL, /*lexnum=*/-1, -1);
        }
        | IDF PARENTHESE_OUVRANTE liste_args PARENTHESE_FERMANTE
        {
        int id = $1;
        int d = association_nom(id, FCT);
        if (d == -1) {
                fprintf(stderr, "[SEM] ERREUR : fonction '%s' non déclarée.\n",
                tab_lexico[id].lexeme);
                exit(1);
        }
        Noeud *n = creer_noeud(A_APPEL_FCT, id, d);
        ajouter_fils(n, $3);   // $3 = liste_args (déjà construite comme liste)
        $$ = n;
        }
        ;



expression_booleenne:
        expression_booleenne OU expression_et
        {
                Noeud *n = creer_noeud(A_OR, -1, -1);
                ajouter_fils(n, $1);
                ajouter_frere($1, $3);
                $$ = n;
        }
        | expression_et
        {
                $$ = $1;
        }
        ;


expression_et:
        expression_et ET expression_not
        {
                Noeud *n = creer_noeud(A_AND, -1, -1);
                ajouter_fils(n, $1);
                ajouter_frere($1, $3);
                $$ = n;
        }
        | expression_not
        {
                $$ = $1;
        }
;

expression_not:
        NON expression_not
        {
                Noeud *n = creer_noeud(A_NOT, -1, -1);
                ajouter_fils(n, $2);
                $$ = n;
        }
        | expression_comp
        {
                $$ = $1;
        }
;

expression_comp:
      expression1 INFERIEUR expression1
      {
          Noeud *n = creer_noeud(A_INF, -1, -1);
          ajouter_fils(n, $1);
          ajouter_frere($1, $3);
          $$ = n;
      }
    | expression1 SUPERIEUR expression1
      {
          Noeud *n = creer_noeud(A_SUP, -1, -1);
          ajouter_fils(n, $1);
          ajouter_frere($1, $3);
          $$ = n;
      }
    | expression1 EGALE expression1
      {
          Noeud *n = creer_noeud(A_EGAL, -1, -1);
          ajouter_fils(n, $1);
          ajouter_frere($1, $3);
          $$ = n;
      }
    | expression1 INFERIEUR_EGAL expression1
      {
          Noeud *n = creer_noeud(A_INF_EGAL, -1, -1);
          ajouter_fils(n, $1);
          ajouter_frere($1, $3);
          $$ = n;
      }
    | expression1 SUPERIEUR_EGAL expression1
      {
          Noeud *n = creer_noeud(A_SUP_EGAL, -1, -1);
          ajouter_fils(n, $1);
          ajouter_frere($1, $3);
          $$ = n;
      }
    | expression1 DIFFERENT expression1
      {
          Noeud *n = creer_noeud(A_DIFF, -1, -1);
          ajouter_fils(n, $1);
          ajouter_frere($1, $3);
          $$ = n;
      }
    | PARENTHESE_OUVRANTE expression_booleenne PARENTHESE_FERMANTE
      {
          $$ = $2;
      }
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
