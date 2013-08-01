/*
** epikong.h for Epikong in /afs/epitech.net/users/all/pidoux_q/public/epikong
** 
** Made by sevan hubert
** Login   <hubert_s@epitech.net>
** 
** Started on  Sat Mar 26 12:04:08 2011 sevan hubert
** Last update Sat Mar 26 18:42:17 2011 sevan hubert
*/

#ifndef		_EPIKONG_
# define	_EPIKONG_

#include <stdlib.h>

typedef struct	t_map
{
  char	*map;
  int	sizeX;
  int	sizeY;
} s_map;

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
s_map   *makeMap(char const *file);

#endif
