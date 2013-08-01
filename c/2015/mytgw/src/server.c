/*
** server.c for  in /home/pidoux_q/Dropbox/AFS/rendu/c/2015/my_tgw/my_tgw
**
** Made by quentin pidoux
** Login   <pidoux_q@epitech.net>
**
** Started on  Tue Jul 24 15:41:44 2012 quentin pidoux
** Last update Tue Jul 24 18:44:20 2012 quentin pidoux
*/

#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <stdbool.h>
#include <netdb.h>
#include <unistd.h>

#include "../inc/xFunc.h"
#include "../inc/xConnect.h"
#include "../inc/server.h"
#include "../inc/log.h"

int     main_loop(int error, t_serv_info *servinfo, t_dest_info *dest)
{
  fd_set		readfds;
  fd_set		writefds;
  int			maxfd;
  int			cs1;
  char			*msg;

  msg = "BIENVENU\n";

  FD_ZERO(&readfds);
  FD_ZERO(&writefds);

  if (select(servinfo->sock, &readfds, &writefds, NULL, NULL))
    {
      printf("lool\n");
      if (FD_ISSET(servinfo->sock, &readfds))
	cs1=accept(servinfo->sock, (struct sockaddr *)&servinfo->sin_client,
		   (socklen_t *)&servinfo->client_len);
      if (cs1 > 1)
	{
	  xwrite(cs1, msg, strlen(msg));
	  logg(servinfo, dest);
	}
    }

  return (0);
}


void    my_server(char *ip, int port, char *ip2, int port2)
{
  int			error;
  t_serv_info		*serv;
  t_dest_info		*dest;
  struct protoent	*pe;

  serv = malloc(sizeof(serv));
  dest = malloc(sizeof(dest));

  pe = getprotobyname("TCP");
  serv->sock = xsocket(PF_INET, SOCK_STREAM, pe->p_proto);
  serv->sin.sin_addr.s_addr = INADDR_ANY;
  serv->sin.sin_family = AF_INET;
  serv->sin.sin_port = htons(port);
  serv->ip = ip;
  serv->port = port;
  error = xbind(serv->sock,
		(const struct sockaddr *)&serv->sin, sizeof(serv->sin));
  error = xlisten(serv->sock, 42);
  serv->client_len = sizeof(serv->sin_client);
  dest->ip = ip2;
  dest->port = port2;
  main_loop(error, serv, dest);
  close(serv->sock);
}
