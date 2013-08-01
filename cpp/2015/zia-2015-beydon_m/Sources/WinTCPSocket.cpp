#ifdef	_WIN32

#include		<cstring>
#include		"WinTCPSocket.h"
#include		"IOOperation.h"

using namespace Network;

WinTCPSocket::WinTCPSocket(Synchronizer *sync): _sync(sync)
{
	this->_isOpen = false;
}

WinTCPSocket::WinTCPSocket(Synchronizer *sync, t_socket const & s, struct sockaddr const *sin): _sync(sync)
{
	(void)memcpy(&this->_infos, sin, sizeof(struct sockaddr));
	this->_s = s;
	this->_isOpen = true;
}

WinTCPSocket::~WinTCPSocket()
{
	if (this->_isOpen)
		this->close();
}

void				WinTCPSocket::open(int family)
{
	this->_s = WSASocket(family, SOCK_STREAM, IPPROTO_TCP, 0, 0, 0);
	this->_isOpen = true;
}

bool				WinTCPSocket::isOpen() const
{
	return (this->_isOpen);
}

void				WinTCPSocket::connect(char *ip, int port)
{
	this->_infos.sin_addr.s_addr = inet_addr(ip);
	this->_infos.sin_family = AF_INET;
	this->_infos.sin_port = htons(port);
	WSAConnect(this->_s, (struct sockaddr *)&this->_infos, sizeof(this->_infos), NULL, NULL, NULL, NULL);
}

int					WinTCPSocket::bind_(int port)
{
	this->_infos.sin_family = AF_INET;
	this->_infos.sin_addr.s_addr = INADDR_ANY;
	this->_infos.sin_port = htons(port);
	return (bind(this->_s, (struct sockaddr *)&this->_infos, sizeof(struct sockaddr)));
}

void				WinTCPSocket::listen_(int wait)
{
	listen(this->_s, wait);
}

char				*WinTCPSocket::getIp() const
{
	return (inet_ntoa(this->_infos.sin_addr));
}

int					WinTCPSocket::getPort() const
{
	return (ntohs(this->_infos.sin_port));
}

t_socket const &	WinTCPSocket::getSocket() const
{
	return (this->_s);
}

int					WinTCPSocket::send(Buffer & buf)
{
	DWORD		bytes;
	int			ret;

	ret = WSASend(this->_s, &buf.getBuff(), 1, &bytes, 0, NULL, NULL);
	if (ret == 0)
		return (bytes);
	else
		return (-1);
}

int					WinTCPSocket::recv(Buffer & buf)
{
	DWORD		bytes;
	DWORD		flags = 0;
	int			ret;

	ret = WSARecv(this->_s, &buf.getBuff(), 1, &bytes, &flags, NULL, NULL);
	if (ret == 0)
		return (bytes);
	else
		return (-1);
}

void				WinTCPSocket::close()
{
	this->_sync->removeHandlers(this);
	shutdown(this->_s, SD_BOTH);
	closesocket(this->_s);
	this->_isOpen = false;
}


void				WinTCPSocket::asyncRead(Buffer & p, ReadHandler &c)
{
	this->_sync->addHandler(new detail::ReadWriteOperation(this, detail::READ, p, c));
}

void				WinTCPSocket::asyncWrite(Buffer & p, WriteHandler &c)
{
	this->_sync->addHandler(new detail::ReadWriteOperation(this, detail::WRITE, p, c));
}

void					WinTCPSocket::asyncAccept(AcceptHandler &c)
{
	this->_sync->addHandler(new detail::AcceptOperation(this, detail::ACCEPT, c));
}

WinTCPSocket *				WinTCPSocket::accept()
{
	struct sockaddr_in sin;
	t_socket		new_socket;
	int			len = sizeof(struct sockaddr);

	new_socket = WSAAccept(this->_s, (struct sockaddr *)&this->_infos, &len, NULL, NULL);
	return (new WinTCPSocket(this->_sync, new_socket, (struct sockaddr *)&sin));
}


#endif