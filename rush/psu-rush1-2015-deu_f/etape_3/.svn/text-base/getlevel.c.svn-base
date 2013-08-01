/*
** getlevel.c for  in /home/pidoux_q/epikong/etape_3
**
** Made by quentin pidoux
** Login   <pidoux_q@epitech.net>
**
** Started on  Sat Mar  3 14:29:12 2012 quentin pidoux
** Last update Sat Mar  3 19:23:35 2012 quentin pidoux
*/

#include		<SDL/SDL.h>
#include		<unistd.h>
#include		<SDL/SDL_image.h>
#include		<sys/mman.h>
#include		<fcntl.h>
#include		<stdio.h>
#include		"board.h"
#include		"get_map.h"

static char		*gere_event(SDL_Event event, int *flag, int *l)
{
  *flag = 0;
  if (event.type == SDL_QUIT)
    return (NULL);
  else if ((event.type == SDL_KEYDOWN) && (event.key.keysym.sym == SDLK_ESCAPE))
    return (NULL);
  else if((event.type == SDL_KEYDOWN) && (event.key.keysym.sym == SDLK_KP1))
    {
      *l = 1;
      return ("../map/1.map");
    }
  else if((event.type == SDL_KEYDOWN) && (event.key.keysym.sym == SDLK_KP2))
    {
      *l = 2;
      return ("../map/2.map");
    }
  else if((event.type == SDL_KEYDOWN) && (event.key.keysym.sym == SDLK_KP3))
    {
      *l = 3;
      return ("../map/3.map");
    }
  else if((event.type == SDL_KEYDOWN) && (event.key.keysym.sym == SDLK_KP4))
    {
      *l = 4;
      return ("../map/4.map");
    }
  else if((event.type == SDL_KEYDOWN) && (event.key.keysym.sym == SDLK_KP5))
    {
      *l = 5;
      return ("../map/4.map");
    }
  else
    {
      *flag = 1;
      return (NULL);
    }
}

int			ismapnumber(char *levelname)
{
  return(atoi(&levelname[7]));
}

char			*getlevel(int *l)
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
      xSDL_WaitEvent(&event);
      levelname = gere_event(event, &flag, l);
      if (flag == 0)
	return (levelname);
      xSDL_FillRect(ecran, NULL , SDL_MapRGB(ecran->format, 255, 255, 0));
      xSDL_BlitSurface(menu, NULL, ecran, &position);
      xSDL_Flip(ecran);
    }
  return (NULL);
}
