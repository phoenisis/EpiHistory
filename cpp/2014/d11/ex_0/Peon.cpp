//
// Peon.cpp for ex_0 in /home/pidoux_q/rendu/cpp/d11/ex_0
// 
// Made by quentin PIDOUX
// Login   <pidoux_q@epitech.net>
// 
// Started on  Fri Jan 14 13:18:13 2011 quentin PIDOUX
// Last update Mon Jan 17 20:26:18 2011 quentin PIDOUX
//

#include "Peon.hh"
#include "Victim.hh"
#include <string>
#include <iostream>

Peon::Peon(std::string name) : Victim(name)
{
  Victim::NAME = name;
  std::cout << "Zog zog." << std::endl;
}

Peon::Peon(Peon & c) : Victim(c.getName())
{
}

Peon& Peon::operator=(Peon &b)
{
  this->NAME = b.getName();

  return (*this);
}

Peon::~Peon()
{
  std::cout << "Bleuark..." << std::endl;
}

void Peon::getPolymorphed() const
{
  std::cout <<Victim::NAME 
	    <<" has been turned into a pink pony !"
	    <<std::endl;
}

std::ostream &operator << (std::ostream& o, Peon & p)
{
o << "I'm "<< p.getName()
  << ", and I like otters !" << std::endl;
  return o;
}
