/*
** main_server.c for  in /home/pidoux_q/Dropbox/AFS/rendu/c/2015/zappy-2015-2014s-herve_a/server
**
** Made by quentin pidoux
** Login   <pidoux_q@epitech.net>
**
** Started on  Sun Jul 15 22:32:32 2012 quentin pidoux
** Last update Sun Jul 15 22:32:38 2012 quentin pidoux
*/

#include "zappy_server.h"
#include "parse.h"

int			my_socket(int fd)
{
  struct protoent	*protocole;

  protocole = getprotobyname("TCP");
  fd = socket(AF_INET, SOCK_STREAM, protocole->p_proto);

  return fd;
}

void		client_present(char *login, t_env *e)
{
  login = "";
  e->time = get_time(e);
  printf("client connected - %s", asctime(e->time));
  return ;
}

t_env           handle_select(t_env e)
{
  if ((e.myloop.error = select(e.myloop.fd_max + 1, &e.myloop.fd_read,
			       &e.myloop.fd_write, NULL, &e.myloop.tv)) != -1)
    {
      e.myloop.i = 0;
      while (e.myloop.i < MAX_FD)
	{
	  if (FD_ISSET(e.myloop.i, &e.myloop.fd_read))
	    e.fct_read[e.myloop.i](&e, e.myloop.i);
	  if (FD_ISSET(e.myloop.i, &e.myloop.fd_write))
	    e.fct_write[e.myloop.i](&e, e.myloop.i);
	  e.myloop.i++;
	}
    }
  close(e.myloop.i);
  return e;
}

void		handle_main_loop(t_env e)
{
  while (42)
    {
      FD_ZERO(&e.myloop.fd_read);
      FD_ZERO(&e.myloop.fd_write);
      e.myloop.fd_max = 0;
      e.myloop.i = 0;
      while (e.myloop.i < MAX_FD);
      {
	if (e.fd_type[e.myloop.i] != FD_FREE)
	  {
	    FD_SET(e.myloop.i, &e.myloop.fd_read);
	    FD_SET(e.myloop.i, &e.myloop.fd_write);
	    e.myloop.fd_max = e.myloop.i;
	  }
	e.myloop.i++;
      }
      e = handle_select(e);
    }
}

void				server_loop(int port, t_create_world *args)
{
  t_env         			e;

  e.mapp = generate_mapp(args);
  printf("Generating map done...\n");
  e.myloop.i = 0;
  e.time = get_time(&e);
  e.args = args;
  memset(e.fd_type, FD_FREE, MAX_FD);
  e.port = port;
  add_server(&e);
  e.myloop.tv.tv_sec = 5;
  e.myloop.tv.tv_usec = 0;
  e.myloop = e.myloop;
  handle_main_loop(e);
}
