#ifndef	__CLIENTSOCKET_H__
# define	__CLIENTSOCKET_H__
#ifdef _WIN32
# include <WinSock2.h>
# include "WinFunc.h"
#else
# include <sys/types.h>
# include <netinet/in.h>
# include <sys/socket.h>
# include "UnixFunc.h"
#endif
#include	"ISocket.h"
#include	"Buffer.h"
#include	"Synchronizer.h"

class					Synchronizer;

class					ClientSocket : public ISocket
{
public:
	ClientSocket(Synchronizer *sync);
	ClientSocket(Synchronizer *sync, T_SOCKET const &, struct sockaddr const *);
	~ClientSocket();
	void				open(int, std::string const &);
	bool				isOpen() const;
	void				connect(char *, int);
	char				*getIp() const;
	int					getPort() const;
	T_SOCKET const &	getSocket() const;
	int					send(Buffer *);
	int					recv(Buffer *);
	void				asyncRead(Buffer *, int	id);
	void				asyncWrite(Buffer *, int id);
	void				close();
private:
	T_SOCKET	_s;
	struct sockaddr_in _infos;
	bool		_isOpen;
	Synchronizer *_sync;
};

#endif
