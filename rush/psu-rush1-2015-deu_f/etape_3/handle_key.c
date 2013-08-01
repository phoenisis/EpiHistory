/*
** handle_key.c for j in /home/pidoux_q/epikong/etape_3
**
** Made by quentin pidoux
** Login   <pidoux_q@epitech.net>
**
** Started on  Sat Mar  3 14:29:18 2012 quentin pidoux
** Last update Sat Mar  3 14:29:19 2012 quentin pidoux
*/

#include	<stdio.h>
#include	<fcntl.h>
#include	<unistd.h>
#include	<SDL/SDL.h>
#include	<sys/mman.h>
#include	<SDL/SDL_image.h>
#include	"board.h"

int		handle_key()
{
  Uint8		*keystates;
  static SDL_Event event;

  SDL_PollEvent(&event);
  keystates = xSDL_GetKeyState(NULL);
  if (event.type == SDL_QUIT)
    return (QUIT);
  else if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE)
    return (QUIT);
  else if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_SPACE)
    return (JUMP);
  else if (keystates[SDLK_LEFT])
    return (LEFT);
  else if (keystates[SDLK_RIGHT])
    return (RIGHT);
  else if (keystates[SDLK_UP])
    return (UP);
  else if (keystates[SDLK_DOWN])
    return (DOWN);
  return (ELSE);
}
