//
// Character.cpp for ex_0 in /home/pidoux_q/rendu/cpp/d10/ex_0
// 
// Made by quentin PIDOUX
// Login   <pidoux_q@epitech.net>
// 
// Started on  Thu Jan 13 17:15:06 2011 quentin PIDOUX
// Last update Thu Jan 13 23:07:10 2011 quentin PIDOUX
//

#include "Character.hh"
#include "Warrior.hh"
#include <string>
#include <iostream>

Character::Character(std::string name, int lvl)
{
  this->name = name;
  this->Lvl = lvl;

  this->Pv = 100;
  this->Power = 100;

  this->race = "Koala";
  this->Force = 5;
  this->Endurance = 5;
  this->Intelligence = 5;
  this->Esprit = 5;
  this->Agilite = 5;

  std::cout << this->name << " Created" << std::endl;
}

Character::~Character()
{
}

const std::string& Character::getName() const
{
  return (this->name);
}

int Character::getLvl() const
{
  return (this->Lvl);
}

int Character::getPv() const
{
  return (this->Pv);
}

int Character::getPower() const
{
  return (this->Power);
}

int Character::CloseAttack()
{
  int final;
  final = 10 + this->Force;

  if (this->Power >= 10)
    {
      this->Power = this->Power - 10;
      std::cout << this->name << " strikes with a wood stick"
		<< std::endl;
      return (final);
    }
  else
    {
      std::cout << this->name << " out of power"
		<< std::endl;
      return (0);
    }
}

int Character::RangeAttack()
{
  int final;
  final = 5 + this->Force;

 if (this->Power >= 10)
   {
      this->Power = this->Power - 10;
      std::cout << this->name << " launchs a stone" 
		<< std::endl;
      return (final);
    }
 else 
   {
     std::cout << this->name << " out of power"
	       << std::endl;
     return (0);
   }
}

void Character::Heal()
{
  int i = 0;

  while (i < 50 || this->Pv <= 100)
    {
      this->Pv = this->Pv + 1 ;
      i++;
    }
  std::cout << this->name << " takes a potion" 
	    << std::endl;
}

void Character::RestorePower()
{
int i = 0;

  while (i < 100 || this->Power <= 100)
    {
      this->Pv = this->Power + 1 ;
      i++;
    }
  std::cout << this->name << " eats" 
	    << std::endl;
}

void Character::TakeDamage(int _damage)
{
  this->Pv = this->Pv - _damage;
  if (this->Pv > 0)
    std::cout << this->name << " takes " << _damage << " damage"
	      << std::endl;
  else
    std::cout << this->name << " out of combat"
	      << std::endl;
}
