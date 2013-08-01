#ifndef	_WIN32
#include		<cstring>
#include		"UnixUDPSocket.h"

using namespace Network;

static int _close(int s)
{
  return (close(s));
}

UnixUDPSocket::UnixUDPSocket(Synchronizer *sync, struct sockaddr const *s_out): _sync(sync)
{
	(void)memcpy(&this->_out, s_out, sizeof(struct sockaddr));
	this->_isOpen = false;
}

UnixUDPSocket::UnixUDPSocket(Synchronizer *sync, t_socket const & s, struct sockaddr const *sin, struct sockaddr const *s_out): _sync(sync)
{
	(void)memcpy(&this->_in, sin, sizeof(struct sockaddr));
	(void)memcpy(&this->_out, s_out, sizeof(struct sockaddr));
	this->_s = s;
	this->_isOpen = true;
}

UnixUDPSocket::~UnixUDPSocket()
{
	if (this->_isOpen)
		this->close();
}

void				UnixUDPSocket::open(int family)
{
	struct protoent	*p;

	p = getprotobyname("UDP");
	this->_s = socket(family, SOCK_DGRAM, p->p_proto);
	this->_isOpen = true;
}

int				UnixUDPSocket::bind_(int port)
{
	this->_in.sin_addr.s_addr = INADDR_ANY;
	this->_in.sin_family = AF_INET;
	this->_in.sin_port = htons(port);
	return (bind(this->_s, (struct sockaddr *)&this->_in, sizeof(struct sockaddr)));
}

void			UnixUDPSocket::connect(char *, int)
{
}

void				UnixUDPSocket::listen_(int)
{
}

bool				UnixUDPSocket::isOpen() const
{
	return (this->_isOpen);
}

TCPSocket *		UnixUDPSocket::accept()
{
	return (NULL);
}

char				*UnixUDPSocket::getIp() const
{
	return (inet_ntoa(this->_in.sin_addr));
}

int					UnixUDPSocket::getPort() const
{
	return (ntohs(this->_in.sin_port));
}

t_socket const &	UnixUDPSocket::getSocket() const
{
	return (this->_s);
}

void				UnixUDPSocket::close()
{
	_close(this->_s);
	this->_isOpen = false;
}

int						UnixUDPSocket::send(Buffer &pack)
{
	return (sendto(this->_s, pack.getBuff().buf, pack.getBuffLen(), 0, (struct sockaddr *)&this->_out, sizeof(struct sockaddr)));
}

int						UnixUDPSocket::recv(Buffer &pack)
{
	socklen_t					len = sizeof(struct sockaddr);

	return (recvfrom(this->_s, pack.getBuff().buf, pack.getBuffLen(), 0, (struct sockaddr *)&this->_in, &len));
}

void					UnixUDPSocket::asyncRead(Buffer &p, ReadHandler & c)
{
	this->_sync->addHandler(new detail::ReadWriteOperation(this, detail::READ, p, c));
}

void					UnixUDPSocket::asyncWrite(Buffer &p, WriteHandler & c)
{
	this->_sync->addHandler(new detail::ReadWriteOperation(this, detail::WRITE, p, c));
}

void					UnixUDPSocket::asyncAccept(AcceptHandler &)
{
}


#endif
