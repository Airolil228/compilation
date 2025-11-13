#ifndef PILE_H
#define PILE_H

#include <stdbool.h>


// Élement de pile
typedef struct ElementPile {
	int valeur;
	struct ElementPile* suivant;
} elementPile;

// Pile qui pointe juste vers le premier élément
typedef struct Pile {
	int taille;
	elementPile* tete; 
} pile;


pile* creationPile();

void afficher_pile(pile* p); 

void empile(pile* pile, int val);

void depile(pile* pile);

int taille(pile* pile);

bool estVide(pile* pile);

int sommet(pile* pile);


#endif /* PILE_H */