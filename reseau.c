#include "reseau.h"

int reseau_am(SDL_Surface* ecran, T_SOMMET* graph, int taille, image im, ligne* tab){
    int depart, arrivee;
    char mot[100];
    affichage_image(ecran,im);
    affichage_graphe(ecran, graph, taille, im, tab);
    printf("Donner les numeros des sommets de depart et d'arrivee\t");
    scanf("%d %d", &depart, &arrivee);
    puts("");
    fgets(mot, 100, stdin);
    if ((depart>=0&&depart<taille)&&(arrivee>=0&&arrivee<taille)){
        Astar(depart, arrivee, graph, taille);
        affichage_liste_fermee_am(arrivee, graph);
        affichage_liste_fermee_graph_am(ecran,graph,arrivee,im,tab);
        puts("");
        printf("Cout : %lf", graph[arrivee].F);
        puts("");
        reinitialise_graphe(graph, taille);
        return 1;
    }
    else{
      if (depart<0 || depart>= taille){
          printf("Le sommet %d n'existe pas\n", depart);
      }
      if (arrivee<0 || arrivee>= taille){
          printf("Le sommet %d n'existe pas\n", arrivee);
      }
      return 0;
    }
}

int reseau_pa(SDL_Surface* ecran, T_SOMMET* graph, int taille, L_SOMMET* tab, int n, image im, ligne* t){
    int depart, arrivee;
    char nom_dep[100]; char nom_arr[100];

    affichage_image(ecran,im);
    affichage_graphe(ecran, graph, taille, im, t);

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

        Astar(depart, arrivee, graph, taille);

        delier_somm(tab,n,graph[depart].nom,graph);
        delier_somm(tab,n,graph[arrivee].nom,graph);
        affichage_liste_fermee_pa(arrivee,graph[depart].nom, graph, graph[arrivee].nom);
        affichage_liste_fermee_graph_pa(ecran,graph,arrivee,graph[depart].nom,graph[arrivee].nom,im,t);
        puts("");
        printf("Cout : %lf\n", graph[arrivee].F);
        reinitialise_graphe(graph,taille);
        return 1;
    }
    else{
        if (depart==-1){
            printf("La station %s n'existe pas\n", nom_dep);
        }
        if (arrivee==-1){
            printf("La station %s n'existe pas\n", nom_arr);
        }
        return 0;
    }
}

int reseau_am1(SDL_Surface* ecran, T_SOMMET* graph, int taille, image im, ligne* tab){
    int depart, arrivee,i;
    char mot[100];
    L_SOMMET** mat;
    mat = calloc(1200, sizeof(*mat));
    *mat = calloc(1200*750, sizeof(**mat));
    for (i=1; i<1200; i++){
      mat[i] = mat[i-1]+750;
    }

    affichage_image(ecran,im);
    affichage_graphe1(ecran, graph, mat, taille, im, tab);

    printf("Utilisez le clic gauche de la souris pour voir les sommets de la zone pointée\n");
    pause_reseau(ecran,0,mat,graph, im);
    free(mat);

    printf("Donner les numeros des sommets de depart et d'arrivee\t");
    scanf("%d %d", &depart, &arrivee);
    puts("");
    fgets(mot, 100, stdin);
    if ((depart>=0&&depart<taille)&&(arrivee>=0&&arrivee<taille)){
        Astar(depart, arrivee, graph, taille);
        affichage_liste_fermee_am(arrivee, graph);
        affichage_liste_fermee_graph_am(ecran,graph,arrivee,im,tab);
        puts("");
        printf("Cout : %lf", graph[arrivee].F);
        puts("");
        reinitialise_graphe(graph, taille);
        return 1;
    }
    else{
      if (depart<0 || depart>= taille){
          printf("Le sommet %d n'existe pas\n", depart);
      }
      if (arrivee<0 || arrivee>= taille){
          printf("Le sommet %d n'existe pas\n", arrivee);
      }
      return 0;
    }
}

