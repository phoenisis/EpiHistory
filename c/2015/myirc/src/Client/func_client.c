/*
** func_client.c for  in /home/pidoux_q/Dropbox/AFS/rendu/c/2015/myirc-2015-2014s-pidoux_q/src/Client
**
** Made by quentin pidoux
** Login   <pidoux_q@epitech.net>
**
** Started on  Fri Apr 20 11:46:43 2012 quentin pidoux
** Last update Fri Apr 20 15:45:37 2012 quentin pidoux
*/

#include "../../inc/client.h"

void		reset_loop(int sock, fd_set *readfds)
{
  refresh();
  FD_ZERO(readfds);
  FD_SET(sock, readfds);
  FD_SET(0, readfds);
}

void		get_new_ip_and_port(const char *str, int old_sock)
{
  int		i;
  int		j;
  char		new_ip[20];
  char		new_port[6];

  j = 0;
  i = 0;
  while (str[i] != ':')
    new_ip[j++] = str[i++];

  new_ip[j] = '\0';
  i++;
  j = 0;
  while (str[i] != '\0')
    new_port[j++] = str[i++];

  close(old_sock);
  endwin();
  client(new_ip, atoi(new_port));
}

void		write_msg(char *buf, t_curse curse)
{
  static int	j = 0;

  mvprintw(j, 0, buf);
  j++;
  if (j == curse.ws.ws_row - 3)
    {
      while (j > 0)
	{
	  mvprintw(j, 0, "");
	  clrtoeol();
	  j--;
	}
      mvprintw(j, 0, "");
      clrtoeol();
    }
}

void		recup_msg(int sock, t_curse curse, char *buf)
{
  getstr(buf);
  write(sock, buf, strlen(buf));
  mvprintw(curse.ws.ws_row - 1, 0, "");
  clrtoeol();
}

void		send_msg(int sock, t_curse curse, char *buf)
{
  int		i;

  i = read(sock, buf, 4096);
  if (i > 0)
    {
      write_msg(buf, curse);
      mvprintw(curse.ws.ws_row - 1, 0, "");
      clrtoeol();
    }
  else
    strcat(buf, "/part");
}

