//
//  IElf.h
//  Pere Noel
//
//  Created by Quentin Yann PIDOUX on 14/01/12.
//  Copyright Rush2012. All rights reserved.
//

#ifndef Pere_Noel_IElf_h
#define Pere_Noel_IElf_h
#include "Emballage.h"
#include "TapisRoulantPePeNoel.h"
#include "Objet.h"
#include <iostream>
#include <string>


class IElf 
{
public:
    virtual ~IElf() {};

    virtual void emballeMoiCa(Objet *) = 0;
    virtual void ouvreMoi(Objet *) = 0;
    virtual void fermeMoi(Objet *) = 0;
    
    virtual void pushIn(TapisRoulantPePeNoel *) = 0;
    virtual void pushOut(TapisRoulantPePeNoel *) = 0;
    virtual Objet **regarderTable() = 0;
    
};

#endif
