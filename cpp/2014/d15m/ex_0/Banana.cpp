//
// Banana.cpp for ex_0 in /home/pidoux_q/rendu/cpp/d15m/ex_0
// 
// Made by quentin PIDOUX
// Login   <pidoux_q@epitech.net>
// 
// Started on  Tue Jan 18 11:10:54 2011 quentin PIDOUX
// Last update Tue Jan 18 22:47:24 2011 quentin PIDOUX
//

#include "Banana.h"
#include <string>

Banana::Banana() : Fruit()
{
  this->Name = "banana";
  this->_vitamins = 5;
}

Banana::Banana(const Banana& c)
{
  this->Name = c.getName();
  this->_vitamins = c.getVitamins();
}

Banana& Banana::operator = (const Banana& c)
{
  this->Name = c.getName();
  this->_vitamins = c.getVitamins();

  return (*this);
}

Banana::~Banana()
{
}
