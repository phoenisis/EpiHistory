/*
** Buzz.h for ex@ in /home/pidoux_q/rendu/cpp/d14/ex_2
** 
** Made by quentin PIDOUX
** Login   <pidoux_q@epitech.net>
** 
** Started on  Mon Jan 17 14:50:43 2011 quentin PIDOUX
** Last update Tue Jan 18 08:27:05 2011 quentin PIDOUX
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
  Buzz(const std::string &name, std::string const &ASCII);
  Buzz(const Buzz &);
  Buzz operator = (const Buzz&);
  ~Buzz();
};

#endif
