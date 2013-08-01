//
//  Nounours.cpp
//  Pere Noel
//
//  Created by Quentin Yann PIDOUX on 14/01/12.
//  Copyright rush2012. All rights reserved.
//

#include "Nounours.h"
#include <iostream>
#include <string>

Nounours::Nounours(std::string name)
  : Ajouet(name)
{
    this->setStatus(true);
    this->setType(Objet::NOUNOURS);
}

Nounours::Nounours(const Nounours &c)
:Ajouet(c.getName())
{
    this->setStatus(true);
    this->setType(Objet::NOUNOURS);
}

Nounours::~Nounours()
{
}

Nounours &Nounours::operator=(const Nounours &c)
{
    this->setName(c.getName());  
    this->setType(Objet::NOUNOURS);
    
    return *this;
}

void Nounours::estPris()
{
    if (this->getStatus() == false)
        this->setStatus(false);
    else 
    {
        this->setStatus(false);
        std::cout << "gra hu"
        << std::endl;
    }
}
