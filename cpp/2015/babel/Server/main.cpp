#ifdef	_WIN32
# include "WinFunc.h"
# include	<WinSock2.h>
#else
# include	<sys/socket.h>
# include	"UnixFunc.h"
#endif
#include	<cstring>
#include	<iostream>
#include	"Synchronizer.h"
#include	"Server.h"

void		init()
{
#ifdef	_WIN32
	WSADATA		wsaData;
	WORD		ver;

	ver = MAKEWORD(2, 2);
	WSAStartup(ver, &wsaData);
#endif
}

void		start_server()
{
	Synchronizer	sync;
	Server			s(&sync);
	s.run();
}

int			main()
{
	init();
	start_server();
	return (0);
}