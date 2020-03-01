#include "Tas.h"
#include "Graphe.h"


int main(int argc, char** argv){
    T_SOMMET* graph;
    int taille, depart = atoi(argv[2]), arrivee = atoi(argv[3]);
    puts("Chargement du graphe, veuillez patientez quelques secondes");
    graph = lecture_graphe(argv[1], &taille);
    if (graph!=NULL){
      if ((depart>=0&&depart<taille)&&(arrivee>=0&&arrivee<taille)){
          Astar(depart, arrivee, graph, taille);
          affichage_liste_fermee_am(arrivee, graph);
          puts("");
          printf("Cout : %lf", graph[arrivee].F);
          puts("");
      }
      else{
        if (depart<0 || depart >= taille){
            printf("Le sommet %d n'existe pas\n", depart);
        }
        if (arrivee<0 || arrivee >= taille){
            printf("Le sommet %d n'existe pas\n", arrivee);
        }
      }
    }
    liberer_graphe(graph,&taille);
}
