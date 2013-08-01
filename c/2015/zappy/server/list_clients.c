/*
** list_clients.c for  in /home/pidoux_q/Dropbox/AFS/rendu/c/2015/zappy-2015-2014s-herve_a/server
**
** Made by quentin pidoux
** Login   <pidoux_q@epitech.net>
**
** Started on  Sun Jul 15 22:32:44 2012 quentin pidoux
** Last update Sun Jul 15 22:37:47 2012 clement cohen
*/

#include <limits.h>
#include "zappy_server.h"
#include "error.h"

struct s_clients         *list_guiless_clients(t_env *e, int fd)
{
  t_clients     *temp;

  temp = (t_clients*)malloc(sizeof(t_clients));
  temp->client = fd;
  temp->nxt = e->guiless_client;
  e->guiless_client = temp;

  t_clients     *temp1;
  temp1 = e->guiless_client;
  free (temp);
  return e->guiless_client;
}

struct s_clients         *list_graphic_clients(t_env *e, int fd)
{
  t_clients     *temp;

  temp = (t_clients*)malloc(sizeof(t_clients));
  temp->client = fd;
  temp->nxt = e->graphic_client;
  e->graphic_client = temp;

  t_clients     *temp1;
  temp1 = e->graphic_client;
  free (temp);
  return e->graphic_client;
}
