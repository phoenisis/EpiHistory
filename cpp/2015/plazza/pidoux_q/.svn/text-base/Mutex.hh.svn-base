#ifndef __MUTEX__
# define __MUTEX__

# include <pthread.h>

class	Mutex
{
public :
  Mutex();
  ~Mutex();
  bool lock();
  bool unlock();
  bool trylock();

private :
  pthread_mutex_t *mutex;
};


#endif
