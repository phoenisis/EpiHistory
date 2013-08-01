#ifndef _WIN32
# include <sys/socket.h>
# include <sys/types.h>
# include <netdb.h>
# include <cstring>
# include <poll.h>
# include <unistd.h>
# include "UnixFunc.h"

T_SOCKET		_socket(int family, std::string const & proto)
{
	int			type;
	struct protoent *protocol;

	if (!proto.compare("TCP"))
		type = SOCK_STREAM;
	else
		type = SOCK_DGRAM;
	protocol = getprotobyname(proto.c_str());
	return (socket(family, type, protocol->p_proto));
}

int				_connect(T_SOCKET s, struct sockaddr *sock)
{
	return (connect(s, sock, sizeof(struct sockaddr)));
}

T_SOCKET		_accept(T_SOCKET s, struct sockaddr *sock)
{
	socklen_t			len = sizeof(struct sockaddr);

	return (accept(s, sock, &len));
}

int				_send(T_SOCKET s, T_BUFFER *buff)
{
	return (send(s, buff->buf, buff->len, 0));
}

int				_recv(T_SOCKET s, T_BUFFER *buff)
{
	return (recv(s, buff->buf, buff->len, 0));
}

int				_poll(T_POLLFD *a, int nfds, int timeout)
{
	return (poll(a, nfds, timeout));
}

void			_close(T_SOCKET & s)
{
	close(s);
}

void			setRead(T_POLLFD & p, T_SOCKET const & s)
{
	p.fd = s;
	p.events = p.events | POLLIN;
}

void			setWrite(T_POLLFD & p, T_SOCKET const & s)
{
	p.fd = s;
	p.events = p.events | POLLOUT;
}

bool			canWrite(T_POLLFD & p)
{
	if ((p.revents & POLLOUT))
		return (true);
	else
		return (false);
}

bool			canRead(T_POLLFD & p)
{
	if ((p.revents & POLLIN))
		return (true);
	else
		return (false);
}

bool			isDisconnected(T_POLLFD & p)
{
	if ((p.revents & POLLHUP))
		return (true);
	else
		return (false);
}

bool			hasError(T_POLLFD & p)
{
	if ((p.revents & POLLERR) || (p.revents & POLLNVAL))
		return (true);
	else
		return (false);
}
#endif
