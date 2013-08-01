//
// Woody.cpp for ex_2 in /home/pidoux_q/rendu/cpp/d14/ex_2
// 
// Made by quentin PIDOUX
// Login   <pidoux_q@epitech.net>
// 
// Started on  Mon Jan 17 15:15:01 2011 quentin PIDOUX
// Last update Mon Jan 17 19:36:10 2011 quentin PIDOUX
//

#include "Woody.h"
#include "Toy.h"
#include <string>

Woody::Woody()
{
}

Woody::Woody(const Woody &c) : Toy()
{
  this->Type = c.getType();
  this->Name = c.getName();
}

Woody::Woody(const std::string &name)
{
  this->Name = name;
  this->Type = Toy::WOODY;
}

Woody Woody::operator = (const Woody&c)
{
  this->Type = c.getType();
  this->Name = c.getName();

  return (*this);
}

Woody::Woody(const std::string &name, const std::string &ASCII)
{
  this->Type = Toy::WOODY;
  this->Name = name;
  this->ASCII.getPictureFromFile(ASCII); 
}

Woody::~Woody()
{
}
