//
// Federation.hh for ex_0 in /home/pidoux_q/rendu/cpp/d08m/ex_0
// 
// Made by quentin PIDOUX
// Login   <pidoux_q@epitech.net>
// 
// Started on  Tue Jan 11 10:24:57 2011 quentin PIDOUX
// Last update Tue Jan 11 17:06:13 2011 quentin PIDOUX
//

#ifndef _FEDERATION_HH_
#define _FEDERATION_HH_
#include "Warpsystem.hh"
#include <string>

namespace Federation
{
  namespace Starfleet
  {
    class Ship
    {
    public :
      Ship(int length, int width, std::string name, int MaxWarp);
      ~Ship();
      void setupCore(WarpSystem::Core *Core);
      void checkCore();
    private:
      std::string name;
      int         _length;
      int         _width;
      std::string _name;
      short       _maxWarp;
      WarpSystem::Core _Core;
    };
  }

  class Ship
  {
  public:
    Ship(int length, int width, std::string name);
    ~Ship();
  private:
    std::string name;
    int         _length;
    int         _width;
    std::string _name;
    short       _maxWarp;
    WarpSystem::Core _Core;
  };
}
#endif
