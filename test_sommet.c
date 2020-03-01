#include <stdio.h>
#include <stdlib.h>
#include "Sommet.h"

int main()
{
    T_SOMMET s1, s2;
    T_ARC c;
    s1=Sommet_vide();
    s2=Sommet_vide();


    printf("Affichage de s1 et s2: Les deux sommets sont vides\n");
    affiche_Sommet(&s1);
    affiche_Sommet(&s2);
    getchar();
    puts(" ");


    remplir_sommet(&s1, "Aaaa", "M1",0,0.95,0.05);
    printf("Affichage de s1 et s2: Le sommet s1 a ete remplie\n");
    affiche_Sommet(&s1);
    affiche_Sommet(&s2);
    getchar();
    puts(" ");


    remplir_sommet(&s2, "Bbbb", "M1",1,0.05,0.95);
    printf("Affichage simple de s1 et s2: Les deux sommets ont ete remplis\n");
    affiche_Sommet_sim(&s1);
    affiche_Sommet_sim(&s2);
    getchar();
    puts("");


    printf("Ajouts d'arc dans la liste des voisins\n");
    c.arrivee=1; c.coute = 50; s1.voisins=ajout_tete(c,s1.voisins);
    c.arrivee=13;    c.coute = 25;  s1.voisins=ajout_tete(c,s1.voisins);
    c.arrivee=0;    c.coute=10;  s2.voisins=ajout_tete(c,s2.voisins);
    c.arrivee=13;    c.coute = 15; s2.voisins=ajout_tete(c,s2.voisins);
    affiche_Sommet_sim(&s1);
    affiche_Sommet_sim(&s2);
    getchar();
    puts("");


    printf("Reinitialisation d'un sommet\n");
    s1.pere = &s2; s1.LF = 1;  s1.ind_tas= 4; s1.F = 41; s1.G = 2;
    printf("Affichage du sommet modifie\n");
    affiche_Sommet(&s1);
    reinitialise_sommet(&s1);
    printf("Affichage du sommet reinitialise\n");
    affiche_Sommet(&s1);
    getchar();
    puts("");


    printf("Liberation des sommets\n");
    s1.voisins=liberer_liste(s1.voisins);
    s2.voisins=liberer_liste(s2.voisins);
    affiche_Sommet_sim(&s1);
    affiche_Sommet_sim(&s2);
    return 0;
}
