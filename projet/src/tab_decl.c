#include "../include/tab_decl.h"
#include "../include/tab_lexico.h"
#include <string.h>

int zone_de_deb_utiliser = 0;
int numregion = 0;
TAB_DE_Decl tab_de_dec[Taille_TAB];

/* Initialisation de la table de declaration */
void init_tab_decl() {
    for (int i = 0; i < Taille_TAB; i++) {
        tab_de_dec[i].nature = -1;
        tab_de_dec[i].suivant = -1;
        tab_de_dec[i].region = -1;
        tab_de_dec[i].description = -1;
        tab_de_dec[i].exec = 0;
    }
    zone_de_deb_utiliser = 0;

    for(int i = 0; i < MAX_LEXEME_PRIM; i++){
        inserer_decl(i,0,0,i,1);
    }
}

int inserer_decl(int lex_id, int nature, int region, int description, int exec) {
    if (lex_id < 0 || lex_id >= Zone_de_debordement) {
        /* lex_id doit être dans la zone PRIMAIRE uniquement */
        fprintf(stderr,"[tabdecl] inserer_decl: lex_id=%d hors de la primaire [0..%d]\n", lex_id, Zone_de_debordement - 1);
        return -1;
    }

    if (nature < 0 || nature > FCT) {
        fprintf(stderr,"[tabdecl] inserer_decl: nature %d invalide (attendu 0..6)\n", nature);
        return -1;
    }

    /* Préparer l’enregistrement */
    TAB_DE_Decl rec;
    rec.nature = nature;
    rec.suivant = -1;          
    rec.region = region;
    rec.description = description;
    rec.exec = exec;

    /* Cas 1 : la case primaire (lex_id) est libre */
    if (tab_de_dec[lex_id].nature == 0) {
        tab_de_dec[lex_id] = rec;
        return lex_id; 
    }

    /* Cas 2 : insérer en DÉBORDEMENT */
    int indice_deb = Zone_de_debordement + zone_de_deb_utiliser;
    if (indice_deb > Taille_TAB) {
        /* Plus de place en débordement */
        fprintf(stderr, "[tabdecl] inserer_decl: zone de débordement pleine (prochain=%d, max=%d)\n", indice_deb, Taille_TAB);
        return -1;
    }

    /* Placer le nouvel enregistrement dans la table (partie débordement) */
    tab_de_dec[indice_deb] = rec;
    zone_de_deb_utiliser++; /* on a consommé une case de débordement */

    /* Chaînage : relier depuis la case primaire à la fin de la chaîne */
    if (tab_de_dec[lex_id].suivant == -1) {
        /* pas encore de débordement pour ce lexème */
        tab_de_dec[lex_id].suivant = indice_deb;
        return indice_deb;
    }

    /* Sinon, parcourir la chaîne jusqu’au dernier maillon */
    int indice_chaine = tab_de_dec[lex_id].suivant;
    while (tab_de_dec[indice_chaine].suivant != -1) {
        indice_chaine = tab_de_dec[indice_chaine].suivant;
    }
    tab_de_dec[indice_chaine].suivant = indice_deb;
    return indice_deb;
}


/* Fonction d'affichage de la table des déclarations */
/* - Affiche chaque case non vide (nature != 0) */
static const char* nature_str(int n) {
    switch (n) {
        case TYPE_B: return "TYPE_B"; 
        case TYPE_S: return "TYPE_S";
        case TYPE_T: return "TYPE_T";
        case VAR:    return "VAR";
        case PARAM:  return "PARAM";
        case PROC:   return "PROC";
        case FCT:    return "FCT";
    }
    return "vide"; 
}

/* Affiche le contenu de la table */
void afficher_tab_decl(FILE *flux) {
    if (!flux) flux = stdout;

    fprintf(flux, "\n===== TABLE DES DECLARATIONS =====\n");
    fprintf(flux, "Zone primaire      : [0 .. %d]\n", Zone_de_debordement - 1);
    fprintf(flux, "Zone de débordement: [%d .. %d]  (utilisées : %d)\n\n",
            Zone_de_debordement, Taille_TAB, zone_de_deb_utiliser);

    fprintf(flux, "%-8s %-10s %-10s %-10s %-12s %-10s\n",
            "Index", "Nature", "Suivant", "Region", "Description", "Exec");
    fprintf(flux, "---------------------------------------------------------------\n");

    for (int i = 0; i < Taille_TAB; i++) {
        if (tab_de_dec[i].nature != -1) {
            fprintf(flux, "%-8d %-10s %-10d %-10d %-12d %-10d\n",
                    i,
                    nature_str(tab_de_dec[i].nature),
                    tab_de_dec[i].suivant,
                    tab_de_dec[i].region,
                    tab_de_dec[i].description,
                    tab_de_dec[i].exec);
        }
    }
    fprintf(flux, "===============================================================\n\n");
}

/* Affiche uniquement la chaîne d’un identificateur donné
   (utile pour vérifier les liens de débordement) */
void afficher_chaine(FILE *flux, int lex_id) {
    if (!flux) flux = stdout;  /* sécurité */
    if (lex_id < 0 || lex_id >= Zone_de_debordement) {
        fprintf(flux, "Identificateur %d hors zone primaire.\n", lex_id);
        return;
    }
    if (tab_de_dec[lex_id].nature == 0) {
        fprintf(flux, "Aucune déclaration pour le lexème %d.\n", lex_id);
        return;
    }

    fprintf(flux, "\nChaîne de l'identificateur %d :\n", lex_id);
    int courant = lex_id;
    while (courant != -1) {
        TAB_DE_Decl *decl = &tab_de_dec[courant];
        fprintf(flux, "  [%d] nature=%s  region=%d  desc=%d  exec=%d  suivant=%d\n",
                courant,
                nature_str(decl->nature),
                decl->region,
                decl->description,
                decl->exec,
                decl->suivant);
        courant = decl->suivant;
    }
    fprintf(flux, "\n");
}


//int main() {
    //init_tab_decl();

    /*
    inserer_decl(10, VAR, 0, 0, 0);
    inserer_decl(10, VAR, 1, 0, 5);
    inserer_decl(15, PROC, 0, 2, 10);
    */

    /* Afficher sur la console */
    // afficher_tab_decl(stdout);

    /* Afficher la chaîne du lexème 10 */
    // afficher_chaine(stderr, 10);

    /* Afficher dans un fichier */
    //FILE *f = fopen("table_decl.txt", "w");
    //afficher_tab_decl(f);
    //afficher_chaine(f, 10);
    //fclose(f);
//}
