/*
** main.c for  in /home/pidoux_q/epikong/etape_1
**
** Made by quentin pidoux
** Login   <pidoux_q@epitech.net>
**
** Started on  Sat Mar  3 13:58:10 2012 quentin pidoux
** Last update Sat Mar  3 13:58:11 2012 quentin pidoux
*/

#include		<stdio.h>
#include		<fcntl.h>
#include		<unistd.h>
#include		<SDL/SDL.h>
#include		<sys/mman.h>
#include		<SDL/SDL_image.h>
#include		"board.h"
#include		"get_map.h"

void			gere_errors(int num)
{
  if (num == 1)
    xfprintf(stderr,"Epikong-error : Size map are not good\n");
  else if (num == 2)
    xfprintf(stderr,"Epikong-error : Where are the entry ?\n");
  else if (num == 3)
    xfprintf(stderr,"Epikong-error : Where are the exit ?\n");
  else if (num == 4)
    xfprintf(stderr,"Epikong-error : Too many Entries !\n");
  else if (num == 5)
    xfprintf(stderr,"Epikong-error : Too many exits !\n");
  else if (num == 6)
    xfprintf(stderr,"Epikong-error : Too many keys !\n");
  else if (num == 7)
    xfprintf(stderr,"Epikong-error : Where is the key ? !\n");
  exit(EXIT_FAILURE);
}

static void		init_sprites(SDL_Surface **l, SDL_Surface **w, SDL_Surface **m, SDL_Surface **p)
{
  *l = xIMG_Load("../image/ladder.png");
  *w = xIMG_Load("../image/wall.png");
  *m = xIMG_Load("../image/mobLeft.png");
  *p = xIMG_Load("../image/unarmedStandingLeft.png");
}

static void		aff_obj(char c, SDL_Rect position, SDL_Surface *ecran)
{
  static SDL_Surface	*ladder = NULL;
  static SDL_Surface	*wall = NULL;
  static SDL_Surface	*monster = NULL;
  static SDL_Surface	*pj = NULL;
  static SDL_Surface	*door = NULL;
  static SDL_Surface	*key = NULL;

  if (!ladder)
    {
      init_sprites(&ladder, &wall, &monster, &pj);
      door = xIMG_Load("../image/exit.png");
      key = xIMG_Load("../image/key.png");
    }
  if (c == Wall)
    xSDL_BlitSurface(wall, NULL, ecran, &position);
  else if (c == Ladder)
    xSDL_BlitSurface(ladder, NULL, ecran, &position);
  else if (c == Monster)
    xSDL_BlitSurface(monster, NULL, ecran, &position);
  else if (c == Entry)
    xSDL_BlitSurface(pj, NULL, ecran, &position);
  else if (c == Exit)
    xSDL_BlitSurface(door, NULL, ecran, &position);
  else if (c == Key)
    xSDL_BlitSurface(key, NULL, ecran, &position);
}

static void		aff_board(t_board *board)
{
  SDL_Surface		*ecran;
  SDL_Rect		position;
  int			i;

  i = 0;
  ecran = xSDL_SetVideoMode(board->size * 30 , board->h * 30,32, SDL_HWSURFACE | SDL_DOUBLEBUF);
  SDL_WM_SetCaption("Epikong", NULL);
  while (board->map[i])
    {
      while (board->map[i] && board->map[i] != '\n')
	{
	  position.x = (i % (board->size + 1)) * 30;
	  position.y = (i / (board->size + 1)) * 30;
	  aff_obj(board->map[i], position, ecran);
	  i++;
	}
      i++;
    }
  xSDL_Flip(ecran);
}

int			main(int ac, char **av)
{
  t_board		board;

  if (ac < 2 || ac > 3)
    {
      printf("./epikong_etape_1 file.map\n");
      exit(EXIT_FAILURE);
    }
  if (SDL_Init(SDL_INIT_VIDEO) == -1)
    {
      write(2, "SDL_INIT Error\n", 15);
      exit(EXIT_FAILURE);
    }
  get_map(&board, av[1]);
  aff_board(&board);
  handle_key();
  SDL_Quit();
  return (1);
}
