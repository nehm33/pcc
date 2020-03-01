#include "Liste.h"

L_ARC creer_liste() { return NULL; }

int liste_vide(L_ARC l) { return l==NULL; }

L_ARC ajout_tete(T_ARC a, L_ARC l) {
  L_ARC p=NULL;
  if ( (p=calloc( 1, sizeof (*p)))!=NULL)  { p->val=a; p->suiv=l; }
  return p;
}

L_ARC ajout_queue(T_ARC a, L_ARC l) { //j'ai rajouté cette fonction car j'en ai besoin pour copier la liste
    L_ARC p=l, yao=NULL;
    yao = ajout_tete(a,yao);
    if (liste_vide(l)){return yao;}
    while (!liste_vide(p->suiv)){
        p = p->suiv;
    }
    p->suiv = yao;
    return l;
}



L_ARC supprimer_tete(L_ARC l) {
  if (!liste_vide(l)) { L_ARC p=l;
    l=l->suiv; free(p);
  }
  return l;
}


void visualiser_liste(L_ARC l) { L_ARC p=NULL;
  for (p=l; !liste_vide(p); p=p->suiv) affiche_arc(&(p->val));
  puts("");
}


L_ARC liberer_liste(L_ARC l) {
    while(!liste_vide(l)){
    l=supprimer_tete(l);}
    return l;
}


L_ARC copie(L_ARC l) {
  L_ARC p1=NULL,p2=NULL;
  for (p1=l; !liste_vide(p1);p1=p1->suiv){
      p2 = ajout_queue(p1->val,p2);
  }
  return p2;
}
