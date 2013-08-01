#ifndef		__WINSYNCHRONIZER_H__
# define	__WINSYNCHRONIZER_H__
# ifdef	_WIN32
#  include	<WinSock2.h>
#  include	<list>
#  include	"WinMutex.h"
#  include	"WinThread.h"
#  include	"ThreadPool.h"
#  include	"ISocket.h"
#  include	"IOOperation.h"

namespace Network
{
	class							WinSynchronizer
	{
	public:
		WinSynchronizer(int time = -1, Thread::ThreadPool * tp = NULL);
		~WinSynchronizer();
		void						addHandler(SmartPointer<detail::IOOperation>);
		void						removeHandlers(ISocket *);
		int							poll();
		void						setTime(int time);
		void						setThreadPool(Thread::ThreadPool *);
	private:
		void						construct_poll(WSAPOLLFD *);
		void						doRead(ISocket *, Buffer &, ReadHandler &);
		void						doWrite(ISocket *, Buffer &, WriteHandler &);
		void						doAccept(ISocket *, AcceptHandler &);
		void						setRead(WSAPOLLFD & p, t_socket const & s);
		void						setWrite(WSAPOLLFD & p, t_socket const & s);
		bool						canWrite(WSAPOLLFD & p);
		bool						canRead(WSAPOLLFD & p);
		bool						isDisconnected(WSAPOLLFD & p);
		bool						hasError(WSAPOLLFD & p);
		void						transferPolls();
		std::list<SmartPointer<detail::IOOperation> >		_handlers;
		std::list<SmartPointer<detail::IOOperation> > 		_newHandlers;
		Thread::Mutex 				_pushMutex;
		int							_time;
		Thread::ThreadPool *		_tp;
	};

	typedef WinSynchronizer	Synchronizer;
}
# endif
#endif