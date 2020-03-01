#include "Arc.h"


void affiche_arc (T_ARC* a){
  if (!est_arc_vide(*a)) printf("l'arrivee :%d le cout :%lf ;",a->arrivee,a->coute);
  else printf("Arc vide ");
}


T_ARC creer_arc(int arriv, double c){
  T_ARC a;
  a.arrivee=arriv;
  a.coute=c;
  return a;

}


int est_arc_vide(T_ARC a) {
  return (a.arrivee<0 || a.coute<0);
}
