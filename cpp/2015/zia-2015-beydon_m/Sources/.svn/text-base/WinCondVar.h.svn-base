#ifndef __WINCONDVAR_H__
# define	__WINCONDVAR_H__
# ifdef _WIN32
#  define WIN32_LEAN_AND_MEAN
#  include	<Windows.h>
#  include	"WinMutex.h"

namespace Thread
{
	class WinCondVar
	{
	public:
		WinCondVar();
		~WinCondVar();
		void		Wait();
		void		WakeUp();
	private:
		CONDITION_VARIABLE	_cv;
		CRITICAL_SECTION	_cs;
	};
	typedef WinCondVar CondVar;
}

# endif
#endif // !__WINCONDVAR_H__
