//
//  Carton.cpp
//  Pere Noel
//
//  Created by Quentin Yann PIDOUX on 14/01/12.
//  Copyright Rush2012. All rights reserved.
//

#include "Carton.h"
#include <iostream>

Carton::Carton() : _open(true)
{
  this->setType(Objet::CARTON);
}

Carton::Carton(const Carton& other)
{
    this->_open = other.isOpen();
    this->setIn(other.getIn());
    this->setType(other.getType());
}


Carton::~Carton()
{
}

Carton&		Carton::operator=(const Carton& other)
{
    if (this != &other)
    {
        this->_open = other.isOpen();
        this->setIn(other.getIn());
	this->setType(other.getType());
    }
    return *this;
}

bool		Carton::isOpen() const
{
    return (this->_open);
}

void		Carton::setOpen(bool status)
{
    this->_open = status;
}

void		Carton::emballeMoiCa(Objet *aEmballer)
{
  if (this->isOpen())
    if (this->_in == NULL)
      {
	this->_in = aEmballer;
	this->setOpen(false);
      }
    else
      std::cout << "Le Carton est deja plein" << std::endl;
  else
    std::cout << "Le Carton est ferme" << std::endl;
}
