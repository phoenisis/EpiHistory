#include "Victim.hh"
#include "Sorcerer.hh"
#include <string>
#include <iostream>

Victim::Victim(const std::string name)
: NAME(name)
{
    std::cout << "Some random victim called " 
    << this->NAME
    << " just popped !" << std::endl;
}

Victim::Victim(const Victim & c)
{
  this->NAME = c.getName();
}

Victim::~Victim()
{
    std::cout << "Victim " 
    << this->NAME 
    << " just died for no apparent reason !"
    << std::endl;
}

Victim& Victim::operator = (Victim &b)
{
  this->NAME = b.getName();

  return (*this);
}


std::ostream &operator << (std::ostream& o, Victim & p)
{
  o << "I'm " 
    << p.getName() 
    << " and i loke otters !" 
    << std::endl;
  return o;
}

std::string Victim::getName() const
{
  return(this->NAME);
}

void Victim::getPolymorphed() const
{
  std::cout << this->NAME 
	    << " has been turned into a cute little sheep !"
	    << std::endl;
}
