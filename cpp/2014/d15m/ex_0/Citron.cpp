//
// Citron.cpp for ex_0 in /home/pidoux_q/rendu/cpp/d15m/ex_0
// 
// Made by quentin PIDOUX
// Login   <pidoux_q@epitech.net>
// 
// Started on  Tue Jan 18 11:11:07 2011 quentin PIDOUX
// Last update Tue Jan 18 22:48:24 2011 quentin PIDOUX
//

#include "Citron.h"
#include <string>

Citron::Citron() : Fruit()
{
  this->Name = "citron";
  this->_vitamins = 3;
}

Citron::Citron(const Citron &c)
{
  this->Name = c.getName();
  this->_vitamins = c.getVitamins();
}

Citron& Citron::operator = (const Citron &c)
{
  this->Name = c.getName();
  this->_vitamins = c.getVitamins();

  return (*this);
}

Citron::~Citron()
{
}
