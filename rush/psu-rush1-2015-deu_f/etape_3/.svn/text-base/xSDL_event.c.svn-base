/*
** xSDL_event.c for  in /home/pidoux_q/epikong/etape_3
**
** Made by quentin pidoux
** Login   <pidoux_q@epitech.net>
**
** Started on  Sat Mar  3 14:30:26 2012 quentin pidoux
** Last update Sat Mar  3 14:30:28 2012 quentin pidoux
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	<SDL/SDL.h>
#include	"xfunction.h"

Uint8		*xSDL_GetKeyState(int *numkeys)
{
  Uint8*	res;

  if (!(res = SDL_GetKeyState(numkeys)))
    {
      xwrite(2, "error: SDL_GetKeyState\n", 23);
      exit(EXIT_FAILURE);
    }
  return (res);
}

void		xSDL_WaitEvent(SDL_Event *event)
{
  if ((SDL_WaitEvent(event)) == 0)
    {
      xwrite(2, "error: SDL_WaitEvent\n", 21);
      exit(EXIT_FAILURE);
    }
}
