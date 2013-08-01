#include "Banana.h"
#include <string>

Banana::Banana() : Fruit()
{
  this->Name = "banana";
  this->_vitamins = 5;
}

Banana::Banana(const Banana& c)
:Fruit()
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
