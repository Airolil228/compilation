#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "../include/tab_repres.h"
#include "../include/tab_decl.h"
#include "../include/tab_lexico.h"


int tab_repres_entet[MAX_TAB_REPRES]; 
int indice_table_repres  = 0; 
int offset = 0;

void init_tab_repres(){
    for(int i = 0; i < MAX_TAB_REPRES; i++){
        tab_repres_entet[i] = -1;
    }
}


void afficher_tab_repres(){
    fprintf(stdout, "\n==================== TABLE DES REPRES DES TYPES ====================\n");
        for(int i = 0; i < MAX_TAB_REPRES; i++ ){
            if(tab_repres_entet[i] != -1){
                fprintf(stdout,"%d ",tab_repres_entet[i]); 
            }
        }         
    fprintf(stdout, "\n=====================================================================\n");

}

int getElementRepres(int index){
    if( index > 0 && index < MAX_TAB_REPRES ){
        return tab_repres_entet[index];
    }else{
        fprintf(stderr,"Indice non valide \n"); 
    }
    return -1;
}

void insereNbchampsTabReprese(int index_nb_champs,int nb_champs){
    tab_repres_entet[index_nb_champs] = nb_champs; 
    indice_table_repres++; 
}

void insereTabRepres(int val){
    tab_repres_entet[indice_table_repres] = val; 
    indice_table_repres++;
}

int taille_tab_repres(){
    int taille = 0; 
    while( tab_repres_entet[taille] != -1){
        taille += 1; 
    }
    return taille; 
}