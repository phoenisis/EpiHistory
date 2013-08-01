/*
** setplayer.c for  in /home/pidoux_q/epikong/etape_3
**
** Made by quentin pidoux
** Login   <pidoux_q@epitech.net>
**
** Started on  Sat Mar  3 14:30:06 2012 quentin pidoux
** Last update Sat Mar  3 14:30:06 2012 quentin pidoux
*/

#include	<sys/mman.h>
#include	<fcntl.h>
#include	<stdio.h>
#include	<unistd.h>
#include	<stdlib.h>
#include	"board.h"

void		init_images(SDL_Surface* img[3][2])
{
  img[0][0] = xIMG_Load("../image/unarmedRunningLeft.png");
  img[0][1] = xIMG_Load("../image/unarmedRunningRight.png");
  img[1][0] = xIMG_Load("../image/unarmedJumpingLeft.png");
  img[1][1] = xIMG_Load("../image/unarmedJumpingRight.png");
  img[2][0] = xIMG_Load("../image/unarmedStandingLeft.png");
  img[2][1] = xIMG_Load("../image/unarmedStandingRight.png");
}

void		create_player(t_perso* pl)
{
  pl->x = pl->ix;
  pl->y = pl->iy;
  pl->way = Standing;
  pl->nb_life = 3;
  pl->dir = LEFT;
  pl->type =  Human;
  pl->gotkey = 0;
  init_images(pl->img);
}

void		init_player(int *ix, int *iy, t_board *map)
{
  int		i;
  int		j;

  i = 0;
  j = 0;
  while (map->map && map->map[i])
    {
      while (map->map[i] && map->map[i] != endLine)
	{
	  if (map->map[i] == Entry)
	    {
	      *ix = (i % (map->size + 1));
	      *iy = j;
	    }
	  if (map->map[i] == Exit)
	    {
	      map->player.exx = (i % (map->size + 1));
	      map->player.exy = j;
	    }
	  i++;
	}
      j++;
      i++;
    }
  create_player(&map->player);
}

void		aff_player(t_board* board, t_perso* pl, int x, int y)
{
  int		pos;
  SDL_Rect	SDL_pos;

  SDL_pos.x = x * 30;
  SDL_pos.y = y * 30;
  aff_obj(Empty, SDL_pos, board->ecran);
  pos = x + (y * board->size) + y;
  if (board->map[pos] != Entry)
    aff_obj(board->map[pos], SDL_pos, board->ecran);
  SDL_pos.x = pl->x * 30;
  SDL_pos.y = pl->y * 30;
  xSDL_BlitSurface(pl->img[pl->way - Walk][pl->dir - LEFT], NULL, board->ecran, &SDL_pos);
  xSDL_Flip(board->ecran);
}
