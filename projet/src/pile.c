#include "../include/pile.h"
#include <stdio.h>
#include <stdlib.h>

pile creer_noeud() {
    pile p = (pile) malloc(sizeof(struct Pile));
    
    if (!p) {
        fprintf(stdout, "Erreur d'allocation mémoire pour le noeud\n");
        exit(EXIT_FAILURE);
    }

    p->sommet = NULL;
    return p;
}

int main() {
    pile ma_pile = creer_noeud();
    if (ma_pile != NULL) {
        printf("Pile créée avec succès.\n");
    } else {
        printf("Échec de la création de la pile.\n");
    }
    free(ma_pile);
    
}