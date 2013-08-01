//
// AWeapon.cpp for ex_1 in /home/pidoux_q/rendu/cpp/d11/ex_1
// 
// Made by quentin PIDOUX
// Login   <pidoux_q@epitech.net>
// 
// Started on  Fri Jan 14 16:28:20 2011 quentin PIDOUX
// Last update Fri Jan 14 16:34:46 2011 quentin PIDOUX
//

#include "AWeapon.hh"
#include <string>
#include <iostream>

AWeapon::AWeapon(std::string const & name, int apcost, int damage)
{
  this->name = name;
  this->apcost = apcost;
  this-> damage = damage;
}

AWeapon::~AWeapon()
{
}

std::string AWeapon::getName() const
{
  return (this->name);
}

int AWeapon::getAPCost() const
{
  return (this->apcost);
}

int AWeapon::getDamage() const
{
  return (this->damage);
}

void AWeapon::attack() const = 0;
