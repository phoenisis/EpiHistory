/*
** Buzz.h for ex@ in /home/pidoux_q/rendu/cpp/d14/ex_2
** 
** Made by quentin PIDOUX
** Login   <pidoux_q@epitech.net>
** 
** Started on  Mon Jan 17 14:50:43 2011 quentin PIDOUX
** Last update Mon Jan 17 19:40:19 2011 quentin PIDOUX
*/

#ifndef _BUZZ_H_
#define _BUZZ_H_

#include "Toy.h"
#include <string>
#include <fstream>

class Buzz  : public Toy
{
 public:
  Buzz();
  Buzz(const std::string &name);
  Buzz(const std::string &name, const std::string &ASCII);
  Buzz(const Buzz &);
  Buzz operator = (const Buzz&);
  ~Buzz();
  virtual void speak(const std::string sentence);
};

#endif
