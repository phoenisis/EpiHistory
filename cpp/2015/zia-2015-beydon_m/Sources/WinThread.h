#ifndef		__WINTHREAD_H__
# define	__WINTHREAD_H__
# ifdef		_WIN32
#  define WIN32_LEAN_AND_MEAN
#  include	<Windows.h>
#  include	<queue>
#  include	"SmartPointer.h"
#  include	"WinCondVar.h"
#  include	"Function.h"

namespace Thread
{
	typedef Function::Delegate<void> ThreadAction;
	typedef DWORD thread_ret;

	class			WinThread
	{
	public:
		WinThread();
		WinThread(WinThread &t) : _handle(t.getHandle()), _id(t.getId()), _isRunning(t.isRunning()) {};
		WinThread(ThreadAction *);
		~WinThread();
		void			execAction(ThreadAction &);
		HANDLE &		getHandle() {return (this->_handle);};
		thread_ret		WaitForThread();
		bool			isRunning();
		int				getId();
		thread_ret		getThreadExitStatus();
	private:
		void			run();
		static thread_ret	WINAPI exec(void *obj)
		{
			ThreadAction * b = reinterpret_cast<ThreadAction *>(obj);

			b->exec();
			delete b;
			return (0);
		}
		CondVar		_condvar;
		HANDLE		_handle;
		DWORD			_id;
		std::queue< ThreadAction >  _action;
		bool		_isRunning;
		thread_ret		_exitValue;
	};

	typedef WinThread Thread;
}
# endif
#endif