int reseau_pa1(SDL_Surface* ecran, T_SOMMET* graph, int taille, L_SOMMET* tab, int n, image im, ligne* t){
    int depart, arrivee,i;
    char nom_dep[100]; char nom_arr[100]; char mot[100];
    L_SOMMET** mat;
    mat = calloc(1200, sizeof(*mat));
    *mat = calloc(1200*750, sizeof(**mat));
    for (i=1; i<1200; i++){
      mat[i] = mat[i-1]+750;
    }

    affichage_image(ecran,im);
    affichage_graphe1(ecran, graph, mat, taille, im, t);

    printf("Utilisez le clic gauche de la souris pour voir les sommets de la zone pointée\n");

    pause_reseau(ecran,1,mat,graph, im);
    free(mat);

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

        Astar(depart, arrivee, graph, taille);

        delier_somm(tab,n,graph[depart].nom,graph);
        delier_somm(tab,n,graph[arrivee].nom,graph);
        affichage_liste_fermee_pa(arrivee,graph[depart].nom, graph, graph[arrivee].nom);
        affichage_liste_fermee_graph_pa(ecran,graph,arrivee,graph[depart].nom,graph[arrivee].nom,im,t);
        puts("");
        printf("Cout : %lf\n", graph[arrivee].F);
        reinitialise_graphe(graph,taille);
        return 1;
    }
    else{
        if (depart==-1){
            printf("La station %s n'existe pas\n", nom_dep);
        }
        if (arrivee==-1){
            printf("La station %s n'existe pas\n", nom_arr);
        }
        return 0;
    }
}

void pause_reseau(SDL_Surface* ecran, int pa, L_SOMMET** mat, T_SOMMET* graph, image im){
  SDL_Surface* texte, *blit;
  SDL_Event event;
  SDL_Rect position, positionblit;
  TTF_Font *police = NULL;
  SDL_Color couleurNoire = {0, 0, 0};
  char text[100];
  int continuer=1, k=1,i,j;
  double x,y;

  if (strcasecmp(im.nom, "NewYork_map.PNG")==0||strcasecmp(im.nom, "Paris_map.PNG")==0)  blit = SDL_CreateRGBSurface(SDL_HWSURFACE, 500, 23, 32,0,0,0,0);
  else blit = SDL_CreateRGBSurface(SDL_HWSURFACE, 700, 23, 32,0,0,0,0);

  if (strcasecmp(im.nom,"USAOuest_map.PNG")==0) positionblit.x = 0;
  else{
    if (strcasecmp(im.nom, "NewYork_map.PNG")==0||strcasecmp(im.nom, "Paris_map.PNG")==0) positionblit.x = 700;
    else positionblit.x =500;
  }

  if (strcasecmp(im.nom, "GrandLacs_map.PNG")==0||strcasecmp(im.nom, "USACentral_map.PNG")==0) positionblit.y = 0;
  else positionblit.y = 727;

  SDL_FillRect(blit, NULL, SDL_MapRGB(ecran->format, 255, 255, 255));

  TTF_Init();
  police = TTF_OpenFont("arial.ttf", 22);
  TTF_SetFontStyle(police, TTF_STYLE_BOLD|TTF_STYLE_ITALIC);
  while (continuer){
      SDL_WaitEvent(&event);
      switch (event.type){
          case SDL_MOUSEBUTTONDOWN:
              printf("clic %d : \n", k);
              if (event.button.button == SDL_BUTTON_LEFT){
                  for (i=-3; i<4; i++){
                      for (j=-3; j<4; j++){
                          if (pa) visualiser_liste_som_pa(mat[event.button.x+i][event.button.y+j], graph);
                          else visualiser_liste_som(mat[event.button.x+i][event.button.y+j]);
                      }
                  }
                  puts("");puts("");
              }
              k++;
              break;
          case SDL_KEYDOWN:
              if (event.key.keysym.sym){
                  continuer = 0;
              }
              break;
          case SDL_MOUSEMOTION:
              conversion_inv(1200, 750, event.motion.x, event.motion.y, im.xmax, im.xmin, im.ymax, im.ymin, &x, &y);

              if (pa) sprintf(text, "Coordonnees : %lf %lf", x, y);
              else sprintf(text, "Coordonnees : %lf %lf", x*0.000001, y*0.000001);

              SDL_BlitSurface(blit, NULL, ecran, &positionblit);
              texte = TTF_RenderText_Blended(police, text, couleurNoire);

              if (strcasecmp(im.nom,"USAOuest_map.PNG")==0) position.x = 0;
              else position.x =1200-texte->w;

              if (strcasecmp(im.nom, "GrandLacs_map.PNG")==0||strcasecmp(im.nom, "USACentral_map.PNG")==0) position.y = 0;
              else position.y= 750-texte->h;

              SDL_BlitSurface(texte, NULL, ecran, &position);
              SDL_Flip(ecran);
              SDL_FreeSurface(texte);
              break;
      }
  }
  SDL_FreeSurface(blit);
  TTF_CloseFont(police);
  TTF_Quit();
}
