#ifndef		__WINFUNC_H__
# define		__WINFUNC_H__
# include	<WinSock2.h>
# include	<string>

typedef SOCKET	T_SOCKET;
typedef	WSABUF	T_BUFFER;
typedef	WSAPOLLFD	T_POLLFD;

T_SOCKET		_socket(int family, std::string const &proto);
int				_connect(T_SOCKET s, struct sockaddr *sock);
T_SOCKET		_accept(T_SOCKET s, struct sockaddr *sock);
int				_send(T_SOCKET s, T_BUFFER *buff);
int				_recv(T_SOCKET s, T_BUFFER *buff);
int				_poll(T_POLLFD *a, int nfds, int timeout);
void			_close(T_SOCKET &);
void			setRead(T_POLLFD & p, T_SOCKET const & s);
void			setWrite(T_POLLFD & p, T_SOCKET const & s);
bool			canWrite(T_POLLFD & p);
bool			canRead(T_POLLFD & p);
bool			isDisconnected(T_POLLFD & p);
bool			hasError(T_POLLFD & p);

#endif
