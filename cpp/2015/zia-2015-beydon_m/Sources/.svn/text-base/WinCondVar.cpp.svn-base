#ifdef _WIN32
# include	"WinCondVar.h"
using namespace Thread;

WinCondVar::WinCondVar()
{
	InitializeConditionVariable(&this->_cv);
	InitializeCriticalSection(&this->_cs);
}

WinCondVar::~WinCondVar()
{
	DeleteCriticalSection(&this->_cs);
}

void		WinCondVar::Wait()
{
	EnterCriticalSection(&this->_cs);
	SleepConditionVariableCS(&this->_cv, &this->_cs, INFINITE);
	LeaveCriticalSection(&this->_cs);
}

void		WinCondVar::WakeUp()
{
	WakeAllConditionVariable(&this->_cv);
}

#endif // _WIN32
