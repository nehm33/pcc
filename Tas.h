#ifndef _Tas
#define _Tas

#include "Sommet.h"

typedef struct{
  int num;
  double F;
} T_SOMMET_simple;

// les indices indtas des sommets du graphe doivent etre echanges a chaque fois qu'il y a un echange dans le tas
// lorsqu'un sommet n'est plus dans le tas, indtas vaut -1

void swap(T_SOMMET_simple* x, T_SOMMET_simple* y) ; // Echanger deux elements du tas
void ajout_tas(T_SOMMET_simple* t, int* n, T_SOMMET* s, T_SOMMET* graph) ;/* la valeur de n(la taille du tas) est incr�ment�e � la fin, s est le sommet � ajouter au tas t */
void monte_tas(T_SOMMET_simple* t, T_SOMMET* s, T_SOMMET* graph) ; /* on fait monter un des sommets du tas en l'occurence s dont la valeur de F a change*/
void descendre_tas(T_SOMMET_simple* t, int n, T_SOMMET* graph) ; // on fait descendre un des elements du tas
int suppression_tas(T_SOMMET_simple* t, int* n, T_SOMMET* graph) ; /* on retourne le numéro du sommet. la valeur de n est d�cr�ment� � la fin */

#endif // _Tas
