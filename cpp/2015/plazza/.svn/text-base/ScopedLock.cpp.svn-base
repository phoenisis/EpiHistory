#include "ScopedLock.hh"

ScopedLock::ScopedLock(Mutex& mutex)
{
  this->_mutex.lock();
}

ScopedLock::~ScopedLock(void)
{
  this->_mutex.unlock();
}

ScopedLock::ScopedLock(ScopedLock const& other) : _mutex(other._mutex) {}

ScopedLock& ScopedLock::operator=(ScopedLock const& other)
{
  if (this != &other)
    this->_mutex = other._mutex;
  return (*this);
}

void	ScopedLock::trylock(void)
{
  this->_mutex.trylock();
}
