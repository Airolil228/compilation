    #include <stdlib.h>
    #include <stdio.h>
    #include <string.h>
    #include <stdbool.h>

    #include "../include/tab_lexico.h"
    //#include "../include/types.h"
    
    int premier_el_vide_tablexico = 4 ; // les 4 premiers sont pour les lexèmes primitifs
    int indice_vide_tab_hashcode; 

    table_lexico tab_lexico[MAX_TAB_LEXICO];
    char *lexemes_prim[MAX_LEXEME_PRIM] = {"entier", "double", "char", "boolean"};
    int tab_hashcode[MAX_TAB_HASHCODE] ; 

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

        fprintf(flux, "Contenu de la table de hachage : \n");
        for(int i = 0; i < MAX_TAB_HASHCODE ; ++i){
            fprintf(flux, "tab_hashcode[%d] = %d \n", i, tab_hashcode[i]);
        }
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
        premier_el_vide_tablexico++;
    }

int inserer_lexeme(char * lexeme){
    int hash = hachage(lexeme); 
    int val_tab_hashcode = tab_hashcode[hash]; // valeur actuelle dans la table de hachage
    
    if(val_tab_hashcode == -1){ // pas de collision
        tab_hashcode[hash] = premier_el_vide_tablexico;
        inserer_deux_premier_champ(lexeme, premier_el_vide_tablexico);
        return premier_el_vide_tablexico - 1; // on retourne l'index où on a inséré le lexème
    }

    // Collision : traverser la chaîne depuis val_tab_hashcode
    int current = val_tab_hashcode;
    while(current != -1){
        if(strcmp(tab_lexico[current].lexeme, lexeme) == 0){
            return current; // Lexème trouvé, retourner l'index existant
        }
        if(tab_lexico[current].suivant == -1){
            // Fin de la chaîne, insérer ici
            tab_lexico[current].suivant = premier_el_vide_tablexico; 
            inserer_deux_premier_champ(lexeme, premier_el_vide_tablexico);
            return premier_el_vide_tablexico - 1; 
        }
        current = tab_lexico[current].suivant; 
    }

    // Ne devrait pas arriver si la chaîne est correcte
    fprintf(stderr, "Erreur: chaîne corrompue pour hash %d\n", hash);
    exit(EXIT_FAILURE);
}


    void init_tab_lexico(){
        for(int i = 0; i < MAX_TAB_LEXICO; ++i){
            tab_lexico[i].longueur = 0; 
            tab_lexico[i].suivant = -1; 
        }

        for(int j = 0; j < MAX_TAB_HASHCODE; ++j){
            tab_hashcode[j] = -1; 
        }
        //inserer les types primitives
        inserer_lexeme_primitif();
    }


/*
    int main(){
         init_tab_lexico();
         afficher_tab_lex(NULL);

        inserer_lexeme("variable1");
        inserer_lexeme("variable1");
        inserer_lexeme("variable2");
        inserer_lexeme("variable3435");
        
         afficher_tab_lex(NULL);
         exit(-1);
    }
*/   