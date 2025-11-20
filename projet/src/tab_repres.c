#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "../include/tab_repres.h"
#include "../include/tab_decl.h"
#include "../include/tab_repres.h"


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

void inserer_type_struct_tab_repres(int num_lex, int nb_champ, int type){
     int position = 0;
     int i = 1;  
     tab_repres_entet[indice_table_repres] = nb_champ;
     indice_table_repres++;

     tab_repres_entet[indice_table_repres] = num_lex; 
     indice_table_repres++;
     tab_repres_entet[indice_table_repres] = type; 
     indice_table_repres++;
     tab_repres_entet[indice_table_repres] = position; 
     indice_table_repres++;

     while( i <= nb_champ){
        printf("[DEBUG] Champ %d de la structure %d traité\n", i, num_lex);
        i++;
     }
     offset += nb_champ; // Supposons 1 unité par champ     
     printf("[DEBUG] Structure %d insérée avec %d champs\n", num_lex, nb_champ);
    }

/*
int main(){
    init_tab_repres(); 
    afficher_tab_repres();
    
    exit(EXIT_SUCCESS);
}
*/