//
//  Objet.cpp
//  Pere Noel
//
//  Created by Quentin Yann PIDOUX on 14/01/12.
//  Copyright rush2012. All rights reserved.
//

#include "Objet.h"
#include <iostream>
#include <string>

Objet::~Objet()
{
}

void Objet::estPris()
{
    if (this->getStatus() == false)
        this->setStatus(false);
    else 
        (this->setStatus(true));
}

bool Objet::getStatus() const
{
    return this->_Status;
}

void Objet::setStatus(const int stat)
{
    this->_Status = stat;
}

Objet::Type Objet::getType() const
{
  return (this->_type);
}

void Objet::setType(Type type)
{
    this->_type = type;   
}

std::string Objet::getName() const
{
  return ("");
}

void Objet::setName(const std::string name)
{
  (void)name;
}

void Objet::emballeMoiCa(Objet *co)
{
    (void)co;
}

void Objet::ouvreMoi()
{
}

bool Objet::isEmpty() const
{
    return true;
}

bool Objet::isOpen() const
{
    return true;
}

void Objet::setOpen(bool c)
{
    this->_Status = c;
}

Objet *Objet::getIn() const
{
    return this->_in;
}

void Objet::setIn(Objet *c)
{
    if(this->_in)
        delete _in;
    this->_in = c;
}
