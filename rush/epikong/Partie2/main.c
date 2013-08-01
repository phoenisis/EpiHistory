/*
** main.c for  in /afs/epitech.net/users/all/pidoux_q/public/epikong/Partie1
** 
** Made by sevan hubert
** Login   <hubert_s@epitech.net>
** 
** Started on  Sat Mar 26 18:39:49 2011 sevan hubert
** Last update Sun Mar 27 18:27:37 2011 sevan hubert
*/

#include <SDL/SDL.h>
#include "epikong.h"

#define LARGEUR_TILE 24
#define HAUTEUR_TILE 16

void Aff_map(SDL_Surface* screen, s_map *map)
{
  int i;
  SDL_Rect Rect_dest;
  SDL_Rect Rect_source;

  i = 0;
  Rect_source.w = LARGEUR_TILE;
  Rect_source.h = HAUTEUR_TILE;
  while (map->map[i])
    {
      Rect_dest.x = posX(map, i) * LARGEUR_TILE;
      Rect_dest.y = posY(map, i) * HAUTEUR_TILE;
      Rect_source.x = (map->map[i] - '0') * LARGEUR_TILE;
      Rect_source.y = 0;
      SDL_BlitSurface(map->tileset, &Rect_source, screen, &Rect_dest);
      i++;
    }
  SDL_Flip(screen);
}

void	Aff_heros(SDL_Surface* screen, s_heros *heros)
{
  SDL_Rect Rect_dest;
  SDL_Rect Rect_source;

  Rect_dest.x = heros->caseX * LARGEUR_TILE;
  Rect_dest.y = heros->caseY * HAUTEUR_TILE;
  Rect_source.x = (0) * LARGEUR_TILE;
  Rect_source.y = 0;
  SDL_BlitSurface(heros->tileset, &Rect_source, screen, &Rect_dest);
  SDL_Flip(screen);
}

s_map	*init_map(char **argv, s_heros *heros)
{
  s_map	*map;

  if (argv[1])
    {
      heros->tileset = NULL;
      map->tileset = NULL;
      map = makeMap(argv[1], heros);
      heros->tileset = SDL_LoadBMP("tileset1.bmp");
      map->tileset = SDL_LoadBMP("tileset1.bmp");
      if (!(map->tileset && heros->tileset))
	{
	  printf("Error : can't load tileset.\n");
	  exit(-1);
	}
    }
  else
    {
      printf("Usage : ./epikong file_map\n");
      exit(-1);
    }
  return (map);
}

int main(int argc, char** argv)
{
  SDL_Surface*	screen;
  SDL_Event	event;
  s_map		*map;
  s_heros	*heros = malloc(sizeof(heros));
  Uint32	colorkey;

  map = init_map(argv, heros);
  SDL_Init(SDL_INIT_VIDEO);
  //colorkey = SDL_MapRGB(heros->tileset->format, 0xC4, 0xDF, 0x9B );
  screen = SDL_SetVideoMode(LARGEUR_TILE * map->sizeX, \
			    HAUTEUR_TILE * map->sizeY, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
  //SDL_SetColorKey(heros->tileset, SDL_RLEACCEL | SDL_SRCCOLORKEY, colorkey );
  Aff_heros(screen, heros);
  Aff_map(screen, map);
  while (event.type!=SDL_KEYDOWN)
    SDL_WaitEvent(&event);
  SDL_FreeSurface(map->tileset);
  SDL_Quit();
  free(map);
  return (0);
}
