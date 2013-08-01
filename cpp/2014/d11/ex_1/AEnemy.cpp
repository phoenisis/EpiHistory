//
// AEnemy.cpp for ex_1 in /home/pidoux_q/rendu/cpp/d11/ex_1
// 
// Made by quentin PIDOUX
// Login   <pidoux_q@epitech.net>
// 
// Started on  Fri Jan 14 16:53:21 2011 quentin PIDOUX
// Last update Fri Jan 14 16:59:59 2011 quentin PIDOUX
//

#include "AEnemy.hh"
#include <string>
#include <iostream>

AEnemy::AEnemy(int hp, std::string const & type)
{
  this->hp = hp;
  this->type = type;
}

AEnemy::~AEnemy()
{
}

std::string  AEnemy::getType() const
{
  return (this->type);
}

int AEnemy::getHP() const
{
  return (this->hp);
}

virtual void AEnemy::takeDamage(int)
{
  if (this->hp - takeDamage <= 0)
    {
      std::cout << "Aaargh ..." << std::endl;
    }
  else 
    {
      this->hp = this->hp - takeDamage;
    }
}
