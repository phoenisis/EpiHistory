/*
** life.c for  in /home/pidoux_q/epikong/etape_3
**
** Made by quentin pidoux
** Login   <pidoux_q@epitech.net>
**
** Started on  Sat Mar  3 14:29:25 2012 quentin pidoux
** Last update Sat Mar  3 14:29:30 2012 quentin pidoux
*/

#include	"board.h"

void		dec_life(t_board *board)
{
  SDL_Rect	pos;

  pos.x = (board->player.nb_life - 1) * 30;
  board->player.nb_life--;
  pos.y = 0;
  aff_obj(Wall, pos, board->ecran);
}

void		aff_life(t_board *board, SDL_Surface *ecran)
{
  SDL_Rect	life;
  SDL_Rect	lastlife;
  int		i;
  int		count;

  count = 0;
  i = 0;
  life.x = 0;
  life.y = 0;
  while (board->map[i] && i < 3)
    {
      life.x = (i % (board->size + 1)) * 30;
      life.y = (i / (board->size + 1)) * 30;
      aff_obj(Life, life, ecran);
      i++;
      count++;
    }
  lastlife.x = life.x;
  lastlife.y = life.y;
}
