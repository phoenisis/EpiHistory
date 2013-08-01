#ifndef		__UNIXTHREAD_H__
# define	__UNIXTHREAD_H__
# ifndef		_WIN32
#  include	<pthread.h>
#  include	<queue>
#  include	"SmartPointer.h"
#  include	"UnixCondVar.h"
#  include	"Function.h"

namespace Thread
{
	typedef Function::Delegate<void> ThreadAction;
	typedef void * thread_ret;

	class			UnixThread
	{
	public:
		UnixThread();
		UnixThread(UnixThread &t) : _handle(t.getHandle()), _id(t.getId()), _isRunning(t.isRunning()) {};
		UnixThread(ThreadAction *);
		~UnixThread();
		void			execAction(ThreadAction &);
		pthread_t &		getHandle() {return (this->_handle);};
		thread_ret			WaitForThread();
		bool		isRunning();
		int			getId();
		thread_ret			getThreadExitStatus();
	private:
		void				run();
		static thread_ret	 exec(void *obj)
		{
			ThreadAction * b = reinterpret_cast<ThreadAction *>(obj);

			b->exec();
			delete b;
			return (0);
		}
		CondVar			_condvar;
		pthread_t		_handle;
		int			_id;
		std::queue< ThreadAction > _action;
		bool		_isRunning;
		thread_ret		_exitValue;
	};

	typedef UnixThread Thread;
}
# endif
#endif
