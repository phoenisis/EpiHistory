#include "Mage.hh"
#include <string>
#include <iostream>


Mage::Mage(const std::string &name, int lvl) : Character(name, lvl)
{
  this->name = name;
  this->Lvl = lvl;

  this->Pv = 100;
  this->Power = 100;

  this->classe = "Mage";
  this->race = "Gnome";
  this->Force = 6;
  this->Endurance = 6;
  this->Intelligence = 12;
  this->Esprit = 11;
  this->Agilite = 7;

  std::cout << this->name 
	    << " teleported" 
	    << std::endl;
}

Mage::~Mage()
{
}

int Mage::CloseAttack()
{
  if (this->Power >= 10)
    {
      this->Power -= 10;
      std::cout << this->name 
        << " blinks"
		<< std::endl;
        this->Attack = RANGE;
      return (0);
    }
  else
    {
      std::cout << this->name 
        << " out of power"
		<< std::endl;
      return (0);
    }
}

int Mage::RangeAttack()
{
  int final;
  final = 20 + this->Intelligence;
  if (this->Power >= 25)
    {
      this->Power -= 25;
      std::cout << this->name 
        << " launches a fire ball" 
		<< std::endl;
      return (0);
    }
  else 
    {
      std::cout << this->name 
        << " out of power"
		<< std::endl;
      return (0);
    }
}

void Mage::Heal()
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

void Mage::RestorePower()
{
  int i = 0;
  
  while (i < (50 + this->Intelligence)  && this->Power < 100)
    {
      this->Power += 1 ;
      i++;
    }
  std::cout << this->name 
         << " eats" 
         << std::endl;
}