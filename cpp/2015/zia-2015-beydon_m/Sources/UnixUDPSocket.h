#ifndef		__UNIXUDPSOCKET_H__
# define	__UNIXUDPSOCKET_H__
# ifndef _WIN32
#  include <sys/socket.h>
#  include <netinet/in.h>
#  include <arpa/inet.h>
#  include	"UnixTCPSocket.h"
#  include	"ISocket.h"
#  include	"UnixSynchronizer.h"
#  include	"Function.h"

namespace Network
{
	class					UnixUDPSocket : public ISocket
	{
	public:
		UnixUDPSocket(Synchronizer *, struct sockaddr const *);
		UnixUDPSocket(Synchronizer *, t_socket const &, struct sockaddr const *, struct sockaddr const *);
		~UnixUDPSocket();
		void				open(int);
		bool				isOpen() const;
		void				connect(char *, int);
		int					bind_(int);
		void				listen_(int);
		TCPSocket *			accept();
		char				*getIp() const;
		int					getPort() const;
		t_socket const &	getSocket() const;
		int					send(Buffer &);
		int					recv(Buffer &);
		void				asyncRead(Buffer &, ReadHandler &);
		void				asyncWrite(Buffer &, WriteHandler &);
		void				close();
		void				asyncAccept(AcceptHandler &);
	private:
		t_socket			_s;
		struct sockaddr_in	_in;
		bool				_isOpen;
		Synchronizer *_sync;
		struct sockaddr_in	_out;
	};

	typedef UnixUDPSocket UDPSocket;
}
# endif
#endif
