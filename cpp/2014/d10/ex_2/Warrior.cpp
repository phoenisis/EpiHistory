//
// Warrior.cpp for ex_1 in /home/pidoux_q/rendu/cpp/d10/ex_1
// 
// Made by quentin PIDOUX
// Login   <pidoux_q@epitech.net>
// 
// Started on  Thu Jan 13 18:18:45 2011 quentin PIDOUX
// Last update Thu Jan 13 23:07:08 2011 quentin PIDOUX
//

#include "Warrior.hh"
#include "Character.hh"
#include <string>
#include <iostream>

Warrior::Warrior(std::string name, int lvl, std::string Weapon) : Character(name, lvl)
{
  Character::name = name;
  Character::Lvl = lvl;
  this->Weapon = Weapon;

  Character::Pv = 100;
  Character::Power = 100;

  this->classe = "Guerrier";
  Character::race = "Nain";
  Character::Force = 12;
  Character::Endurance = 12;
  Character::Intelligence = 6;
  Character::Esprit = 5;
  Character::Agilite = 7;

  std::cout << this->name 
	    << " KKKKKKKKKKRRRRRRRRRRRRRREEEEEEEEOOOOOOORRRRGGGGGGG" 
	    << std::endl;
}

Warrior::~Warrior()
{
}

int Warrior::CloseAttack()
{
  int final;
  final = 20 + Character::Force;

  if (Character::Power >= 30)
    {
      Character::Power = Character::Power - 30;
      std::cout << Character::name << " strikes with a wood " << this->Weapon
		<< std::endl;
      return (final);
    }
  else
    {
      std::cout << Character::name << " out of power"
		<< std::endl;
      return (0);
    }
}

int Warrior::RangeAttack()
{
  int final;
  final = 0;
  if (Character::Power >= 10)
    {
      Character::Power = Character::Power - 10;
      std::cout << Character::name << " intercepts" 
		<< std::endl;
      Warrior::CLOSE;
      return (0);
    }
  else 
    {
      std::cout << Character::name << " out of power"
		<< std::endl;
      return (0);
    }
}

void Warrior::RestorePower()
{
  int i = 0;
  
  while (i < 100 || this->Pv <= 100)
    {
      Character::Pv = Character::Pv + 1 ;
      i++;
    }
  std::cout << Character::name << " eats" 
	    << std::endl;
}

