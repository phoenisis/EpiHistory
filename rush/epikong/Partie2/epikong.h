/*
** epikong.h for Epikong in /afs/epitech.net/users/all/pidoux_q/public/epikong
** 
** Made by sevan hubert
** Login   <hubert_s@epitech.net>
** 
** Started on  Sat Mar 26 12:04:08 2011 sevan hubert
** Last update Sun Mar 27 16:02:59 2011 sevan hubert
*/

#ifndef		_EPIKONG_
# define	_EPIKONG_

#include <stdlib.h>
#include <SDL/SDL.h>

typedef struct	t_map
{
  char	      *map;
  int	      sizeX;
  int	      sizeY;
  SDL_Surface *tileset;
} s_map;

typedef struct	t_heros
{
  int	      caseX;
  int	      caseY;
  int	      pixX;
  int	      pixY;
  SDL_Surface *tileset;
} s_heros;

typedef struct	t_monster
{
  int	      caseX;
  int	      caseY;
  int	      pixX;
  int	      pixY;
  SDL_Surface *tileset;
} s_monster;


/*   XFUNCS    */
void	*xmalloc(int x);
int	xread(int fd, void *buf, size_t count);

/* USUAL FUNCS */
char	*get_next_line(const int fd);
char	*my_strncpy(char *str, int i, int pos);

/*POS FUNCS */
int     posX(s_map* this, int pos);
int     posY(s_map* this, int pos);

/* CORE FUNCS */
s_map   *makeMap(char const *file, s_heros *heros);

#endif
