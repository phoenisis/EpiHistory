//
// AWeapon.hh for ex_1 in /home/pidoux_q/rendu/cpp/d11/ex_1
// 
// Made by quentin PIDOUX
// Login   <pidoux_q@epitech.net>
// 
// Started on  Fri Jan 14 16:22:58 2011 quentin PIDOUX
// Last update Fri Jan 14 16:38:28 2011 quentin PIDOUX
//

#ifndef _AWEAPON_HH_
#define _AWEAPON_HH_
#include <string>
#include <iostream>

class AWeapon
{
protected:
  std::string name;
  int apcost;
  int damage;

public:
  AWeapon(std::string const & name, int apcost, int damage);
  ~AWeapon();
  std::string getName() const;
  int getAPCost() const;
  int getDamage() const;
  void attack() const = 0;
};



#endif
