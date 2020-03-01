#ifndef _Reseau
#define _Reseau

#include "Graphe.h"
#include "affichage_graph.h"

void pause_reseau(SDL_Surface* ecran, int pa, L_SOMMET** mat, T_SOMMET* graph, image im) ; // programme de pause d'afficher dans la console les sommets dans l'entourage d'un clic et de donner les coordonnees gps de la souris
int reseau_am(SDL_Surface* ecran, T_SOMMET* graph, int taille, image im, ligne* tab) ; // trouve le plus court chemin graphique des reseaux routiers americains
int reseau_pa(SDL_Surface* ecran, T_SOMMET* graph, int taille, L_SOMMET* tabhash, int n, image im, ligne* tab) ; // trouve le plus court chemin graphique pour paris
int reseau_am1(SDL_Surface* ecran, T_SOMMET* graph, int taille, image im, ligne* tab) ; // utilise la fonction pause_reseau
int reseau_pa1(SDL_Surface* ecran, T_SOMMET* graph, int taille, L_SOMMET* tabhash, int n, image im, ligne* tab) ; // utilise la fonction pause_reseau


#endif // _Reseau
