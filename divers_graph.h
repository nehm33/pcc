#ifndef _Couleur
#define _Couleur

#include <stdio.h>
#include <stdlib.h>
#include "Graphe.h"


typedef struct lig{
    char lig[6];
    long couleur;
} ligne;

ligne* creation_tab_lig() ; // Creation et reamplissage d'un tableau de lignes
long couleur_sommet(char* line, ligne* tab) ; // Determine la couleur d'un sommet
long couleur_arc(char* line1, char* line2, ligne* tab) ; // Determine la couleur d'un arc
void conversion(int longueur, int largeur, int* L, int* l, double xmax, double xmin, double ymax, double ymin, double x, double y) ; // Convertit des coordonnees gps en coordonnees de pixels
void conversion_inv(int longueur, int largeur, int L, int l, double xmax, double xmin, double ymax, double ymin, double* x, double* y) ; // Fait l'inverse de conversion
void visualiser_liste_som_pa(L_SOMMET liste, T_SOMMET* graph) ; // Affichage d'une liste de sommets avec leur nom grace au graphe

#endif // _Couleur
