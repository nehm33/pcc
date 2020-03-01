#include "Sommet.h"



T_SOMMET Sommet_vide(){
    T_SOMMET s;
    init_Sommet(&s);
    return s;
}

void init_Sommet (T_SOMMET* s){
    s->F = -1; s->G = -1; s->ind_tas = -1;
    s->LF = 0; s->x = 0; s->y = 0; s->num =0;
    s->nom = NULL; s->pere = NULL; s->ligne = NULL; s->voisins =NULL;
}

void remplir_sommet(T_SOMMET* s, char* nom, char* ligne, int num, double x, double y){
    s->nom=nom;
    s->ligne=ligne;
    s->num = num; s->x = x; s->y = y;
}

void affiche_Sommet (T_SOMMET* s){
    printf("Sommet %d: %s %s %lf %lf\n\tAppartient LF: %d \n\tIndiceTas: %d \n\tF=%lf   G=%lf\n",s->num, s->nom, s->ligne, s->x, s->y, s->LF, s->ind_tas, s->F, s->G);
    printf("\tListe d'arc: "); visualiser_liste(s->voisins);
}

void affiche_Sommet_sim(T_SOMMET* s){
    printf("Sommet %d: %s %s %lf %lf\n",s->num, s->nom, s->ligne, s->x, s->y);
    printf("\tListe d'arc: "); visualiser_liste(s->voisins);
}

void liberer_Sommet (T_SOMMET* s){
    free(s->nom); free(s->ligne);
    s->voisins=liberer_liste(s->voisins);
}

void reinitialise_sommet(T_SOMMET* s){
    s->ind_tas=-1;
    s->LF=0;
    s->F=-1;
    s->G=-1;
    s->pere=NULL;
}
