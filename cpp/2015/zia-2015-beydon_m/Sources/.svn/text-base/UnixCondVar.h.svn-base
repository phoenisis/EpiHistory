#ifndef __UNIXCONDVAR_H__
# define __UNIXCONDVAR_H__
# ifndef _WIN32
# include	<pthread.h>

namespace Thread
{
	class UnixCondVar
	{
	public:
		UnixCondVar();
		~UnixCondVar();
		void	Wait();
		void	WakeUp();
	private:
		pthread_cond_t	_cv;
		pthread_mutex_t _cs;
	};
	typedef UnixCondVar CondVar;
}
# endif
#endif // !__UNIXCONDVAR_H__
