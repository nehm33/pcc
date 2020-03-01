#include "divers.h"
#include "Liste_sommet.h"
#include <ctype.h>

double heuristique(T_SOMMET s1, T_SOMMET s2){
    return (fabs(s1.x-s2.x)+fabs(s1.y-s2.y))/5.;
}

int hashcode(char* som, int n){
    int i,nbr=0;
    for (i=0; som[i]!='\0'; i++){
        if ((som[i]>='A'&&som[i]<='Z')||(som[i]>='a'&&som[i]<='z')){
            nbr += tolower(som[i]);
        }
    }
    return nbr%n;
}

void change_arc(T_SOMMET s, char* nom, T_SOMMET* graph, double new_val){
    L_ARC p;
    for (p=s.voisins; !liste_vide(p); p=p->suiv){
        if (strcasecmp(graph[(p->val).arrivee].nom,nom)==0){
            (p->val).coute = new_val;
        }
    }
}

void relier_somm(L_SOMMET* t_hash, int n, char* nom, T_SOMMET* graph){
    int a = hashcode(nom,n);
    L_SOMMET p;
    for (p=t_hash[a]; !liste_vide_som(p); p=p->suiv){
        if (strcasecmp(graph[p->val].nom,nom)==0){
            change_arc(graph[p->val],nom,graph,0);
        }
    }
}

void delier_somm(L_SOMMET* t_hash, int n, char* nom, T_SOMMET* graph){
    int a = hashcode(nom,n);
    L_SOMMET p;
    for (p=t_hash[a]; !liste_vide_som(p); p=p->suiv){
        if (strcasecmp(graph[p->val].nom,nom)==0){
            change_arc(graph[p->val],nom,graph,360);
        }
    }
}

void affichage_tabhash(L_SOMMET* t_hash, int n){
    int i;
    for (i=0; i<n; i++){
        visualiser_liste_som(t_hash[i]);
    }
}

L_SOMMET* tabhash(T_SOMMET* graph, int taille_graph, int n){
  L_SOMMET* t_hash; // initialisation du tableau de hachage (un tableau de liste)
  if ((t_hash=calloc(n,sizeof(*t_hash)))==NULL) return NULL;
  int i;
  int inter;   // l'élement qui prend la valeur de table de hachage
  for (i=0; i<taille_graph; i++) {  // parcourir le graphe
    inter = hashcode(graph[i].nom,n);  // éviter le répition
    t_hash[inter]=ajout_tete_som(i,t_hash[inter]);
  }
  return t_hash;
}

int trouver_somm(L_SOMMET* t_hash, int n, char* nom, T_SOMMET* graph){
  int i;
  L_SOMMET p=NULL;
    for (p=t_hash[hashcode(nom,n)]; !liste_vide_som(p); p=p->suiv){ // parcourir la liste de cette case
        if (compare(graph[p->val].nom,nom)==0) {
          return p->val;
      }
  }
  return -1;
}

void liberer_tabhash(L_SOMMET* t_hash, int n){
  int i;
  for (i=0; i<n ; i++){
    liberer_liste_som(t_hash[i]);
  }
}

int compare(char* nom1, char* nom2){
    int i,k=0;
    char* cmp1; char* cmp2;
    cmp1 = calloc(100, sizeof(*cmp1));
    cmp2 = calloc(100, sizeof(*cmp2));
    for (i=0; i<strlen(nom1); i++){
        if ((nom1[i]>='A'&&nom1[i]<='Z')||(nom1[i]>='a'&&nom1[i]<='z')){
            cmp1[k] = tolower(nom1[i]);
            k++;
        }
    }
    k=0;
    for (i=0; i<strlen(nom2); i++){
        if ((nom2[i]>='A'&&nom2[i]<='Z')||(nom2[i]>='a'&&nom2[i]<='z')){
            cmp2[k] = tolower(nom2[i]);
            k++;
        }
    }
    return strcasecmp(cmp1,cmp2);
}
