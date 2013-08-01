/*
** move_monster.c for  in /home/pidoux_q/epikong/etape_3
**
** Made by quentin pidoux
** Login   <pidoux_q@epitech.net>
**
** Started on  Sat Mar  3 14:29:51 2012 quentin pidoux
** Last update Sat Mar  3 14:29:52 2012 quentin pidoux
*/

#include        <sys/mman.h>
#include        <fcntl.h>
#include        <stdio.h>
#include        <unistd.h>
#include        <stdlib.h>
#include	"board.h"

void		move_monsters(t_board *board)
{
  t_perso *tmp;

  tmp = board->mobs;
  while (tmp)
    {
      move_mob(tmp, board);
      tmp = tmp->next;
    }
  xSDL_Flip(board->ecran);
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
}
