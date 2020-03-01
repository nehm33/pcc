#include "Tas.h"
#include "Graphe.h"


int main(int argc, char** argv){
    T_SOMMET* graph;
    L_SOMMET* tab;
    int taille,n=75,depart, arrivee;
    char mot[100], nom_dep[100], nom_arr[100];

    graph = lecture_graphe("metroetu.csv", &taille);
    tab = tabhash(graph,taille,n);

    if (graph!=NULL){
      do{
          printf("Donner le nom du sommet de depart\t");
          fgets(nom_dep, 100, stdin);
          printf("Donner le nom du sommet d'arrivee\t");
          fgets(nom_arr, 100, stdin);
          puts("");

          nom_dep[strlen(nom_dep)-1] = 0;nom_arr[strlen(nom_arr)-1] = 0;

          depart = trouver_somm(tab,n,nom_dep,graph);
          arrivee = trouver_somm(tab,n,nom_arr,graph);
          if (depart!=-1 &&arrivee!=-1){
              relier_somm(tab,n,graph[depart].nom,graph);
              relier_somm(tab,n,graph[arrivee].nom,graph);

              printf("%d %d\n", depart, arrivee);

              Astar(depart, arrivee, graph, taille);

              delier_somm(tab,n,graph[depart].nom,graph);
              delier_somm(tab,n,graph[arrivee].nom,graph);
              affichage_liste_fermee_pa(arrivee,graph[depart].nom, graph, graph[arrivee].nom);
              puts("");
              printf("Cout : %lf\n", graph[arrivee].F);puts("");puts("");
          }
          else{
              if (depart==-1){
                  printf("La station %s n'existe pas\n\n", nom_dep);
              }
              if (arrivee==-1){
                  printf("La station %s n'existe pas\n\n", nom_arr);
              }
          }
          printf("Menu:\n1: Rechercher un autre itineraire\t\t\t2: Quitter\n");
          fgets(mot,100,stdin);
          reinitialise_graphe(graph,taille);
      } while (mot[0]=='1');
    }

    liberer_tabhash(tab, n);
    liberer_graphe(graph,&taille);
}
