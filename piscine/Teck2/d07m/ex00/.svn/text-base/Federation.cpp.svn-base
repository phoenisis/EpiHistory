#include "Federation.hh"
#include "Warpsystem.hh"
#include <string>
#include <iostream>

Federation::Starfleet::Ship::Ship(int length, int width, std::string name, short MaxWarp)
{
  this->_name = name;
  this->_length = length;
  this->_width = width;
  this->_maxWarp = MaxWarp;

  std::cout << "The ship USS "
	    << this->_name
	    << " has been finished. It is "
	    << this->_length
	    << " m in length and "
	    << this->_width
	    << " m in width."
	    << std::endl
	    << "It can go to Warp "
	    << this->_maxWarp
	    << "!"
	    << std::endl;
}

Federation::Starfleet::Ship::~Ship()
{
}

void Federation::Starfleet::Ship::setupCore(WarpSystem::Core *Core)
{
  this->_Core = Core;
  std::cout << "USS "
	    << this->_name
	    << ": The core is set."
	    << std::endl;
}

void Federation::Starfleet::Ship::checkCore()
{
  if (this->_Core->checkReactor()->isStable() == true)
    std::cout << "USS " 
	      << this->_name 
	      << ": The core is stable at the time." 
	      << std::endl;
  else
    std::cout << "USS " 
	      << this->_name 
	      << ": The core is unstable at the time." 
	      << std::endl;
}

Federation::Ship::Ship(int length, int width, std::string name)
{
  this->_name = name;
  this->_length = length;
  this->_width = width;
  this->_maxWarp = 1;

  std::cout << "The independant ship "
	    << this->_name
	    << " just finished its construction. It is "
	    << this->_length
	    << " m in length and "
	    << this->_width
	    << " m in width."
	    << std::endl;
}

Federation::Ship::~Ship()
{
}

void Federation::Ship::setupCore(WarpSystem::Core *Core)
{
  this->_Core = Core;
  std::cout << this->_name
	    << ": The core is set."
	    << std::endl;
}

void Federation::Ship::checkCore()
{
  if (this->_Core->checkReactor()->isStable() == true)
    std::cout << this->_name 
	      << ": The core is stable at the time." 
	      << std::endl;
  else
    std::cout << this->_name 
	      << ": The core is unstable at the time." 
	      << std::endl;
}
