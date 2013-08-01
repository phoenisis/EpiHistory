/*
** display_funcs.c for  in /home/pidoux_q/Dropbox/AFS/rendu/c/2015/zappy-2015-2014s-herve_a/server
**
** Made by quentin pidoux
** Login   <pidoux_q@epitech.net>
**
** Started on  Sun Jul 15 22:33:17 2012 quentin pidoux
** Last update Sun Jul 15 23:06:11 2012 clement cohen
*/

#include "zappy_server.h"
#include "broadcast.h"

int	        display_mapp(t_env *e, int fd)
{
  char		tmp[100];
  sprintf(tmp, "msz %d %d\n", e->args->x, e->args->y);
  printf("Message envoye :%s\n", tmp);
  e->fct_write[fd] = (fct)client_write(fd, tmp);
  return (0);
}

int		is_number(char **tab)
{
  int i;
  int x;

  x = 0;
  i = 1;
  while (i != 3)
    {
      while (tab[i][x])
	{
	  if (tab[i][x] >= '0' && tab[i][x] <= '9')
	    x++;
	  else
	    return (0);
	}
      x = 0;
      i++;
    }
  return (1);
}

void		display_all_case(t_env *e, int fd)
{
  int		x;
  int		y;

  x = 0;
  y = 0;
  while (y < e->args->y)
    {
      while (x < e->args->x)
	{
	  print_info(e->mapp[y][x], e, fd);
	  x++;
	}
      x = 0;
      y++;
    }
}

void		display_case(char *str, t_env *e, int fd)
{
  int x;
  int y;
  char	**tab;

  x = 0;
  y = 0;
  tab = str_to_wordtab(str, ' ');
  if (is_number(tab) == 1)
    {
      x = atoi(tab[1]);
      y = atoi(tab[2]);
      if (x <= e->args->x && y <= e->args->y)
	print_info(e->mapp[x][y], e, fd);
    }
}
