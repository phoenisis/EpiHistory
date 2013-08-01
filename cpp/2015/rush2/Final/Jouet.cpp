//
//  Jouet.cpp
//  Pere Noel
//
//  Created by Quentin Yann PIDOUX on 14/01/12.
//  Copyright rush2012. All rights reserved.
//

#include "Objet.h"
#include "Jouet.h"
#include <iostream>
#include <string>

Ajouet::Ajouet(std::string name)
: _Name(name)
{
}

Ajouet::Ajouet(const Ajouet &c)
: _Name(c.getName())
{
  this->setType(c.getType());
}

Ajouet::~Ajouet()
{
}

Ajouet &Ajouet::operator=(const Ajouet &c)
{
  if (this != &c)
    {
      this->_Name = c.getName();
      this->setType(c.getType());
    }
  return *this;
}

std::string Ajouet::getName() const
{
    return this->_Name;
}

void Ajouet::setName(const std::string name)
{
    this->_Name = name;
}
