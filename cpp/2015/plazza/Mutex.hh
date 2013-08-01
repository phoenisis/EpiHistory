#ifndef __MUTEX_HH__
#define	__MUTEX_HH__

#include <pthread.h>
#include <iostream>


class Mutex
{
private:
  pthread_mutex_t	_mutex;
  int			_mutex_ctr;
public:
  Mutex(void);
  Mutex(Mutex const&);
  Mutex& operator=(Mutex const&);
  ~Mutex(void);
  
  bool	lock(void);
  bool	unlock(void);
  bool	trylock(void);

  pthread_mutex_t&	getMutex(void);
  int			getMutexCtr(void) const;
};

#endif //__MUTEX_HH__
