/*
** check_monster.c for  in /home/pidoux_q/epikong/etape_3
**
** Made by quentin pidoux
** Login   <pidoux_q@epitech.net>
**
** Started on  Sat Mar  3 14:28:34 2012 quentin pidoux
** Last update Sat Mar  3 14:28:35 2012 quentin pidoux
*/

#include	<sys/mman.h>
#include	<fcntl.h>
#include	<stdio.h>
#include	<unistd.h>
#include	<stdlib.h>
#include	"board.h"

int		checkwall(t_perso mob, t_board *map, int x)
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

int		checkempty(t_perso mob, t_board *map, int x)
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
