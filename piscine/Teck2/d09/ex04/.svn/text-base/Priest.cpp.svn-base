#include "Character.hh"
#include "Priest.hh"
#include <string>
#include <iostream>


Priest::Priest(const std::string &name, int lvl) : Mage(name, lvl), Character(name, lvl)
{
  this->name = name;
  this->Lvl = lvl;

  this->Pv = 100;
  this->Power = 100;

  this->classe = "Pretre";
  this->race = "Orc";
  this->Force = 4;
  this->Endurance = 4;
  this->Intelligence = 42;
  this->Esprit = 21;
  this->Agilite = 2;

  std::cout << this->name 
	    << " enters in the order" 
	    << std::endl;
}

Priest::~Priest()
{
}

int Priest::CloseAttack()
{
  int final;
  final = 10 + this->Intelligence;

  if (this->Power >= 10)
    {
      this->Power -= 10;
      std::cout << this->name 
        << " uses a spirit explosion"
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
}

void Priest::Heal()
{
  int i = 0;
  if (this->Power >= 10)
    {
        while (i < 70 && this->Pv < 100)
        {
            this->Pv += 1;
            i++;
        }
        std::cout << this->name 
        << " cast a little heal spell"
		<< std::endl;
    }
  else
    {
      std::cout << this->name 
        << " out of power" 
		<< std::endl;
    }
}