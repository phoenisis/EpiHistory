/*
** main.c for  in /afs/epitech.net/users/all/pidoux_q/public/epikong/Partie1
** 
** Made by sevan hubert
** Login   <hubert_s@epitech.net>
** 
** Started on  Sat Mar 26 18:39:49 2011 sevan hubert
** Last update Sun Mar 27 23:18:47 2011 sevan hubert
*/

#include <SDL/SDL.h>
#include "epikong.h"

#define LARGEUR_TILE 24
#define HAUTEUR_TILE 16

void Afficher(SDL_Surface* screen, SDL_Surface* tileset, s_map *map)
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
      SDL_BlitSurface(tileset, &Rect_source, screen, &Rect_dest);
      i++;
    }
  SDL_Flip(screen);
}

s_map	*init_map(char **argv)
{
  s_map	*map;

  if (argv[1])
    map = makeMap(argv[1]);
  else
    {
      printf("Usage : ./epikong file_map\n");
      exit(-1);
    }
  return map;
}

int main(int argc, char** argv)
{
  SDL_Surface* screen, *tileset;
  SDL_Event event;
  s_map	*map;

  (void)argc;
  map = init_map(argv);
  SDL_Init(SDL_INIT_VIDEO);
  screen = SDL_SetVideoMode(LARGEUR_TILE * map->sizeX, \
			    HAUTEUR_TILE * map->sizeY, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
  tileset = SDL_LoadBMP("tileset1.bmp");
  if (!tileset)
    {
      printf("Echec de chargement tileset1.bmp\n");
      SDL_Quit();
      exit(-1);
    }
  Afficher(screen, tileset, map);
  while (event.type!=SDL_KEYDOWN)
    SDL_WaitEvent(&event);
  SDL_FreeSurface(tileset);
  SDL_Quit();
  free(map);
  return 0;
}
