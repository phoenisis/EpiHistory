//
// PowerFist.cpp for ex_1 in /home/pidoux_q/rendu/cpp/d11/ex_1
// 
// Made by quentin PIDOUX
// Login   <pidoux_q@epitech.net>
// 
// Started on  Fri Jan 14 16:44:28 2011 quentin PIDOUX
// Last update Fri Jan 14 16:49:54 2011 quentin PIDOUX
//

#include "PowerFist.hh"
#include <string>
#include <iostream>

PowerFist::PowerFist()
{
  AWeapon::name = "Power Fist";
  AWeapon::opcost = 8;
  AWeapon::damage = 50;
}

PowerFist::~PowerFist()
{
}

void PowerFist::attack() const
{
  std::cout << "* pschhh... SBAM! *" <<std::endl;
}
