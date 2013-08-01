/*
** main.c for  in /home/pidoux_q/epikong/etape_2
**
** Made by quentin pidoux
** Login   <pidoux_q@epitech.net>
**
** Started on  Sat Mar  3 14:04:18 2012 quentin pidoux
** Last update Sat Mar  3 14:04:18 2012 quentin pidoux
*/

#include		"board.h"
#include		"get_map.h"

void			gere_errors(int num)
{
  if (num == 1)
    xfprintf(stderr,"Epikong-error : Size map are not good\n");
  else if (num == 2)
    xfprintf(stderr,"Epikong-error : Where are the entry ?\n");
  else if (num == 3)
    xfprintf(stderr,"Epikong-error : Where are the exit ?\n");
  else if (num == 4)
    xfprintf(stderr,"Epikong-error : Too many Entries !\n");
  else if (num == 5)
    xfprintf(stderr,"Epikong-error : Too many exits !\n");
  else if (num == 6)
    xfprintf(stderr,"Epikong-error : Too many keys !\n");
  else if (num == 7)
    xfprintf(stderr,"Epikong-error : Where is the key ? !\n");
  exit(EXIT_FAILURE);
}



int			main()
{
  t_board		board;
  SDL_Surface		*ecran;
  char			*levelname;

  if (SDL_Init(SDL_INIT_VIDEO) == -1)
    {
      xwrite(2, "SDL_INIT Error\n", 15);
      exit(EXIT_FAILURE);
    }
  if ((levelname = getlevel()) != NULL)
    get_map(&board, levelname);
  else
    return (1);
  board.mobs = create_mobs(&board);
  init_player(&board.player.ix, &board.player.iy, &board);
  board.player.nb_life = 3;
  ecran = xSDL_SetVideoMode(board.size * 30 , board.h * 30, 32,
			   SDL_HWSURFACE | SDL_DOUBLEBUF);
  SDL_WM_SetCaption("Epikong", NULL);
  board.ecran = ecran;
  aff_board(&board, ecran);
  play_the_game(&board);
  return (0);
}
