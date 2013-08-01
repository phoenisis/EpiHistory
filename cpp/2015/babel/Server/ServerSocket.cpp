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
#include		"ServerSocket.h"
#include		"Synchronizer.h"
#include		"AcceptHandler.h"

ServerSocket::ServerSocket() : _isOpen(false)
{
}

ServerSocket::ServerSocket(Synchronizer *sync): _sync(sync)
{
	this->_isOpen = false;
}

ServerSocket::ServerSocket(Synchronizer *sync, T_SOCKET const & s, struct sockaddr const *sin): _sync(sync)
{
	(void)memcpy(&this->_infos, sin, sizeof(struct sockaddr *));
	this->_s = s;
	this->_isOpen = true;
}

ServerSocket::~ServerSocket()
{
	if (this->_isOpen)
		this->close();
}

void				ServerSocket::open(int family, std::string const &proto)
{
	this->_s = _socket(family, proto);
	this->_isOpen = true;
}

void				ServerSocket::doBind(int port, int l)
{
	this->_infos.sin_addr.s_addr = inet_addr("127.0.0.1");
	this->_infos.sin_family = AF_INET;
	this->_infos.sin_port = htons(port);
	bind(this->_s, (struct sockaddr *)&this->_infos, sizeof(struct sockaddr));
	listen(this->_s, l);
}

bool				ServerSocket::isOpen() const
{
	return (this->_isOpen);
}

ClientSocket *		ServerSocket::accept()
{
	struct sockaddr_in sin;
	T_SOCKET		new_socket;

	new_socket = _accept(this->_s, (struct sockaddr *)&sin);
	return (new ClientSocket(this->_sync, new_socket, (struct sockaddr *)&sin));
}

char				*ServerSocket::getIp() const
{
	return (inet_ntoa(this->_infos.sin_addr));
}

int					ServerSocket::getPort() const
{
	return (ntohs(this->_infos.sin_port));
}

T_SOCKET const &	ServerSocket::getSocket() const
{
	return (this->_s);
}

void				ServerSocket::close()
{
	_close(this->_s);
	this->_isOpen = false;
}

void					ServerSocket::asyncAccept()
{
	this->_sync->addHandler(new AcceptHandler(this, ACCEPT));
}
