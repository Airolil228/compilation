/*Anas et Yacine*/
#include <stdio.h>
#include "../include/semantique.h"

/* cumul de la taille globale */
static int total_globaux = 0;

void sem_init(void){
    init_tab_lexico();
    init_tab_decl();
    pile_region = creationPile();
    empile(pile_region, 0);
    total_globaux = 0;
}

/* Renvoie index lexico */
int sem_ident(const char *yytext){
    return inserer_lexeme((char*)yytext);
}

/* ====================== DECLARATIONS ======================= */

/* Insertion dans tab_decl */
void sem_decl_var(int id_lex, int type_code, int taille_type){
    printf("[SEM] VAR id_lex=%d type=%d\n", id_lex, type_code);
    if (taille_type <= 0) taille_type = 1;
    inserer_decl(id_lex, VAR, sommet(pile_region), type_code, taille_type);
    total_globaux += taille_type;
}

/* Paramètre formel  */
void sem_decl_param(int id_lex, int type_code, int offset){
    printf("[SEM] PARAM id_lex=%d type=%d\n", id_lex, type_code);
    if (offset < 0) offset = 0;
    inserer_decl(id_lex, PARAM, sommet(pile_region), type_code, offset);
}

/* Fonction  */
void sem_decl_fct(int id_lex, int type_retour, int etiq_exec){
    printf("[SEM] FONCTION id_lex=%d type_retour=%d\n", id_lex, type_retour);
    inserer_decl(id_lex, FCT, sommet(pile_region), type_retour, etiq_exec);
}

/* Procédure  */
void sem_decl_proc(int id_lex, int etiq_exec){
    printf("[SEM] PROCEDURE id_lex=%d\n", id_lex);
    inserer_decl(id_lex, PROC, sommet(pile_region), -1, etiq_exec);
}

/* Type de base nommé  */
void sem_decl_type_base(int id_lex, int code_type){
    inserer_decl(id_lex, TYPE_B, 0, code_type, 0);
}

/* Type struct : nature TYPE_S*/
void sem_decl_struct(int id_lex, int region_champs, int taille_struct){
    printf("[SEM] STRUCT id_lex=%d\n", id_lex);
    if (taille_struct < 0) taille_struct = 0;
    inserer_decl(id_lex, TYPE_S, sommet(pile_region), region_champs, taille_struct);
}

/* Type tableau : nature TYPE_T*/
void sem_decl_tab(int id_lex, int type_elem, int borne_inf, int borne_sup){
    printf("[SEM] TAB id_lex=%d type_elem=%d\n", id_lex, type_elem);
    int taille = 0;
    if (borne_sup >= borne_inf)
        taille = borne_sup - borne_inf + 1;
    inserer_decl(id_lex, TYPE_T, sommet(pile_region), type_elem, taille);
}

/* ====================== FIN GLOBAUX & DEBUG ======================= */

void sem_fin_globaux(void){
    /* Rien à faire tant qu'on n'a pas la table des régions */
}

void sem_dump(void){
    afficher_tab_lex(NULL);
    afficher_tab_decl(stdout);

    fprintf(stdout, "\n--- CHAÎNES PAR IDENTIFIANT ---\n");
    afficher_chaine(stdout, 0); // Anas
    afficher_chaine(stdout, 1); // bool/boolean/char selon ton lexique
    afficher_chaine(stdout, 2); // appelle / monType1 / etc.
}
