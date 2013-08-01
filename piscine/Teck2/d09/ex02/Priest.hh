#ifndef _PRIEST_HH_
#define _PRIEST_HH_

#include "Character.hh"
#include "Mage.hh"
#include <iostream>
#include <string>

class Priest : virtual public Mage
{
public:
  Priest(const std::string &name, int lvl);
  ~Priest();

  void Heal();
  int CloseAttack();

protected:
  //caracteristiques

  std::string classe;
};


#endif
