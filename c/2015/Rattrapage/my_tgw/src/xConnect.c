
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
