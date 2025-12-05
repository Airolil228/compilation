/*Anas et Yacine*/
#include "../include/arbre.h"
#include <stdlib.h>
#include <string.h>

/* Convertit un NoeudType en chaîne */
static const char *noeud_type_vers_chaine(NoeudType t) {
    switch (t) {
        /* Feuilles */
        case A_IDF: return "A_IDF";
        case A_CSTE_ENT: return "A_CSTE_ENT";
        case A_CSTE_REELLE: return "A_CSTE_REELLE";
        case A_CSTE_BOOL: return "A_CSTE_BOOL";

        /* Listes */
        case A_LISTE: return "A_LISTE";
        case A_LISTE_IND: return "A_LISTE_IND";
        case A_LISTE_CH: return "A_LISTE_CH";
        case A_LISTE_PARAM: return "A_LISTE_PARAM";

        /* Affectation */
        case A_OPAFF: return "A_OPAFF";
        case A_RETOURNE: return "A_RETOURNE";

        /* Appels */
        case A_APPEL_PROC: return "A_APPEL_PROC";
        case A_APPEL_FCT: return "A_APPEL_FCT";

        /* Opérations arithmétiques */
        case A_PLUS: return "A_PLUS";
        case A_MOINS: return "A_MOINS";
        case A_MULT: return "A_MULT";
        case A_DIV: return "A_DIV";
        case A_MODULO: return "A_MODULO";

        /* Opérations logiques */
        case A_OR: return "A_OR";
        case A_AND: return "A_AND";
        case A_NOT: return "A_NOT";

        /* Comparaisons */
        case A_INF: return "A_INF";
        case A_SUP: return "A_SUP";
        case A_INF_EGAL: return "A_INF_EGAL";
        case A_SUP_EGAL: return "A_SUP_EGAL";
        case A_DIFF: return "A_DIFF";
        case A_EGAL: return "A_EGAL";

        /* Instructions */
        case A_IF_THEN_ELSE: return "A_IF_THEN_ELSE";
        case A_WHILE: return "A_WHILE";

        default: return "UNCONNU";
    }
}

/* Création d'un nouveau noeud */
Noeud *creer_noeud(NoeudType type, int lexnum, int declnum) {
    Noeud *n = (Noeud *) malloc(sizeof(Noeud));
    if (n == NULL) {
        perror("Erreur : malloc");
        return NULL;
    }
    n->type = type;
    n->lexnum = lexnum;
    n->declnum = declnum;
    n->fils_gauche = NULL;
    n->frere_droit = NULL;
    return n;
}

/* Ajoute un frère droit */
void ajouter_frere(Noeud *noeud, Noeud *frere) {
    if (noeud == NULL) return;

    Noeud *cur = noeud;
    while (cur->frere_droit != NULL) {
        cur = cur->frere_droit;
    }
    cur->frere_droit = frere;
}

/* Ajoute un fils gauche */
void ajouter_fils(Noeud *parent, Noeud *fils) {
    if (parent == NULL) return;
    parent->fils_gauche = fils;
    
}

static void afficher_arbre_prefix(Noeud *n, const char *prefix, int isLast) {
    if (!n) 
        return;
    printf("%s%s", prefix, (isLast ? "└── " : "├── "));

    /* Affichage du contenu du noeud */
    printf("%s (lex=%d, decl=%d)\n",
           noeud_type_vers_chaine(n->type),
           n->lexnum,
           n->declnum);

    /* Préfixe pour les enfants */
    char newPrefix[512];
    snprintf(newPrefix, sizeof(newPrefix), "%s%s",
             prefix, (isLast ? "    " : "│   "));

    /* Lister tous les fils du noeud */
    Noeud *child = n->fils_gauche;
    while (child) {
        Noeud *next = child->frere_droit;
        afficher_arbre_prefix(child, newPrefix, next == NULL);
        child = next;
    }
}

void afficher_arbre(Noeud *racine) {
    if (!racine) {
        printf("(arbre vide)\n");
        return;
    }
    /* Racine sans préfixe */
    printf("%s (lex=%d, decl=%d)\n",
           noeud_type_vers_chaine(racine->type),
           racine->lexnum,
           racine->declnum);

    /* Afficher ses fils */
    Noeud *child = racine->fils_gauche;
    while (child) {
        Noeud *next = child->frere_droit;
        afficher_arbre_prefix(child, "", next == NULL);
        child = next;
    }
}

/* Libération mémoire : détruit récursivement fils et frères */
void detruire_arbre(Noeud *racine) {
    if (racine == NULL) return;

    if (racine->fils_gauche != NULL) {
        detruire_arbre(racine->fils_gauche);
        racine->fils_gauche = NULL;
    }
    if (racine->frere_droit != NULL) {
        detruire_arbre(racine->frere_droit);
        racine->frere_droit = NULL;
    }

    free(racine);
}