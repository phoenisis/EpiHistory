#ifndef _FEDERATION_HH_
#define _FEDERATION_HH_
#include <string>
#include "Warpsystem.hh"

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
    private:
      int		_length;
      int		_width;
      std::string	_name;
      short		_maxWarp;
      WarpSystem::Core	*_Core;
      Captain		*_capitain;
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
