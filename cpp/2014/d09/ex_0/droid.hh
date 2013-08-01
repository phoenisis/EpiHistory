//
// droid.hh for ex_0 in /home/pidoux_q/rendu/cpp/d09/ex_0
// 
// Made by quentin PIDOUX
// Login   <pidoux_q@epitech.net>
// 
// Started on  Wed Jan 12 11:28:50 2011 quentin PIDOUX
// Last update Thu Jan 13 08:30:21 2011 quentin PIDOUX
//

#ifndef _DROID_HH_
#define _DROID_HH_
#include <string>
#include <iostream>

class Droid
{
public:
  Droid(std::string name);
  Droid();
  Droid(const Droid &);
  ~Droid();

  //operator

  Droid & operator << (size_t &);
  bool operator=(const Droid &);
  bool operator!=(const Droid &);

  //get & set
  
  std::string getId();
  void setId(std::string change);
  size_t getEnergy();
  void setEnergy(size_t change);
  size_t getAttack();
  size_t getToughness();
  std::string * getStatus();
  void setStatus(std::string * change);
  
private:
  size_t batt;
  std::string Id;	 // le matricule
  size_t Energy;	 // l'energie restante avant de changer les piles
  size_t const Attack;	 // la puissance d'attaque
  size_t const Toughness;// sa resistance
  std::string * Status;	 // le statut actuel du droid
};

std::ostream & operator << (std::ostream &, Droid &);

#endif
