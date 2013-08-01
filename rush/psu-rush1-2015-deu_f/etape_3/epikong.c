/*
** epikong.c for  in /home/pidoux_q/epikong/etape_3
**
** Made by quentin pidoux
** Login   <pidoux_q@epitech.net>
**
** Started on  Sat Mar  3 14:28:40 2012 quentin pidoux
** Last update Sat Mar  3 14:28:43 2012 quentin pidoux
*/

#include "board.h"

char	*getnextlevel(int *level)
{
  *level = *level + 1;
  switch (*level - 1)
    {
    case 1:
      return ("../map/2.map");
    case 2:
      return ("../map/3.map");
    case 3:
      return ("../map/4.map");
    case 4:
      return ("../map/5.map");
    }
  return (NULL);
}

void	aff_victory()
{
  SDL_Surface           *ecran;
  SDL_Surface		*end;
  SDL_Rect		position;

  position.x = 0;
  position.y = 0;
  ecran = xSDL_SetVideoMode(779, 571, 32,
			   SDL_HWSURFACE | SDL_DOUBLEBUF);
  end =  xIMG_Load("../image/victory.png");
  xSDL_BlitSurface(end, NULL, ecran, &position);
  xSDL_Flip(ecran);
  xsleep(3);
}

int	epikong()
{
  t_board		board;
  SDL_Surface		*ecran;
  char			*levelname;
  static int		level = 0;

  if (level == 0)
    {
      if ((levelname = getlevel(&level)) == NULL)
	return (0);
    }
  else
    levelname = getnextlevel(&level);
  if (levelname == NULL)
    return (-1);
  get_map(&board, levelname);
  board.mobs = create_mobs(&board);
  init_player(&board.player.ix, &board.player.iy, &board);
  board.player.nb_life = 3;
  ecran = xSDL_SetVideoMode(board.size * 30 , board.h * 30, 32,
			   SDL_HWSURFACE | SDL_DOUBLEBUF);
  SDL_WM_SetCaption("Epikong", NULL);
  board.ecran = ecran;
  aff_board(&board, ecran);
  return (play_the_game(&board));
}
