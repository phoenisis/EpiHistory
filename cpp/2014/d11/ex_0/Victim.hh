//
// Victim.hh for ex_0 in /home/pidoux_q/rendu/cpp/d11/ex_0
// 
// Made by quentin PIDOUX
// Login   <pidoux_q@epitech.net>
// 
// Started on  Fri Jan 14 12:48:28 2011 quentin PIDOUX
// Last update Fri Jan 14 16:20:57 2011 quentin PIDOUX
//

#ifndef _VICTIM_HH_
#define _VICTIM_HH_
#include <string>
#include <iostream>

class Victim
{
public:
  Victim(std::string NAME);
  Victim(Victim &);
  Victim& operator=(Victim &b);
  ~Victim();
  std::string getName();
  virtual void getPolymorphed() const;
protected: 
  std::string NAME;
};

std::ostream &operator << (std::ostream&, Victim &);

#endif
