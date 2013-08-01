#ifdef	_WIN32
#include		<cstring>
#include		"WinUDPSocket.h"

using namespace Network;

WinUDPSocket::WinUDPSocket(Synchronizer *sync, struct sockaddr const *s_out): _sync(sync)
{
	(void)memcpy(&this->_out, s_out, sizeof(struct sockaddr));
	this->_isOpen = false;
}

WinUDPSocket::WinUDPSocket(Synchronizer *sync, t_socket const & s, struct sockaddr const *sin, struct sockaddr const *s_out): _sync(sync)
{
	(void)memcpy(&this->_in, sin, sizeof(struct sockaddr));
	(void)memcpy(&this->_out, s_out, sizeof(struct sockaddr));
	this->_s = s;
	this->_isOpen = true;
}

WinUDPSocket::~WinUDPSocket()
{
	if (this->_isOpen)
		this->close();
}

void				WinUDPSocket::open(int family)
{
	this->_s = WSASocket(family, SOCK_DGRAM, IPPROTO_UDP, 0, 0, 0);
	this->_isOpen = true;
}

int				WinUDPSocket::bind_(int port)
{
	this->_in.sin_addr.s_addr = htonl(INADDR_ANY);
	this->_in.sin_family = AF_INET;
	this->_in.sin_port = htons(port);
	return (bind(this->_s, (struct sockaddr *)&this->_in, sizeof(struct sockaddr)));
}

void			WinUDPSocket::connect(char *, int)
{
}

void				WinUDPSocket::listen_(int)
{
}

bool				WinUDPSocket::isOpen() const
{
	return (this->_isOpen);
}

TCPSocket *		WinUDPSocket::accept()
{
	return (NULL);
}

char				*WinUDPSocket::getIp() const
{
	return (inet_ntoa(this->_in.sin_addr));
}

int					WinUDPSocket::getPort() const
{
	return (ntohs(this->_in.sin_port));
}

t_socket const &	WinUDPSocket::getSocket() const
{
	return (this->_s);
}

void				WinUDPSocket::close()
{
	this->_sync->removeHandlers(this);
	shutdown(this->_s, SD_BOTH);
	closesocket(this->_s);
	this->_isOpen = false;
}

int						WinUDPSocket::send(Buffer & pack)
{
	return (sendto(this->_s, pack.getBuff().buf, pack.getBuffLen(), 0, (struct sockaddr *)&this->_out, sizeof(struct sockaddr)));
}

int						WinUDPSocket::recv(Buffer & pack)
{
	int					len = sizeof(struct sockaddr);

	return (recvfrom(this->_s, pack.getBuff().buf, pack.getBuffLen(), 0, (struct sockaddr *)&this->_in, &len));
}

void					WinUDPSocket::asyncRead(Buffer & p, ReadHandler & c)
{
	this->_sync->addHandler(new detail::ReadWriteOperation(this, detail::READ, p, c));
}

void					WinUDPSocket::asyncWrite(Buffer & p, WriteHandler & c)
{
	this->_sync->addHandler(new detail::ReadWriteOperation(this, detail::WRITE, p, c));
}

void					WinUDPSocket::asyncAccept(AcceptHandler &)
{
}

#endif