/*
** Toy.h for ex_0 in /home/pidoux_q/rendu/cpp/d14/ex_0
** 
** Made by quentin PIDOUX
** Login   <pidoux_q@epitech.net>
** 
** Started on  Mon Jan 17 10:34:49 2011 quentin PIDOUX
** Last update Mon Jan 17 20:41:32 2011 quentin PIDOUX
*/

#ifndef _TOY_H_
#define _TOY_H_

#include <string>
#include <iostream>
#include "Picture.h"

class Toy
{
 public:
  enum ToyType
  {
    BASIC_TOY,
    ALIEN,
    BUZZ,
    WOODY
  };

  Toy();
  Toy(const Toy &);
  Toy& operator = (const Toy &c);
  Toy(ToyType type, const std::string& name, const std::string& ASCII);
  ~Toy();

  ToyType getType()const ;
  std::string getName()const ;
  void setName(std::string);
  std::string getAscii()const ;
  void setAscii(const std::string& ASCII);
  std::string Name;
  ToyType Type;
  Picture ASCII;

  virtual void speak(const std::string sentence);
  void operator << (const std::string & o);

};

std::ostream &operator << (std::ostream&, Toy &);
#endif
