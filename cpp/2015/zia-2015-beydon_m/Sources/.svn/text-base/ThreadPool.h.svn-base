#ifndef		__THREADPOOL_H__
# define	__THREADPOOL_H__
# ifdef _WIN32
#  include	"WinThread.h"
#  include	"WinMutex.h"
# else
#  include	"UnixThread.h"
#  include	"UnixMutex.h"
# endif
# include	<vector>
# include	<queue>
# include	"Function.h"

namespace Thread
{
	class		ThreadPool
	{
	public:
		ThreadPool(unsigned int max = 2);
		~ThreadPool();
		void		startNewAction(ThreadAction &);
	private:
		bool						_isEmpty();
		void						run();
#ifdef _WIN32
		static	thread_ret	WINAPI	exec(void *obj)
#else
		static	thread_ret			exec(void *obj)
#endif
		{
			ThreadAction *b = reinterpret_cast<ThreadAction *>(obj);

			b->exec();
			return (0);
		}
		CondVar					_condvar;
		Mutex					_pmutex;
		SmartPointer<Thread>	_t;
		std::vector< SmartPointer<Thread> >	_threads;
		int					_max;
		std::queue<ThreadAction>	_actions;
	};
}
#endif