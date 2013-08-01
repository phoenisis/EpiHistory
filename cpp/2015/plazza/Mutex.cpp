//
// Mutex.cpp for  in /home/deu_f//Plazza/Tp
// 
// Made by florent deu
// Login   <deu_f@epitech.net>
// 
// Started on  Thu Apr  5 20:01:39 2012 florent deu
// Last update Thu Apr  5 21:53:52 2012 florent deu
//

#include "Mutex.hh"

Mutex::Mutex() : _mutex(), _mutex_ctr(0)
{
  pthread_mutex_init(&(this->_mutex), NULL);
}

Mutex::~Mutex()
{
  this->_mutex_ctr = 0;
  pthread_mutex_destroy(&(this->_mutex));
}

Mutex::Mutex(Mutex const& other) : _mutex(other._mutex), _mutex_ctr(other._mutex_ctr) {}

Mutex&	Mutex::operator=(Mutex const& other)
{
  this->_mutex_ctr = other._mutex_ctr;
  if (this != &other)
    {
      pthread_mutex_destroy(&(this->_mutex));
      this->_mutex = other._mutex;
    }
  return *this;
}

pthread_mutex_t&	Mutex::getMutex()
{
  return this->_mutex;
}

int	Mutex::getMutexCtr() const
{
  return this->_mutex_ctr;
}

bool	Mutex::lock(void)
{
  if (pthread_mutex_lock(&(this->_mutex)))
    return false;
  this->_mutex_ctr += 1;
  return true;
}

bool	Mutex::unlock(void)
{
  if (pthread_mutex_unlock(&(this->_mutex)))
    return false;
  return true;  
}

bool	Mutex::trylock(void)
{
  if (!pthread_mutex_trylock(&(this->_mutex)))
    return true;
  return false;
}
