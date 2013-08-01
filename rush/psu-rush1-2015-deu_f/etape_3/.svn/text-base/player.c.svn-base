/*
** player.c for  in /home/pidoux_q/epikong/etape_3
**
** Made by quentin pidoux
** Login   <pidoux_q@epitech.net>
**
** Started on  Sat Mar  3 14:29:57 2012 quentin pidoux
** Last update Sat Mar  3 14:29:58 2012 quentin pidoux
*/

#include	<sys/mman.h>
#include	<fcntl.h>
#include	<stdio.h>
#include	<unistd.h>
#include	<stdlib.h>
#include	"board.h"

void		walk(t_board* board, t_perso* pl, int pos)
{
  int		x;
  int		y;

  x = pl->x;
  y = pl->y;
  pl->way = Walk;
  if (pl->dir == LEFT && board->map[pos - 1] != Wall)
    pl->x--;
  else if (pl->dir == RIGHT && board->map[pos + 1] != Wall)
    pl->x++;
  else
    return ;
  aff_player(board, pl, x, y);
}

void		climb(t_board *board, t_perso *pl, int pos, eKey dir)
{
  int		x;
  int		y;

  x = pl->x;
  y = pl->y;
  if (dir == DOWN && board->map[pos + board->size + 1] == Ladder)
    pl->y++;
  else if (dir == UP && board->map[pos] == Ladder
	   && board->map[pos - board->size - 1] != Wall)
    pl->y--;
  else
    {
      pl->way = Standing;
      return ;
    }
  pl->way = Climb;
  aff_player(board, pl, x, y);
}

void		jump(t_board *board, t_perso *pl, int pos)
{
  int		x;
  int		y;

  x = pl->x;
  y = pl->y;
  if (board->map[pos - (board->size + 1)] != Wall)
    {
      if (pl->way == Walk)
	{
	  if (pl->dir == LEFT && board->map[pos - 1 - (board->size + 1)] != Wall)
	    pl->x--;
	  else if (pl->dir == RIGHT && board->map[pos + 1 - (board->size + 1)] != Wall)
	    pl->x++;
	}
      else if (board->map[pos - 2 * (board->size + 1)] != Wall)
	pl->y--;
      pl->y--;
      pl->way = Jump;
    }
  else
    {
      pl->way = Standing;
      return ;
    }
  aff_player(board, pl, x, y);
}

void		fall(t_board *board, t_perso *pl, int pos, eKey dir)
{
  int		y;
  int		i;
  static int	speed = 1;

  i = 0;
  y = pl->y;
  while (i < speed && board->map[pos] == Empty
	 && board->map[pos + board->size + 1] != Wall
	 && board->map[pos + board->size + 1] != Ladder)
    {
      pos += board->size + 1;
      pl->way = Fall;
      pl->nb_fall++;
      pl->y++;
      i++;
    }
  if (!i)
    {
      speed = 1;
      pl->nb_fall = 0;
      if (dir == ELSE)
	pl->way = Standing;
    }
  else if (speed > 1)
    speed *= speed;
  else
    speed = 2;
  aff_player(board, pl, pl->x, y);
}

void		move(t_board* board, t_perso* pl, eKey dir)
{
  int		pos;

  pos = pl->x + (pl->y * board->size) + pl->y;
  if (dir == LEFT || dir == RIGHT)
    {
      pl->dir = dir;
      walk(board, pl, pos);
    }
  else if ((dir == UP || dir == DOWN) &&
	   (pl->way == Standing || pl->way == Climb))
    climb(board, pl, pos, dir);
  pos = pl->x + (pl->y * board->size) + pl->y;
  if (dir == JUMP && (pl->way == Standing || pl->way == Walk))
    jump(board, pl, pos);
  else
    fall(board, pl, pos, dir);
}
