/*
** game.c for  in /home/pidoux_q/epikong/etape_3
**
** Made by quentin pidoux
** Login   <pidoux_q@epitech.net>
**
** Started on  Sat Mar  3 14:28:50 2012 quentin pidoux
** Last update Sat Mar  3 20:25:56 2012 quentin pidoux
*/

#include	"board.h"

void		check_key_grapping(t_perso *pl, t_board *board)
{
  SDL_Rect	pos;

  if (board->map[pl->x + (pl->y * board->size) + pl->y] == Key)
    {
      board->map[pl->x + (pl->y * board->size) + pl->y] = '.';
      pl->gotkey = 1;
      pos.x = pl->x * 30;
      pos.y = pl->y * 30;
      aff_obj(Empty, pos, board->ecran);
      pos.x = pl->exx * 30;
      pos.y = pl->exy * 30;
      aff_obj(NearDoor, pos, board->ecran);
    }
}

void		check_is_injury(t_perso *bl, t_board *board)
{
  t_perso	*tmp;
  int		x;
  int		y;

  tmp = board->mobs;
  while (tmp)
    {
      if ((tmp->y == bl->y) && (tmp->x == bl->x))
	{
	  dec_life(board);
	  x = bl->x;
	  y = bl->y;
	  bl->x = bl->ix;
	  bl->y = bl->iy;
	  aff_player(board, bl, x, y);
	}
      tmp = tmp->next;
    }
}

int		check_is_dead(t_perso bl)
{
  if (bl.nb_life <= 0)
    return (1);
  return (0);
}

int		check_on_the_door(t_perso bl)
{
  if (bl.x == bl.exx && bl.y == bl.exy && bl.gotkey == 1)
    return (1);
  return (0);
}

int		check_game_event(t_board *board)
{
  int		x;
  int		y;

  check_key_grapping(&board->player, board);
  check_is_injury(&board->player, board);
  if (board->player.nb_fall >= 4)
    {
      dec_life(board);
      x = board->player.x;
      y = board->player.y;
      board->player.x = board->player.ix;
      board->player.y = board->player.iy;
      aff_player(board, &board->player, x, y);
    }
  if (check_is_dead(board->player))
    return (2);
  if (check_on_the_door(board->player))
    return (1);
  return (0);
}

void		end_game(t_board *board)
{
  SDL_Surface	*end;
  SDL_Rect	pos;

  pos.x = 0;
  pos.y = 0;
  end = xIMG_Load("../image/end.png");
  board->ecran = xSDL_SetVideoMode(779, 571, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
  xSDL_BlitSurface(end, NULL, board->ecran, &pos);
  xSDL_Flip(board->ecran);
  xsleep(3);
}

int		play_the_game(t_board *board)
{
  int		dir;
  double	i;
  int		n;

  i = 0;
  n = 0;
  move_monsters(board);
  while ((dir = handle_key()))
    {
      move(board, &board->player, dir);
      if (i > 3)
	{
	  move_monsters(board);
	  i = 0;
	}
      if ((n = check_game_event(board)) > 0)
	break;
      xusleep(70000);
      i++;
    }
  if (n == 2)
    end_game(board);
  else if (n == 1)
    return (n);
  return (0);
}

