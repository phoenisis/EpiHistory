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
      Ship(int length, int width, std::string name, short maxwarp);
      ~Ship();
      void setupCore(WarpSystem::Core *Core);
      void checkCore();
    private:
      int		_length;
      int		_width;
      std::string	_name;
      short		_maxWarp;
      WarpSystem::Core	*_Core;
    };
  }

  class Ship
  {
  public:
    Ship(int length, int width, std::string name);
    void setupCore(WarpSystem::Core *Core);
    void checkCore();
    ~Ship();
  private:
    std::string name;
    int         _length;
    int         _width;
    std::string _name;
    short       _maxWarp;
    WarpSystem::Core *_Core;
  };
}
#endif
