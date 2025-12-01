#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "../include/tab_repres.h"
#include "../include/tab_decl.h"
#include "../include/tab_lexico.h"

/*Vasily*/
int tab_repres_entet[MAX_TAB_REPRES]; 
int indice_table_repres  = 0; 
int offset = 0;
int deplacement = 0; 

/*Vasily*/
void init_tab_repres(){
    for(int i = 0; i < MAX_TAB_REPRES; i++){
        tab_repres_entet[i] = -1;
    }
}


/*Vasily*/
void afficher_tab_repres(){
    fprintf(stdout, "\n==================== TABLE DES REPRES DES TYPES ====================\n");
        for(int i = 0; i < MAX_TAB_REPRES; i++ ){
            if(tab_repres_entet[i] != -1){
                fprintf(stdout,"%d ",tab_repres_entet[i]); 
            }
        }         
    fprintf(stdout, "\n=====================================================================\n");

}

/*Vasily*/
int getElementRepres(int index){
    if( index > 0 && index < MAX_TAB_REPRES ){
        return tab_repres_entet[index];
    }else{
        fprintf(stderr,"Indice non valide \n"); 
    }
    return -1;
}

/*Vasily*/
void insereNbchampsTabReprese(int index_nb_champs,int nb_champs){
    tab_repres_entet[index_nb_champs] = nb_champs; 
}

/*Vasily*/
void insereTabRepres(int val){
    tab_repres_entet[indice_table_repres] = val; 
    indice_table_repres++;
}


/*Vasily*/
int taille_tab_repres(){
    int taille = 0; 
    while( tab_repres_entet[taille] != -1){
        taille += 1; 
    }
    return taille; 
}

/*Vasily*/
void initDepl(){
    deplacement = 0;
}

/*Vasily*/
int getTaille(int ind_decl){
    if(ind_decl < 0 ){
        fprintf(stderr,"Erreur d'indice dans la tab de réprese"); 
        return -1;
    }
    
    int nature_var = tab_de_dec[ind_decl].nature; 
    
    switch(nature_var){
        case TYPE_B:
            printf("Le type primitif\n");
            return 1;
        break;
    }

    return -1;
}

/*Vasily*/
int deplacer(int taille){
    return (deplacement+=taille)-1; 
}