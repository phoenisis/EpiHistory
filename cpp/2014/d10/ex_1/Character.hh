//
// Character.hh for ex_0 in /home/pidoux_q/rendu/cpp/d10/ex_0
// 
// Made by quentin PIDOUX
// Login   <pidoux_q@epitech.net>
// 
// Started on  Thu Jan 13 17:13:55 2011 quentin PIDOUX
// Last update Thu Jan 13 22:13:52 2011 quentin PIDOUX
//

#ifndef _CARACTER_HH_
#define _CARACTER_HH_

#include <iostream>
#include <string>



class Character
{
public:
  Character(std::string name, int lvl);
  ~Character();

  //info 

  int getPv() const;
  int getPower() const;
  const std::string& getName() const;
  int getLvl() const;

  //Attaque

  int CloseAttack();
  int RangeAttack();

  //Soin

  void Heal();
  void RestorePower();

  //Damages

  void TakeDamage(int _damage);


protected:
  //caracteristiques 

  std::string race;
  std::string name;
  typedef int AttackRange;
  typedef int AttackClose;
  AttackRange RANGE;
  AttackClose CLOSE;
  int Pv;
  int Power;
  int Lvl;

  //skill

  int Force;
  int Endurance;
  int Intelligence;
  int Esprit;
  int Agilite;
};

#endif
