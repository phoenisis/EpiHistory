#ifndef _PEON_HH_
#define _PEON_HH_
#include <string>
#include "Victim.hh"
#include "Sorcerer.hh"

class Peon : public Victim
{
    public:
    Peon(const std::string NAME);
    Peon(const Peon &);
    ~Peon();
    Peon& operator=(Peon &b);
    virtual void getPolymorphed() const;
    using Victim::getName;
};
std::ostream &operator << (std::ostream&, Peon &);

#endif
