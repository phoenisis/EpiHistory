//
//  ElfDePePeNoel.h
//  Pere Noel
//
//  Created by Quentin Yann PIDOUX on 14/01/12.
//  Copyright 2012 __MyCompanyName__. All rights reserved.
//

#ifndef Pere_Noel_ElfDePePeNoel_h
#define Pere_Noel_ElfDePePeNoel_h
#include "IElf.h"
#include "Objet.h"
#include "TapisRoulantPePeNoel.h"
#include "table.h"
#include "xml.h"
#include <iostream>
#include <string>

class ElfDePePeNoel: public IElf
{
private:
    Objet *mainDroite;
    Objet *mainGauche;
    TapisRoulantPePeNoel *_tapis;
    TablePePeNoel     *_table;
    
public:
    ElfDePePeNoel();
    ElfDePePeNoel(const ElfDePePeNoel *);
    ~ElfDePePeNoel();
    
    void emballeMoiCa(Objet *);
    void ouvreMoi(Objet *);
    void setMainDroite(Objet *);
    void setMainGauche(Objet *);
    Objet *getMainDroite() const;
    Objet *getMainGauche() const;
    void fermeMoi(Objet *);
    void prendre(Objet *);
    void poser(Objet *);
    Objet **regardertable();
    
    virtual void pushIn(TapisRoulantPePeNoel *);
    virtual void pushOut(TapisRoulantPePeNoel *);
    virtual void pushZwify(Objet *);
};

#endif
