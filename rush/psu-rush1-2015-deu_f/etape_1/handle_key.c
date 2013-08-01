/*
** handle_key.c for  in /home/pidoux_q/epikong/etape_1
**
** Made by quentin pidoux
** Login   <pidoux_q@epitech.net>
**
** Started on  Sat Mar  3 13:58:02 2012 quentin pidoux
** Last update Sat Mar  3 13:58:02 2012 quentin pidoux
*/

#include	<stdio.h>
#include	<fcntl.h>
#include	<unistd.h>
#include	<SDL/SDL.h>
#include	<sys/mman.h>
#include	<SDL/SDL_image.h>
#include	"board.h"

void		handle_key()
{
  int		flag;
  SDL_Event	event;

  flag = 1;
  while (flag)
    {
      SDL_WaitEvent(&event);
      if (event.type == SDL_QUIT)
	flag = 0;
      else if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE)
	flag = 0;
    }
}
