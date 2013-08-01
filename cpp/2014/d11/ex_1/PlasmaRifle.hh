//
// PlasmaRifle.hh for ex_1 in /home/pidoux_q/rendu/cpp/d11/ex_1
// 
// Made by quentin PIDOUX
// Login   <pidoux_q@epitech.net>
// 
// Started on  Fri Jan 14 16:35:01 2011 quentin PIDOUX
// Last update Fri Jan 14 16:51:19 2011 quentin PIDOUX
//

#ifndef _PLASMARIFLE_HH_
#define _PLASMARIFLE_HH_
#include "AWeapon.hh"
#include <string>
#include <iostream>

class PlasmaRifle : plublic AWeapon
{
public:
  PlasmaRifle();
  ~PlasmaRifle();
  void attack() const;
};
