#include "affichage_graph.h"

void affichage_liste_fermee_graph_am(SDL_Surface* ecran, T_SOMMET* graph, int arrivee, image im, ligne* tab){
  T_SOMMET s, t;
  affichage_image(ecran, im);
  s =graph[arrivee];
  for (t=*(s.pere); t.pere!=NULL; t=*(t.pere)){
    affichage_arc(ecran, s, t, im, tab);
    s =t;
    affichage_sommet(ecran, t, im, tab);
  }

  affichage_arc(ecran, s, t, im, tab);
  affichage_sommet_fin(ecran, graph[arrivee],t, im,tab); // affichage du sommet et du numero d'arrivee
  SDL_Flip(ecran);
}

void affichage_liste_fermee_graph_pa(SDL_Surface* ecran, T_SOMMET* graph, int arrivee, char* nom_dep, char* nom_arr, image im, ligne* tab){
  T_SOMMET s,t,s_arr;
  affichage_image(ecran, im);
  s =graph[arrivee];

  for (t=s; t.pere!=NULL && strcasecmp(t.nom, nom_dep)!=0; t=*(t.pere)){
    if (strcasecmp((t.pere)->nom, nom_arr)!=0){
        affichage_arc(ecran, s, t, im, tab);
        s =t;
        if (strcasecmp(t.nom, nom_arr)==0) s_arr=t;
        else affichage_sommet(ecran,t,im,tab);
    }
  }

  affichage_arc(ecran, s, t, im, tab);
  affichage_sommet_fin_pa(ecran, s_arr, t, im,tab);

  SDL_Flip(ecran);
}

void affichage_image(SDL_Surface* ecran, image im){
  SDL_Surface* imageDeFond = NULL;
  SDL_Rect positionFond;
  positionFond.x=0;
  positionFond.y=0;

  imageDeFond = IMG_Load(im.nom);
  SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
  SDL_Flip(ecran); // Mise a jours de l'ecran
}

image* creation_tab_image(){
  image* tab;
  tab=calloc(7,sizeof(*tab));
  sprintf(tab[0].nom,"Paris_map.PNG");
  tab[0].xmax = 2.78103;
  tab[0].xmin = 1.95592;
  tab[0].ymax = 49.14364;
  tab[0].ymin = 48.27763;
  tab[0].dimx = 1200;
  tab[0].dimy = 700;
  sprintf(tab[1].nom,"NewYork_map.PNG");
  tab[1].xmax = -73394540;
  tab[1].xmin = -74598090;
  tab[1].ymax = 41398940;
  tab[1].ymin = 40286360;
  tab[1].dimx = 1200;
  tab[1].dimy = 700;
  sprintf(tab[2].nom,"Colorado_map.PNG");
  tab[2].xmax = -101448010;
  tab[2].xmin = -109391120;
  tab[2].ymax = 41362690;
  tab[2].ymin = 35522380;
  tab[2].dimx = 1200;
  tab[2].dimy = 700;
  sprintf(tab[3].nom,"Floride_map.PNG");
  tab[3].xmax = -79923740;
  tab[3].xmin = -88616800;
  tab[3].ymax = 31406190;
  tab[3].ymin = 24526890;
  tab[3].dimx = 1200;
  tab[3].dimy = 700;
  sprintf(tab[4].nom,"GrandLacs_map.PNG");
  tab[4].xmax = -73829390;
  tab[4].xmin = -93027830;
  tab[4].ymax = 48757340;
  tab[4].ymin = 40952540;
  tab[4].dimx = 1200;
  tab[4].dimy = 700;
  sprintf(tab[5].nom,"USAOuest_map.PNG");
  tab[5].xmax = -99906040;
  tab[5].xmin = -125267580;
  tab[5].ymax = 49145420;
  tab[5].ymin = 27848570;
  tab[5].dimx = 1200;
  tab[5].dimy = 700;
  sprintf(tab[6].nom,"USACentral_map.PNG");
  tab[6].xmax = -78417800;
  tab[6].xmin = -120079860;
  tab[6].ymax = 49514280;
  tab[6].ymin = 24822020;
  tab[6].dimx = 1200;
  tab[6].dimy = 700;
  return tab;
}


image trouve_image(char* nom, image* tab) {
  int i;
  for (i=0; i < 7 ;i++) { // le 7 correspond au nombre d'images
      if (strcasecmp(nom,tab[i].nom)==0){
        return tab[i];
      }
  }
  return tab[0];
}

void affichage_sommet(SDL_Surface* ecran, T_SOMMET som, image im, ligne* tab) {
  int yao;
  int bouksim;
  conversion(im.dimx,im.dimy, &yao, &bouksim, im.xmax, im.xmin, im.ymax, im.ymin, som.x,som.y) ;
  dessinecercleplein(ecran, yao, bouksim,3,couleur_sommet(som.ligne,tab));
}


void affichage_arc(SDL_Surface* ecran, T_SOMMET som1, T_SOMMET som2, image im, ligne* tab) {
  int yao;
  int bouksim;
  int emmanuel;
  int oussama;
  conversion(im.dimx,im.dimy, &yao, &bouksim, im.xmax, im.xmin, im.ymax, im.ymin, som1.x,som1.y) ;
  conversion(im.dimx,im.dimy, &emmanuel, &oussama, im.xmax, im.xmin, im.ymax, im.ymin, som2.x,som2.y) ;
  dessineligne(ecran, yao, bouksim, emmanuel, oussama, couleur_arc(som1.ligne, som2.ligne,tab));
}

