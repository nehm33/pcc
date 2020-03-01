#ifndef __DRAW_H__
#define __DRAW_H__

#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>

void setPixelVerif(SDL_Surface* affichage, int x, int y, Uint32 coul);
void dessineligneHorizontale(SDL_Surface* affichage, int x, int y, int w, Uint32 coul);
void dessineligneVerticale(SDL_Surface* affichage, int x, int y, int h, Uint32 coul);
void dessinerectangle(SDL_Surface* affichage, int x, int y, int w, int h, Uint32 coul);
void dessinerectangleplein(SDL_Surface* affichage, int x, int y, int w, int h, Uint32 coul);
void dessineligne(SDL_Surface* affichage, int x1, int y1, int x2, int y2, Uint32 coul);
void dessinecercle(SDL_Surface* affichage, int cx, int cy, int rayon, int coul);
void dessinecercleplein(SDL_Surface* affichage, int cx, int cy, int rayon, int coul);
SDL_Surface* newfenetregraphique(int dimx, int dimy);

#endif
