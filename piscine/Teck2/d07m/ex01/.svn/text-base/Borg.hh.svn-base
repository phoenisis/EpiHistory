#ifndef _BORG_H_
#define  _BORG_H_
#include "Warpsystem.hh"
#include <string>

namespace  Borg
{
  class Ship
  {
  private:
    int _size;
    short _maxWarp;
    bool _stability;
    WarpSystem::Core	*_Core;
  public:
    Ship();
    ~Ship();
    void setupCore(WarpSystem::Core *Core);
    void checkCore();
  };
}

#endif
