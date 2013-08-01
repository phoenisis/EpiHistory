#ifdef		_WIN32
# include	"WinTimer.h"

WinTimer::WinTimer() : _isSet(false)
{
}

WinTimer::~WinTimer()
{
}

void		WinTimer::setTimerAt(int time)
{
	this->_t = GetTickCount64();
	this->_t += time;
}

bool		WinTimer::isUp()
{
	if (this->_t >= GetTickCount64())
		return (true);
	return (false);
}

#endif