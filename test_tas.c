#include "Tas.h"
#include "Graphe.h"
#include <time.h>

void affiche_tas(T_SOMMET_simple* tab, int n){
    int i;
    for (i=0; i<n; i++){
        printf("%d, ", tab[i].num);
    }
    puts("");
}

int main(){
    T_SOMMET* t;T_SOMMET_simple* t2;
    T_SOMMET s;
    int j,i,n,n2=0,val,a;
    double d;
    char mot[100];
    srand(time(NULL));
    printf("Donner le nombre d'elements du graphe: ");
    scanf("%d", &n);
    puts("");
    fgets(mot, 100, stdin);
    t = calloc(n, sizeof(*t));
    t2 = calloc(n, sizeof(*t2));
    for (i=0; i<n; i++){
        s = Sommet_vide();
        s.nom = calloc(4, sizeof(*(s.nom)));
        s.nom[0] = 'a';s.nom[1] = 'a';s.nom[2] = 'a';s.nom[3] = 'a';
        s.nom[0] += i;
        s.num = i; s.ligne = "M1";
        s.F = rand()%1000;
        t[i] = s;
    }
    printf("Affichage du graphe\n");
    affiche_graphe(t,n);

    printf("Test de l'ajout dans le tas\n");
    for (i=0; i<n; i++){
        printf("Ajout du sommet numero %d\n", i);
        ajout_tas(t2,&n2,t+i,t);
        printf("Affichage du graphe\n");
        affiche_graphe(t,n);
        printf("Affichage du tas\n");
        affiche_tas(t2,n2);
        getchar();
    }
    printf("La taille du tas est: %d\n",n2);
    printf("Affichage du tas\n");
    affiche_tas(t2,n2);
    getchar();

    printf("Test de la suppression dans le tas\n");
    printf("Sommet supprime numero 1\n");
    a=suppression_tas(t2, &n2,t);
    affiche_Sommet(t+a);
    printf("Sommet supprime numero 2\n");
    affiche_Sommet(t+suppression_tas(t2, &n2,t));
    puts("");
    printf("La taille du tas est: %d\n",n2);
    getchar();
    printf("Affichage du graphe\n");
    affiche_graphe(t,n);
    printf("Affichage du tas\n");
    affiche_tas(t2,n2);
    getchar();

    printf("Test de la montee d'un tas\n");
    printf("Donner le numero d'un sommet et sa nouvelle valeur de F ");
    scanf("%d %lf",&val, &d);
    puts("");
    t[val].F = d;
    printf("Sommet modifie:\n");
    affiche_Sommet(t+val);
    monte_tas(t2, t+val,t);
    printf("La taille du tas est: %d\n",n2);
    getchar();
    printf("Affichage du graphe\n");
    affiche_graphe(t,n);
    printf("Affichage du tas\n");
    affiche_tas(t2,n2);
    getchar();

    printf("Ajout d'un ancien element du tas\n");
    printf("Sommet ajoute:\n");
    affiche_Sommet(t+a);
    ajout_tas(t2,&n2,t+a,t);
    printf("Affichage du graphe\n");
    affiche_graphe(t,n);
    printf("Affichage du tas\n");
    affiche_tas(t2,n2);
    getchar();

    free(t2);
}
