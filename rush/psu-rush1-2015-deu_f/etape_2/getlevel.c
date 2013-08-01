/*
** getlevel.c for  in /home/pidoux_q/epikong/etape_2
**
** Made by quentin pidoux
** Login   <pidoux_q@epitech.net>
**
** Started on  Sat Mar  3 14:04:03 2012 quentin pidoux
** Last update Sat Mar  3 14:04:04 2012 quentin pidoux
*/

#include		<SDL/SDL.h>
#include		<unistd.h>
#include		<SDL/SDL_image.h>
#include		<sys/mman.h>
#include		<fcntl.h>
#include		<stdio.h>
#include		"board.h"
#include		"get_map.h"

static char		*gere_event(SDL_Event event, int *flag)
{
  *flag = 0;
  if (event.type == SDL_QUIT)
    return (NULL);
  else if ((event.type == SDL_KEYDOWN) && (event.key.keysym.sym == SDLK_ESCAPE))
    return (NULL);
  else if((event.type == SDL_KEYDOWN) && (event.key.keysym.sym == SDLK_KP1))
    return ("../map/1.map");
  else if((event.type == SDL_KEYDOWN) && (event.key.keysym.sym == SDLK_KP2))
    return ("../map/2.map");
  else if((event.type == SDL_KEYDOWN) && (event.key.keysym.sym == SDLK_KP3))
    return ("../map/3.map");
  else if((event.type == SDL_KEYDOWN) && (event.key.keysym.sym == SDLK_KP4))
    return ("../map/4.map");
  else if((event.type == SDL_KEYDOWN) && (event.key.keysym.sym == SDLK_KP5))
    return ("../map/5.map");
  else
    {
      *flag = 1;
      return (NULL);
    }
}

char			*getlevel()
{
  SDL_Surface		*ecran;
  SDL_Surface		*menu;
  SDL_Rect		position;
  SDL_Event		event;
  int			flag;
  char			*levelname;

  flag = 1;
  ecran = xSDL_SetVideoMode(485, 463, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
  SDL_WM_SetCaption("Epikong", NULL);
  menu = xIMG_Load("../image/menu.png");
  position.x = 0;
  position.y = 0;
  while (flag)
    {
      SDL_WaitEvent(&event);
      levelname = gere_event(event, &flag);
      if (flag == 0)
	return (levelname);
      xSDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 0, 0, 0));
      xSDL_BlitSurface(menu, NULL, ecran, &position);
      xSDL_Flip(ecran);
    }
  return (NULL);
}
