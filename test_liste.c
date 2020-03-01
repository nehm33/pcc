#include <stdio.h>
#include <stdlib.h>
#include "Liste.h"

int main() { T_ARC c; L_ARC l1=NULL,l2=NULL,l3=NULL; int p;
    l1=creer_liste(); l2=creer_liste();l3=creer_liste();

    printf("test de l'ajout en tete d'un arc et de l'affichage\n");
    printf("Ajout en tete d'un arc\n");
    c.arrivee=1; c.coute = 50; l1=ajout_tete(c,l1);
    printf("Liste : ");    visualiser_liste(l1);
    printf("Ajout en tete d'un arc\n");
    c.arrivee=13;    c.coute = 25;  l1=ajout_tete(c,l1);
    printf("Liste : ");    visualiser_liste(l1);
    printf("Ajout en tete d'un arc\n");
    c.arrivee=1;    c.coute=10;  l1=ajout_tete(c,l1);
    printf("Liste : ");    visualiser_liste(l1);
    printf("Ajout en tete d'un arc\n");
    c.arrivee=13;    c.coute = 15; l1=ajout_tete(c,l1);
    printf("Liste : ");    visualiser_liste(l1);
    getchar();


    l3=copie(l1);
    printf("Copie de l1 dans l3\n");
    printf("Liste l1: "); visualiser_liste(l1);
    printf("Liste l3: "); visualiser_liste(l3);
    getchar();

    l2=l1;
    printf("Affectation de la liste l1 dans l2\n");
    printf("Liste l2: "); visualiser_liste(l2);
    printf("Liste l1: "); visualiser_liste(l1);
    getchar();

    printf("Ajout en tete d'un arc dans l1\n");
    c=creer_arc(2,6); l1=ajout_tete(c,l1);
    printf("Ajout de l'arc :");affiche_arc(&c);puts("");
    printf("Liste l1: "); visualiser_liste(l1);
    printf("Liste l2: "); visualiser_liste(l2);
    printf("Liste l3: "); visualiser_liste(l3);
    getchar();

    printf("\ntest de la suppression en tete d'une carte \n");
    printf("Liste : ");visualiser_liste(l1);
    printf("Suppression en tete\n");    l1=supprimer_tete(l1);
    printf("Liste : ");    visualiser_liste(l1);
    printf("Suppression en tete\n");    l1=supprimer_tete(l1);
    printf("Liste : ");    visualiser_liste(l1);
    printf("Suppression en tete\n");    l1=supprimer_tete(l1);
    printf("Liste : ");    visualiser_liste(l1);
    printf("Suppression en tete\n");    l1=supprimer_tete(l1);
    printf("Liste : ");    visualiser_liste(l1);
    printf("Suppression en tete\n");    l1=supprimer_tete(l1);
    printf("Liste : ");    visualiser_liste(l1);
    printf("Suppression en tete\n");    l1=supprimer_tete(l1);
    printf("Liste : ");    visualiser_liste(l1);
    getchar();

    printf("\nLiberation de toutes les listes\n");
    l1=liberer_liste(l1);     l2=liberer_liste(l2); l3 = liberer_liste(l3);

    printf("\nTest de la liste vide\n");
    visualiser_liste(l2);
    p=liste_vide(l2);
    if (p==1) printf("La liste est vide\n");
    else {printf("La liste n'est pas vide, c'est une erreur\n"); exit(EXIT_FAILURE);}

    exit(EXIT_SUCCESS);
}
