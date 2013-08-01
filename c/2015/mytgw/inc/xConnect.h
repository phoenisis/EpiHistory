/*
** xConnect.h for  in /home/pidoux_q/Dropbox/AFS/rendu/c/2015/psu_mytgw-2015-pidoux_q
**
** Made by quentin pidoux
** Login   <pidoux_q@epitech.net>
**
** Started on  Tue Jul 24 16:27:57 2012 quentin pidoux
** Last update Tue Jul 24 16:27:57 2012 quentin pidoux
*/

#ifndef XCONNECT_H_
# define XCONNECT_H_

# include <sys/types.h>
# include <sys/socket.h>

# define SOCKET_FAILED  "socket failed\n"
# define BIND_FAILED    "bind failed\n"
# define LISTEN_FAILED  "listen failed\n"
# define ACCEPT_FAILED  "accept failed\n"

int		xsocket(int, int, int);
int		xbind(int, const struct sockaddr *, socklen_t);
int		xlisten(int, int);
int		xaccept(int, struct sockaddr *, socklen_t *);

#endif /* !XCONNECT_H_ */
