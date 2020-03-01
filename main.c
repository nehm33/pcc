#include "reseau.h"

void pause(SDL_Surface* ecran, image im, int pa)
{
    int continuer = 1;
    SDL_Surface* texte, *blit;
    SDL_Event event;
    SDL_Rect position, positionblit;
    TTF_Font *police = NULL;
    SDL_Color couleurNoire = {0, 0, 0};
    char text[100];
    double x,y;

    if (strcasecmp(im.nom, "NewYork_map.PNG")==0||strcasecmp(im.nom, "Paris_map.PNG")==0 ) blit = SDL_CreateRGBSurface(SDL_HWSURFACE, 500, 23, 32,0,0,0,0);
    else blit = SDL_CreateRGBSurface(SDL_HWSURFACE, 700, 23, 32,0,0,0,0);

    if (strcasecmp(im.nom,"USAOuest_map.PNG")==0) positionblit.x = 0;
    else{
      if (strcasecmp(im.nom, "NewYork_map.PNG")==0||strcasecmp(im.nom, "Paris_map.PNG")==0) positionblit.x = 700;
      else positionblit.x =500;
    }

    if (strcasecmp(im.nom, "GrandLacs_map.PNG")==0||strcasecmp(im.nom, "USACentral_map.PNG")==0) positionblit.y = 0;
    else positionblit.y = 677;

    SDL_FillRect(blit, NULL, SDL_MapRGB(ecran->format, 255, 255, 255));
    TTF_Init();
    police = TTF_OpenFont("arial.ttf", 22);
    TTF_SetFontStyle(police, TTF_STYLE_BOLD|TTF_STYLE_ITALIC);

    while (continuer)
{
    SDL_WaitEvent(&event);
    switch(event.type)
    {
        case SDL_QUIT:
            continuer = 0;
            break;
        case SDL_KEYDOWN: /* Si appui sur une touche */
            continuer = 0;
            break;
        case SDL_MOUSEMOTION:
            conversion_inv(1200, 700, event.motion.x, event.motion.y, im.xmax, im.xmin, im.ymax, im.ymin, &x, &y);
            if (pa) sprintf(text, "Coordonnees : %lf %lf", x, y);
            else sprintf(text, "Coordonnees : %lf %lf", x*0.000001, y*0.000001);
            SDL_BlitSurface(blit, NULL, ecran, &positionblit);
            texte = TTF_RenderText_Blended(police, text, couleurNoire);

            if (strcasecmp(im.nom,"USAOuest_map.PNG")==0) position.x = 0;
            else position.x =1200-texte->w;

            if (strcasecmp(im.nom, "GrandLacs_map.PNG")==0||strcasecmp(im.nom, "USACentral_map.PNG")==0) position.y = 0;
            else position.y= 700-texte->h;

            SDL_BlitSurface(texte, NULL, ecran, &position);
            SDL_Flip(ecran);
            SDL_FreeSurface(texte);
    }
}
SDL_FreeSurface(blit);
TTF_CloseFont(police);
TTF_Quit();
}

void pause_simple(){
  int continuer=1;
  SDL_Event event;

  while (continuer){
    SDL_WaitEvent(&event);
    switch(event.type)
    {
        case SDL_QUIT:
            continuer = 0;
            break;
        case SDL_KEYDOWN: /* Si appui sur une touche */
            continuer = 0;
            break;
    }
  }
}

void pause1(SDL_Surface* ecran, int* reponse){
    int continuer = 1;
    SDL_Event event;
    SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 255, 255, 255));
    SDL_Flip(ecran);

    TTF_Init();
    SDL_Surface *texte = NULL;
    SDL_Rect position;
    TTF_Font *police = NULL;
    SDL_Color couleurNoire = {0, 0, 0};
    police = TTF_OpenFont("arial.ttf", 50);
    TTF_SetFontStyle(police, TTF_STYLE_NORMAL);
    texte = TTF_RenderText_Blended(police, " Voulez-vous trouver des points a l'aide de la souris? ", couleurNoire);
    position.x = (1200-texte->w)/2;
    position.y = 325-texte->h/2;
    SDL_BlitSurface(texte, NULL, ecran, &position);
    position.y = 330+texte->h/2;
    texte = TTF_RenderText_Blended(police, "(o/n)", couleurNoire);
    position.x = (1200-texte->w)/2;
    SDL_BlitSurface(texte, NULL, ecran, &position);
    TTF_CloseFont(police);
    TTF_Quit();
    SDL_Flip(ecran);

    while (continuer){
    SDL_WaitEvent(&event);
    switch(event.type)
    {
        case SDL_KEYDOWN: /* Si appui sur une touche */
            switch(event.key.keysym.sym){
              case SDLK_o:
                *reponse=1;
                continuer = 0;
                break;
              case SDLK_n:
                continuer = 0;
                break;
              default:
                break;
            }
            break;
    }
}
}

