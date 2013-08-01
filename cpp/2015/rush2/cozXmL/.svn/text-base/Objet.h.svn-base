//
//  Objet.h
//  Pere Noel
//
//  Created by Quentin Yann PIDOUX on 14/01/12.
//  Copyright rush2012. All rights reserved.
//

#ifndef Pere_Noel_Objet_h
#define Pere_Noel_Objet_h
#include <iostream>
#include <string>

class Objet
{
private:
    bool _Status;

protected:
    Objet		*_in;
    
public:
    typedef enum
    {
        JOUET = 0,
        CARTON,
        PAPIERCADEAU,
        NOUNOURS,
        PETITPONEY
    } Type;
    
    virtual ~Objet();
    virtual void estPris();
    bool getStatus() const;
    void setStatus(const int);
    Type getType() const;
    virtual std::string getName() const;
    virtual void setName(const std::string);
    virtual void setType(Type);
    virtual void emballeMoiCa(Objet*);
    virtual void ouvreMoi();
    virtual bool isEmpty() const;
    virtual bool isOpen() const;
    virtual void setOpen(bool);
    virtual Objet *getIn() const;
    virtual void setIn(Objet *);

private:
    Type _type;
};

#endif
