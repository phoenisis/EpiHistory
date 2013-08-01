//
// Sorcerer.hh for ex_0 in /home/pidoux_q/rendu/cpp/d11/ex_0
// 
// Made by quentin PIDOUX
// Login   <pidoux_q@epitech.net>
// 
// Started on  Fri Jan 14 11:45:28 2011 quentin PIDOUX
// Last update Fri Jan 14 16:20:59 2011 quentin PIDOUX
//

#ifndef _SORCERER_HH_
#define _SORCERER_HH_
#include <string>
#include <iostream>
#include "Victim.hh"

class Sorcerer
{
public:
  Sorcerer(std::string NAME, std::string TITLE);
  Sorcerer(Sorcerer &);
  Sorcerer& operator = (Sorcerer &b);
  ~Sorcerer();
  std::string getName();
  std::string getTitle();
  void polymorph(Victim const &) const; 
protected:
  std::string NAME;
  std::string TITLE;
};

std::ostream &operator << (std::ostream&, Sorcerer &);

#endif
