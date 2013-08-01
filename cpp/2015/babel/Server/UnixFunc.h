#ifndef		__UNIXFUNC_H__
# define		__UNIXFUNC_H__
# include		<sys/poll.h>
# include		<string>

typedef int	T_SOCKET;

typedef	struct s_buf
{
	char	*buf;
	unsigned int	len;
}			T_BUFFER;
typedef	struct pollfd	T_POLLFD;

T_SOCKET		_socket(int family, std::string const & proto);
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
