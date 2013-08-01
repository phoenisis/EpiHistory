/*
** handle_clients_welcome.c for  in /home/pidoux_q/Dropbox/AFS/rendu/c/2015/zappy-2015-2014s-herve_a/server
**
** Made by quentin pidoux
** Login   <pidoux_q@epitech.net>
**
** Started on  Sun Jul 15 22:33:59 2012 quentin pidoux
** Last update Sun Jul 15 23:13:13 2012 clement cohen
*/

#include "zappy_server.h"
#include "main_zappy.h"

void			print_server_infos(struct sockaddr_in addr)
{
  printf("Server listening on port %d\n", ntohs(addr.sin_port));
  printf("_______________________________________________________\
__________________\n");
  printf("\nAvailables interfaces are :\n");
  system("ifconfig | grep -w inet | cut -c -24");
  printf("________________________________________________________\
_________________\n");
  printf("Waiting for teams to connect :\n");
}

void			print_client_infos(struct sockaddr_in addr)
{
  printf("Connection from %s:%d\n", inet_ntoa(addr.sin_addr),
ntohs(addr.sin_port));
}

int				accept_connections(int serverfd, int clientfd,
						   struct sockaddr_in clientaddr)
{
  int  		clientaddrlen;
  int		client;

  client = 0;
  clientaddrlen = 0;
  clientaddrlen = sizeof(clientaddr);
  clientfd = accept(serverfd, (struct sockaddr *)&clientaddr,
		    (socklen_t *)&clientaddrlen);
  client++;
  printf("%d\n", client);
  if (clientfd == -1)
    handle_error("accept", true);
  print_client_infos(clientaddr);
  return clientfd;
}
