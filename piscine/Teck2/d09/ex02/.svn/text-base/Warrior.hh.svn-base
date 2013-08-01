#ifndef _WARRIOR_HH_
#define _WARRIOR_HH_

#include "Character.hh"
#include <iostream>
#include <string>

class Warrior :virtual public Character
{
private:
    std::string weaponName;

public:
     Warrior(const std::string &name, int lvl);
    ~Warrior();

    int CloseAttack();
    int RangeAttack();
    void Heal();
    void RestorePower();

protected:
  //caracteristiques
    std::string classe;
};

#endif
