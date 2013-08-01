#ifdef	_WIN32
#include		<WinSock2.h>
#include		"WinFunc.h"
#else
#include		<arpa/inet.h>
#include		<sys/socket.h>
#include		<netinet/in.h>
#include		"UnixFunc.h"
#endif
#include		<cstring>
#include		"ClientSocket.h"
#include		"Synchronizer.h"
#include		"ReadWriteHandler.h"

ClientSocket::ClientSocket(Synchronizer *sync): _sync(sync)
{
	this->_isOpen = false;
}

ClientSocket::ClientSocket(Synchronizer *sync, T_SOCKET const & s, struct sockaddr const *sin): _sync(sync)
{
	(void)memcpy(&this->_infos, sin, sizeof(struct sockaddr *));
	this->_s = s;
	this->_isOpen = true;
}

ClientSocket::~ClientSocket()
{
	if (this->_isOpen)
		this->close();
}

void				ClientSocket::open(int family, std::string const &proto)
{
	this->_s = _socket(family, proto);
	this->_isOpen = true;
}

bool				ClientSocket::isOpen() const
{
	return (this->_isOpen);
}

void				ClientSocket::connect(char *ip, int port)
{
	this->_infos.sin_addr.s_addr = inet_addr(ip);
	this->_infos.sin_family = AF_INET;
	this->_infos.sin_port = htons(port);
	_connect(this->_s, (struct sockaddr *)&this->_infos);
}

char				*ClientSocket::getIp() const
{
	return (inet_ntoa(this->_infos.sin_addr));
}

int					ClientSocket::getPort() const
{
	return (ntohs(this->_infos.sin_port));
}

T_SOCKET const &	ClientSocket::getSocket() const
{
	return (this->_s);
}

int					ClientSocket::send(Buffer * buf)
{
	return (_send(this->_s, &buf->getBuffer()));
}

int					ClientSocket::recv(Buffer * buf)
{
	return (_recv(this->_s, &buf->getBuffer()));
}

void				ClientSocket::close()
{
	this->_sync->removeHandlers(this);
	_close(this->_s);
	this->_isOpen = false;
}


void				ClientSocket::asyncRead(Buffer *buf, int id)
{
	this->_sync->addHandler(new ReadWriteHandler(this, READ, buf, id));
}

void				ClientSocket::asyncWrite(Buffer *buf, int id)
{
	this->_sync->addHandler(new ReadWriteHandler(this, WRITE, buf, id));
}

