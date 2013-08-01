#ifndef	_WIN32
#include	"UnixTimer.h"

UnixTimer::UnixTimer() : _isSet(false)
{
}

UnixTimer::~UnixTimer()
{
}

void		UnixTimer::setTimerAt(int time)
{
	struct timeval	s;

	gettimeofday(&this->_t, NULL);
	s.tv_sec = time / 1000000;
	s.tv_usec = time % 1000000;
	timeradd(&this->_t, &s, &this->_t);
}

bool		UnixTimer::isUp()
{
	struct timeval	s;

	gettimeofday(&s, NULL);
	if (timercmp(&this->_t, &s, >) || !timercmp(&this->_t, &s, !=))
		return (true);
	return (false);
}

#endif