/*Anas et Yacine*/
/*#ifdef TEST_ASSOC_NOM*/
#include "../include/semantique.h"
#include <string.h>

TAB_DE_Decl tab_de_dec[Taille_TAB];
int zone_de_deb_utiliser = 0;
extern pile* pile_region;

/* Initialisation de la table de declaration */
void init_tab_decl(){
    for (int i = 0; i < Taille_TAB; i++) {
        if( i >= 0 && i < NB_TYPES_DE_BASE ) {
            /* Initialiser les types de base prédéfinis */
            tab_de_dec[i].nature = TYPE_B;
            tab_de_dec[i].suivant = -1;
            tab_de_dec[i].region = 0;
            tab_de_dec[i].description = -1;
            tab_de_dec[i].exec = -1;
        }else{
            tab_de_dec[i].nature = -1;
            tab_de_dec[i].suivant = -1;
            tab_de_dec[i].region = 0;
            tab_de_dec[i].description = -1;
            tab_de_dec[i].exec = -1;
        }
    }

    

    zone_de_deb_utiliser = 0;
}

int inserer_decl(int lex_id, int nature, int region, int description, int exec) {
    if (lex_id < 0 || lex_id >= Zone_de_debordement) {
        /* lex_id doit être dans la zone PRIMAIRE uniquement */
        fprintf(stderr,"[tabdecl] inserer_decl: lex_id=%d hors de la primaire [0..%d]\n", lex_id, Zone_de_debordement - 1);
        return -1;
    }

    if (nature < TYPE_B || nature > FCT) {
        fprintf(stderr,"[tabdecl] inserer_decl: nature %d invalide (attendu 0..7)\n", nature);
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
    if (tab_de_dec[lex_id].nature == -1) {
        tab_de_dec[lex_id] = rec;
        return lex_id; 
    }

    /* Cas 2 : insérer en DÉBORDEMENT */
    int indice_deb = Zone_de_debordement + zone_de_deb_utiliser;
    if (indice_deb >= Taille_TAB) {
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
        case TYPE_B: return "TYPE_B ";
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
    if (tab_de_dec[lex_id].nature == -1) {
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

int association_nom(int idxLex, int typeRecherche){
    if (idxLex < 0 || idxLex >= Zone_de_debordement)
        return -1;

    int declTrouvee = -1;

    /* On parcourt la pile des régions en commençant par la plus locale */
    elementPile *curseurRegion = pile_region->tete;

    while (curseurRegion != NULL && declTrouvee == -1){
        int regCible = curseurRegion->valeur;
        /* on scanne toutes les déclarations portant ce lexème */
        int pos = idxLex;
        while (pos != -1 && declTrouvee == -1){
            TAB_DE_Decl *entry = &tab_de_dec[pos];
            int nat = entry->nature;
            int reg = entry->region;
            /* Critère : même région OU VAR/PARAM compatibles */
            int okNature = (nat == typeRecherche) ||((typeRecherche == VAR   && nat == PARAM) ||
                            (typeRecherche == PARAM && nat == VAR));

            if (okNature && reg == regCible){
                declTrouvee = pos;
            }
            else{
                pos = entry->suivant;  // passer au débordement suivant
            }
        }
        /* Région suivante */
        curseurRegion = curseurRegion->suivant;
    }
    return declTrouvee;
}
/*
int main() {
    printf("===== TEST association_nom =====\n");

  
    init_tab_lexico();
    init_tab_decl();

    //création pile des régions 
    pile_region = creationPile();
    empile(pile_region, 0);  // région globale

  
     // 1) Global : var x : entier ;
    
    int id_x = inserer_lexeme("x");
    inserer_decl(id_x, VAR, 0, 1, 1);   // VAR region 0

    printf("\n-- Test 1 : global --\n");
    int r_global = association_nom(id_x, VAR);
    printf("association_nom(x, VAR) = %d (attendu = entrée VAR région 0)\n", r_global);

   
     // 2) Fonction (region 1) : param x
    
    empile(pile_region, 1);
    inserer_decl(id_x, PARAM, 1, 1, 0);  // PARAM region 1

    printf("\n-- Test 2 : dans fonction (region 1) --\n");
    int r_local = association_nom(id_x, VAR);
    printf("association_nom(x, VAR) = %d (attendu = entrée PARAM région 1)\n", r_local);

    
     // 3) Retour global
 
    depile(pile_region);

    printf("\n-- Test 3 : retour en global --\n");
    int r_global2 = association_nom(id_x, VAR);
    printf("association_nom(x, VAR) = %d (attendu = VAR région 0)\n", r_global2);

    
     // 4) Identificateur non déclaré
    
    int id_y = inserer_lexeme("y");

    printf("\n-- Test 4 : identificateur non déclaré --\n");
    int r_none = association_nom(id_y, VAR);
    printf("association_nom(y, VAR) = %d (attendu = -1)\n", r_none);

    printf("\n===== FIN DU TEST =====\n");

    return 0;
    //Pour tester association_nom decommenter le main et le ifdef et endif 
    //et compiler avec le gcc en dessous 
    //gcc -DTEST_ASSOC_NOM tab_decl.c tab_lexico.c pile.c -o test_decl
}

#endif*/