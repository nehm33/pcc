#include "Draw.h"

SDL_Surface* newfenetregraphique(int dimx, int dimy){
  SDL_Surface *ecran = NULL;
  SDL_Init(SDL_INIT_VIDEO);
  ecran = SDL_SetVideoMode(dimx, dimy, 32, SDL_HWSURFACE);
  if (ecran == NULL) {
    fprintf(stderr, "Erreur lors de la creation de la fenetre graphique\n");
    return NULL;
  }
  SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 255, 255, 255));
  return ecran;
}


void setPixel(SDL_Surface* affichage, int x, int y, Uint32 coul) {
  *((Uint32*)(affichage->pixels) + x + y * affichage->w) = coul;
}


void setPixelVerif(SDL_Surface* affichage, int x, int y, Uint32 coul) {
  if (x >= 0 && x < affichage->w && y >= 0 && y < affichage->h)
    setPixel(affichage, x, y, coul);
}

void dessineligneHorizontale(SDL_Surface* affichage, int x, int y, int w, Uint32 coul) {
  SDL_Rect r;

  r.x = x;
  r.y = y;
  r.w = w;
  r.h = 1;

  SDL_FillRect(affichage, &r, coul);
}

void dessineligneVerticale(SDL_Surface* affichage, int x, int y, int h, Uint32 coul) {
  SDL_Rect r;

  r.x = x;
  r.y = y;
  r.w = 1;
  r.h = h;

  SDL_FillRect(affichage, &r, coul);
}


void dessinerectangle(SDL_Surface* affichage, int x, int y, int w, int h, Uint32 coul) {
  dessineligneHorizontale(affichage, x, y, w, coul);
  dessineligneHorizontale(affichage, x, y + h - 1, w, coul);
  dessineligneVerticale(affichage, x, y + 1, h - 2, coul);
  dessineligneVerticale(affichage, x + w - 1, y + 1, h - 2, coul);
}


void dessinerectangleplein(SDL_Surface* affichage, int x, int y, int w, int h, Uint32 coul) {
  dessinerectangle(affichage, x, y, w, h, coul);
  for (int i=1; i<h-1; i++) {
    dessineligneHorizontale(affichage, x, y + i, w, coul);
  }
}


void echangerEntiers(int* x, int* y) {
  int t = *x;
  *x = *y;
  *y = t;
}


void dessineligne(SDL_Surface* affichage, int x1, int y1, int x2, int y2, Uint32 coul) {
  int d, dx, dy, aincr, bincr, xincr, yincr, x, y;

  if (abs(x2 - x1) < abs(y2 - y1)) {
    /* parcours par l'axe vertical */

    if (y1 > y2) {
      echangerEntiers(&x1, &x2);
      echangerEntiers(&y1, &y2);
    }

    xincr = x2 > x1 ? 1 : -1;
    dy = y2 - y1;
    dx = abs(x2 - x1);
    d = 2 * dx - dy;
    aincr = 2 * (dx - dy);
    bincr = 2 * dx;
    x = x1;
    y = y1;

    setPixelVerif(affichage, x, y, coul);

    for (y = y1+1; y <= y2; ++y) {
      if (d >= 0) {
	x += xincr;
	d += aincr;
      } else
	d += bincr;

      setPixelVerif(affichage, x, y, coul);
    }

  } else {
    /* parcours par l'axe horizontal */

    if (x1 > x2) {
      echangerEntiers(&x1, &x2);
      echangerEntiers(&y1, &y2);
    }

    yincr = y2 > y1 ? 1 : -1;
    dx = x2 - x1;
    dy = abs(y2 - y1);
    d = 2 * dy - dx;
    aincr = 2 * (dy - dx);
    bincr = 2 * dy;
    x = x1;
    y = y1;

    setPixelVerif(affichage, x, y, coul);

    for (x = x1+1; x <= x2; ++x) {
      if (d >= 0) {
	y += yincr;
	d += aincr;
      } else
	d += bincr;

      setPixelVerif(affichage, x, y, coul);
    }
  }
}


void dessinecercle(SDL_Surface* affichage, int cx, int cy, int rayon, int coul) {
  int d, y, x;

  d = 3 - (2 * rayon);
  x = 0;
  y = rayon;

  while (y >= x) {
    setPixelVerif(affichage, cx + x, cy + y, coul);
    setPixelVerif(affichage, cx + y, cy + x, coul);
    setPixelVerif(affichage, cx - x, cy + y, coul);
    setPixelVerif(affichage, cx - y, cy + x, coul);
    setPixelVerif(affichage, cx + x, cy - y, coul);
    setPixelVerif(affichage, cx + y, cy - x, coul);
    setPixelVerif(affichage, cx - x, cy - y, coul);
    setPixelVerif(affichage, cx - y, cy - x, coul);

    if (d < 0)
      d = d + (4 * x) + 6;
    else {
      d = d + 4 * (x - y) + 10;
      y--;
    }

    x++;
  }
}


void dessinecercleplein(SDL_Surface* affichage, int cx, int cy, int rayon, int coul) {
  int d, y, x;

  d = 3 - (2 * rayon);
  x = 0;
  y = rayon;

  while (y >= x) {
    setPixelVerif(affichage, cx + x, cy + y, coul);
    setPixelVerif(affichage, cx + y, cy + x, coul);
    setPixelVerif(affichage, cx - x, cy + y, coul);
    setPixelVerif(affichage, cx - y, cy + x, coul);
    setPixelVerif(affichage, cx + x, cy - y, coul);
    setPixelVerif(affichage, cx + y, cy - x, coul);
    setPixelVerif(affichage, cx - x, cy - y, coul);
    setPixelVerif(affichage, cx - y, cy - x, coul);
    dessineligneHorizontale(affichage, cx - x, cy + y, 2*x, coul);
    dessineligneHorizontale(affichage, cx - x, cy - y, 2*x, coul);
    dessineligneHorizontale(affichage, cx - y, cy + x, 2*y, coul);
    dessineligneHorizontale(affichage, cx - y, cy - x, 2*y, coul);

    if (d < 0)
      d = d + (4 * x) + 6;
    else {
      d = d + 4 * (x - y) + 10;
      y--;
    }

    x++;
  }
}
