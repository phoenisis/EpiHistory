#ifndef _SORCERER_HH_
#define _SORCERER_HH_
#include <string>
#include <iostream>
#include "Victim.hh"

class Sorcerer
{
protected:
    std::string NAME;
    std::string TITLE;
    
public:
    explicit Sorcerer(const std::string NAME, const std::string TITLE);
    Sorcerer(const Sorcerer &);
    ~Sorcerer();
    Sorcerer& operator = (Sorcerer &b);
    std::string getName() const;
    std::string getTitle() const;
    
    void polymorph(Victim const &) const; 
};

std::ostream &operator << (std::ostream&, Sorcerer &);

#endif
