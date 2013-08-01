/*
** sprites.c for  in /home/pidoux_q/epikong/etape_3
**
** Made by quentin pidoux
** Login   <pidoux_q@epitech.net>
**
** Started on  Sat Mar  3 14:30:18 2012 quentin pidoux
** Last update Sat Mar  3 19:25:07 2012 quentin pidoux
*/

#include		"board.h"
#include		"get_map.h"

static void		init_sprites(SDL_Surface **l, SDL_Surface **w, SDL_Surface **m, SDL_Surface **p)
{
  *l = xIMG_Load("../image/ladder.png");
  *w = xIMG_Load("../image/wall.png");
  *m = xIMG_Load("../image/mobLeft.png");
  *p = xIMG_Load("../image/unarmedStandingLeft.png");
}

static void		init_other_sprites(SDL_Surface **l, SDL_Surface **w, SDL_Surface **m, SDL_Surface **p)
{
  *l = xIMG_Load("../image/exit.png");
  *w = xIMG_Load("../image/key.png");
  *m = xIMG_Load("../image/white.png");
  *p = xIMG_Load("../image/life.png");
}

void			check_reste_sprites(char c, SDL_Rect position, SDL_Surface *ecran)
{
  static SDL_Surface	*door = NULL;
  static SDL_Surface	*key = NULL;
  static SDL_Surface	*white = NULL;
  static SDL_Surface	*life = NULL;
  static SDL_Surface	*neardoor = NULL;

  if (!door)
    {
      init_other_sprites(&door, &key, &white, &life);
      neardoor = xIMG_Load("../image/exit2.png");
    }
  if (c == Exit)
    xSDL_BlitSurface(door, NULL, ecran, &position);
  else if (c == Key)
    xSDL_BlitSurface(key, NULL, ecran, &position);
  else if (c == Empty)
    xSDL_BlitSurface(white, NULL, ecran, &position);
  else if (c == Life)
    xSDL_BlitSurface(life, NULL, ecran, &position);
  else if (c == NearDoor)
    xSDL_BlitSurface(neardoor, NULL, ecran, &position);
}

void			aff_obj(char c, SDL_Rect position, SDL_Surface *ecran)
{
  static SDL_Surface	*ladder;
  static SDL_Surface	*wall = NULL;
  static SDL_Surface	*monster = NULL;
  static SDL_Surface	*pj = NULL;

  if (!ladder)
    init_sprites(&ladder, &wall, &monster, &pj);
  if (c == Wall)
    xSDL_BlitSurface(wall, NULL, ecran, &position);
  else if (c == Ladder)
    xSDL_BlitSurface(ladder, NULL, ecran, &position);
  else if (c == Monster)
    xSDL_BlitSurface(monster, NULL, ecran, &position);
  else if (c == Entry)
    xSDL_BlitSurface(pj, NULL, ecran, &position);
  else
    check_reste_sprites(c, position, ecran);
}


void			aff_board(t_board *board, SDL_Surface *ecran)
{
  SDL_Rect		position;
  int			i;

  i = 0;
  while (board->map[i])
    {
      while (board->map[i] && board->map[i] != '\n')
	{
	  position.x = (i % (board->size + 1)) * 30;
	  position.y = (i / (board->size + 1)) * 30;
	  aff_obj(board->map[i], position, ecran);
	  i++;
	}
      i++;
    }
  aff_life(board, ecran);
  xSDL_Flip(ecran);
}
