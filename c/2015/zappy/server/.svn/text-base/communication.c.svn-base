/*
** communication.c for  in /home/pidoux_q/Dropbox/AFS/rendu/c/2015/zappy-2015-2014s-herve_a/server
**
** Made by quentin pidoux
** Login   <pidoux_q@epitech.net>
**
** Started on  Sun Jul 15 22:33:37 2012 quentin pidoux
** Last update Sun Jul 15 22:56:28 2012 clement cohen
*/

#include <limits.h>
#include "zappy_server.h"
#include "broadcast.h"
#include "error.h"

int		client_write(int fd, char *buf)
{
  write(fd, buf, strlen(buf));

  return (EXIT_SUCCESS);
}

int			client_read(t_env *e, int fd)
{
  int  			r;
  char			buf[512];
  int			error;

  memset(buf, 0, 512);
  r = read(fd, buf, 511);
  if (r > 0)
    {
      error = write(1, buf, sizeof(buf));
      t_clients		*temp1;
      temp1 = e->graphic_client;
      broadcast(buf, e, fd);
    }
  return (EXIT_SUCCESS);
}

bool		check_graph(int fd, t_env *e)
{
  int  			r;
  char			buf[128];

  printf("Sending message 'BIENVENUE' to %d\n", fd);
  e->fct_write[fd] = (fct)client_write(fd, "BIENVENUE\n");
  memset(buf, 0, 128);
  r = read(fd, buf, 127);
  if (r > 0)
    {
      write(1, buf, sizeof(buf));
      if (strncmp(buf, "GRAPHIC\n", 8) == 0)
	return (true);
      else
	return (false);
    }
  return (false);
}

bool connected(int fd)
{
  char		buf;

  int err = send(fd, &buf, 1, MSG_DONTWAIT);
  if (err == -1 || err == 0)
    return (false);
  return (true);
}
