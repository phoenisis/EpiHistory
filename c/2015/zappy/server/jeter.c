/*
** jeter.c for jeter in /home/cohen_d//zappy/zappy-2015-2014s-herve_a/server
** 
** Made by clement cohen
** Login   <cohen_d@epitech.net>
** 
** Started on  Sun Jul 15 22:26:59 2012 clement cohen
** Last update Sun Jul 15 23:11:14 2012 clement cohen
*/

#include "mapp.h"
#include "zappy_server.h"
#include "broadcast.h"
#include "team_name.h"

void		jete2(char **tab, t_player *tmp, t_env *e, int fd)
{
  if ((strcmp(tab[0], "sibur") == 0) && tmp->player == fd
      && atoi(tab[2]) <= tmp->inventory->sibur)
    {
      tmp->inventory->sibur = tmp->inventory->sibur - atoi(tab[2]);
      e->mapp[tmp->posX][tmp->posY].sibur += atoi(tab[2]);
    }
  else if ((strcmp(tab[0], "thystame") == 0) && tmp->player == fd
	   && atoi(tab[2]) <= tmp->inventory->thystame)
    {
      tmp->inventory->thystame = tmp->inventory->thystame - atoi(tab[2]);
      e->mapp[tmp->posX][tmp->posY].thystame += atoi(tab[2]);
    }
  else if ((strcmp(tab[0], "phiras") == 0) && tmp->player == fd
	   && atoi(tab[2]) <= tmp->inventory->phiras)
    {
      tmp->inventory->phiras -= atoi(tab[2]);
      e->mapp[tmp->posX][tmp->posY].phiras += atoi(tab[2]);
    }
  else
    tmp = tmp->nxt;
}

void		jete3(char **tab, t_player *tmp, t_env *e)
{
  tmp->inventory->deraumere = tmp->inventory->deraumere - atoi(tab[2]);
  e->mapp[tmp->posX][tmp->posY].deraumere += atoi(tab[2]);
}

void		jete(char *str, t_env *e, int fd)
{
  t_player	*tmp;
  char		**tab;

  tmp = e->player;
  tab = str_to_wordtab(str, ' ');
  while (tmp->nxt && tmp->player)
    {
      if ((strcmp(tab[0], "food") == 0) && tmp->player == fd
	  && atoi(tab[2]) <= tmp->inventory->food)
	{
	  tmp->inventory->food -= atoi(tab[2]);
	  e->mapp[tmp->posX][tmp->posY].food += atoi(tab[2]);
	}
      else if ((strcmp(tab[0], "deraumere") == 0) && tmp->player == fd
	       && atoi(tab[2]) <= tmp->inventory->deraumere)
	jete3(tab, tmp, e);
      else if ((strcmp(tab[0], "mendiane") == 0) && tmp->player == fd
	       && atoi(tab[2]) <= tmp->inventory->mendiane)
	{
	  tmp->inventory->mendiane = tmp->inventory->mendiane - atoi(tab[2]);
	  e->mapp[tmp->posX][tmp->posY].mendiane += atoi(tab[2]);
	}
      else
	jete2(tab, tmp, e, fd);
    }
}
