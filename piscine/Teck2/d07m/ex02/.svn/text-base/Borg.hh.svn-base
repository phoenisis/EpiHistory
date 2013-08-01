#ifndef _BORG_H_
#define  _BORG_H_
#include "Warpsystem.hh"
#include "Destination.hh"
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
      Destination _location;
      Destination _home;
  public:
    Ship();
    ~Ship();
    void setupCore(WarpSystem::Core *Core);
    void checkCore();
      bool move(int warp, Destination d); // deplace _location a d
      bool move(int warp); // deplace _location a _home
      bool move(Destination d); // deplace _location a d
      bool move(); // deplace _location a _home
  };
}

#endif
