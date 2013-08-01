/*
** serveur.c for  in /home/pidoux_q/Dropbox/AFS/rendu/c/2015/myirc-2015-2014s-pidoux_q/src/Serveur
**
** Made by quentin pidoux
** Login   <pidoux_q@epitech.net>
**
** Started on  Fri Apr 20 11:47:25 2012 quentin pidoux
** Last update Fri Apr 20 14:58:42 2012 quentin pidoux
*/

#include "../../inc/serveur.h"
#include "../../inc/xfunc.h"

void    recup_info_client(t_list **list, t_servinfo *servinfo)
{
  char			buff[10];
  int			i;
  char			msg[24];
  int			cs1;

  cs1 = accept(servinfo->sock, (struct sockaddr *)&servinfo->sin_client,
	       (socklen_t *)&servinfo->client_len);
  if (cs1 != -1)
    {
      memset(buff, 0, 10);
      i = read(cs1, buff, 10);
      buff[i] = '\0';
      if (i > 0)
	{
	  add_client(list, cs1, buff);
	  memset(msg, 0, 24);
	  strcat(msg, buff);
	  strcat(msg, " is connected\n");
	  write_msg(list, msg);
	}
    }
}

int     main_loop(int error, t_servinfo *servinfo)
{
  fd_set		readfds;
  fd_set		writefds;
  t_list		*list;
  int			maxfd;

  list = NULL;
  while (1)
    {
      FD_ZERO(&readfds);
      init_fd(servinfo->sock, list, &readfds);
      maxfd = recup_maxfd(list, servinfo->sock);
      if ((error = select(maxfd + 1, &readfds, &writefds, NULL, NULL)) != -1)
	{
	  new_event(&list, &readfds);
	  if (FD_ISSET(servinfo->sock, &readfds))
	    recup_info_client(&list, servinfo);
	}
    }
  return (0);
}

int     init_serveur(int port)
{
  struct protoent	*pe;
  t_servinfo		servinfo;
  int			error;

  pe = getprotobyname("TCP");
  servinfo.sock = xsocket(AF_INET, SOCK_STREAM, pe->p_proto);
  printf("\tMy IRC \nServer IP: %d:%d\nLocal  IP: %d:%d\nSocket %d open.\n",
         system(IP), port, system(IPL), port, servinfo.sock);
  servinfo.sin.sin_addr.s_addr = INADDR_ANY;
  servinfo.sin.sin_family = AF_INET;
  servinfo.sin.sin_port = htons(port);
  error = xbind(servinfo.sock,
		(const struct sockaddr *)&servinfo.sin, sizeof(servinfo.sin));
  error = xlisten(servinfo.sock, 42);
  servinfo.client_len = sizeof(servinfo.sin_client);
  error = 0;
  main_loop(error, &servinfo);
  close(servinfo.sock);
  return (0);
 }

int	main(int ac, char **av)
{
  if (ac == 2)
    init_serveur(atoi(av[1]));
  else
    write(2, "Usage: ./serveur port\n", 22);
  return (0);
}
