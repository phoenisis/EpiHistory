//
//  TapisRoulantPePeNoel.h
//  Pere Noel
//
//  Created by Quentin Yann PIDOUX on 15/01/12.
//  Copyright Rush2012. All rights reserved.
//

#ifndef test_TapisRoulantPePeNoel_h
#define test_TapisRoulantPePeNoel_h
#include "Objet.h"
#include "ITapisRoulant.h"
#include <iostream>
#include <string>

class TapisRoulantPePeNoel: public ITapisRoulant
{
private:
    Objet **OnTable;
    
public:
    TapisRoulantPePeNoel();
    TapisRoulantPePeNoel(const TapisRoulantPePeNoel&);
    ~TapisRoulantPePeNoel();
    virtual Objet** regardertable();
    virtual Objet *gettab(int i) const;
    virtual void putnewobjet(Objet *toput);
    virtual Objet* takeObjet(int pos);
    virtual void settab(Objet *toput);
    TapisRoulantPePeNoel& operator=(TapisRoulantPePeNoel const& other);
    virtual void pushButonIn();
    virtual void pushButonOut();
};

#endif
