/*
** server.h for  in /home/pidoux_q/Dropbox/AFS/rendu/c/2015/psu_mytgw-2015-pidoux_q
**
** Made by quentin pidoux
** Login   <pidoux_q@epitech.net>
**
** Started on  Tue Jul 24 16:27:48 2012 quentin pidoux
** Last update Tue Jul 24 17:45:36 2012 quentin pidoux
*/

#ifndef SERVER_H_
# define SERVER_H_

# include <string.h>
# include <sys/types.h>
# include <sys/socket.h>
# include <netdb.h>
# include <netinet/in.h>
# include <arpa/inet.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct  s_serv_info
{
  struct sockaddr_in    sin;
  struct sockaddr_in    sin_client;
  int                   client_len;
  int                   sock;
  int			port;
  char			*ip;
}                       t_serv_info;

typedef struct  s_dest_info
{
  struct sockaddr_in    sin;
  struct sockaddr_in    sin_client;
  int                   client_len;
  int                   sock;
  int			port;
  char			*ip;
}                       t_dest_info;

typedef struct  s_list
{
    int             value;
    char            *nick;
    struct s_list   *next;
}               t_list;

void    my_server(char *, int, char *, int);
int     main_loop(int, t_serv_info *, t_dest_info *);

#endif /* !SERVER_H_ */
