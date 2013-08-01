#ifndef		__WINMUTEX_H__
# define	__WINMUTEX_H__
# ifdef _WIN32
# define WIN32_LEAN_AND_MEAN
# include	<Windows.h>

namespace Thread
{
	class		WinMutex
	{
	public:
		WinMutex();
		~WinMutex();
		void	lock();
		void	unlock();
		bool	trylock();
	private:
		CRITICAL_SECTION	_mutex;
	};

	typedef WinMutex Mutex;
}
# endif
#endif