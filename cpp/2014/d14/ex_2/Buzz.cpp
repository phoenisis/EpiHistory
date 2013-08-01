//
// Buzz.cpp for ex_2 in /home/pidoux_q/rendu/cpp/d14/ex_2
// 
// Made by quentin PIDOUX
// Login   <pidoux_q@epitech.net>
// 
// Started on  Mon Jan 17 14:51:05 2011 quentin PIDOUX
// Last update Tue Jan 18 08:26:21 2011 quentin PIDOUX
//

#include "Buzz.h"
#include "Toy.h"
#include <string>

Buzz::Buzz() : Toy()
{
}

Buzz::Buzz(const Buzz &c) :Toy()
{
  this->Type = c.getType();
  this->Name = c.getName();
}

Buzz Buzz::operator = (const Buzz&c)
{
  this->Type = c.getType();
  this->Name = c.getName();

  return (*this);
}

Buzz::Buzz(const std::string &name, std::string const &ASCII)
{
  this->Type = Toy::BUZZ;
  this->Name = name;
  this->ASCII.getPictureFromFile(ASCII); 
}

Buzz::~Buzz()
{
}
