#include "Liste_sommet.h"

L_SOMMET creer_liste_som() { return NULL; }

int liste_vide_som(L_SOMMET l) { return l==NULL; }

L_SOMMET ajout_tete_som(int a, L_SOMMET l){ L_SOMMET p=NULL;
  if ((p=calloc(1,sizeof(*p)))!=NULL)  { p->val=a; p->suiv=l; }
  return p;
}

L_SOMMET supprimer_tete_som(L_SOMMET l) {
  if (!liste_vide_som(l)) { L_SOMMET p=l;
    l=l->suiv; free(p);
  }
  return l;
}

void visualiser_liste_som(L_SOMMET l) { L_SOMMET p=NULL;
  for (p=l; !liste_vide_som(p); p=p->suiv) printf("%d; ",p->val);
}

L_SOMMET liberer_liste_som(L_SOMMET l) {
    while(!liste_vide_som(l)){
    l=supprimer_tete_som(l);}
    return l;
}
