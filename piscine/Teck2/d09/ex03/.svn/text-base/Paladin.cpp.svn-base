#include "Paladin.hh"
#include "Warrior.hh"
#include "Priest.hh"
#include "Character.hh"
#include <string>
#include <iostream>

Paladin::Paladin(const std::string &name, int lvl) : Warrior(name, lvl), Priest(name, lvl), Mage(name, lvl), Character(name, lvl)
{
    this->name = name;
    this->Lvl = lvl;

    this->Pv = 100;
    this->Power = 100;

    this->weaponName = "Hammer";
    this->classe = "Paladin";
    this->race = "Humain";
    this->Force = 9;
    this->Endurance = 10;
    this->Intelligence = 10;
    this->Esprit = 10;
    this->Agilite = 2;

    this->Attack = RANGE;
}

Paladin::~Paladin()
{
}

int Paladin::RangeAttack()
{
    int final = this->Esprit + 20;
  if (this->Power >= 25)
    {
      Character::Power -= 25;
      std::cout << this->name 
        << " launches a fire ball" 
		<< std::endl;
        return (final);
    }
  else 
    {
      std::cout << this->name 
        << " out of power"
		<< std::endl;
      return (0);
    }
    return 0;
}
