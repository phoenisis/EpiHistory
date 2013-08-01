//
// Fruit.cpp for ex_0 in /home/pidoux_q/rendu/cpp/d15m/ex_0
// 
// Made by quentin PIDOUX
// Login   <pidoux_q@epitech.net>
// 
// Started on  Tue Jan 18 10:54:56 2011 quentin PIDOUX
// Last update Wed Jan 19 08:23:07 2011 quentin PIDOUX
//

#include "Fruit.h"
#include <string>

Fruit::Fruit()
{
}

Fruit::Fruit(const Fruit& c)
{
  this->Name = c.getName();
  this->_vitamins = c.getVitamins();
}

Fruit& Fruit::operator = (const Fruit &c)
{
  this->Name = c.getName();
  this->_vitamins = c.getVitamins();

  return (*this); 
}

Fruit::~Fruit()
{
}

int Fruit::getVitamins() const
{
  return (this->_vitamins);
}

std::string Fruit::getName() const
{
  return (this->Name);
}
