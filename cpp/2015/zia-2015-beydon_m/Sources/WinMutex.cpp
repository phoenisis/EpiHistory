#ifdef	_WIN32
# include	"WinMutex.h"

using namespace Thread;

WinMutex::WinMutex()
{
	InitializeCriticalSection(&this->_mutex);
}

WinMutex::~WinMutex()
{
	DeleteCriticalSection(&this->_mutex);
}

void		WinMutex::lock()
{
	EnterCriticalSection(&this->_mutex);
}

void		WinMutex::unlock()
{
	LeaveCriticalSection(&this->_mutex);
}

bool		WinMutex::trylock()
{
	if (TryEnterCriticalSection(&this->_mutex) == 0)
		return (false);
	return (true);
}

#endif