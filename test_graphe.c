#include "Graphe.h"
#include <time.h>

int main(){
    T_SOMMET* tab;
    int nbr,i,a;
    tab = lecture_graphe("graphe2.txt", &nbr);
    affiche_graphe(tab,nbr);
    srand(time(NULL));
    getchar();

    printf("Modification du graphe\n");
    printf("Sommets modifies : ");
    for (i=0; i<5; i++){
        a = rand()%nbr;
        printf("%d, ", a);
        tab[a].LF = 1; tab[a].ind_tas = rand()%15;
        tab[a].F = rand()%1000; tab[a].G = rand()%1000;
        tab[a].pere = tab+1;
    }
    puts("");
    affiche_graphe(tab, nbr);
    getchar();

    printf("Reinitialisation du graphe\n");
    reinitialise_graphe(tab,nbr);
    affiche_graphe(tab,nbr);
    getchar();
    liberer_graphe(tab, &nbr);
}
