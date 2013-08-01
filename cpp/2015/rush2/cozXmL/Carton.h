//
//  Carton.h
//  Pere Noel
//
//  Created by Quentin Yann PIDOUX on 14/01/12.
//  Copyright 2012 __MyCompanyName__. All rights reserved.
//

#ifndef Pere_Noel_Carton_h
#define Pere_Noel_Carton_h
#include "Emballage.h"
#include <iostream>
#include <string>

class	Carton : public Emballage
{
    bool		_open;
    
    public :
    Carton();
    Carton(const Carton&);
    ~Carton();
    Carton&	operator=(const Carton&);
    virtual bool	isOpen() const;
    virtual void	setOpen(bool);
    virtual void	emballeMoiCa(Objet*);
};


#endif
