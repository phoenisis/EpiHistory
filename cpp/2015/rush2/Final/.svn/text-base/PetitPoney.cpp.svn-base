//
//  PetitPoney.cpp
//  Pere Noel
//
//  Created by Quentin Yann PIDOUX on 14/01/12.
//  Copyright Rush2012. All rights reserved.
//

#include "PetitPoney.h"
#include "Jouet.h"
#include <iostream>

PetitPoney::PetitPoney(std::string name)
:Ajouet(name)
{
    this->setStatus(true);
    this->setType(Objet::PETITPONEY);
}

PetitPoney::PetitPoney(const PetitPoney &c)
:Ajouet(c.getName())
{
    this->setStatus(true);
    this->setType(Objet::PETITPONEY);
}

PetitPoney::~PetitPoney()
{
}

PetitPoney &PetitPoney::operator=(const PetitPoney &c)
{
    this->setName(c.getName());
    this->setType(Objet::PETITPONEY);

    return *this;
}

void PetitPoney::estPris()
{
    if (this->getStatus() == false)
        this->setStatus(false);
    else 
    {
        this->setStatus(false);
        std::cout << "yo man"
        << std::endl;
    }
}
