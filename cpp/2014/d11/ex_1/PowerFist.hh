//
// PowerFist.hh for ex_1 in /home/pidoux_q/rendu/cpp/d11/ex_1
// 
// Made by quentin PIDOUX
// Login   <pidoux_q@epitech.net>
// 
// Started on  Fri Jan 14 16:43:04 2011 quentin PIDOUX
// Last update Fri Jan 14 16:48:10 2011 quentin PIDOUX
//

#ifndef _POWERFIST_HH_
#define _POWERFIST_HH_
#include "AWeapon.hh"
#include <string>
#include <iostream>

class PowerFist : plublic AWeapon
{
public:
  PowerFist();
  ~PowerFist();
  void attack() const;
};
