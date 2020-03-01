#include "affichage_graph.h"

int main(){
    image* pic; image i;
    SDL_Surface* ecran = NULL;
    /*T_SOMMET* graph;
    int taille;
    ligne* t;
    pic = creation_tab_image();
    i = trouve_image("paris.jpg", pic);
    graph = lecture_graphe("metroetu.csv", &taille);
    t = creation_tab_lig();
    ecran = newfenetregraphique(i.dimx,i.dimy);
    affichage_graphe(ecran, graph,i, t);
    getchar();
    Astar(8, 75, graph, taille);
    affichage_liste_fermee_graph_pa(ecran, graph, 75, graph[8].nom, graph[75].nom, i, t);
    getchar();
    liberer_graphe(graph, &taille);
    free(t);
    free(pic);*/
    ecran=newfenetregraphique(1200,750);
    sprintf(i.nom,"Paris_map.PNG");
    affichage_image(ecran, i);
    SDL_Flip(ecran);
    puts("");
    getchar();
}
