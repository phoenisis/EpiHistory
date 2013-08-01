#include "ScopedLock.hh"
#include "Mutex.hh"


ScopedLock::ScopedLock(Mutex *m)
{
  m->lock();
  this->mutex = m;
}

ScopedLock::~ScopedLock()
{
  this->mutex->unlock();
}
