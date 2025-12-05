/*Anas et Yacine*/
#ifndef ARBRE_H
#define ARBRE_H

#include <stdio.h>

/* Types de nœuds */
typedef enum {

    /* Feuilles */
    A_IDF,
    A_CSTE_ENT,
    A_CSTE_REELLE,
    A_CSTE_BOOL,

    /* Listes */
    A_LISTE,
    A_LISTE_IND,
    A_LISTE_CH,
    A_LISTE_PARAM,

    /* Affectation */
    A_OPAFF,
    A_RETOURNE,

    /* Appels */
    A_APPEL_PROC,
    A_APPEL_FCT,

    /* Opérations arithmétiques */
    A_PLUS,
    A_MOINS,
    A_MULT,
    A_DIV,
    A_MODULO,

    /* Opérations logiques */
    A_OR,
    A_AND,
    A_NOT,

    /* Comparaisons */
    A_INF,
    A_SUP,
    A_INF_EGAL,
    A_SUP_EGAL,
    A_DIFF,
    A_EGAL, 

    /* Instructions */
    A_IF_THEN_ELSE,
    A_WHILE

} NoeudType;


/* Structure d'un nœud */
typedef struct noeud {
    NoeudType type;
    int lexnum;     /* numéro lexicographique */
    int declnum;    /* numéro de déclaration  */
    struct noeud *fils_gauche;  /* fils gauche */
    struct noeud *frere_droit; /* frère droit */
} Noeud;

/* Création d'un nouveau nœud */
Noeud *creer_noeud(NoeudType type, int lexnum, int declnum);

/* Ajoute un fils gauche à un nœud */
void ajouter_fils(Noeud *parent, Noeud *fils);

/* Ajoute un frère droit à un nœud */
void ajouter_frere(Noeud *noeud, Noeud *frere);

static void afficher_arbre_prefix(Noeud *n, const char *prefix, int isLast);

/* Affichage lisible de l'arbre abstrait */
void afficher_arbre(Noeud *racine);

/* Libération mémoire */
void detruire_arbre(Noeud *racine);

#endif /* ARBRE_H */
