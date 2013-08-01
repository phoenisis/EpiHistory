//
// AEnemy.hh for ex_1 in /home/pidoux_q/rendu/cpp/d11/ex_1
// 
// Made by quentin PIDOUX
// Login   <pidoux_q@epitech.net>
// 
// Started on  Fri Jan 14 16:50:07 2011 quentin PIDOUX
// Last update Fri Jan 14 17:00:54 2011 quentin PIDOUX
//

#ifndef _AENEMY_HH_
#define _AENEMY_HH_
#include <string>
#include <iostream>

class AEnemy
{
private:
  int hp;
  std::string type;
public:
  AEnemy(int hp, std::string const & type);
  ~AEnemy();
  std::string  getType() const;
  int getHP() const;
  
  virtual void takeDamage(int);
};
