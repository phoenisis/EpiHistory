//
// Peon.hh for ex_0 in /home/pidoux_q/rendu/cpp/d11/ex_0
// 
// Made by quentin PIDOUX
// Login   <pidoux_q@epitech.net>
// 
// Started on  Fri Jan 14 13:18:23 2011 quentin PIDOUX
// Last update Mon Jan 17 19:51:51 2011 quentin PIDOUX
//

#ifndef _PEON_HH_
#define _PEON_HH_
#include <string>
#include "Victim.hh"


class Peon : public Victim
{
public:
  Peon(std::string NAME);
  Peon(Peon &);
  Peon& operator=(Peon &b);
  ~Peon();
  virtual void getPolymorphed() const;

};
std::ostream &operator << (std::ostream&, Toy &);

#endif
