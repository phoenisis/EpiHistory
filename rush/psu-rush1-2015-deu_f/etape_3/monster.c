/*
** monster.c for  in /home/pidoux_q/epikong/etape_3
**
** Made by quentin pidoux
** Login   <pidoux_q@epitech.net>
**
** Started on  Sat Mar  3 14:29:43 2012 quentin pidoux
** Last update Sat Mar  3 14:29:44 2012 quentin pidoux
*/

#include	<sys/mman.h>
#include	<fcntl.h>
#include	<stdio.h>
#include	<unistd.h>
#include	<stdlib.h>
#include	"board.h"

static t_perso	*add_elem(t_perso *elem, int x, int y)
{
  t_perso	*new;

  new = malloc(sizeof(*new));
  if (new == NULL)
    {
      PRINT_ERROR;
      exit(EXIT_FAILURE);
    }
  new->x = x;
  new->y = y;
  new->next = elem;
  new->way = Left;
  elem = new;
  return (elem);
}

t_perso		*create_mobs(t_board *board)
{
  int		x;
  int		y;

  x = 0;
  y = 0;
  board->mobs = NULL;
  while (board->map && board->map[x])
    {
      while (board->map[x] != endLine && board->map[x])
	{
	  if (board->map[x] == Monster)
	    {
	      board->mobs = add_elem(board->mobs, x % ( board->size + 1), y);
	      board->map[x] = '.';
	    }
	  x++;
	}
      y++;
      x++;
    }
  return (board->mobs);
}

/*
static int	checkwall(t_perso mob, t_board *map, int x)
{
  int		dir;

   if (mob.way == Left)
    dir = -1;
  else
    dir = 1;
   if (map->map[((mob.y) * map->size) + x + dir + mob.y] == Wall)
     return (0);
   return (1);
}
static int	checkempty(t_perso mob, t_board *map, int x)
{
  int		dir;

  if (mob.way == Left)
    dir = 0;
  else
    dir = 2;
  if (map->map[((mob.y + 1) * map->size) + x + dir + mob.y] == Empty)
    return (0);
  return (1);
}

void		check_player(t_perso *mob, t_board *map, SDL_Rect pos)
{
  if (mob->x != map->player.x || mob->y != map->player.y)
    aff_obj(map->map[mob->x + (mob->y * map->size) + mob->y], pos, map->ecran);
  else
    aff_obj(Entry, pos, map->ecran);
}

int		moveleft(t_perso *mob, t_board *map, SDL_Rect pos)
{
  if (((checkwall(*mob, map, mob->x)) == 1)
      && (checkempty(*mob, map, mob->x) == 1))
    {
      aff_obj(Empty, pos, map->ecran);
      check_player(mob, map, pos);
      mob->x = mob->x - 1;
      pos.x = mob->x * 30;
      aff_obj(Monster, pos, map->ecran);
      return (1);
    }
  else
    {
      mob->way = Right;
      return (0);
    }
}

int		moveright(t_perso *mob, t_board *map, SDL_Rect pos)
{
  if ((checkwall(*mob, map, mob->x) == 1)
      && (checkempty(*mob, map, mob->x) == 1))
    {
      aff_obj(Empty, pos, map->ecran);
      check_player(mob, map, pos);
      mob->x = mob->x + 1;
      pos.x = mob->x * 30;
      aff_obj(Monster, pos, map->ecran);
      return (1);
    }
  else
    {
      mob->way = Left;
      return (0);
    }
}

void		move_mob(t_perso *mob, t_board *map)
{
  SDL_Rect	pos;

  pos.x = mob->x * 30;
  pos.y = mob->y * 30;
  if (!mob)
    return ;
  if (mob->way == Left)
    {
      if (moveleft(mob, map, pos) == 1)
	return;
    }
  if (mob->way == Right)
    {
      if (moveright(mob, map, pos) == 1)
	return;
    }
  if (mob->way == Left)
    move_mob(mob, map);
    }*/
