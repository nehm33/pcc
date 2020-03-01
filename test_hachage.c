#include "divers.h"
#include "Graphe.h"


int main(){
    T_SOMMET* graph;
    int taille, n=75;
    L_SOMMET* tab;

    graph = lecture_graphe("metroetu.csv", &taille);
    tab = tabhash(graph, taille, n);
    printf("Affichage de la table de hachage\n");
    affichage_tabhash(tab,n);
    puts("");
    printf("Trouver le sommet La Defense\n");
    printf("Sommet %d : La Defense\n", trouver_somm(tab,n,graph[0].nom,graph));
    getchar();

    printf("Test de la liaison des sommets\n");
    relier_somm(tab,n,graph[0].nom,graph);
    printf("Affichage du nouveau graphe\n");
    affiche_graphe(graph, taille);
    puts("");
    getchar();

    printf("Test de la rupture des liaisons des sommets\n");
    delier_somm(tab,n,graph[0].nom,graph);
    printf("Affichage du nouveau graphe\n");
    affiche_graphe(graph, taille);
    puts("");
    liberer_tabhash(tab,n);
}
