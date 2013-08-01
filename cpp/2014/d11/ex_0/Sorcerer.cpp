//
// Sorcerer.cpp for ex_0 in /home/pidoux_q/rendu/cpp/d11/ex_0
// 
// Made by quentin PIDOUX
// Login   <pidoux_q@epitech.net>
// 
// Started on  Fri Jan 14 11:47:17 2011 quentin PIDOUX
// Last update Fri Jan 14 16:20:59 2011 quentin PIDOUX
//

#include "Sorcerer.hh"
#include <string>
#include <iostream>

Sorcerer::Sorcerer(std::string NAME, std::string TITLE)
{
  this->NAME = NAME;
  this->TITLE = TITLE;
  std::cout <<this->NAME <<", " <<this->TITLE
	    << ", is born !" << std::endl;
}

Sorcerer::Sorcerer(Sorcerer & Sor)
{
  this->NAME = Sor.getName();
  this->TITLE = Sor.getTitle();
}

Sorcerer& Sorcerer::operator = (Sorcerer &b)
{
  this->NAME = b.getName();
  this->TITLE = b.getTitle();

  return (*this);
}

Sorcerer::~Sorcerer()
{
  std::cout << this->NAME<< ", "
	    << this->TITLE<<", is dead. Consequences will never be the same !"
	    << std::endl;
}

std::string Sorcerer::getName()
{
  return (this->NAME);
}

std::string Sorcerer:: getTitle()
{
  return (this->TITLE);
}

std::ostream &operator << (std::ostream& o, Sorcerer & p)
{
  o << "I am "<< p.getName() << ", " << p.getTitle()
    << ", and I like ponies !" << std::endl;
  return o;
}

void Sorcerer::polymorph(Victim::Victim const & V) const
{
  V.getPolymorphed();
}
