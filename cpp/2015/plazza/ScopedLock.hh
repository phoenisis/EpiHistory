#ifndef __SCOPEDLOCK__HH__
#define __SCOPEDLOCK__HH__

#include "Mutex.hh"

class ScopedLock
{
private:
  ScopedLock(ScopedLock const&);
  ScopedLock& operator=(const ScopedLock &);
  Mutex&	_mutex;
public:
  ScopedLock(Mutex&);
  ~ScopedLock(void);
  void trylock(void);
};

#endif //__SCOPEDLOCK__HH_
