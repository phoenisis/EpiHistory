#ifndef		__ISOCKET_H__
# define	__ISOCKET_H__
# include	<string>
# include	"SmartPointer.h"
# include	"Neterror.h"
# include	"Function.h"
# include	"Buffer.h"

namespace Network
{
	class ISocket;
	typedef	Function::Delegate<void (Neterror::eError, Buffer &)> ReadHandler;
	typedef	Function::Delegate<void (Neterror::eError, Buffer &)> WriteHandler;
	typedef	Function::Delegate<void (Neterror::eError, ISocket *)> AcceptHandler;

# ifdef _WIN32
# include	<WinSock2.h>
typedef SOCKET t_socket;
# else
typedef	int		t_socket;
# endif

	class							ISocket
	{
	public:
		virtual ~ISocket() {};
		virtual void				open(int) = 0;
		virtual bool				isOpen() const = 0;
		virtual char				*getIp() const = 0;
		virtual int					getPort() const = 0;
		virtual t_socket const &	getSocket() const = 0;
		virtual	void				close() = 0;
		virtual	void				connect(char *, int) = 0;
		virtual	int					bind_(int) = 0;
		virtual void				listen_(int) = 0;
		virtual ISocket *			accept() = 0;
		virtual int					send(Buffer &) = 0;
		virtual int					recv(Buffer &) = 0;
		virtual void				asyncRead(Buffer &, ReadHandler &) = 0;
		virtual void				asyncWrite(Buffer &, WriteHandler &) = 0;
		virtual void				asyncAccept(AcceptHandler &) = 0;
	};
}
#endif
