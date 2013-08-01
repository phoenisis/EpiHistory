#ifndef _FEDERATION_HH_
#define _FEDERATION_HH_
#include <string>
#include "Warpsystem.hh"
#include "Destination.hh"

namespace Federation
{
  namespace Starfleet
  {
    class Ensign
    {
    private:
      std::string _name;
    public:
      Ensign(std::string name);
      ~Ensign();
    };

    class Captain
    {
    private:
      std::string _name;
      int _age;
    public:
      Captain(std::string a);
      ~Captain();
      std::string getName();
      int getAge();
      void setAge(int);
    };

    class Ship
    {
    public :
      Ship(int length, int width, std::string name, short maxwarp);
      ~Ship();
      void setupCore(WarpSystem::Core *Core);
      void checkCore();
      void promote(Federation::Starfleet::Captain *Captain);
        bool move(int warp, Destination d); // deplace _location a d
        bool move(int warp); // deplace _location a _home
        bool move(Destination d); // deplace _location a d
        bool move(); // deplace _location a _home
    private:
      int		_length;
      int		_width;
      std::string	_name;
      short		_maxWarp;
      WarpSystem::Core	*_Core;
      Captain		*_capitain;
      Destination _location;
      Destination _home;
    };
  }

  class Ship
  {
  public:
    Ship(int length, int width, std::string name);
    void setupCore(WarpSystem::Core *Core);
    void checkCore();
    ~Ship();
      bool move(int warp, Destination d); // deplace _location a d
      bool move(int warp); // deplace _location a _home
      bool move(Destination d); // deplace _location a d
      bool move(); // deplace _location a _home
  private:
    std::string name;
    int         _length;
    int         _width;
    std::string _name;
    short       _maxWarp;
    WarpSystem::Core *_Core;
    Destination _location;
    Destination _home;
  };
}
#endif
