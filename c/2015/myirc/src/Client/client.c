/*
** client.c for  in /home/pidoux_q/Dropbox/AFS/rendu/c/2015/myirc-2015-2014s-pidoux_q/src/Client
**
** Made by quentin pidoux
** Login   <pidoux_q@epitech.net>
**
** Started on  Fri Apr 20 11:46:35 2012 quentin pidoux
** Last update Fri Apr 20 18:01:13 2012 quentin pidoux
*/

#include "../../inc/client.h"

void		init_interface(t_curse *curse)
{
  int		i;

  i = 0;
  initscr();
  cbreak();
  keypad(stdscr, TRUE);
  curs_set(0);
  ioctl(0, TIOCGWINSZ, &curse->ws);
  curse->window = newwin(curse->ws.ws_row, curse->ws.ws_col, 0, 0);
  while (i < curse->ws.ws_col)
    mvprintw(curse->ws.ws_row - 2, i++, "-");
}

struct sockaddr_in	recupip(struct sockaddr_in sockin, char *name)
{
  struct hostent*       ip;
  int                   i;

  ip = gethostbyname(name);
  if (ip == NULL)
    {
      puts("The host name doesn't exist.");
      exit(EXIT_FAILURE);
    }
  if (ip->h_addr_list[0] != NULL)
    {
      i = 0;
      while (ip->h_addr_list[i + 1] != NULL)
	i++;
      memcpy(&sockin.sin_addr.s_addr, ip->h_addr_list[i], ip->h_length);
    }
  return (sockin);
}

void		init_sockin(struct sockaddr_in *sockin, int *sock,
			    char *name, int port)
{
  char		*user;

  if ((*sock = socket(AF_INET, SOCK_STREAM, 0)) == -1)
    {
      puts("open socket fail");
      exit(EXIT_FAILURE);
    }
  *sockin = recupip(*sockin, name);
  (*sockin).sin_port = htons(port);
  (*sockin).sin_family = AF_INET;
  if (connect(*sock, (struct sockaddr *)sockin, sizeof(*sockin)) == -1)
    {
      puts("connection failed");
      exit(EXIT_FAILURE);
    }
  printf("Connection at %s with %d port\n", inet_ntoa(sockin->sin_addr),
	 htons(sockin->sin_port));
  user = getenv("USER");
  if (user == NULL)
    write(*sock, "Guest", 5);
  else
    write(*sock, user, strlen(user));
}

void            cmd(const char *buf, int sock)
{
  if (buf[7] == '\0' || buf[8] == '\0')
    return ;
  get_new_ip_and_port(buf + 8, sock);
}

void		client(char *name, int port)
{
  struct sockaddr_in    sockin;
  int                   sock;
  fd_set                readfds;
  fd_set                writefds;
  char                  buf[4096];
  t_curse               curse;

  init_sockin(&sockin, &sock, name, port);
  init_interface(&curse);
  while (strcmp(buf, "/part") != 0)
    {
      if (strncmp(buf, "/server", 7) == 0)
        cmd(buf, sock);
      reset_loop(sock, &readfds);
      memset(buf, 0, 4096);
      if (select(sock + 1, &readfds, &writefds, NULL, NULL) != -1)
	{
	  if (FD_ISSET(sock, &readfds))
	    send_msg(sock, curse, buf);
	  if (FD_ISSET(0, &readfds))
	    recup_msg(sock, curse, buf);
	}
    }
  endwin();
  close(sock);
}
