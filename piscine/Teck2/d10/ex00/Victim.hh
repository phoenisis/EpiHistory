#ifndef _VICTIM_HH_
#define _VICTIM_HH_
#include <string>
#include <iostream>

class Victim
{
    
protected: 
    std::string NAME;
    
public:
  Victim(const std::string NAME);
  Victim(const Victim &);
  Victim& operator=(Victim &b);
  ~Victim();
  std::string getName()const;
  virtual void getPolymorphed() const;
};

std::ostream &operator << (std::ostream&, Victim &);

#endif
