#ifndef		__UNIXSYNCHRONIZER_H__
# define	__UNIXSYNCHRONIZER_H__
# ifndef	_WIN32
#  include	<list>
#  include	<poll.h>
#  include	"UnixMutex.h"
#  include	"UnixThread.h"
#  include	"ThreadPool.h"
#  include	"ISocket.h"
#  include	"IOOperation.h"

namespace	Network
{
	class							UnixSynchronizer
	{
	public:
		UnixSynchronizer(int time = -1, Thread::ThreadPool * tp = NULL);
		~UnixSynchronizer();
		void						addHandler(SmartPointer<detail::IOOperation>);
		void						removeHandlers(ISocket *);
		int							poll();
		void						setTime(int time);
		void						setThreadPool(Thread::ThreadPool *);
	private:
		void						construct_poll(struct pollfd *);
		void						setRead(struct pollfd & p, t_socket const & s);
		void						setWrite(struct pollfd & p, t_socket const & s);
		bool						canWrite(struct pollfd & p);
		bool						canRead(struct pollfd & p);
		bool						isDisconnected(struct pollfd & p);
		bool						hasError(struct pollfd & p);
		void						transferPolls();
		void						doRead(ISocket *, Buffer &, ReadHandler &);
		void						doWrite(ISocket *, Buffer &, WriteHandler &);
		void						doAccept(ISocket *, AcceptHandler &);
		std::list<SmartPointer<detail::IOOperation> >		_handlers;
		std::list<SmartPointer<detail::IOOperation> > 		_newHandlers;
		Thread::Mutex 				_pushMutex;
		int							_time;
		Thread::ThreadPool *		_tp;
	};

	typedef UnixSynchronizer Synchronizer;
}
# endif
#endif
