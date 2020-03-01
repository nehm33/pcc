#include "divers_graph.h"
#include <SDL.h>

ligne* creation_tab_lig(){
    ligne* t;
    t = calloc(48, sizeof(*t));
    sprintf(t[0].lig, "M1"); t[0].couleur = 0x8000FF;
    sprintf(t[1].lig, "M2"); t[1].couleur = 0x400080;
    sprintf(t[2].lig, "M3"); t[2].couleur = 0x400040;
    sprintf(t[3].lig, "M3bis"); t[3].couleur = 0xFF00FF;
    sprintf(t[4].lig, "M4"); t[4].couleur = 0xFF0080;
    sprintf(t[5].lig, "M5"); t[5].couleur = 0x804040;
    sprintf(t[6].lig, "M6"); t[6].couleur = 0x800080;
    sprintf(t[7].lig, "M7"); t[7].couleur = 0x00FF00;
    sprintf(t[8].lig, "M7bis"); t[8].couleur = 0x00FF80;
    sprintf(t[9].lig, "M8"); t[9].couleur = 0x0000FF;
    sprintf(t[10].lig, "M9"); t[10].couleur = 0x00FFFF;
    sprintf(t[11].lig, "M10"); t[11].couleur = 0xFF8080;
    sprintf(t[12].lig, "M11"); t[12].couleur = 0xE69E1A;
    sprintf(t[13].lig, "M12"); t[13].couleur = 0x800040;
    sprintf(t[14].lig, "M13"); t[14].couleur = 0x0000A0;
    sprintf(t[15].lig, "M14"); t[15].couleur = 0x808080;
    sprintf(t[16].lig, "funi"); t[16].couleur = 0xEFE4B0;
    sprintf(t[17].lig, "A1"); t[17].couleur = 0x00FF40;
    sprintf(t[18].lig, "A3"); t[18].couleur = 0x808040;
    sprintf(t[19].lig, "A5"); t[19].couleur = 0x800FB0;
    sprintf(t[20].lig, "A"); t[20].couleur = 0x008080;
    sprintf(t[21].lig, "A2"); t[21].couleur = 0x004000;
    sprintf(t[22].lig, "A4"); t[22].couleur = 0x80FF00;
    sprintf(t[23].lig, "B4"); t[23].couleur = 0x808000;
    sprintf(t[24].lig, "B2"); t[24].couleur = 0x4000FF;
    sprintf(t[25].lig, "B"); t[25].couleur = 0xFFFF00;
    sprintf(t[26].lig, "B3"); t[26].couleur = 0x80FFFF;
    sprintf(t[27].lig, "B5"); t[27].couleur = 0xFF80FF;
    sprintf(t[28].lig, "C1"); t[28].couleur = 0xFF8000;
    sprintf(t[29].lig, "C3"); t[29].couleur = 0x5A4E25;
    sprintf(t[30].lig, "C7"); t[30].couleur = 0x3C3D03;
    sprintf(t[31].lig, "C5"); t[31].couleur = 0xB4EBBD;
    sprintf(t[32].lig, "C"); t[32].couleur = 0x804000;
    sprintf(t[33].lig, "C2"); t[33].couleur = 0x008040;
    sprintf(t[34].lig, "C4"); t[34].couleur = 0x800000;
    sprintf(t[35].lig, "C6"); t[35].couleur = 0x004040;
    sprintf(t[36].lig, "C8"); t[36].couleur = 0xFFFF80;
    sprintf(t[37].lig, "D"); t[37].couleur = 0x400000;
    sprintf(t[38].lig, "D2"); t[38].couleur = 0x008000;
    sprintf(t[39].lig, "D4"); t[39].couleur = 0xFF8040;
    sprintf(t[40].lig, "D6"); t[40].couleur = 0x000040;
    sprintf(t[41].lig, "E"); t[41].couleur = 0x80CF30;
    sprintf(t[42].lig, "E2"); t[42].couleur = 0x8080C0;
    sprintf(t[43].lig, "E4"); t[43].couleur = 0xC0C0C0;
    sprintf(t[44].lig, "Val"); t[44].couleur = 0x787507;
    sprintf(t[45].lig, "T1"); t[45].couleur = 0x004080;
    sprintf(t[46].lig, "T2"); t[46].couleur = 0x80FF80;
    sprintf(t[47].lig, "T3"); t[47].couleur = 0xFF0000;
    return t;
}

long couleur_sommet(char* line, ligne* tab){
    int i;
    for (i=0; i<48; i++){
        if (strcasecmp(line,tab[i].lig)==0){
            return tab[i].couleur;
        }
    }
    return 255;
}

long couleur_arc(char* line1, char* line2, ligne* tab){
    if (strcasecmp(line1,line2)!=0){
        return 0;
    }
    return couleur_sommet(line1, tab);
}

void conversion(int longueur, int largeur, int* L, int* l, double xmax, double xmin, double ymax, double ymin, double x, double y) {
  *L=((x-xmin)*longueur)/(xmax-xmin);
  *l=((y-ymax)*largeur)/(ymin-ymax);
}

void visualiser_liste_som_pa(L_SOMMET liste, T_SOMMET* graph){
  L_SOMMET p=NULL;
  for (p=liste; !liste_vide_som(p); p=p->suiv){
    printf("%s; ", graph[p->val].nom);
  }
}

void conversion_inv(int longueur, int largeur, int L, int l, double xmax, double xmin, double ymax, double ymin, double* x, double* y){
  *x = xmin+(xmax-xmin)*L/longueur;
  *y = ymax + (ymin-ymax)*l/largeur;
}
