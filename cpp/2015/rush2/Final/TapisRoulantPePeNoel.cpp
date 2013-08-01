//
//  TapisRoulantPePeNoel.cpp
//  Pere Noel
//
//  Created by Quentin Yann PIDOUX on 15/01/12.
//  Copyright Rush2012. All rights reserved.
//

#include <iostream>
#include <string>
#include <ctime>
#include <cstdio>
#include <cstdlib>
#include "ITapisRoulant.h"
#include "TapisRoulantPePeNoel.h"
#include "Objet.h"
#include "PetitPoney.h"
#include "Nounours.h"
#include "PapierCadeau.h"
#include "Jouet.h"
#include "Carton.h"

Objet**			TapisRoulantPePeNoel::regardertable()
{
    return (this->OnTable);
}

Objet*			TapisRoulantPePeNoel::gettab(int i) const
{
    return (this->OnTable[i]);
}

void			TapisRoulantPePeNoel::putnewobjet(Objet *toput)
{
    int			i;
    
    for (i = 0; this->gettab(i) != NULL && i < 2; ++i)
    {
    }
    if (i < 2)
        this->~TapisRoulantPePeNoel();
    else
        this->settab(toput);
}

Objet*			TapisRoulantPePeNoel::takeObjet(int pos)
{
    Objet*       		tmp;
    
    tmp = this->OnTable[pos];
    this->OnTable[pos] = NULL;
    return (tmp);
}

void			TapisRoulantPePeNoel::settab(Objet * toput)
{
    int			i;
    
    for(i = 0; this->OnTable[i] != NULL; ++i)
    {
    }
    this->OnTable[i] = toput;
}

TapisRoulantPePeNoel::TapisRoulantPePeNoel()
{    
    std::cerr << "Nouveau tapis qui bouge" << std::endl;
}

TapisRoulantPePeNoel::TapisRoulantPePeNoel(const TapisRoulantPePeNoel &other)
{
    int			i;
    
    if(this != &other)
    {
        this->OnTable = new Objet*[2];
        for(i = 0; i <= 2; ++i)
            this->OnTable[i] = other.gettab(i);
    }
}

TapisRoulantPePeNoel::~TapisRoulantPePeNoel()
{
    int			i;
    
    std::cerr << "*#TtzZzZz#* Il y a trop de cadeaux !" << std::endl;
    for (i = 0; i <= 2; ++i)
        delete this->OnTable[i];
    delete[] this->OnTable;
}

TapisRoulantPePeNoel& TapisRoulantPePeNoel::operator=(TapisRoulantPePeNoel const & other)
{
    int			i;
    
    if (&other != this)
    {
        if (this->OnTable)
            delete[] this->OnTable;	
        this->OnTable = new Objet*[2];
        for(i = 0; other.gettab(i) != NULL; ++i)
            this->OnTable[i] = other.gettab(i);
        this->OnTable[i] = NULL;
    }
    return (*this);
}

void TapisRoulantPePeNoel::pushButonIn() 
{
    srand(time(NULL));
    long i = random()%2;
    
    if (regardertable() == NULL)
    {
        if (i == 0)
            this->putnewobjet(new Carton());
        else 
            this->putnewobjet(new PapierCadeau());
    }
    else
        std::cerr << "Le tapis est deja plein"
        << std::endl;
}

void TapisRoulantPePeNoel::pushButonOut()
{
    if (regardertable() != NULL)
    {
        this->takeObjet(0);
    }
}