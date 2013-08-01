//
// Victim.cpp for ex_0 in /home/pidoux_q/rendu/cpp/d11/ex_0
// 
// Made by quentin PIDOUX
// Login   <pidoux_q@epitech.net>
// 
// Started on  Fri Jan 14 12:51:39 2011 quentin PIDOUX
// Last update Fri Jan 14 16:20:59 2011 quentin PIDOUX
//

#include "Victim.hh"
#include <string>
#include <iostream>

Victim::Victim(std::string NAME)
{
  this->NAME = NAME;
  std::cout <<"Some random victim called " <<this->NAME
	    << " just popped !" << std::endl;
}

Victim::Victim(Victim & c)
{
  this->NAME = c.getName();
}

Victim& Victim::operator = (Victim &b)
{
  this->NAME = b.getName();

  return (*this);
}

Victim::~Victim()
{
  std::cout << "Victim " << this->NAME 
	    << " just died for no apparent reason !"
	    << std::endl;
}

std::ostream &operator << (std::ostream& o, Victim & p)
{
  o << "I'm " << p.getName() << " and i loke otters !" << std::endl;
  return o;
}

std::string Victim::getName()
{
  return(this->NAME);
}

void Victim::getPolymorphed() const
{
  std::cout <<this->NAME 
	    <<" has been turned into a cute little sheep !"
	    <<std::endl;
}
