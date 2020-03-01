#ifndef _Sommet
#define _Sommet

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Liste.h"

typedef struct sommet {
    char* nom;
    char* ligne;
    struct sommet* pere;
    int num,ind_tas,LF ;
    double x,y,F,G ;
    L_ARC voisins;} T_SOMMET ;

void affiche_Sommet (T_SOMMET* s); // Affichage d'un sommet sauf son parametre pere
void affiche_Sommet_sim (T_SOMMET* s); // Affichage de 4 paramètres d'un sommet
void init_Sommet (T_SOMMET* s); // Initialisation d'un sommet
T_SOMMET Sommet_vide(); // Creation et initialisation d'un sommet
void remplir_sommet(T_SOMMET* s, char* nom, char* ligne, int num, double x, double y); // Change les valeurs d'un sommet
void liberer_Sommet (T_SOMMET* s); // Liberation d'un sommet
void reinitialise_sommet(T_SOMMET* s); // Initialisation des parametres secondaires d'un sommet

#endif // _Sommet
