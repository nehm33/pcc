#ifndef _Listesom
#define _Listesom

#include <stdio.h>
#include <stdlib.h>
#include "Sommet.h"

typedef struct lsuc { int val; struct lsuc* suiv ; }* L_SOMMET;

L_SOMMET creer_liste_som(); // Cr�ation d'une liste vide
int liste_vide_som(L_SOMMET l); // V�rifie si une liste est vide
L_SOMMET ajout_tete_som(int a, L_SOMMET l); // Ajout d'un sommet en tete de liste
L_SOMMET supprimer_tete_som(L_SOMMET l); // Suppression d'un sommet en t�te de liste
void visualiser_liste_som(L_SOMMET l); // Affichage d'une liste � l'�cran
L_SOMMET liberer_liste_som(L_SOMMET l); // Lib�radtionde l'espace allou� en m�mooire et retourne NULL

#endif // _Listesom
