#ifndef __MUTEX__
# define __MUTEX__

# include <pthread.h>

class	Mutex
{
public :
  Mutex();
  ~Mutex();
  void lock();
  void unlock();
  bool trylock();

private :
  pthread_mutex_t *mutex;
};


#endif
