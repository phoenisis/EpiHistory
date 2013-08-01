#include "Borg.hh"
#include "Federation.hh"
#include <string>
#include <iostream>

Borg::Ship::Ship()
{
  this->_size = 3000;
  this->_maxWarp = 9;
    this->_location = UNICOMPLEX;
    this->_home = this->_location;

  std::cout << "We are the Borgs. Lower your shields and surrender yourselves unconditionally."
	    << std::endl
	    << "Your biological characteristics and technologies will be assimilated."
	    << std::endl
	    << "Resistance is futile."
	    << std::endl;
}

Borg::Ship::~Ship()
{
}

void Borg::Ship::setupCore(WarpSystem::Core *Core)
{
  this->_Core = Core;
}

void Borg::Ship::checkCore()
{
  if (this->_Core->checkReactor()->isStable() == true)
    std::cout << "Everything is in order." 
	      << std::endl;
  else
    std::cout << "Critical failure imminent." 
	      << std::endl;
}

bool Borg::Ship::move(int warp, Destination d)
{
    if(warp <= this->_maxWarp && d != this->_location && this->_stability == true)
    {
        this->_location = d;
        return (true);
    }
    else
        return (false);
}

bool Borg::Ship::move(int warp)
{
    if (warp <= this->_maxWarp && this->_location != this->_home && this-> _stability == true) 
    {
        this->_location = this->_home;
        return (true);
    }
    else
        return (false);
}

bool Borg::Ship::move(Destination d)
{
    if (this->_location != this->_home && this->_stability == true) 
    {
        this->_location = _location = d;
        return (true);
    }
    else
        return (false);
}

bool Borg::Ship::move()
{
    if (this->_location != this->_home && this->_stability == true) 
    {
        this->_location = _home;
        return (true);
    }
    else 
        return (false);
}