void affichage_graphe(SDL_Surface* ecran, T_SOMMET* graph, int taille, image im, ligne* tab){ // afficher les deux
  int i,j;
  L_ARC p;
  for (i = 0; i < taille; i++) {
    affichage_sommet(ecran, graph[i], im, tab);
    for (p=graph[i].voisins; !liste_vide(p); p=p->suiv) {
      j=(p->val).arrivee;
      affichage_arc(ecran, graph[i], graph[j], im, tab); }
    }
  SDL_Flip(ecran); // Mise a jour de l'ecran
  }

void affichage_sommet_fin(SDL_Surface* ecran, T_SOMMET som1, T_SOMMET som2, image im, ligne* tab){
    int yao;
    int bouksim;
    char c[10];
    T_SOMMET som_h, som_b;

    //Initialisation de sdl_ttf
    TTF_Init();
    SDL_Surface *texte = NULL;
    SDL_Rect position;
    TTF_Font *police = NULL;
    SDL_Color couleurNoire = {0, 0, 0};
    police = TTF_OpenFont("arial.ttf", 20); //chargement de la police
    TTF_SetFontStyle(police, TTF_STYLE_NORMAL);

    if (som1.y <= som2.y){
      som_b = som1; som_h =som2;
    }
    else{
      som_b = som2; som_h = som1;
    }

    conversion(im.dimx,im.dimy, &yao, &bouksim, im.xmax, im.xmin, im.ymax, im.ymin, som_h.x,som_h.y) ;
    dessinecercleplein(ecran, yao, bouksim,3,couleur_sommet(som_h.ligne,tab));

    sprintf(c, "%d", som_h.num);
    texte = TTF_RenderText_Blended(police, c, couleurNoire);
    position.x = yao;
    position.y = bouksim-texte->h/2-8;
    SDL_BlitSurface(texte, NULL, ecran, &position);

    conversion(im.dimx,im.dimy, &yao, &bouksim, im.xmax, im.xmin, im.ymax, im.ymin, som_b.x,som_b.y) ;
    dessinecercleplein(ecran, yao, bouksim,3,couleur_sommet(som_b.ligne,tab));

    sprintf(c, "%d", som_b.num);
    texte = TTF_RenderText_Blended(police, c, couleurNoire);
    position.x = yao;
    position.y = bouksim-texte->h/2+8;
    SDL_BlitSurface(texte, NULL, ecran, &position);
    TTF_CloseFont(police);
    TTF_Quit(); // fermeture de la sdl_ttf
}

void affichage_sommet_fin_pa(SDL_Surface* ecran, T_SOMMET som1, T_SOMMET som2, image im, ligne* tab){
    int yao;
    int bouksim;
    T_SOMMET som_g, som_d;

    //Initialisation de sdl_ttf
    TTF_Init();
    SDL_Surface *texte = NULL;
    SDL_Rect position;
    TTF_Font *police = NULL;
    SDL_Color couleurNoire = {0, 0, 0};
    police = TTF_OpenFont("arial.ttf", 10); //chargement de la police
    TTF_SetFontStyle(police, TTF_STYLE_BOLD);

    if (som1.x <= som2.x){
      som_g = som1; som_d =som2;
    }
    else{
      som_g = som2; som_d = som1;
    }

    conversion(im.dimx,im.dimy, &yao, &bouksim, im.xmax, im.xmin, im.ymax, im.ymin, som_g.x,som_g.y) ;
    dessinecercleplein(ecran, yao, bouksim,3,couleur_sommet(som_g.ligne,tab));

    texte = TTF_RenderText_Blended(police, som_g.nom, couleurNoire);
    position.x = yao-4-texte->w;
    position.y = bouksim-texte->h/2;
    SDL_BlitSurface(texte, NULL, ecran, &position);

    conversion(im.dimx,im.dimy, &yao, &bouksim, im.xmax, im.xmin, im.ymax, im.ymin, som_d.x,som_d.y) ;
    dessinecercleplein(ecran, yao, bouksim,3,couleur_sommet(som_d.ligne,tab));


    texte = TTF_RenderText_Blended(police, som_d.nom, couleurNoire);
    position.x = yao +4;
    position.y = bouksim-texte->h/2;
    SDL_BlitSurface(texte, NULL, ecran, &position);
    TTF_CloseFont(police);
    TTF_Quit(); // fermeture de la sdl_ttf
}


void affichage_sommet1(SDL_Surface* ecran, T_SOMMET som, L_SOMMET** mat, image im, ligne* tab){
    int yao;
    int bouksim;
    conversion(im.dimx,im.dimy, &yao, &bouksim, im.xmax, im.xmin, im.ymax, im.ymin, som.x,som.y) ;
    mat[yao][bouksim] = ajout_tete_som(som.num, mat[yao][bouksim]); // ajout dans la matrice
    dessinecercleplein(ecran, yao, bouksim,3,couleur_sommet(som.ligne,tab));
}

void affichage_graphe1(SDL_Surface* ecran, T_SOMMET* graph, L_SOMMET** mat, int taille, image im, ligne* tab){
    int i,j;
    L_ARC p;
    for (i = 0; i < taille; i++) {
        affichage_sommet1(ecran, graph[i], mat, im, tab);
        for (p=graph[i].voisins; !liste_vide(p); p=p->suiv) {
            j=(p->val).arrivee;
            affichage_arc(ecran, graph[i], graph[j], im, tab); }
        }
    SDL_Flip(ecran);
}
