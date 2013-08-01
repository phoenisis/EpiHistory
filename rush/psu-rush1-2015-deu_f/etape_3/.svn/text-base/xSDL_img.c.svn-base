/*
** xSDL_img.c for  in /home/pidoux_q/epikong/etape_3
**
** Made by quentin pidoux
** Login   <pidoux_q@epitech.net>
**
** Started on  Sat Mar  3 14:30:53 2012 quentin pidoux
** Last update Sat Mar  3 19:33:24 2012 quentin pidoux
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	<SDL/SDL.h>
#include	<SDL/SDL_image.h>
#include	"xfunction.h"

SDL_Surface*	xSDL_SetVideoMode(int w, int h, int bpp, Uint32 flags)
{
  SDL_Surface*	res;

  if (!(res = SDL_SetVideoMode(w, h, bpp, flags)))
    {
      xwrite(2, "error: SDL_SetVideoMode\n", 24);
      exit(EXIT_FAILURE);
    }
  return (res);
}

SDL_Surface	*xIMG_Load(const char *file)
{
  SDL_Surface*	res;

  if (!(res = IMG_Load(file)))
    {
      xwrite(2, "error: IMG_Load\n", 16);
      exit(EXIT_FAILURE);
    }
  return (res);
}

void		xSDL_BlitSurface(SDL_Surface *src, SDL_Rect *srcrect, SDL_Surface *dst, SDL_Rect *dstrect)
{
  if ((SDL_BlitSurface(src, srcrect, dst, dstrect)) == -1)
    {
      xwrite(2, "error: SDL_BlitSurface\n", 23);
      exit(EXIT_FAILURE);
    }
}

void		xSDL_Flip(SDL_Surface* screen)
{
  if ((SDL_Flip(screen)) == -1)
    {
      xwrite(2, "error: SDL_Flip\n", 16);
      exit(EXIT_FAILURE);
    }
}



void		xSDL_FillRect(SDL_Surface *dst, SDL_Rect *dstrect, Uint32 color)
{
  if ((SDL_FillRect(dst, dstrect, color)) == -1)
    {
      xwrite(2, "error: SDL_FillRect\n", 20);
      exit(EXIT_FAILURE);
    }
}
