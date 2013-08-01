#ifdef _WIN32
# include	<WinSock2.h>
#endif
#include	<string>
#include	<iostream>
#include	"Config.h"
#include	"Server.h"

void		win_init()
{
#ifdef _WIN32
	WSADATA	d;

	WSAStartup(MAKEWORD(2, 2), &d);
#endif
}

int			main()
{
	win_init();
	Config	c("./config.xml");
	Server	s(&c);

	s.run();
	return (0);
}