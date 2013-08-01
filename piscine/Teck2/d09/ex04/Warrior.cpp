#include "Warrior.hh"
#include "Character.hh"
#include <string>
#include <iostream>

Warrior::Warrior(const std::string &name, int lvl) : Character(name, lvl)
{
    this->name = name;
    this->Lvl = lvl;

    this->Pv = 100;
    this->Power = 100;

    this->weaponName = "Hammer";
    this->classe = "Guerrier";
    this->race = "Nain";
    this->Force = 12;
    this->Endurance = 12;
    this->Intelligence = 6;
    this->Esprit = 5;
    this->Agilite = 7;

    std::cout << "I'm "
        << this->name 
        <<" KKKKKKKKKKRRRRRRRRRRRRRREEEEEEEEOOOOOOORRRRGGGGGGG" 
	    << std::endl;
    this->Attack = RANGE;
}

Warrior::~Warrior()
{
}

int Warrior::CloseAttack()
{
  int final;
  final = 20 + this->Force;

  if (this->Power >= 30)
    {
      this->Power -= 30;
      std::cout << this->name 
        << " strikes with his "
        << this->weaponName
		<< std::endl;
      return (final);
    }
  else
    {
      std::cout << Character::name 
        << " out of power"
		<< std::endl;
      return (0);
    }
}

int Warrior::RangeAttack()
{
    if (this->Attack == CLOSE)
    {
        this->Attack = RANGE;
        this->CloseAttack();
    }
    
  else if (this->Power >= 10)
    {
      this->Power -= 10;
      std::cout << this->name 
        << " intercepts" 
		<< std::endl;
        this->Attack = CLOSE;
        return (0);
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

void Warrior::Heal()
{
    int i = 0;
    
    while (i < 50 && this->Pv < 100)
    {
        this->Pv += 1;
        i++;
    }
    std::cout << this->name 
    << " takes a potion"
    << std::endl;
}

void Warrior::RestorePower()
{
  int i = 0;
  
  while (i < 100 && this->Power <= 100)
    {
      this->Power += 1 ;
      i++;
    }
    std::cout << this->name 
    << " eats" 
    << std::endl;
}