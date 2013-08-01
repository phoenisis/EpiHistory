/*
** handle_clients.c for  in /home/pidoux_q/Dropbox/AFS/rendu/c/2015/zappy-2015-2014s-herve_a/server
**
** Made by quentin pidoux
** Login   <pidoux_q@epitech.net>
**
** Started on  Sun Jul 15 22:32:55 2012 quentin pidoux
** Last update Sun Jul 15 23:20:07 2012 clement cohen
*/

#include <limits.h>
#include "zappy_server.h"
#include "broadcast.h"
#include "error.h"

void		stock_infos(t_env *e, int fd)
{
  char		tmp[1024];
  int       i;

  i = 0;
  sprintf(tmp, "%d-%d-%d-%d-", e->args->x, e->args->y,
	  e->args->nbclients, e->args->delay);
  while (e->args->name[i] != 0)
    {
      while (e->args->name[i])
	{
	  strcat(tmp, e->args->name[i]);
	  strcat(tmp, "-");
	  i++;
	}
    }
  e->fct_write[fd] = (fct)client_write(fd, tmp);
}

void		check_add_client(t_env *e, int flag, int cs)
{
  if (flag == 1)
    {
      client_present(e->name, e);
      flag = 0;
    }
  else if (check_graph(cs, e) == true)
    {
      printf("Client Graphic\n");
      e->fct_write[cs] = (fct)display_mapp(e, cs);
      e->graphic_client = list_graphic_clients(e, cs);
    }
  else
    {
      printf("Client non graphic\n");
      e->fct_write[cs] = (fct)display_mapp(e, cs);
      e->guiless_client = list_guiless_clients(e, cs);
    }
}

void		add_client(t_env *e, int s)
{
  int			cs;
  struct sockaddr_in    client_sin;
  int                   client_sin_len;
  int                   flag;

  while (42)
    {
      flag = 1;
      client_sin_len = sizeof(client_sin);
      cs = accept(s, (struct sockaddr *)&client_sin,
		  (socklen_t *)&client_sin_len);
      e->fd_type[cs] = FD_CLIENT;
      check_add_client(e, flag, cs);
      e->fct_read[cs] = (fct)client_read(e, cs);
    }
}

void    server_read(t_env *e, int fd)
{
  add_client(e, fd);
}

void		add_server(t_env *e)
{
  int                   s;
  struct sockaddr_in    sin;
  struct protoent       *pe;

  e->guiless_client = NULL;
  e->graphic_client = NULL;
  e->player = NULL;
  e->player = init_player(e);
  pe = getprotobyname("TCP");
  s = socket(PF_INET, SOCK_STREAM, pe->p_proto);
  sin.sin_family = AF_INET;
  sin.sin_port = htons(e->port);
  sin.sin_addr.s_addr = INADDR_ANY;
  bind(s, (struct sockaddr*)&sin, sizeof(sin));
  listen(s, 42);
  print_server_infos(sin);
  server_read(e, s);
  e->fd_type[s] = FD_SERVER;
  e->fct_read[s] = (fct)server_read;
  e->fct_write[s] = NULL;
}
