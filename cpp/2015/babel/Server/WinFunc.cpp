#ifdef _WIN32
# include <Winsock2.h>
# include	<string>
# include	<iostream>
# include "WinFunc.h"

T_SOCKET		_socket(int family, std::string const &proto)
{
	int			type;
	int			protocol;

	if (!proto.compare("TCP"))
	{
		type = SOCK_STREAM;
		protocol = IPPROTO_TCP;
	}
	else
	{
		type = SOCK_DGRAM;
		protocol = IPPROTO_UDP;
	}
	return (WSASocket(family, type, protocol, NULL, NULL, NULL));
}

int				_connect(T_SOCKET s, struct sockaddr *sock)
{
	return (WSAConnect(s, sock, sizeof(struct sockaddr), NULL, NULL, NULL, NULL));
}

T_SOCKET		_accept(T_SOCKET s, struct sockaddr *sock)
{
	int			len = sizeof(struct sockaddr);

	return (WSAAccept(s, sock, &len, NULL, NULL));
}

int				_send(T_SOCKET s, T_BUFFER *buff)
{
	DWORD		bytes;
	int			ret;

	ret = WSASend(s, buff, 1, &bytes, 0, NULL, NULL);
	if (ret == 0)
		return (bytes);
	else
		return (-1);
}

int				_recv(T_SOCKET s, T_BUFFER *buff)
{
	DWORD		bytes;
	DWORD		flags = 0;
	int			ret;

	ret = WSARecv(s, buff, 1, &bytes, &flags, NULL, NULL);
	if (ret == 0)
		return (bytes);
	else
		return (-1);
}

int				_poll(T_POLLFD *fds, int nfds, int timeout)
{
	return (WSAPoll(fds, nfds, timeout));
}

void			_close(T_SOCKET & s)
{
	shutdown(s, SD_BOTH);
	closesocket(s);
}

void			setRead(T_POLLFD & p, T_SOCKET const & s)
{
	p.fd = s;
	p.events = p.events | POLLRDNORM;
	p.revents = 0;
}

void			setWrite(T_POLLFD & p, T_SOCKET const & s)
{
	p.fd = s;
	p.events = p.events | POLLWRNORM;
	p.revents;
}

bool			canWrite(T_POLLFD & p)
{
	if ((p.revents & POLLWRNORM))
		return (true);
	else
		return (false);
}

bool			canRead(T_POLLFD & p)
{
	if ((p.revents & POLLRDNORM))
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
