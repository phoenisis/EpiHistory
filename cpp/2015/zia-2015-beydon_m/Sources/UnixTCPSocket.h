#ifndef	__UNIXTCPSOCKET_H__
# define	__UNIXTCPSOCKET_H__
# ifndef _WIN32
#  include	<unistd.h>
#  include	<sys/socket.h>
#  include	<sys/types.h>
#  include	<netdb.h>
#  include	<netinet/in.h>
#  include	<arpa/inet.h>
#  include	"ISocket.h"
#  include	"Buffer.h"
#  include	"Function.h"
#  include	"UnixSynchronizer.h"

namespace Network
{
	class					UnixTCPSocket : public ISocket
	{
	public:
		UnixTCPSocket(Synchronizer *sync);
		UnixTCPSocket(Synchronizer *sync, t_socket const &, struct sockaddr const *);
		~UnixTCPSocket();
		void				open(int);
		bool				isOpen() const;
		void				connect(char *, int);
		int					bind_(int);
		void				listen_(int);
		UnixTCPSocket *			accept();
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
		int					_s;
		struct sockaddr_in	_infos;
		bool				_isOpen;
		Synchronizer *_sync;
	};
	typedef UnixTCPSocket TCPSocket;
}
# endif
#endif
