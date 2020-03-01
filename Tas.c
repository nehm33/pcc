#include "Tas.h"



void swap(T_SOMMET_simple* x, T_SOMMET_simple* y){
  T_SOMMET_simple z;
  z = *x;
  *x = *y;
  *y = z;

}


void ajout_tas(T_SOMMET_simple* t, int* n, T_SOMMET* s, T_SOMMET* graph) {  /* la valeur de n(la taille du tas) est incrémentée à la fin, s est le sommet à ajouter au tas t */
  int k;
  s->ind_tas = *n;
  graph[s->num].ind_tas = *n;
  t[*n].num = s->num; t[*n].F = s->F;  // on fait correspondre le sommet simple t[n] au sommet s
  k = *n;
  while (t[k].F<(t[(k-1)/2]).F && ((k-1)/2)>=0 ) {
    swap(t+k,t+(k-1)/2);
    graph[t[k].num].ind_tas = k;
    graph[t[(k-1)/2].num].ind_tas = (k-1)/2;
    k = (k-1)/2;
  }
  *n += 1;
}

void monte_tas(T_SOMMET_simple* t, T_SOMMET* s, T_SOMMET* graph) {  /* on fait monter un des sommets du tas en l'occurence s */
  int k;
  k=s->ind_tas;
  t[k].F = s->F;
  while (t[k].F<(t[(k-1)/2]).F && ((k-1)/2)>=0 ) {
    swap(t+k,t+(k-1)/2);
    graph[t[k].num].ind_tas = k;
    graph[t[(k-1)/2].num].ind_tas = (k-1)/2;
    k = (k-1)/2;
  }
}


void descendre_tas(T_SOMMET_simple* t, int n, T_SOMMET* graph) {
  int k=0;
  while (((t[k].F>(t[2*(k+1)]).F) && (2*(k+1)<n)) || ((t[k].F>(t[2*(k+1)-1]).F) && (2*(k+1)-1<n))) {
    if (2*(k+1)<n){
      if ((t[2*(k+1)-1]).F > (t[2*(k+1)]).F) {
        swap(t+k,t+2*(k+1));
        graph[t[k].num].ind_tas = k;
        graph[t[2*k+2].num].ind_tas = 2*k+2;
        k = 2*(k+1);
      }
      else{
        swap(t+k,t+(2*(k+1)-1));
        graph[t[k].num].ind_tas = k;
        graph[t[2*k+1].num].ind_tas = 2*k+1;
        k = 2*(k+1)-1;
      }
    }
    else{
      swap(t+k,t+(2*(k+1)-1));
      graph[t[k].num].ind_tas = k;
      graph[t[2*k+1].num].ind_tas = 2*k+1;
      k = 2*(k+1)-1;
    }
  }
}


int suppression_tas(T_SOMMET_simple* t, int* n, T_SOMMET* graph) { /* la valeur de n est décrémenté à la fin */
    swap(t+(*n-1),t);
    *n -= 1;
    descendre_tas(t,*n,graph);
    graph[t[0].num].ind_tas = 0;
    graph[t[*n].num].ind_tas = -1;
    return t[*n].num;
}
