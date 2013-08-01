//
//  ElfDePePeNoel.cpp
//  Pere Noel
//
//  Created by Quentin Yann PIDOUX on 14/01/12.
//  Copyright Rush2012. All rights reserved.
//

#include "ElfDePePeNoel.h"
#include "IElf.h"
#include "Emballage.h"
#include "Objet.h"
#include "Carton.h"
#include "Jouet.h"
#include "xml.h"
#include <iostream>
#include <string>

void ElfDePePeNoel::emballeMoiCa(Objet *c)
{
    if (c->isEmpty() == true)
        std::cerr << "Le cadeau est vide, il vaudrait mieux le remplire."
            << std::endl;
    else 
        c->setIn(c);
}

ElfDePePeNoel::ElfDePePeNoel()
:   mainDroite(NULL),
    mainGauche(NULL)
{
}

Objet *ElfDePePeNoel::getMainGauche() const
{
    return this->mainGauche;
}

Objet *ElfDePePeNoel::getMainDroite() const
{
    return this->mainDroite;
}

ElfDePePeNoel::ElfDePePeNoel(const ElfDePePeNoel *c)
{
    this->mainDroite = c->getMainDroite();
    this->mainGauche = c->getMainDroite();
}

ElfDePePeNoel::~ElfDePePeNoel()
{
}

void ElfDePePeNoel::ouvreMoi(Objet *c)
{
    c->setOpen(true);
}

void ElfDePePeNoel::fermeMoi(Objet *c)
{
  std::cout << "tuuuut tuuut tuut" << std::endl;
    c->setOpen(false);
}

void ElfDePePeNoel::setMainDroite(Objet *c)
{
    this->mainDroite = c;
}

void ElfDePePeNoel::setMainGauche(Objet *c)
{
    this->mainGauche = c;
}

void ElfDePePeNoel::prendre(Objet *c)
{
 if (this->mainDroite == NULL || this->mainGauche == NULL)
 {
   std::cout << "siffle en travaillant" << std::endl;
     if (this->mainDroite == NULL)
         this->setMainDroite(c);
     else 
         this->setMainGauche(c);         
 }
    else 
        std::cerr << "Oups j'ai les mains prises o_0'"
        << std::endl;
}

void ElfDePePeNoel::poser(Objet *c)
{
    if (c->getType() == Objet::PAPIERCADEAU)
    {
        while(c->getIn())
            c = c->getIn();
        if (c->getType() == 3 || c->getType() == 4)
            this->_tapis->putnewobjet(c);
    }
    else
        this->_table->putnewobjet(c);
}

Objet **ElfDePePeNoel::regardertable()
{
    return(this->_table->regardertable());
}

void ElfDePePeNoel::pushIn(TapisRoulantPePeNoel *c)
{
    c->pushButonIn();
}

void ElfDePePeNoel::pushOut(TapisRoulantPePeNoel *c)
{
    c->pushButonOut();
}

void ElfDePePeNoel::pushZwify(Objet *c)
{
    creacadeau(c);
}
