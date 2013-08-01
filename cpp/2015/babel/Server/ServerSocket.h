#ifndef		__SERVER_SOCKET_H__
# define	__SERVER_SOCKET_H__
# ifdef _WIN32
#  include <WinSock2.h>
#  include "WinFunc.h"
# else
#  include <sys/types.h>
#  include <netinet/in.h>
#  include <sys/socket.h>
#  include "UnixFunc.h"
# endif
#include	"ISocket.h"
#include	"ClientSocket.h"
#include	"Synchronizer.h"

class					Synchronizer;
class					ClientSocket;

class					ServerSocket : public ISocket
{
public:
	ServerSocket();
	ServerSocket(Synchronizer *);
	ServerSocket(Synchronizer *, T_SOCKET const &, struct sockaddr const *);
	~ServerSocket();
	void				open(int, std::string const &);
	void				doBind(int, int);
	ClientSocket *		accept();
	void				asyncAccept();
	bool				isOpen() const;
	char				*getIp() const;
	int					getPort() const;
	T_SOCKET const &	getSocket() const;
	void				close();
private:
	T_SOCKET	_s;
	struct sockaddr_in _infos;
	bool		_isOpen;
	Synchronizer *_sync;
};

#endif
