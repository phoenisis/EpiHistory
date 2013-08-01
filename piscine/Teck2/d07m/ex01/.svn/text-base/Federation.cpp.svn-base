#include <string>
#include <iostream>
#include "Federation.hh"
#include "Warpsystem.hh"

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

void Federation::Starfleet::Ship::promote(Federation::Starfleet::Captain *cap)
{
this->_capitain = cap;
std::cout << this->_capitain->getName()
	    << ": I'm glad to be the captain of the USS "
	    << this->_name
	    << "."
	    << std::endl;
}

Federation::Starfleet::Captain::Captain(std::string name)
{
  this->_name = name;
}
Federation::Starfleet::Captain::~Captain()
{
}

std::string Federation::Starfleet::Captain::getName()
{
  return(this->_name);
}

int Federation::Starfleet::Captain::getAge()
{
  return(this->_age);
}

void Federation::Starfleet::Captain::setAge(int age)
{
  this->_age = age;
}

Federation::Starfleet::Ensign::Ensign(std::string name)
{
  this->_name = name;
  std::cout << "Ensign "
	    << this->_name
	    << ", awaiting orders."
	    << std::endl;
}

Federation::Starfleet::Ensign::~Ensign()
{
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
