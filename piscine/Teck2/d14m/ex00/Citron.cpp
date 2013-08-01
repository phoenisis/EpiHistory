#include "Citron.h"
#include <string>

Citron::Citron() : Fruit()
{
  this->Name = "citron";
  this->_vitamins = 3;
}

Citron::Citron(const Citron &c)
:Fruit()
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
