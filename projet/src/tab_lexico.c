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
        car = *lexeme;
        hash += car;
        lexeme++;  
        i++;  
    }
    return hash % 32; 
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

    fprintf(flux, "\n==================== TABLE DES LEXEMES ====================\n");
    //fprintf(flux, "Zone de débordement: [%d .. %d]  (utilisées : %d)\n\n",
    //        Zone_de_debordement, Taille_TAB, zone_de_deb_utiliser);

    fprintf(flux, "%-8s %-10s %-10s %-10s \n",
            "Index", "long", "lexème", "suivant");

    fprintf(flux, "---------------------------------------------------------------\n");
    for (int i = 0; i < MAX_TAB_LEXICO ; i++) {
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
    int i = 0; 
    while( tab_lexico[i].longueur != 0){
		i++; 
		if(i == MAX_TAB_LEXICO ){
		   fprintf(stderr,"La table lexicale est pleine ! \n");
		   exit(EXIT_FAILURE); 
		}
	}
	return i;
}

void inserer_deux_premier_champ(char *lexeme,int index){
	tab_lexico[index].longueur = longeur_lexeme(lexeme);                                                                                                                            
	strcpy(tab_lexico[index].lexeme, lexeme);
}



int inserer_lexeme(char *lexeme){
    int index,longueur,case_vide, suite ; 
    int var_temp ; 
    
    if(est_lexeme_primitif(lexeme) == 1){
        printf("Lexeme primitif, pas besoin d'insertion \n");
        return -1;
    }

    index = hachage(lexeme);
    longueur = longeur_lexeme(lexeme);
    case_vide = prochaine_case_vide_table_lexico();
    
    //s'il y a de la place à inserer => insère 
    if( tab_lexico[index].longueur == 0 ){
		
		inserer_deux_premier_champ(lexeme,index);    
	}else{
		/* on parcours jusqu'au on trouve la place pour notre lexeme */
		while(suite){ 
			/*Le cas ou lexeme existe déjâ */
			if(tab_lexico[index].longueur == longueur &&  strcmp(tab_lexico[index].lexeme, lexeme)){ 
				suite = 0; /* sort d'un boucle*/
			}
			if(suite){ /* on trouve le nouveau suivant et on l'insere   */
				var_temp = index; 
				index = tab_lexico[index].suivant;
				
				if( index == -1 ){
					index = prochaine_case_vide_table_lexico(); 
					tab_lexico[var_temp].suivant = index;  
					
					inserer_deux_premier_champ(lexeme,index);                                                                                            
                    suite = 0;  
				} 
			}
		}
	}
	
    
    return index;
    
}


void init_tab_lexico(){
    for(int i = 0; i < MAX_TAB_LEXICO; ++i){
        tab_lexico[i].longueur = 0; 
        tab_lexico[i].suivant = -1; 
    }

    //inserer les types primitives
    inserer_lexeme_primitif();
}


int main(){
    init_tab_lexico();
    afficher_tab_lex(NULL);
     
	inserer_lexeme("beaucoup"); 
	inserer_lexeme("caffard");
	inserer_lexeme("boucle");
	
	
	afficher_tab_lex(NULL);
	
	
    exit(-1); 
}
