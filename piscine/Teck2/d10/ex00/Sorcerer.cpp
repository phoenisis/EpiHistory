#include "Sorcerer.hh"
#include <string>
#include <iostream>

Sorcerer::Sorcerer(const std::string name, const std::string tittle) 
: NAME(name), TITLE(tittle)
{

  std::cout << this->NAME 
    <<", " 
    << this->TITLE
    << ", is born !" 
    << std::endl;
}

Sorcerer::Sorcerer(const Sorcerer & Sor)
{
  this->NAME = Sor.getName();
  this->TITLE = Sor.getTitle();
}

Sorcerer::~Sorcerer()
{
    std::cout << this->NAME<< ", "
    << this->TITLE<<", is dead. Consequences will never be the same !"
    << std::endl;
}

Sorcerer& Sorcerer::operator = (Sorcerer &b)
{
  this->NAME = b.getName();
  this->TITLE = b.getTitle();

  return (*this);
}

std::string Sorcerer::getName() const
{
  return (this->NAME);
}

std::string Sorcerer:: getTitle() const
{
  return (this->TITLE);
}

void Sorcerer::polymorph(Victim::Victim const & V) const
{
    V.getPolymorphed();
}

std::ostream &operator << (std::ostream& o, Sorcerer & p)
{
  o << "I am "
    << p.getName() 
    << ", " 
    << p.getTitle()
    << ", and I like ponies !" 
    << std::endl;
  return o;
}
