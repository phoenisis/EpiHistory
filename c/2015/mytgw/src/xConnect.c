/*
** xConnect.c for  in /home/pidoux_q/Dropbox/AFS/rendu/c/2015/psu_mytgw-2015-pidoux_q
**
** Made by quentin pidoux
** Login   <pidoux_q@epitech.net>
**
** Started on  Tue Jul 24 16:27:33 2012 quentin pidoux
** Last update Tue Jul 24 16:27:34 2012 quentin pidoux
*/

#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <stdlib.h>
#include "../inc/xConnect.h"

int		xsocket(int domain, int type, int protocol)
{
  int		i;

  i = socket(domain, type, protocol);
  if (i == -1)
    {
      write(2, SOCKET_FAILED, 14);
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
      write(2, BIND_FAILED, 14);
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
      write(2, LISTEN_FAILED, 16);
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
      write(2, ACCEPT_FAILED, 14);
      close(sock);
      exit(EXIT_FAILURE);
    }
  return (i);
}
