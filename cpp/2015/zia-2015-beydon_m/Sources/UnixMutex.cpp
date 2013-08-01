#ifndef	_WIN32
# include	"UnixMutex.h"

using namespace Thread;

UnixMutex::UnixMutex()
{
	pthread_mutex_init(&this->_mutex, 0);
}

UnixMutex::~UnixMutex()
{
	pthread_mutex_destroy(&this->_mutex);
}

void		UnixMutex::lock()
{
	pthread_mutex_lock(&this->_mutex);
}

void		UnixMutex::unlock()
{
	pthread_mutex_unlock(&this->_mutex);
}

bool		UnixMutex::trylock()
{
	if (pthread_mutex_trylock(&this->_mutex) == 0)
		return (false);
	return (true);
}

#endif