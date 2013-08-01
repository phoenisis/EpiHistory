#ifndef	_WIN32

#include		<cstring>
#include		"UnixTCPSocket.h"
#include		"IOOperation.h"

using namespace Network;

static	int _connect(int sockfd, const struct sockaddr *addr, socklen_t addrlen)
{
  return (connect(sockfd, addr, addrlen));
}

static int _close(int s)
{
  return (close(s));
}

static int _accept(int sockfd, struct sockaddr *addr, socklen_t *addrlen)
{
  return (accept(sockfd, addr, addrlen));
}

UnixTCPSocket::UnixTCPSocket(Synchronizer *sync): _sync(sync)
{
	this->_isOpen = false;
}

UnixTCPSocket::UnixTCPSocket(Synchronizer *sync, t_socket const & s, struct sockaddr const *sin): _sync(sync)
{
	(void)memcpy(&this->_infos, sin, sizeof(struct sockaddr));
	this->_s = s;
	this->_isOpen = true;
}

UnixTCPSocket::~UnixTCPSocket()
{
	if (this->_isOpen)
		this->close();
}

void				UnixTCPSocket::open(int family)
{
	struct protoent	*p;

	p = getprotobyname("TCP");
	this->_s = socket(family, SOCK_STREAM, p->p_proto);
	this->_isOpen = true;
}

bool				UnixTCPSocket::isOpen() const
{
	return (this->_isOpen);
}

void				UnixTCPSocket::connect(char *ip, int port)
{
	this->_infos.sin_addr.s_addr = inet_addr(ip);
	this->_infos.sin_family = AF_INET;
	this->_infos.sin_port = htons(port);
	_connect(this->_s, (struct sockaddr *)&this->_infos, sizeof(this->_infos));
}

int					UnixTCPSocket::bind_(int port)
{
	this->_infos.sin_family = AF_INET;
	this->_infos.sin_addr.s_addr = INADDR_ANY;
	this->_infos.sin_port = htons(port);
	return (bind(this->_s, (struct sockaddr *)&this->_infos, sizeof(struct sockaddr)));
}

void				UnixTCPSocket::listen_(int wait)
{
	listen(this->_s, wait);
}

char				*UnixTCPSocket::getIp() const
{
	return (inet_ntoa(this->_infos.sin_addr));
}

int					UnixTCPSocket::getPort() const
{
	return (ntohs(this->_infos.sin_port));
}

t_socket const &	UnixTCPSocket::getSocket() const
{
	return (this->_s);
}

int					UnixTCPSocket::send(Buffer & buf)
{
	int			ret;

	ret = sendto(this->_s, buf.getBuff().buf, buf.getBuffLen(), 0, 0, 0);
	return (ret);
}

int					UnixTCPSocket::recv(Buffer & buf)
{
	int			ret;

	ret = recvfrom(this->_s, buf.getBuff().buf, buf.getBuffLen(), 0, 0, 0);
	return (ret);
}

void				UnixTCPSocket::close()
{

	this->_sync->removeHandlers(this);
	_close(this->_s);
	this->_isOpen = false;
}

UnixTCPSocket *				UnixTCPSocket::accept()
{
	struct sockaddr_in sin;
	t_socket		new_socket;
	socklen_t			len = sizeof(struct sockaddr);

	new_socket = _accept(this->_s, (struct sockaddr *)&this->_infos, &len);
	return (new UnixTCPSocket(this->_sync, new_socket, (struct sockaddr *)&sin));
}

void				UnixTCPSocket::asyncRead(Buffer &p, ReadHandler & c)
{
	this->_sync->addHandler(new detail::ReadWriteOperation(this, detail::READ, p, c));
}

void				UnixTCPSocket::asyncWrite(Buffer &p, WriteHandler & c)
{
	this->_sync->addHandler(new detail::ReadWriteOperation(this, detail::WRITE, p, c));
}

void					UnixTCPSocket::asyncAccept(AcceptHandler & c)
{
	this->_sync->addHandler(new detail::AcceptOperation(this, detail::ACCEPT, c));
}

#endif
