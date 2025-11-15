#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "../include/tab_decl.h"
#include "../include/tab_lexico.h"
#include "../include/pile.h"

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



int main(){

    exit(EXIT_SUCCESS);
}