#ifndef PILE_REGION_H
#define PILE_REGION_H

#include <stdbool.h>

#define MAX_ELEMENT_REGION 5000 

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

//Une autre implementation de la pile : une implementation statique  
typedef union type_retour{
	char * chaine; 
	int entier;
	bool boolean;
	float floatant;  
} type_retour; 


typedef struct{
	type_retour  type; 
	int val; 
}noeud_pile ;

extern noeud_pile pile_exec[MAX_ELEMENT_REGION]; 
extern pile* pile_region;

pile* creationPile();

void afficher_pile(pile* p); 

void empile(pile* pile, int val);

void depile(pile* pile);

int taille(pile* pile);

bool estVide(pile* pile);

int sommet(pile* pile);


#endif /* PILE_REGION_H */