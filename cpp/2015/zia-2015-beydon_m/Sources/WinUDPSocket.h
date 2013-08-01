#ifndef		__WINUDPSOCKET_H__
# define	__WINUDPSOCKET_H__
# ifdef _WIN32
#  include	<WinSock2.h>
#  include	"WinTCPSocket.h"
#  include	"ISocket.h"
#  include	"WinSynchronizer.h"
#  include	"Function.h"

namespace Network
{
	class					WinUDPSocket : public ISocket
	{
	public:
		WinUDPSocket(Synchronizer *, struct sockaddr const *);
		WinUDPSocket(Synchronizer *, t_socket const &, struct sockaddr const *, struct sockaddr const *);
		~WinUDPSocket();
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

	typedef WinUDPSocket UDPSocket;
}
# endif
#endif
