%{
/*ANAS YACCINE BENEDICT VASILY */

#include <stdio.h>
#include <stdlib.h>
#include "include/tab_lexico.h"
#include "include/tab_decl.h"
#include "include/pile_region.h"
#include "include/arbre.h"
#include "include/tab_repres.h"
#include "include/tab_region.h"

int yylex();
int yyerror(char *s); 

extern int yylineno;      // Nécessaire pour afficher le numéro de ligne
extern char *yytext;      // Nécessaire pour afficher le token
extern FILE *yyin;     // IMPORTANT: source du lexer

extern int numregion;
extern pile *pile_region;

 int nb_champs;                                
 int index_nb_champs ;  // Index de départ pour la structure dans tab_repres
 int nb_param;
 int type_retour_temp; 
 int nb_dim;  
%}
%union {
int ival;   /* pour IDF, numéros de type, constantes entières, etc. */
Noeud* nval; /* pour les nœuds de l'arbre abstrait */
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
%type <nval> variable
%type <nval> expression
%type <nval> expression1
%type <nval> expression2
%type <nval> expression3
%type <nval> affectation
%type <nval> instruction liste_inst suite_liste_inst liste_inst_non_vide suite_liste_inst_non_vide
%type <nval> condition tant_que appel
%type <nval> expression_booleenne expression_et expression_not expression_comp
%type <nval> resultat_retourne
%type <nval> liste_arguments liste_args un_arg


%%

programme: PROG corps
;

corps:  liste_decl liste_inst
        {
                int region_courante = sommet(pile_region);
                set_arbre_region(region_courante, $2);
        }
| liste_inst
        {
                int region_courante = sommet(pile_region);
                set_arbre_region(region_courante, $1);
        }
;        

liste_decl:  declaration POINT_VIRG   
        | liste_decl declaration POINT_VIRG
;

liste_inst: DEBUT suite_liste_inst FIN  { $$ = $2; }
; 

suite_liste_inst: /*vide*/  { $$ = NULL; }
        | suite_liste_inst instruction POINT_VIRG 
        {
                if ($1 == NULL) {
                        $$ = $2;
                } else {
                        ajouter_frere($1, $2);
                        $$ = $1;
                }
        }
        | liste_inst_non_vide POINT_VIRG  { $$ = $1; }
;

declaration:    declaration_variable                              { printf("Declaration de variable reconnue ! \n");}
        | declaration_fonction                                    { printf("Declaration de fonction reconnue ! \n");}
        | declaration_procedure                                   { printf("Declaration de procedure reconnue ! \n");} 
        | declaration_type                                        { printf("Declaration de type reconnue ! \n");}       
;

declaration_type: TYPE IDF DEUX_POINTS STRUCT { initDepl();  nb_champs = 0; index_nb_champs = taille_tab_repres(); insereTabRepres(0);}  liste_champs FINSTRUCT
        {
        inserer_decl($2,TYPE_S,sommet(pile_region),0, -1);
        insereNbchampsTabReprese(index_nb_champs,nb_champs);
        nb_champs = 0; // réinitialiser pour la prochaine structure
        printf("Type structure reconnu ! \n");
        }
        | TYPE IDF DEUX_POINTS TABLEAU { nb_dim = 0; index_nb_champs = taille_tab_repres(); insereTabRepres(0);insereTabRepres(0);} dimension DE nom_type
        {
        inserer_decl($2,TYPE_T,sommet(pile_region),$8,-1);
        insereNbchampsTabReprese(index_nb_champs,$8-1);//insère 
        insereNbchampsTabReprese(index_nb_champs+1,nb_dim);//insère le nb de dimension 
        printf("Type tableau reconnu ! \n"); 
        }
        ;

dimension: CROCHET_OUVRANT liste_dimensions CROCHET_FERMANT             
; 

liste_dimensions: une_dimension                   { nb_dim += 1; } 
        | liste_dimensions VIRGULE  une_dimension { nb_dim += 1; }
; 

une_dimension: CSTE_ENTIERE POINT_POINT CSTE_ENTIERE { insereTabRepres($1); insereTabRepres($3); }
; 

liste_champs: un_champ                     { nb_champs += 1;}
              POINT_VIRG un_champ          { nb_champs +=1; }    
        ;

un_champ: IDF DEUX_POINTS nom_type  { 
                insereTabRepres($1); 
                insereTabRepres($3);
                insereTabRepres(deplacer(getTaille($3))); 
}       


declaration_variable: VARIABLE IDF DEUX_POINTS nom_type 
        {
                int region = sommet(pile_region);
                int taille = getTaille($4);
                int depl = deplacement_courant[region];
                
                inserer_decl($2, VAR, region, $4, depl);
                deplacement_courant[region] += taille;
                incrementer_taille_region(region, taille);
                
                printf("Declaration de variable reconnue ! \n");
        }
        ;  

nom_type: type_simple   { $$ = $1; }
        | IDF           { $$ = $1; }   /* type défini par l’utilisateur (struct, alias, etc.) */
; 

type_simple: ENTIER               { $$ = 1; }    /* code type pour ENTIER */
        | REEL                 { $$ = 2; }    /* code type pour REEL   */
        | BOOLEEN              { $$ = 3; }    /* code type pour BOOL   */
        | CARACTERE            { $$ = 4; }    /* code type pour CHAR   */
        | CHAINE CROCHET_OUVRANT CSTE_ENTIERE CROCHET_FERMANT
                        { $$ = 5; }   /* par ex. type “chaine[n]” */
        ;

declaration_procedure: PROCEDURE
        {
                int nis = get_nis_region(sommet(pile_region)) + 1;
                int num_region_proc = creer_region(nis);
                empile(pile_region, num_region_proc);
                numregion++;
        }
        IDF
        {
                deplacement_courant[sommet(pile_region)] = 0;  /* Réinitialiser le déplacement */
                initDepl();
                nb_param = 0;
                index_nb_champs = taille_tab_repres();
                insereTabRepres(0);
        }
        liste_parametres corps
        {
                int region_proc = sommet(pile_region);  /* Région de la procédure */
                depile(pile_region);
                int region_parente = sommet(pile_region);  /* Région où déclarer */
                inserer_decl($3, PROC, region_parente, index_nb_champs, region_proc);
                insereNbchampsTabReprese(index_nb_champs, nb_param);
                printf("Declaration de procedure reconnue ! \n");
        }
        ;

declaration_fonction: FONCTION
        {
                int nis = get_nis_region(sommet(pile_region)) + 1;
                int num_region_fct = creer_region(nis);
                empile(pile_region, num_region_fct);
                numregion++;
        }
        IDF
        {
                deplacement_courant[sommet(pile_region)] = 0;  /* Réinitialiser le déplacement */
                initDepl();
                nb_param = 0;
                index_nb_champs = taille_tab_repres();
                insereTabRepres(0);
                insereTabRepres(0);
        }
        liste_parametres RETOURNE type_simple corps
        {
                int region_fct = sommet(pile_region);  /* Région de la fonction */
                depile(pile_region);
                int region_parente = sommet(pile_region);  /* Région où déclarer */
                inserer_decl($3, FCT, region_parente, index_nb_champs, region_fct);
                insereNbchampsTabReprese(index_nb_champs, nb_param);
                insereNbchampsTabReprese(index_nb_champs + 1, $7 - 1);
                nb_param = 0;
                printf("Declaration de fonction reconnue ! \n");
        }
        ; 

liste_parametres: /* vide  */
        | PARENTHESE_OUVRANTE liste_param PARENTHESE_FERMANTE 
        ; 

liste_param: un_param 
        | liste_param POINT_VIRG un_param  
        ; 

un_param: IDF DEUX_POINTS type_simple {
        int region = sommet(pile_region);
        int taille = getTaille($3);
        int depl = deplacement_courant[region];
        
        inserer_decl($1, PARAM, region, $3, depl);
        deplacement_courant[region] += taille;
        incrementer_taille_region(region, taille);
        
        insereTabRepres($1);  // Insérer le numéro de lexème du paramètre
        insereTabRepres($3-1); // inserer type dans la table de repres
        nb_param+=1; 
        }
        ; 

liste_inst_non_vide: DEBUT suite_liste_inst_non_vide FIN { $$ = $2; }
;

suite_liste_inst_non_vide: instruction POINT_VIRG { $$ = $1; }
        | suite_liste_inst_non_vide instruction POINT_VIRG
        {
                if ($1 == NULL) {
                        $$ = $2;
                } else {
                        ajouter_frere($1, $2);
                        $$ = $1;
                }
        }
;

instruction: affectation  { $$ = $1; }
        |condition  { $$ = $1; }
        |tant_que   { $$ = $1; }
        |appel      { $$ = $1; }
        |VIDE       { $$ = creer_noeud(A_VIDE, 0, 0); }
        |RETOURNE resultat_retourne
        {
                $$ = creer_noeud(A_RETOURNE, 0, 0);
                if ($2 != NULL) {
                        ajouter_fils($$, $2);
                }
        }
        ; 

resultat_retourne: /* vide */  { $$ = NULL; }
                | expression  { $$ = $1; }
                ; 

appel: IDF liste_arguments
        {
        int id = $1;
        int d = association_nom(id, FCT);
        if (d == -1) {
                d = association_nom(id, PROC);
        }
        if (d == -1) {
                fprintf(stderr, "[SEM] ERREUR : fonction/procédure '%s' non déclarée.\n",
                        tab_lexico[id].lexeme);
                exit(1);
        }
        int nat = tab_de_dec[d].nature;
        $$ = creer_noeud((nat == FCT) ? A_APPEL_FCT : A_APPEL_PROC, $1, d);
        if ($2 != NULL) {
                ajouter_fils($$, $2);
        }
        printf("Appel de fonction/procédure reconnu ! \n");
        }
        ; 

liste_arguments: /* vide */  { $$ = NULL; }
        | PARENTHESE_OUVRANTE liste_args PARENTHESE_FERMANTE  { $$ = $2; }
; 

liste_args: un_arg  { $$ = $1; }
        | liste_args VIRGULE un_arg 
        {
                ajouter_frere($1, $3);
                $$ = $1;
        }
        ;

un_arg: expression  { $$ = $1; }
; 

condition: SI expression_booleenne ALORS liste_inst SINON liste_inst FINSI
        {
                $$ = creer_noeud(A_IF_THEN_ELSE, 0, 0);
                ajouter_fils($$, $2);
                ajouter_frere($2, $4);
                ajouter_frere($4, $6);
                printf("Condition avec sinon reconnue ! \n");
        }
        | SI expression_booleenne ALORS liste_inst FINSI
        {
                $$ = creer_noeud(A_IF_THEN_ELSE, 0, 0);
                ajouter_fils($$, $2);
                ajouter_frere($2, $4);
                printf("Condition sans sinon reconnue ! \n");
        }
        ;                    

tant_que: TANT_QUE expression_booleenne FAIRE liste_inst FINTANT_QUE
        {
                $$ = creer_noeud(A_WHILE, 0, 0);
                ajouter_fils($$, $2);
                ajouter_frere($2, $4);
                printf("Tant que boucle reconnue ! \n");
        }
;                       

affectation: variable OPAFF expression
        {
                $$ = creer_noeud(A_OPAFF, 0, 0);
                ajouter_fils($$, $1);
                ajouter_frere($1, $3);
                printf("Affectation reconnue ! \n");
        }
        ;                                        

/*** Partie autonomie ***/
variable: IDF  
        {
                int id = $1;
                int d = association_nom(id, VAR);

                if (d == -1) {
                        yyerror("Identificateur utilisé comme variable alors qu'il ne l'est pas");
                        exit(1);
                }

                $$ = creer_noeud(A_IDF, $1, d);
        }
        | variable CROCHET_OUVRANT expression1 CROCHET_FERMANT
        {
                Noeud *acces = creer_noeud(A_LISTE_IND, 0, 0);
                ajouter_fils(acces, $1);
                ajouter_frere($1, $3);
                $$ = acces;
        }
        | variable POINT IDF
        {
                Noeud *acces = creer_noeud(A_LISTE_CH, $3, 0);
                ajouter_fils(acces, $1);
                $$ = acces;
        }
        ; 

expression: expression1
        {
                $$ = $1;
                printf("Expression arithmetique reconnue ! \n");
        }
        | expression_booleenne
        {
                $$ = $1;
                printf("Expression booleenne reconnue ! \n");
        }
        ;

expression1: expression1 PLUS expression2
        {
                $$ = creer_noeud(A_PLUS, 0, 0);
                ajouter_fils($$, $1);
                ajouter_frere($1, $3);
        }
        | expression1 MOINS expression2
        {
                $$ = creer_noeud(A_MOINS, 0, 0);
                ajouter_fils($$, $1);
                ajouter_frere($1, $3);
        }
        | expression2  { $$ = $1; }
        ;

expression2: expression2 MULT expression3
        {
                $$ = creer_noeud(A_MULT, 0, 0);
                ajouter_fils($$, $1);
                ajouter_frere($1, $3);
        }
        | expression2 DIV expression3
        {
                $$ = creer_noeud(A_DIV, 0, 0);
                ajouter_fils($$, $1);
                ajouter_frere($1, $3);
        }
        | expression3  { $$ = $1; }
        ;

expression3: variable  { $$ = $1; }
        | CSTE_ENTIERE  { $$ = creer_noeud(A_CSTE_ENT, $1, 0); }
        | CSTE_REEL     { $$ = creer_noeud(A_CSTE_REELLE, $1, 0); }
        | VRAI          { $$ = creer_noeud(A_CSTE_BOOL, 1, 0); }
        | FAUX          { $$ = creer_noeud(A_CSTE_BOOL, 0, 0); }
        | IDF PARENTHESE_OUVRANTE liste_args PARENTHESE_FERMANTE
        {
                int id = $1;
                int d = association_nom(id, FCT);

                if (d == -1) {
                        fprintf(stderr, "[SEM] ERREUR : fonction '%s' non déclarée.\n",
                                tab_lexico[id].lexeme);
                        exit(1);
                }

                $$ = creer_noeud(A_APPEL_FCT, $1, d);
                if ($3 != NULL) {
                        ajouter_fils($$, $3);
                }
        }
        ;


expression_booleenne: expression_booleenne OU expression_et
        {
                $$ = creer_noeud(A_OR, 0, 0);
                ajouter_fils($$, $1);
                ajouter_frere($1, $3);
        }
        | expression_et  { $$ = $1; }
        ;

expression_et: expression_et ET expression_not
        {
                $$ = creer_noeud(A_AND, 0, 0);
                ajouter_fils($$, $1);
                ajouter_frere($1, $3);
        }
        | expression_not  { $$ = $1; }
        ;

expression_not: NON expression_not
        {
                $$ = creer_noeud(A_NOT, 0, 0);
                ajouter_fils($$, $2);
        }
        | expression_comp  { $$ = $1; }
        ;

expression_comp: expression1 INFERIEUR expression1
        {
                $$ = creer_noeud(A_INF, 0, 0);
                ajouter_fils($$, $1);
                ajouter_frere($1, $3);
        }
        | expression1 SUPERIEUR expression1
        {
                $$ = creer_noeud(A_SUP, 0, 0);
                ajouter_fils($$, $1);
                ajouter_frere($1, $3);
        }
        | expression1 EGALE expression1
        {
                $$ = creer_noeud(A_EGALE, 0, 0);
                ajouter_fils($$, $1);
                ajouter_frere($1, $3);
        }
        | expression1 INFERIEUR_EGAL expression1
        {
                $$ = creer_noeud(A_INF_EGAL, 0, 0);
                ajouter_fils($$, $1);
                ajouter_frere($1, $3);
        }
        | expression1 SUPERIEUR_EGAL expression1
        {
                $$ = creer_noeud(A_SUP_EGAL, 0, 0);
                ajouter_fils($$, $1);
                ajouter_frere($1, $3);
        }
        | expression1 DIFFERENT expression1
        {
                $$ = creer_noeud(A_DIFF, 0, 0);
                ajouter_fils($$, $1);
                ajouter_frere($1, $3);
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
        init_tab_repres();      // table des représentations
        init_tab_region();      // table des régions

        pile_region = creationPile();
        numregion = 0;
        empile(pile_region, numregion); // région 0 = globale
        creer_region(0);  // Créer la région 0 (programme principal, NIS=0)

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
        afficher_tab_repres();
        afficher_tab_region(stdout);
        
        /* Affichage des arbres de toutes les régions */
        printf("\n========================================\n");
        printf("        ARBRES ABSTRAITS\n");
        printf("========================================\n");
        
        for (int i = 0; i < get_nb_regions(); i++) {
                printf("\n--- REGION %d (NIS=%d, Taille=%d) ---\n", 
                       i, get_nis_region(i), get_taille_region(i));
                Noeud *arbre = get_arbre_region(i);
                if (arbre) {
                        afficher_arbre(arbre, 0);
                } else {
                        printf("  (arbre vide)\n");
                }
        }
        
        printf("\n========================================\n");
        printf("        FIN DU PROGRAMME\n");
        printf("========================================\n");
        return 0;
}
