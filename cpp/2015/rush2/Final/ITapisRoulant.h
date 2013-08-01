//
//  ITapisRoulant.h
//  Pere Noel
//
//  Created by Quentin Yann PIDOUX on 15/01/12.
//  Copyright Rush2012. All rights reserved.
//

#ifndef test_ITapisRoulant_h
#define test_ITapisRoulant_h
#include "Objet.h"
#include <iostream>
#include <string>

class ITapisRoulant
{
public:
    virtual ~ITapisRoulant() {};
    virtual Objet **regardertable() = 0;
    virtual Objet *gettab(int i) const = 0;
    virtual void putnewobjet(Objet *toput) = 0;
    virtual Objet* takeObjet(int pos) = 0;
    virtual void settab(Objet *toput) = 0;
};


#endif
