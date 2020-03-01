#ifndef _Affichage
#define _Affichage
#include "Graphe.h"
#include "divers_graph.h"
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include "Draw.h"

typedef struct im{
    char nom[50];
    double xmax, xmin, ymax, ymin; // coordonnees gps limites de l'image
    int dimx, dimy;
} image;

image* creation_tab_image() ; // Creation et remplissage du tableau contenant les 7 images
image trouve_image(char* nom, image* tab) ; // Trouve l'image dont le nom est donne
void affichage_image(SDL_Surface* ecran, image im) ; // Affichage d'une image a l'ecran
void affichage_sommet(SDL_Surface* ecran, T_SOMMET som, image im, ligne* tab) ; // Affichage graphique d'un sommet a l'ecran
void affichage_sommet1(SDL_Surface* ecran, T_SOMMET som, L_SOMMET** mat, image im, ligne* tab) ; // Affichage graphique d'un sommet a l'ecran et l'ajoute dans la matrice mat
void affichage_sommet_fin(SDL_Surface* ecran, T_SOMMET som1, T_SOMMET som2, image im, ligne* tab) ; // Affichage graphique d'un sommet et de son numero a l'ecran
void affichage_sommet_fin_pa(SDL_Surface* ecran, T_SOMMET som1, T_SOMMET som2, image im, ligne* tab) ; // Affichage graphique d'un sommet et de son nom a l'ecran
void affichage_arc(SDL_Surface* ecran, T_SOMMET som1, T_SOMMET som2, image im, ligne* tab) ; // Affichage graphique d'un arc
void affichage_graphe(SDL_Surface* ecran, T_SOMMET* graph, int taille, image im, ligne* tab) ; // Affichage graphique d'un graphe
void affichage_graphe1(SDL_Surface* ecran, T_SOMMET* graph, L_SOMMET** mat, int taille, image im, ligne* tab) ; // Affichage graphique d'un graphe et remplissage de la matrice mat
void affichage_liste_fermee_graph_am(SDL_Surface* ecran, T_SOMMET* graph, int arrivee, image im, ligne* tab) ; // Affichage graphique d'une liste fermee pour paris
void affichage_liste_fermee_graph_pa(SDL_Surface* ecran, T_SOMMET* graph, int arrivee, char* nom_dep, char* nom_arr, image im, ligne* tab) ; // Affichage graphique d'une liste fermee pour les reseaux routiers americains

#endif // _Affichage
