#ifndef TAB_REGION_H
#define TAB_REGION_H

#include <stdio.h>
#include "pile.h"

#define TAB_REGION_MAX 100

/* Structure d'une région */
typedef struct {
    int taille;  // Taille totale des variables de cette région (en octets)
    int NIS;     // Niveau d'Imbrication Statique
} Region;

/* Table des régions (déclarée externe) */
extern Region tab_region[TAB_REGION_MAX];
extern int nb_regions;  // Nombre de régions créées

/* Initialisation */
void init_tab_region();

/* Création de régions */
int creer_region(int nis);

/* Accesseurs */
int get_nis_region(int num_region);
int get_taille_region(int num_region);
int get_nb_regions();
int get_region_courante(pile* pile_region);

/* Modification */
void incrementer_taille_region(int num_region, int increment);

/* Affichage */
void afficher_tab_region(FILE *flux);

#endif /* TAB_REGION_H */
