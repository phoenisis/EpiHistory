//
// PlasmaRifle.cpp for ex_1 in /home/pidoux_q/rendu/cpp/d11/ex_1
// 
// Made by quentin PIDOUX
// Login   <pidoux_q@epitech.net>
// 
// Started on  Fri Jan 14 16:38:34 2011 quentin PIDOUX
// Last update Fri Jan 14 16:49:56 2011 quentin PIDOUX
//

#include "PlasmaRifle.hh"
#include <string>
#include <iostream>

PlasmaRifle::PlasmaRifle()
{
  AWeapon::name = "Plasma Rifle";
  AWeapon::apcost = 5;
  AWeapon::damage = 21;
}

PlasmaRifle::~PlasmaRifle()
{
}

void PlasmaRifle::attack() const
{
  std::cout << "* piouuu piouuu piouuu *" << std::endl;
}
