//
// Federation.cpp for ex_0 in /home/pidoux_q/rendu/cpp/d08m/ex_0
// 
// Made by quentin PIDOUX
// Login   <pidoux_q@epitech.net>
// 
// Started on  Tue Jan 11 10:24:42 2011 quentin PIDOUX
// Last update Tue Jan 11 17:06:11 2011 quentin PIDOUX
//

#include "Federation.hh"
#include "Warpsystem.hh"
#include <string>
#include <iostream>

Federation::Starfleet::Ship::Ship(int length, int width, std::string name, int MaxWarp)
{
  this->_name = name;
  this->_length = length;
  this->_width = width;
  this->_maxWarp = MaxWarp;

  std::cout << "The ship USS " << this->_name << "has been finished. It is "
	    << this->_length << " m in length and " << this->_width
	    << " m in width." << std::endl << "It can go to " 
	    << this-> _maxWarp << "!" << std::endl;
}

void Federation::Starfleet::Ship::setupCore(WarpSystem::Core *Core)
{
  this->_Core = * Core;
  std::cout << "USS " << this->_name << ": The core is set." << std::endl;
}

void Federation::Starfleet::Ship::checkCore()
{
  if (this->_Core.checkReactor()->_stability == true)
    std::cout << "USS " << this->_name << ": The core is " 
	      << "stable" << " at the time." << std::endl;
  else
    std::cout << "USS " << this->_name << ": The core is " 
	      << "unstable" << " at the time." << std::endl;
}

Federation::Starfleet::Ship::~Ship()
{
}

Federation::Ship::Ship(int length, int width, std::string name)
{
  this->_name = name;
  this->_length = length;
  this->_width = width;
  this->_maxWarp = 1;

  std::cout << "The ship USS " << this->_name << "has been finished. It is "
	    << this->_length << " m in length and " << this->_width
	    << " m in width." << std::endl << "It can go to " 
	    << this-> _maxWarp << "!" << std::endl;
}

int main(void)
{
  Federation::Starfleet::Ship   UssKreog(289, 132, "Kreog", 6);
  Federation::Ship      Independant(150, 230, "Greok");
  WarpSystem::QuantumReactor QR;
  WarpSystem::QuantumReactor QR2;
  WarpSystem::Core      core(&QR);
  WarpSystem::Core      core2(&QR2);




  UssKreog.setupCore(&core);
  UssKreog.checkCore();
  Independant.setupCore(&core2);
  Independant.checkCore();

  QR.setStability(false);
  QR2.setStability(false);
  UssKreog.checkCore();
  Independant.checkCore();
  return 0;

}
