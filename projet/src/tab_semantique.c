#include <stdio.h>
#include "../include/tab_semantique.h"

/* cumul (optionnel) de la taille globale si tu veux suivre les tailles */
static int total_globaux = 0;

void sem_init(void){
    init_tab_lexico();
    init_tab_decl();
    total_globaux = 0;
}

/* Renvoie index lexico (crée si nécessaire) */
int sem_ident(const char *yytext){
    return inserer_lexeme((char*)yytext);
}

/* Insertion dans tab_decl -> tout en région 0 */
void sem_decl_var(int id_lex, int type_code, int taille_type){
    if (taille_type <= 0) taille_type = 1;
    /* description := code type ; exec := taille (ou offset selon ton choix) */
    inserer_decl(id_lex, VAR, 0, type_code, taille_type);
    total_globaux += taille_type;
}

void sem_fin_globaux(void){
    /* Rien à faire tant qu'on n'a pas la table des régions */
}

void sem_dump(void){
    afficher_tab_lex(NULL);
    afficher_tab_decl(stdout);
}
