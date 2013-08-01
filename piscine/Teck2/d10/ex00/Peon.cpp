#include "Peon.hh"
#include "Victim.hh"
#include <string>
#include <iostream>

Peon::Peon(const std::string name) : Victim(name)
{
    this->NAME = name;
    std::cout << "Zog zog." 
    << std::endl;
}

Peon::Peon(const Peon & c) : Victim(c.getName())
{
}

Peon& Peon::operator=(Peon &b)
{
  this->NAME = b.getName();

  return (*this);
}

Peon::~Peon()
{
    std::cout << "Bleuark..." 
    << std::endl;
}

void Peon::getPolymorphed() const
{
    std::cout << this->NAME 
    << " has been turned into a pink poney !"
    << std::endl;
}

std::ostream &operator << (std::ostream& o, Peon & p)
{
o << "I'm "<< p.getName()
  << ", and I like otters !" << std::endl;
  return o;
}
