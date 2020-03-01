#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include "Draw.h"


#define DIMX 680
#define DIMY 420

int main(int argc, char* argv[]){
  //Juste pour tester la sdl
  SDL_Surface* ecran = NULL;
  ecran=newfenetregraphique(DIMX,DIMY);
  dessinecercleplein(ecran, DIMX/2, DIMY/2, 200, 0x0000FF);
  dessinecercleplein(ecran, 5, 5, 5, 0x0000FF);
  dessinecercleplein(ecran, DIMX-6, DIMY-6, 5, 0x0000FF);
  dessineligne(ecran, 5, 5, DIMX/2, DIMY/2, 0x8000FF);
  dessineligne(ecran, DIMX/2, DIMY/2, DIMX-6, DIMY-6, 0x8000FF);
  SDL_Flip(ecran);
  printf("Bonjour");
  puts("");
  getchar();
  dessinerectangleplein(ecran, 0, 0, DIMX/3,DIMY, 0xFF4F00);
  dessinerectangleplein(ecran, DIMX/3, 0, DIMX/3,DIMY, 0xFFFFFF);
  dessinerectangleplein(ecran, 2*DIMX/3, 0, DIMX/3,DIMY, 0x00FF00);
  SDL_Flip(ecran);
  puts("");
  getchar();
}
