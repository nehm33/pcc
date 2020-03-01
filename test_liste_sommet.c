#include <stdio.h>
#include <stdlib.h>
#include "Liste_sommet.h"


int main() { L_SOMMET l1=NULL; int p;
    l1=creer_liste_som();

    printf("test de l'ajout en tete et de l'affichage\n");
    printf("Ajout en tete\n");
     l1=ajout_tete_som(5,l1);
    printf("Liste : ");    visualiser_liste_som(l1); puts("");
    printf("Ajout en tete \n");
      l1=ajout_tete_som(7,l1);
    printf("Liste : ");    visualiser_liste_som(l1);puts("");
    printf("Ajout en tete \n");
      l1=ajout_tete_som(2,l1);
    printf("Liste : ");    visualiser_liste_som(l1);puts("");
    printf("Ajout en tete \n");
     l1=ajout_tete_som(10,l1);
    printf("Liste : ");    visualiser_liste_som(l1);puts("");
    getchar();

    printf("\ntest de la suppression en tete \n");
    printf("Liste : ");visualiser_liste_som(l1);puts("");
    printf("Suppression en tete\n");    l1=supprimer_tete_som(l1);
    printf("Liste : ");    visualiser_liste_som(l1);puts("");
    printf("Suppression en tete\n");    l1=supprimer_tete_som(l1);
    printf("Liste : ");    visualiser_liste_som(l1);puts("");
    printf("Suppression en tete\n");    l1=supprimer_tete_som(l1);
    printf("Liste : ");    visualiser_liste_som(l1);puts("");
    printf("Suppression en tete\n");    l1=supprimer_tete_som(l1);
    printf("Liste : ");    visualiser_liste_som(l1);puts("");
    printf("Suppression en tete\n");    l1=supprimer_tete_som(l1);
    printf("Liste : ");    visualiser_liste_som(l1);puts("");
    printf("Suppression en tete\n");    l1=supprimer_tete_som(l1);
    printf("Liste : ");    visualiser_liste_som(l1);puts("");
    getchar();

    printf("\nLiberation de toutes les listes\n");
    l1=liberer_liste_som(l1);

    printf("\nTest de la liste vide\n");
    visualiser_liste_som(l1);
    p=liste_vide_som(l1);
    if (p==1) printf("La liste est vide\n");
    else {printf("La liste n'est pas vide, c'est une erreur\n"); exit(EXIT_FAILURE);}

    exit(EXIT_SUCCESS);
}

