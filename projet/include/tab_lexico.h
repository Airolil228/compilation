#ifndef TAB_LEXICO_H
#define TAB_LEXICO_H

#include <stdio.h>
#include <stdlib.h>

#define MAX_TAB_LEXICO 500 // Taille de la table lexicale
#define MAX_LEXEME_PRIM 4  // Nombre de lexèmes primitifs

typedef struct{
    int longueur;      // longueur du lexème
    char lexeme[100];  // le lexème lui-même
    int suivant;      // index du prochain lexème en cas de collision
} table_lexico;

table_lexico tab_lexico[MAX_TAB_LEXICO];

extern char *lexemes_prim[MAX_LEXEME_PRIM] = {"entier", "double", "char", "boolean"};

int inserer_lexeme(char *lexeme);

int rechercher_lexeme(char *lexeme);

void init_tab_lexico();

void afficher_tab_lexico();

#endif /* TAB_LEXICO_H */