void attente(SDL_Surface* ecran){//la fonction d'attente du chargement du programme
  SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 255, 255, 255));
  SDL_Flip(ecran);
  TTF_Init();
  SDL_Surface *texte = NULL;
  SDL_Rect position;
  TTF_Font *police = NULL;
  SDL_Color couleurNoire = {0, 0, 0};
  police = TTF_OpenFont("arial.ttf", 50);
  TTF_SetFontStyle(police, TTF_STYLE_NORMAL);
  texte = TTF_RenderText_Blended(police, " Veuillez patienter svp. ", couleurNoire);
  position.x = (1200-texte->w)/2;
  position.y = (700-texte->h)/2-50;
  SDL_BlitSurface(texte, NULL, ecran, &position);
  texte = TTF_RenderText_Blended(police, "  Attente du chargement du programme. ", couleurNoire);
  position.x = (1200-texte->w)/2;
  position.y += 50;
  SDL_BlitSurface(texte, NULL, ecran, &position);
  TTF_CloseFont(police);
  TTF_Quit();
  SDL_Flip(ecran);
}


int main(int argc, char*argv[]){
    image* pic;
    SDL_Surface* ecran = NULL;
    T_SOMMET* graph_paris, *graph_colorado, *graph_ny, *graph_fl, *graph_gl, *graph_usac, *graph_usao;
    int taille_paris, taille_colorado, taille_ny, taille_fl, taille_gl, taille_usac, taille_usao;
    L_SOMMET* thash;
    ligne* t;
    int  reponse=0;
    pic = creation_tab_image();
    t = creation_tab_lig();
    ecran =newfenetregraphique(1200,700);
    SDL_Surface* imageDeFond = NULL;
    SDL_Rect positionFond;
    positionFond.x=0;
    positionFond.y=0;

    imageDeFond = IMG_Load("interface.png");
    SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
    SDL_Flip(ecran);
    int continuer = 1, continuer_paris = 0, continuer_colorado = 0, continuer_ny = 0, continuer_fl = 0, continuer_gl = 0, continuer_usac = 0, continuer_usao = 0;
    image i,i_colorado, i_newyork, i_floride, i_grandlacs, i_usac, i_usao;
    SDL_Event event;

    while (continuer){
    SDL_WaitEvent(&event);
    switch(event.type){
        case SDL_QUIT:
            continuer = 0;
            break;
        case SDL_KEYDOWN:
            switch (event.key.keysym.sym)
            {
                case SDLK_ESCAPE: /* Appui sur la touche Echap, on arr�te le programme */
                    continuer = 0;
                    break;
                case SDLK_KP1:
                    pause1(ecran, &reponse);

                    i = trouve_image("Paris_map.PNG", pic);
                    if (continuer_paris==0){
                        graph_paris = lecture_graphe("metroetu.csv", &taille_paris);
                        thash = tabhash(graph_paris, taille_paris, 75);
                        continuer_paris = 1;
                    }

                    if (!reponse) reseau_pa(ecran,graph_paris, taille_paris, thash, 75, i, t);
                    else reseau_pa1(ecran,graph_paris, taille_paris, thash, 75, i, t);

                    pause(ecran, i,1);
                    reponse=0;
                    break;
                case SDLK_KP2:
                    pause1(ecran, &reponse);
                    attente(ecran);

                    if (continuer_colorado==0){
                        graph_colorado = lecture_graphe("/users/prog1a/C/librairie/projetS22019/grapheColorado.csv", &taille_colorado);
                        i_colorado = trouve_image("Colorado_map.PNG", pic);
                        continuer_colorado = 1;
                    }
                    if (!reponse) reseau_am(ecran,graph_colorado, taille_colorado, i_colorado, t);
                    else reseau_am1(ecran,graph_colorado, taille_colorado, i_colorado, t);
                    pause(ecran, i_colorado,0);
                    reponse=0;
                    break;
                case SDLK_KP3:
                    pause1(ecran, &reponse);
                    attente(ecran);
                    if (continuer_gl==0){
                      graph_gl = lecture_graphe("/users/prog1a/C/librairie/projetS22019/grapheGrandLacs.csv", &taille_gl);
                      i_grandlacs = trouve_image("GrandLacs_map.PNG", pic);
                      continuer_gl = 1;
                    }
                    if (!reponse) reseau_am(ecran,graph_gl, taille_gl, i_grandlacs, t);
                    else reseau_am1(ecran,graph_gl, taille_gl, i_grandlacs, t);
                    pause(ecran, i_grandlacs,0);
                    reponse=0;
                    break;
                case SDLK_KP4:
                    pause1(ecran, &reponse);
                    attente(ecran);
                    if (continuer_usac==0){
                      graph_usac = lecture_graphe("/users/prog1a/C/librairie/projetS22019/grapheUSACentral.csv", &taille_usac);
                      i_usac = trouve_image("USACentral_map.PNG", pic);
                      continuer_usac = 1;
                    }
                    if (!reponse) reseau_am(ecran,graph_usac, taille_usac, i_usac, t);
                    else reseau_am1(ecran,graph_usac, taille_usac, i_usac, t);
                    pause(ecran, i_usac,0);
                    reponse=0;
                    break;
                case SDLK_KP5:
                    pause1(ecran, &reponse);
                    attente(ecran);
                    if (continuer_ny==0){
                      graph_ny = lecture_graphe("/users/prog1a/C/librairie/projetS22019/grapheNewYork.csv", &taille_ny);
                      i_newyork = trouve_image("NewYork_map.PNG", pic);
                      continuer_ny = 1;
                    }
                    if (!reponse) reseau_am(ecran,graph_ny, taille_ny, i_newyork, t);
                    else reseau_am1(ecran,graph_ny, taille_ny, i_newyork, t);
                    pause(ecran, i_newyork,0);
                    reponse = 0;
                    break;
                case SDLK_KP6:
                    pause1(ecran, &reponse);
                    attente(ecran);
                    if (continuer_fl==0){
                      graph_fl = lecture_graphe("/users/prog1a/C/librairie/projetS22019/grapheFloride.csv", &taille_fl);
                      i_floride = trouve_image("Floride_map.PNG", pic);
                      continuer_fl = 1;
                    }
                    if (!reponse) reseau_am(ecran,graph_fl, taille_fl, i_floride, t);
                    else reseau_am1(ecran,graph_fl, taille_fl, i_floride, t);
                    pause(ecran, i_floride,0);
                    reponse=0;
                    break;
                case SDLK_KP7:
                    pause1(ecran, &reponse);
                    attente(ecran);
                    if (continuer_usao==0){
                      graph_usao = lecture_graphe("/users/prog1a/C/librairie/projetS22019/grapheUSAOuest.csv", &taille_usao);
                      i_usao = trouve_image("USAOuest_map.PNG", pic);
                      continuer_usao = 1;
                    }
                    if (!reponse) reseau_am(ecran,graph_usao, taille_usao, i_usao, t);
                    else reseau_am1(ecran,graph_usao, taille_usao, i_usao, t);
                    pause(ecran, i_usao,0);
                    reponse=0;
                    break;
                case SDLK_F1:
                    SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 255, 255, 255));
                    SDL_Flip(ecran);
                    TTF_Init();
                    SDL_Surface *textea = NULL;
                    SDL_Rect positiona;
                    TTF_Font *policea = NULL;
                    SDL_Color couleurNoirea = {0, 0, 0}, couleurRouge = {255,0,0};
                    policea= TTF_OpenFont("arial.ttf", 30);
                    TTF_SetFontStyle(policea, TTF_STYLE_NORMAL);
                    positiona.x = 0;
                    positiona.y = 8;
                    textea = TTF_RenderText_Blended(policea, "Choississez a l'aide du clavier dans l'application l'une des touches proposees au menu. ", couleurNoirea);
                    SDL_BlitSurface(textea, NULL, ecran, &positiona);
                    positiona.x = 0;
                    positiona.y += 32;
                    textea = TTF_RenderText_Blended(policea, "Vous devez repondre a la question qui suit dans l'application.", couleurNoirea);
                    SDL_BlitSurface(textea, NULL, ecran, &positiona);
                    positiona.x = 0;
                    positiona.y += 32;
                    textea = TTF_RenderText_Blended(policea, "Si vous choississez de trouver des sommets sur la carte, vous devez faire des clics ", couleurNoirea);
                    SDL_BlitSurface(textea, NULL, ecran, &positiona);
                    positiona.x = 0;
                    positiona.y += 32;
                    textea = TTF_RenderText_Blended(policea, "gauches et les sommets dans la zone cliquee seront affichees et ensuite appuyez sur ", couleurNoirea);
                    SDL_BlitSurface(textea, NULL, ecran, &positiona);
                    positiona.x = 0;
                    positiona.y += 32;
                    textea = TTF_RenderText_Blended(policea, "Entree ou n'importe quelle touche dans l'application pour ecrire les sommets de depart et ", couleurNoirea);
                    SDL_BlitSurface(textea, NULL, ecran, &positiona);
                    positiona.x = 0;
                    positiona.y += 32;
                    textea = TTF_RenderText_Blended(policea, "d'arrivee dans la console. Sinon vous ecrivez directement les sommets de depart et ", couleurNoirea);
                    SDL_BlitSurface(textea, NULL, ecran, &positiona);
                    positiona.x = 0;
                    positiona.y += 32;
                    textea = TTF_RenderText_Blended(policea, "d'arrivee dans la console.", couleurNoirea);
                    SDL_BlitSurface(textea, NULL, ecran, &positiona);
                    positiona.x = 0;
                    positiona.y += 32;
                    textea = TTF_RenderText_Blended(policea, "Ne faites pas de clics et n'utilisez pas le clavier durant le chargement du programme.", couleurNoirea);
                    SDL_BlitSurface(textea, NULL, ecran, &positiona);
                    positiona.x = 0;
                    positiona.y += 32;
                    textea = TTF_RenderText_Blended(policea, "Le chemin sera alors affiche dans la console d'abord et quelques instants plus tard,", couleurNoirea);
                    SDL_BlitSurface(textea, NULL, ecran, &positiona);
                    positiona.x = 0;
                    positiona.y += 32;
                    textea = TTF_RenderText_Blended(policea, "le chemin sera affiche dans l'application.", couleurNoirea);
                    SDL_BlitSurface(textea, NULL, ecran, &positiona);
                    positiona.x = 0;
                    positiona.y += 32;
                    textea = TTF_RenderText_Blended(policea, "Lorsque tout cela est termine, vous n'avez plus qu'a appuyer sur Entree ou n'importe quelle ", couleurNoirea);
                    SDL_BlitSurface(textea, NULL, ecran, &positiona);
                    positiona.x = 0;
                    positiona.y += 32;
                    textea = TTF_RenderText_Blended(policea, "touche pour revenir au menu.", couleurNoirea);
                    SDL_BlitSurface(textea, NULL, ecran, &positiona);
                    positiona.x = 0;
                    positiona.y += 32;
                    textea = TTF_RenderText_Blended(policea, "Pour sortir de l'application, appuyez sur la touche Echap.", couleurNoirea);
                    SDL_BlitSurface(textea, NULL, ecran, &positiona);
                    positiona.x = 0;
                    positiona.y += 32;
                    textea = TTF_RenderText_Blended(policea, "Appuyez sur une touche pour sortir de l'aide.", couleurNoirea);
                    SDL_BlitSurface(textea, NULL, ecran, &positiona);
                    TTF_CloseFont(policea);
                    policea = TTF_OpenFont("arial.ttf", 55);
                    TTF_SetFontStyle(policea, TTF_STYLE_NORMAL);
                    positiona.x = 0;
                    positiona.y += 60;
                    textea = TTF_RenderText_Blended(policea, "ATTENTION !!! Si vous faites des clics ou si ", couleurRouge);
                    SDL_BlitSurface(textea, NULL, ecran, &positiona);
                    positiona.x = 0;
                    positiona.y += 60;
                    textea = TTF_RenderText_Blended(policea, "vous appuyez au mauvais moment ou trop, le  ", couleurRouge);
                    SDL_BlitSurface(textea, NULL, ecran, &positiona);
                    positiona.x = 0;
                    positiona.y += 60;
                    textea = TTF_RenderText_Blended(policea, "programme ne marchera pas correctement.", couleurRouge);
                    SDL_BlitSurface(textea, NULL, ecran, &positiona);
                    TTF_CloseFont(policea);
                    TTF_Quit();
                    SDL_Flip(ecran);
                    pause_simple();
                    break;
            }
            break;
    }
        imageDeFond = IMG_Load("interface.png");
        SDL_BlitSurface(imageDeFond, NULL, ecran, &positionFond);
        SDL_Flip(ecran);

}
    if (continuer_paris){
        liberer_graphe(graph_paris, &taille_paris);
        liberer_tabhash(thash, 75);
    }
    if (continuer_colorado) liberer_graphe(graph_colorado, &taille_colorado);
    if (continuer_ny) liberer_graphe(graph_ny, &taille_ny);
    if (continuer_fl) liberer_graphe(graph_fl, &taille_fl);
    if (continuer_gl) liberer_graphe(graph_gl, &taille_gl);
    if (continuer_usac) liberer_graphe(graph_usac, &taille_usac);
    if (continuer_usao) liberer_graphe(graph_usao, &taille_usao);
    free(t); free(pic);
    SDL_Quit();
}
