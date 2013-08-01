#ifndef	__WINTCPSOCKET_H__
# define	__WINTCPSOCKET_H__
# ifdef _WIN32
#  include  <WinSock2.h>
#  include	"ISocket.h"
#  include	"Buffer.h"
#  include	"WinSynchronizer.h"
#  include	"Function.h"

namespace Network
{
	class					WinTCPSocket : public ISocket
	{
	public:
		WinTCPSocket(Synchronizer *sync);
		WinTCPSocket(Synchronizer *sync, t_socket const &, struct sockaddr const *);
		~WinTCPSocket();
		void				open(int);
		bool				isOpen() const;
		void				connect(char *, int);
		int					bind_(int);
		void				listen_(int);
		WinTCPSocket *			accept();
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
		SOCKET			_s;
		struct sockaddr_in	_infos;
		bool				_isOpen;
		Synchronizer *_sync;
	};

	typedef WinTCPSocket TCPSocket;
}
# endif
#endif
