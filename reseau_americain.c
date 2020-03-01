#include "Tas.h"
#include "Graphe.h"


int main(int argc, char** argv){
    T_SOMMET* graph;
    int taille;
    int depart, arrivee;
    char mot[100];
    puts("Chargement du graphe, veuillez patientez quelques secondes");
    graph = lecture_graphe(argv[1], &taille);
    if (graph!=NULL){
      do{
          printf("Donner les numeros des sommets de depart et d'arrivee\t");
          scanf("%d %d", &depart, &arrivee);
          puts("");
          fgets(mot,100,stdin);

          if ((depart>=0&&depart<taille)&&(arrivee>=0&&arrivee<taille)){
              Astar(depart, arrivee, graph, taille);
              affichage_liste_fermee_am(arrivee, graph);
              puts("");
              printf("Cout : %lf", graph[arrivee].F);
              puts("");
          }
          else{
            if (depart < 0 || depart >= taille){
                printf("Le sommet %d n'existe pas\n", depart);
            }
            if (arrivee < 0 || arrivee >= taille){
                printf("Le sommet %d n'existe pas\n", arrivee);
            }
          }

          puts("");
          puts("");
          printf("Menu:\n1: Rechercher un autre chemin\t\t\t2: Quitter\n");
          fgets(mot,100,stdin);
          reinitialise_graphe(graph,taille);
      } while (mot[0]=='1');
    }
    liberer_graphe(graph,&taille);
}
