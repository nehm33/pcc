#include <stdio.h>
#include <stdlib.h>
#include "Graphe.h"
#include <time.h>

int main(){
    T_SOMMET* t;
    T_SOMMET s;
    int i,n,n1;
    srand(time(NULL));
    printf("Donner le nombre d'elements du graphe: ");
    scanf("%d", &n);
    puts("");
    printf("Donner le nombre d'elements de la liste fermee: ");
    scanf("%d", &n1);puts("");
    while (n%5==0){
      printf("Donner un nombre d'elements du graphe non divisible par 5: ");
      scanf("%d", &n);
      puts("");
    }
    t = calloc(n, sizeof(*t));
    for (i=0; i<n; i++){
        s = Sommet_vide();
        s.nom = calloc(4, sizeof(*(s.nom)));
        s.nom[0] = 'a';s.nom[1] = 'a';s.nom[2] = 'a';s.nom[3] = 'a';
        s.nom[0] += i;
        s.num = i; s.ligne = "M1";
        s.F = rand()%1000;
        t[i] = s;
    }
    t[0].LF = 1;

    for (i=1; i<n1; i++){
        t[i*5%n].LF = 1;
        t[i*5%n].pere = t+(i-1)*5%n;
    }

    for (i=0; i<n; i++){
        affiche_Sommet(t+i);
    }
    affichage_liste_fermee((n1-1)*5%n,t);
    free(t);
}
