/*
** move.c for move in /home/cohen_d//zappy/zappy-2015-2014s-herve_a/server
** 
** Made by clement cohen
** Login   <cohen_d@epitech.net>
** 
** Started on  Sun Jul 15 22:28:40 2012 clement cohen
** Last update Sun Jul 15 23:01:43 2012 clement cohen
*/

#include "mapp.h"
#include "zappy_server.h"
#include "broadcast.h"
#include "team_name.h"

void		go_forward(t_env *e, int fd)
{
  t_player	*tmp;

  tmp = e->player;
  tmp->orientation = NORD;
  while (tmp->nxt)
    {
      if (tmp->posX + 1 <= e->args->x && tmp->player == fd)
	{
	  tmp->posX++;
	  display_info_player(itoa(fd), tmp, 1, fd);
	}
      else if (tmp->posX + 1 > e->args->x && tmp->player == fd)
	{
	  tmp->posX = 0;
	  display_info_player(itoa(fd), tmp, 1, fd);
	}
      else
	tmp = tmp->nxt;
    }
}

void		go_backward(t_env *e, int fd)
{
  t_player	*tmp;

  tmp = e->player;
  tmp->orientation = SUD;
  while (tmp->nxt)
    {
      if (tmp->posX - 1 <= 0 && tmp->player == fd)
	{
	  tmp->posX--;
	  display_info_player(itoa(fd), tmp, 1, fd);
	}
      else if ( tmp->posX - 1 < 0 && tmp->player == fd)
	{
	  tmp->posX = e->args->x;
	  display_info_player(itoa(fd), tmp, 1, fd);
	}
      else
	tmp = tmp->nxt;
    }
}
void		go_left(t_env *e, int fd)
{
  t_player	*tmp;

  tmp = e->player;
  tmp->orientation = OUEST;
  while (tmp->nxt)
    {
      if (tmp->posY - 1 <= 0 && tmp->player == fd)
	{
	  tmp->posY--;
	  display_info_player(itoa(fd), tmp, 1, fd);
	}
      else if (tmp->posY - 1 > 0 && tmp->player == fd)
	{
	  tmp->posY = e->args->y;
     	  display_info_player(itoa(fd), tmp, 1, fd);
	}
      else
	tmp = tmp->nxt;
    }
}

void		go_right(t_env *e, int fd)
{
  t_player	*tmp;

  tmp = e->player;
  tmp->orientation = EST;
  while (tmp->nxt)
    {
      if (tmp->posY + 1 >= e->args->y && tmp->player == fd)
	{
	  tmp->posY++;
	  display_info_player(itoa(fd), tmp, 1, fd);
	}
      else if (tmp->posY + 1 > e->args->y && tmp->player == fd)
	{
	  tmp->posY = 0;
	  display_info_player(itoa(fd), tmp, 1, fd);
	}
      tmp = tmp->nxt;
    }
}

