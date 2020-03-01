#ifndef _Graphe
#define _Graphe

#include "Sommet.h"
#include "Tas.h"
#include "divers.h"

T_SOMMET* lecture_graphe(char* fichier, int* taille) ; // Lecture du fichier contenant les sommets et les arcs et creation du graphe
void liberer_graphe(T_SOMMET* graph, int* taille) ;// Liberation du graphe
void affiche_graphe(T_SOMMET* graph, int taille) ; // Affichage du graphe
void reinitialise_graphe(T_SOMMET* graph, int taille); // Remet un graphe tel qu'il etait a sa creation
void Astar(int depart, int arrivee, T_SOMMET* graph, int taille) ; // Algorithme A*
void affichage_liste_fermee(int arrivee, T_SOMMET* graph) ; // Affichage de la liste fermee
void affichage_liste_fermee_am(int arrivee, T_SOMMET* graph) ; // Affichage de la liste fermee pour paris
void affichage_liste_fermee_pa(int arrivee, char* nom_dep, T_SOMMET* graph, char* nom_arriv) ; // Affichage de la liste fermee pour les réseaux routiers americains

#endif // _Graphe
