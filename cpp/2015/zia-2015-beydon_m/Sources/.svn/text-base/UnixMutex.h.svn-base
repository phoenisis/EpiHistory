#ifndef		__UNIXMUTEX_H__
# define	__UNIXMUTEX_H__
# ifndef _WIN32
# include	<pthread.h>

namespace Thread
{
	class		UnixMutex
	{
	public:
		UnixMutex();
		~UnixMutex();
		void	lock();
		void	unlock();
		bool	trylock();
	private:
		pthread_mutex_t	_mutex;
	};

	typedef UnixMutex Mutex;
}

# endif
#endif
