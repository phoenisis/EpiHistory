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
