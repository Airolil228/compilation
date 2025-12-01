#ifndef TAB_LEXICO_H
#define TAB_LEXICO_H
/*VASILY*/
#include <stdio.h>
#include <stdlib.h>

/*VASILY*/
#define MAX_TAB_LEXICO 500 // Taille de la table lexicale
#define MAX_LEXEME_PRIM 4  // Nombre de lexèmes primitifs <=> lexèmes base 
#define MAX_TAB_HASHCODE 32 // Taille de la table de hachage

/*VASILY*/
typedef struct{
    int longueur;      // longueur du lexème
    char lexeme[100];  // le lexème lui-même
    int suivant;      // index du prochain lexème en cas de collision
} table_lexico;

/*VASILY*/
extern table_lexico tab_lexico[MAX_TAB_LEXICO];

/*VASILY*/
extern char *lexemes_prim[MAX_LEXEME_PRIM];

/*VASILY*/
int inserer_lexeme(char *lexeme);

/*VASILY*/
int rechercher_lexeme(char *lexeme);

/*VASILY*/
void init_tab_lexico();

/*VASILY*/
void afficher_tab_lex();

#endif /* TAB_LEXICO_H */