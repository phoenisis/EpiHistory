/*
** Woody.h for ex_2 in /home/pidoux_q/rendu/cpp/d14/ex_2
** 
** Made by quentin PIDOUX
** Login   <pidoux_q@epitech.net>
** 
** Started on  Mon Jan 17 15:18:15 2011 quentin PIDOUX
// Last update Mon Jan 17 19:43:16 2011 quentin PIDOUX
*/

#ifndef _WOODY_H_
#define _WOODY_H_

#include "Toy.h"
#include <string>
#include <fstream>

class Woody : public Toy
{
 public:
  Woody();
  Woody(const std::string &name);
  Woody(const std::string &name, const std::string &ASCII);
  Woody(const Woody &);
  Woody operator = (const Woody&);
  ~Woody();
  virtual void speak(const std::string sentence);
};

#endif
