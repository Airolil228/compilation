#include "../include/tab_region.h"
#include "../include/pile.h"
#include <stdlib.h> 
#include <stdio.h>

/*Bénédicte */

/* Variables globales pour la gestion des régions */
Region tab_region[TAB_REGION_MAX];
/* Note : numregion est défini dans pile.c, on y accède via extern */
extern int numregion; 
int nb_regions = 0;  

/* Définitions des globals référencées par grammaire.y */

/* Initialisation de la table des régions */
/*Bénédicte */
void init_tab_region() {
    int i; 
    for (i = 0; i < TAB_REGION_MAX; i++) {
        tab_region[i].taille = 0;
        tab_region[i].NIS = -1;
    }
    nb_regions = 0;
}

/* Crée une nouvelle région et retourne son numéro */
/*Bénédicte */

int creer_region(int nis) {
    if (nb_regions >= TAB_REGION_MAX) {
        fprintf(stderr, "Erreur : table des régions pleine\n");
        return -1;
    }
    tab_region[nb_regions].taille = 0;
    tab_region[nb_regions].NIS = nis;
    tab_region[nb_regions].arbre = NULL;  // NOUVEAU
    return nb_regions++;
}

/* Récupère le NIS d'une région */
/*Bénédicte */

int get_nis_region(int num_region) {
    if (num_region < 0 || num_region >= nb_regions) {
        fprintf(stderr, "[tab_region] ERREUR : Région %d invalide (0..%d)\n", num_region, nb_regions - 1);
        return -1;
    }
    return tab_region[num_region].NIS;
}

/* Récupère la taille d'une région */
/*Bénédicte */

int get_taille_region(int num_region) {
    if (num_region < 0 || num_region >= nb_regions) {
        fprintf(stderr, "[tab_region] ERREUR : Région %d invalide\n", num_region);
        return -1;
    }
    return tab_region[num_region].taille;
}

/* Incrémente la taille d'une région (pour allocation de variables) */
/*Bénédicte */
void incrementer_taille_region(int num_region, int increment) {
    if (num_region < 0 || num_region >= nb_regions) {
        fprintf(stderr, "[tab_region] ERREUR : Région %d invalide\n", num_region);
        return;
    }
    tab_region[num_region].taille += increment;
}

/* Affiche la table des régions */
/*Bénédicte */

void afficher_tab_region(FILE *flux) {
    if (!flux) flux = stdout;
    
    fprintf(flux, "\n==================== TABLE DES REGIONS ====================\n");
    fprintf(flux, "Nombre de régions créées : %d\n\n", nb_regions);
    
    fprintf(flux, "%-10s %-10s %-10s\n", "Numéro", "NIS", "Taille");
    fprintf(flux, "-----------------------------------------------------------\n");
    
    for (int i = 0; i < nb_regions; i++) {
        fprintf(flux, "%-10d %-10d %-10d\n",
                i,
                tab_region[i].NIS,
                tab_region[i].taille);
    }
    
    fprintf(flux, "============================================================\n\n");
}

/* Récupère le nombre total de régions */
/*Bénédicte */

int get_nb_regions() {
    return nb_regions;
}

/* 
 * Fonction de recherche : trouve la région courante via la pile
 * (utile pour les actions sémantiques)
 */
/*Bénédicte */

 int get_region_courante(pile* pile_region) {
    if (!pile_region || estVide(pile_region)) {
        return -1;  // Pas de région active
    }
    return sommet(pile_region);
}

// NOUVELLES FONCTIONS
/*Bénédicte */
noeud_t* get_arbre_region(int num_region) {
    if (num_region < 0 || num_region >= nb_regions) {
        return NULL;
    }
    return tab_region[num_region].arbre;
}
/*Bénédicte */

void set_arbre_region(int num_region, noeud_t* arbre) {
    if (num_region >= 0 && num_region < nb_regions) {
        tab_region[num_region].arbre = arbre;
    }
}