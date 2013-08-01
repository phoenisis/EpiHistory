/*
** game.c for  in /home/pidoux_q/epikong/etape_2
**
** Made by quentin pidoux
** Login   <pidoux_q@epitech.net>
**
** Started on  Sat Mar  3 14:03:42 2012 quentin pidoux
** Last update Sat Mar  3 14:03:43 2012 quentin pidoux
*/

#include "board.h"

void play_the_game(t_board *board)
{
  int dir;
  int i;

  i = 0;
  move_monsters(board);
  while ((dir = handle_key()))
    {
      move(board, &board->player, dir);
      if (i > 3)
	{
	  move_monsters(board);
	  i = 0;
	}
      xusleep(70000);
      i++;
    }
}
