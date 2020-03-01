#include "Graphe.h"

T_SOMMET* lecture_graphe(char* fichier, int* taille){
    FILE* f;
    T_SOMMET* tab;
    T_ARC c;
    char mot[512];
    int nbsom, nbarc,i,j;
    f = fopen(fichier, "rt");
    if (f==NULL){
      printf("Erreur lors du chargement de %s\n", fichier);
      *taille = 0;
      return NULL;
    }
    // Lecture des sommets
    fscanf(f,"%d %d", &nbsom, &nbarc);
    tab = calloc(nbsom,sizeof(*tab));
    fgets(mot,512,f);
    fgets(mot,512,f);
    for (i=0; i<nbsom; i++){
        tab[i]=Sommet_vide();
        tab[i].nom = calloc(55, sizeof(*(tab[i].nom)));
        tab[i].ligne = calloc(5, sizeof(*(tab[i].ligne)));
        fscanf(f, "%d %lf %lf %s", &((tab[i]).num), &((tab[i]).x), &((tab[i]).y), (tab[i]).ligne);
        fgets(tab[i].nom,55, f);
        (tab[i].nom)[strlen(tab[i].nom)-1] = 0;
    }
    // Lecture des arcs
    fgets(mot,512,f);
    for (i=0; i<nbarc; i++){
        fscanf(f, "%d %d %lf",&j,&(c.arrivee),&(c.coute));
        tab[j].voisins = ajout_tete(c,tab[j].voisins);
        fgets(mot,512,f);
    }
    fclose(f);
    *taille = nbsom;
    return tab;
}

void liberer_graphe(T_SOMMET* graph, int* taille){
    int i;
    for (i=0; i<*taille; i++){
        liberer_Sommet(graph+i);
    }
    free(graph);
    *taille = 0;
}

void affiche_graphe(T_SOMMET* graph, int taille){
    int i;
    for (i=0; i<taille; i++){
        affiche_Sommet(graph+i);
    }
}

void affichage_liste_fermee(int arrivee, T_SOMMET* graph){
    T_SOMMET s;
    s = graph[arrivee];
    // la recursivite sert a afficher le sommet de depart en premier a l'ecran
    if (s.pere!=NULL){
        affichage_liste_fermee((s.pere)->num,graph);
        printf(" %d : %s;\n", s.num, s.nom);
    }
    else{
        printf(" %d : %s;\n", s.num, s.nom);
    }
}

void Astar(int depart, int arrivee, T_SOMMET* graph, int taille){
    T_SOMMET_simple* tas;
    L_ARC p;
    int n=0;
    int k;
    tas = calloc(taille,sizeof(*tas));
    graph[depart].G = 0;
    graph[depart].F = heuristique(graph[depart], graph[arrivee]);
    ajout_tas(tas,&n,graph+depart,graph);
    k = depart;
    while (n!=0 && k!=arrivee){
        k = suppression_tas(tas,&n,graph);
        if (k!=arrivee){
            graph[k].LF = 1;
            for (p = graph[k].voisins; !liste_vide(p); p=p->suiv ){
                if (graph[(p->val).arrivee].LF == 0){
                    if (graph[(p->val).arrivee].ind_tas<0){
                        graph[(p->val).arrivee].pere = graph + k;
                        graph[(p->val).arrivee].G = graph[k].G + (p->val).coute;
                        graph[(p->val).arrivee].F = graph[(p->val).arrivee].G + heuristique(graph[(p->val).arrivee], graph[arrivee]);
                        ajout_tas(tas, &n, graph+(p->val).arrivee,graph);
                    }
                    else{
                        if (graph[k].G+(p->val).coute<graph[(p->val).arrivee].F){
                            graph[(p->val).arrivee].pere = graph + k;
                            graph[(p->val).arrivee].G = graph[k].G + (p->val).coute;
                            graph[(p->val).arrivee].F = graph[(p->val).arrivee].G + heuristique(graph[(p->val).arrivee], graph[arrivee]);
                            monte_tas(tas, graph+(p->val).arrivee, graph);
                        }
                    }
                }
            }
        }
    }
    free(tas);
}

void reinitialise_graphe(T_SOMMET* graph, int taille){
    int i;
    for (i=0; i<taille; i++){
        reinitialise_sommet(graph+i);
    }
}

void affichage_liste_fermee_am(int arrivee, T_SOMMET* graph){
    T_SOMMET s;
    s = graph[arrivee];
    if (s.pere!=NULL){
        affichage_liste_fermee_am((s.pere)->num,graph);
        printf(" %s;\n", s.nom);
    }
    else{
        printf(" %s;\n", s.nom);
    }
}

void affichage_liste_fermee_pa(int arrivee, char* nom_dep, T_SOMMET* graph, char* nom_arriv){
    T_SOMMET s;
    s = graph[arrivee];
    if (s.pere!=NULL && strcasecmp(s.nom, nom_dep)!=0){
        if (strcasecmp((s.pere)->nom,nom_arriv)!=0){
            affichage_liste_fermee_pa((s.pere)->num, nom_dep,graph,nom_arriv);
            printf("%s(ligne %s);\n", s.nom, s.ligne);
        }
        else{
            affichage_liste_fermee_pa((s.pere)->num, nom_dep,graph,nom_arriv);
        }

    }
    else{
        printf("%s(ligne %s);\n", s.nom, s.ligne);
    }
}
