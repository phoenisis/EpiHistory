/*
** move_monster.c for  in /home/pidoux_q/epikong/etape_2
**
** Made by quentin pidoux
** Login   <pidoux_q@epitech.net>
**
** Started on  Sat Mar  3 14:04:34 2012 quentin pidoux
** Last update Sat Mar  3 14:04:35 2012 quentin pidoux
*/

#include "board.h"

void move_monsters(t_board *board)
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
