//Ce module a été realiser par le VASILY 
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


#include "../include/tab_decl.h"
#include "../include/tab_lexico.h"
//#include "../include/pile_region.h"
//#include "../include/types.h"
#include "../include/tab_repres.h"

/*
void init_pile_exection(){
    for(int i = 0; i < MAX_ELEMENT_REGION; i++){
          pile_exec[i].type = -1; 
          pile_exec[i].val = -1; 
    }
}

void affiche_pile_execution(){
    fprintf(stdout,"Pile d'éxecution: \n");
    for(int i = 0; i < MAX_ELEMENT_REGION; i++){
        type_retour type_r = pile_exec[i].type; 
        if( type_r != -1){
            switch(type_r){
            case  entier:
                fprintf(stdout,"%d ", type_r);
            break; 
            case  floatant:
                fprintf(stdout,"%d ", type_r);
            break;
            }
        }else{  
            fprintf(stdout,"VIDE"); 
        }
    }
}
*/

/*Vasily*/
int tab_repres_entet[MAX_TAB_REPRES]; 
int indice_table_repres  = 0; 
int offset = 0;
int deplacement = 0;
int deplacement_courant[100];  /* Déplacement pour chaque région */ 

/*Vasily*/
void init_tab_repres(){
    for(int i = 0; i < MAX_TAB_REPRES; i++){
        tab_repres_entet[i] = -1;
    }
    for(int i = 0; i < 100; i++){
        deplacement_courant[i] = 0;
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
    return  taille;
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
    
    /* Types de base : 1=entier, 2=reel, 3=bool, 4=char */
    if (ind_decl >= 0 && ind_decl < NB_TYPES_DE_BASE) {
        return 4;  /* Sur une machine C, tous les types de base font 4 octets (sizeof(int) = sizeof(float) = 4) */
    }
    
    int nature_var = tab_de_dec[ind_decl].nature; 
    
    switch(nature_var){
        case TYPE_B:
            return 4;  /* type de base : 4 octets */
        
        case TYPE_S: {
            /* Structure : calculer la somme des tailles des champs */
            int index_repres = tab_de_dec[ind_decl].description;
            int nb_champs = tab_repres_entet[index_repres];
            int taille_totale = 0;
            int pos = index_repres + 1;
            
            for (int i = 0; i < nb_champs; i++) {
                int type_champ = tab_repres_entet[pos + 1]; /* type du champ */
                taille_totale += getTaille(type_champ);      /* récursif */
                pos += 3; /* passer au champ suivant (lex, type, depl) */
            }
            return taille_totale;
        }
        
        case TYPE_T: {
            /* Tableau : taille_element * produit_dimensions */
            int index_repres = tab_de_dec[ind_decl].description;
            int type_element = tab_repres_entet[index_repres];
            int nb_dim = tab_repres_entet[index_repres + 1];
            int taille_element = getTaille(type_element);
            int nb_elements = 1;
            
            int pos = index_repres + 2;
            for (int i = 0; i < nb_dim; i++) {
                int borne_inf = tab_repres_entet[pos];
                int borne_sup = tab_repres_entet[pos + 1];
                nb_elements *= (borne_sup - borne_inf + 1);
                pos += 2;
            }
            return taille_element * nb_elements;
        }
        
        case VAR:
        case PARAM: {
            /* Variable ou paramètre : récupérer la taille de son type */
            int type_var = tab_de_dec[ind_decl].description;
            return getTaille(type_var);
        }
    }

    return 4;  /* par défaut */
}

/*Vasily*/
int deplacer(int taille){
    return (deplacement+=taille)-1; 
}

int sauvegarde_tab_repres(FILE *f)
{
    if (!f) return -1;

    if (fwrite(&indice_table_repres, sizeof(indice_table_repres), 1, f) != 1)
        return -1;

    if (fwrite(&deplacement, sizeof(deplacement), 1, f) != 1)
        return -1;

    if (fwrite(deplacement_courant, sizeof(deplacement_courant[0]), 100, f) != 100)
        return -1;

    if (fwrite(tab_repres_entet, sizeof(tab_repres_entet[0]), MAX_TAB_REPRES, f) != (size_t)MAX_TAB_REPRES)
        return -1;

    return 0;
}

int charger_tab_repres(FILE *f)
{
    if (!f) return -1;

    init_tab_repres(); /* remet -1 partout + déplacements à 0 */

    if (fread(&indice_table_repres, sizeof(indice_table_repres), 1, f) != 1)
        return -1;

    if (indice_table_repres < 0 || indice_table_repres > MAX_TAB_REPRES)
        return -1;

    if (fread(&deplacement, sizeof(deplacement), 1, f) != 1)
        return -1;

    if (fread(deplacement_courant, sizeof(deplacement_courant[0]), 100, f) != 100)
        return -1;

    if (fread(tab_repres_entet, sizeof(tab_repres_entet[0]), MAX_TAB_REPRES, f) != (size_t)MAX_TAB_REPRES)
        return -1;

    return 0;
}
