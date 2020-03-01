#ifndef _ARC
#define _ARC

#include <stdio.h>
#include <stdlib.h>

typedef struct { int arrivee; double coute; } T_ARC ;

void affiche_arc (T_ARC* a); // Affichage d'un arc � l'�cran
T_ARC creer_arc(int arriv, double c); // Cr�ation d'un arc et remplissage d'un arc
int est_arc_vide(T_ARC a); // vérifier si l'Arc est vide

#endif // _ARC
