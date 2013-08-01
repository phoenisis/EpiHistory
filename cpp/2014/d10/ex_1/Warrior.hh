//
// Warrior.hh for ex_1 in /home/pidoux_q/rendu/cpp/d10/ex_1
// 
// Made by quentin PIDOUX
// Login   <pidoux_q@epitech.net>
// 
// Started on  Thu Jan 13 18:17:41 2011 quentin PIDOUX
// Last update Thu Jan 13 23:07:10 2011 quentin PIDOUX
//

#ifndef _WARRIOR_HH_
#define _WARRIOR_HH_

#include "Character.hh"
#include <iostream>
#include <string>

class Warrior : public Character
{
public:
  Warrior(std::string name, int lvl, std::string Weapon);
  ~Warrior();

  int CloseAttack();
  int RangeAttack();
  void RestorePower();

protected:
  //caracteristiques

  std::string classe;
  std::string Weapon;

  //skill

};

#endif
