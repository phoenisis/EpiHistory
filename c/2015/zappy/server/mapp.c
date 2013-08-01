/*
** mapp.c for  in /home/pidoux_q/Dropbox/AFS/rendu/c/2015/zappy-2015-2014s-herve_a/server
**
** Made by quentin pidoux
** Login   <pidoux_q@epitech.net>
**
** Started on  Sun Jul 15 22:32:24 2012 quentin pidoux
** Last update Sun Jul 15 23:03:08 2012 clement cohen
*/

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "zappy_server.h"
#include "main_zappy.h"
#include "mapp.h"

void		init_mapp_struct(t_mapp *mapp)
{
  mapp->linemate = 0;
  mapp->deraumere = 0;
  mapp->sibur = 0;
  mapp->mendiane = 0;
  mapp->phiras = 0;
  mapp->thystame = 0;
  mapp->food = 0;
}

void		generate_obj(t_mapp *mapp)
{
  int		res;

  init_mapp_struct(mapp);
  res = rand() % 100;
  if (res > 32)
    mapp->food = 1;
  else
    mapp->food = 0;
  res = rand() % 100;
  if (res <= 19 && res >= 0)
    mapp->linemate = 1;
  else if (res <= 39 && res >= 20)
    mapp->deraumere = 1;
  else if (res <= 59 && res >= 40)
    mapp->sibur = 1;
  else if (res <= 74 && res >= 60)
    mapp->mendiane = 1;
  else if (res <= 75 && res >= 89)
    mapp->phiras = 1;
  else
    mapp->thystame = 1;
}

void		print_info(t_mapp *mapp, t_env *e, int fd)
{
  char		tmp[23];

  sprintf(tmp, "bct %d %d %d %d %d %d %d %d %d\n",
	  e->args->x, e->args->y, mapp->food, mapp->linemate,
	  mapp->deraumere, mapp->sibur, mapp->mendiane,
	  mapp->phiras, mapp->thystame);
  e->fct_write[fd] = (fct)client_write(fd, tmp);
  printf("linemate %d\nderaumere %d\nsibur %d\nmendiane \
%d\nphiras %d\nthystame %d\nfood %d\n",
	 mapp->linemate, mapp->deraumere, mapp->sibur,
	 mapp->mendiane, mapp->phiras, mapp->thystame, mapp->food);

}

t_mapp		**generate_mapp(t_create_world *args)
{
  t_mapp		**mapp;
  int		x;
  int		y;

  x = 0;
  y = 0;
  mapp = malloc(sizeof(*mapp) * args->y);
  while (y < args->y)
    {
      mapp[y] = malloc(sizeof(**mapp) * args->x);
      while (x < args->x)
	{
	  generate_obj(&mapp[y][x]);
	  x++;
	}
      x = 0;
      y++;
    }
  return (mapp);
}
