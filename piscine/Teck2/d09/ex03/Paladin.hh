#ifndef _PALADIN_HH_
#define _PALADIN_HH_

#include "Warrior.hh"
#include "Priest.hh"
#include "Character.hh"
#include <iostream>
#include <string>

class Paladin : virtual public Warrior, public Priest
{
private:
    std::string weaponName;

public:
     explicit Paladin(const std::string &name, int lvl);
    ~Paladin();

  using Warrior::CloseAttack;
  int RangeAttack();
  using Priest::Heal;
  using Mage::RestorePower;

protected:
  //caracteristiques
    std::string classe;
};

#endif
