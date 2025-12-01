#include "../include/pile.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int numregion = 0;
pile* pile_region = NULL;

/*Vasily */
// Création d'une pile vide
pile* creationPile() {
        pile* pile = malloc(sizeof(pile));
        pile->taille = 0;
        pile->tete = NULL;
        return pile;
}

/*Vasily */
void afficher_pile(pile* p){
    elementPile* current = p->tete;

    printf("Pile : ");
    while(current != NULL){
        printf("%d ", current->valeur);
        current = current->suivant;
    }
    printf("\n");
}

/*Vasily */
void empile(pile* pile, int val) {
        // On crée un nouvel élément
        elementPile* e = malloc(sizeof(elementPile));
        e->valeur = val;
        // On le met à la tête de la pile
        e->suivant = pile->tete;
        pile->tete = e;
        pile->taille++;
}

/*Vasily */
void depile(pile* pile) {
        if (pile->tete == NULL)
                return;
        elementPile* e = pile->tete;
        // On enlève le premier élément
        pile->tete = e->suivant;
        free(e);
        pile->taille--;
}

/*Vasily */
int taille(pile* pile) {
        return pile->taille;
}

/*Vasily */
bool estVide(pile* pile) {
        return (pile->taille == 0);
}

/*Vasily */
int sommet(pile* pile) {
        return pile->tete->valeur;
}