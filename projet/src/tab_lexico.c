#include "../include/tab_lexico.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

//#include "../include/types.h"

/*
int nb_lexemes(){
    int nb_lexeme = 0;
    
    for(int i = 0; i < TAB_LEXICO_H ; ++i){
        if(tab_lexico[i].longueur_lexeme == -1){
            ++nb_lexeme;  
        }
    } 
    return nb_lexeme; 
}
*/

int nb_lexemes(){
    int nb_lexeme = 0;
    
    for(int i = 0; i < MAX_TAB_LEXICO ; ++i){
        if(tab_lexico[i].longueur != 0){
            ++nb_lexeme;  
        }
    } 
    return nb_lexeme; 
}

int hachage(char *lexeme){
    int car; 
    int hash = 0; 
    int long_lex = strlen(lexeme); 
    int i = 0;

    while( i < long_lex){
        hash += car; 
        car = *lexeme;
        *lexeme++;  
        hash += car;
        i++;  
    }
    return hash % 20; 
}

int longeur_lexeme(char *lexeme){
    if(lexeme != NULL){
        return strlen(lexeme); 
    }else{
        fprintf(stderr,"Lexeme est nulle \n");   
        return -1; 
    }
}

void inserer_lexeme_primitif(){
    for(int i = 0; i < 4; ++i){
        tab_lexico[i].longueur = longeur_lexeme(lexemes_prim[i]);
        strcpy(tab_lexico[i].lexeme,lexemes_prim[i]); 
    }
}

/* Affiche le contenu de la table */

void afficher_tab_lex(FILE *flux) {
    if (!flux) flux = stdout;

    fprintf(flux, "\n===== TABLE DES LEXEMES =====\n");
    //fprintf(flux, "Zone de débordement: [%d .. %d]  (utilisées : %d)\n\n",
    //        Zone_de_debordement, Taille_TAB, zone_de_deb_utiliser);

    fprintf(flux, "%-8s %-10s %-10s %-10s \n",
            "Index", "long", "lexème", "suivant");

    fprintf(flux, "---------------------------------------------------------------\n");
    for (int i = 0; i < nb_lexemes() ; i++) {
        if (tab_lexico[i].longueur != 0) {
            fprintf(flux, "%-8d %-10d %-10s %-10d\n",
                    i, tab_lexico[i].longueur, tab_lexico[i].lexeme, tab_lexico[i].suivant);
        }
    }

    fprintf(flux, "===============================================================\n\n");
}

int est_lexeme_primitif(char *lexeme){
    for(int i = 0; i < MAX_LEXEME_PRIM; ++i){
        if(strcmp(lexeme, lexemes_prim[i]) == 0){
            return 1; 
        }
    }
    return 0;
}

int prochaine_case_vide_table_lexico(){
    
}

int inserer_lexeme(char *lexeme){
    int index,longeur;
    
    if(est_lexeme_primitif(lexeme) == 1){
        printf("Lexeme primitif, pas besoin d'insertion \n");
        return -1;
    }

    index = hachage(lexeme);
    longeur = longeur_lexeme(lexeme);
    
}


void init_tab_lexico(){
    for(int i = 0; i < MAX_TAB_LEXICO; ++i){
        tab_lexico[i].longueur = 0; 
        tab_lexico[i].suivant = -1; 
    }

    //inserer les types primitives
    inserer_lexeme_primitif();
}

/*
bool chercher_lexeme(char * lexeme){
    int i = 0; 
    for(i = 0; i < ; i++){
        if(strcmp(,)){
            return true;  
        }
    }
    return false; 
}
*/



int main(){
    init_tab_lexico();
    afficher_tab_lex(NULL); 

    exit(-1); 
}
