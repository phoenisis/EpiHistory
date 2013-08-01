#ifndef _MAGE_HH_
#define _MAGE_HH_

#include "Character.hh"
#include <iostream>
#include <string>

class Mage : virtual public Character
{
public:
  Mage(const std::string &name, int lvl);
  ~Mage();

  int CloseAttack();
  int RangeAttack();
  void Heal();
  void RestorePower();

protected:
  //caracteristiques

  std::string classe;
};

#endif
