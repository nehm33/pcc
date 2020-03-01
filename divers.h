#ifndef _DIVERS
#define _DIVERS

#include <math.h>
#include "Liste_sommet.h"

double heuristique(T_SOMMET s1, T_SOMMET s2) ; // fonction heuristique
int hashcode(char* som, int n) ; // fonction de hachage
int compare(char* nom1, char* nom2) ; // fonction de comparaison de chaines ne prenant pas en compte les majuscules et caracteres speciaux
L_SOMMET* tabhash(T_SOMMET* graph, int taille_grah, int n) ; // Creation d'une table de hachage de taille n
void affichage_tabhash(L_SOMMET* t_hash, int n) ; // Affichage de la table de hachage
int trouver_somm(L_SOMMET* t_hash, int n, char* nom, T_SOMMET* graph) ; // permet de trouver le numero du sommet du graphe dont le nom est la parametre nom et sinon retourne -1
void change_arc(T_SOMMET s, char* nom, T_SOMMET* graph, double new_val) ; // permet de changer la valeur de l'arc dont le depart est le sommet s et l'arrivee a comme nom le parametre nom
void relier_somm(L_SOMMET* t_hash, int n, char* nom, T_SOMMET* graph) ; // met tous les arcs reliant les sommets ayant comme nom le parametre nom a 0
void delier_somm(L_SOMMET* t_hash, int n, char* nom, T_SOMMET* graph) ; // remet tous les arcs reliant les sommets ayant comme nom le parametre nom a 360
void liberer_tabhash(L_SOMMET* t_hash, int n) ; // liberation de la table de hachage
#endif // _DIVERS
