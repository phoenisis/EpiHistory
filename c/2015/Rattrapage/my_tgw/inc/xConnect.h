
#ifndef XCONNECT_H_
# define XCONNECT_H_

# include <sys/types.h>
# include <sys/socket.h>

# define SOCKET_FAILED "socket failed\n"
# define BIND_FAILED "bind failed\n"
# define LISTEN_FAILED "listen failed\n"
# define ACCEPT_FAILED "accept failed\n"

int		xsocket(int, int, int);
int		xbind(int, const struct sockaddr *, socklen_t);
int		xlisten(int, int);
int		xaccept(int, struct sockaddr *, socklen_t *);

#endif /* !XCONNECT_H_ */
