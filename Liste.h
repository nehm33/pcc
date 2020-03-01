#ifndef _Liste
#define _Liste

#include <stdio.h>
#include <stdlib.h>
#include "Arc.h"

typedef struct lsucc { T_ARC val; struct lsucc* suiv ; }* L_ARC;

L_ARC creer_liste(); // Cr�ation d'une liste vide
int liste_vide(L_ARC l); // V�rifie si une liste est vide
L_ARC ajout_tete(T_ARC a, L_ARC l); // Ajout d'un arc en tete de liste
L_ARC ajout_queue(T_ARC a, L_ARC l); // Ajout d'un arc en queue de liste
L_ARC supprimer_tete(L_ARC l); // Suppression d'un arc en t�te de liste
void visualiser_liste(L_ARC l); // Affichage d'une liste � l'�cran
L_ARC liberer_liste(L_ARC l); // Lib�radtionde l'espace allou� en m�mooire et retourne NULL
L_ARC copie(L_ARC l); // Cr�ation d'une copie de l

#endif // _Liste
