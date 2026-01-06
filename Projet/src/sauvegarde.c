#include <stdio.h>
#include "../include/sauvegarde.h"

#include "../include/tab_lexico.h"
#include "../include/tab_decl.h"
#include "../include/tab_region.h"
#include "../include/tab_repres.h"

int sauvegarder(char *nom_fic)
{
    FILE *f = fopen(nom_fic, "wb");
    if (!f) return -1;

    if (sauvegarde_tab_lexico(f) != 0) { fclose(f); return -1; }
    if (sauvegarde_tab_decl(f)   != 0) { fclose(f); return -1; }
    if (sauvegarde_tab_region(f) != 0) { fclose(f); return -1; }
    if (sauvegarde_tab_repres(f) != 0) { fclose(f); return -1; }

    fclose(f);
    return 0;
}

int charge(char *nom_fic)
{
    FILE *f = fopen(nom_fic, "rb");
    if (!f) return -1;

    if (charger_tab_lexico(f) != 0) { fclose(f); return -1; }
    if (charger_tab_decl(f)   != 0) { fclose(f); return -1; }
    if (charger_tab_region(f) != 0) { fclose(f); return -1; }
    if (charger_tab_repres(f) != 0) { fclose(f); return -1; }

    fclose(f);
    return 0;
}
