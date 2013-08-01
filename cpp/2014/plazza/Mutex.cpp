#include <pthread.h>
#include "Mutex.hh"

Mutex::Mutex()
{
  this->mutex = new pthread_mutex_t;
  pthread_mutex_init(this->mutex, NULL);
}


Mutex::~Mutex()
{
  pthread_mutex_destroy(this->mutex);
  delete this->mutex;
}


void	Mutex::lock()
{
  pthread_mutex_lock(this->mutex);
}


void	Mutex::unlock()
{
  pthread_mutex_unlock(this->mutex);
}


bool	Mutex::trylock()
{
  return pthread_mutex_trylock(this->mutex);
}
