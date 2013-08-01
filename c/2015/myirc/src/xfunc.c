/*
** xfunc.c for  in /home/pidoux_q/Dropbox/AFS/rendu/c/2015/myirc-2015-2014s-pidoux_q/src
**
** Made by quentin pidoux
** Login   <pidoux_q@epitech.net>
**
** Started on  Fri Apr 20 11:46:26 2012 quentin pidoux
** Last update Fri Apr 20 18:09:02 2012 quentin pidoux
*/

#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <stdlib.h>
#include "../inc/xfunc.h"

int		xsocket(int domain, int type, int protocol)
{
  int		i;

  i = socket(domain, type, protocol);
  if (i == -1)
    {
      write(2, "socket failed\n", 14);
      exit(EXIT_FAILURE);
    }
  return (i);
}

int		xbind(int sock, const struct sockaddr *my_addr, socklen_t addrlen)
{
  int		i;

  i = bind(sock, my_addr, addrlen);
  if (i == -1)
    {
      write(2, "bind failed\n", 14);
      close(sock);
      exit(EXIT_FAILURE);
    }
  return (i);
}

int		xlisten(int sock, int backlog)
{
  int		i;

  i = listen(sock, backlog);
  if (i == -1)
    {
      write(2, "listen failed\n", 16);
      close(sock);
      exit(EXIT_FAILURE);
    }
  return (i);
}

int		xaccept(int sock, struct sockaddr *addr, socklen_t *len)
{
  int		i;

  i = accept(sock, addr, len);
  if (i == -1)
    {
      write(2, "accept failed\n", 14);
      close(sock);
      exit(EXIT_FAILURE);
    }
  return (i);
}

void		*xmalloc(size_t size)
{
  void		*status;

  status = malloc(size);
  if (status == NULL)
    {
      write(2, "Malloc failed\n", 14);
      exit(EXIT_FAILURE);
    }
   return (status);
}
