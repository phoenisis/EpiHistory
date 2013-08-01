/*-*- C++ -*-
** Citron.h for ex_0 in /home/pidoux_q/rendu/cpp/d15m/ex_0
** 
** Made by quentin PIDOUX
** Login   <pidoux_q@epitech.net>
** 
** Started on  Tue Jan 18 10:41:58 2011 quentin PIDOUX
// Last update Tue Jan 18 22:47:58 2011 quentin PIDOUX
*/

#ifndef _CITRON_H_
#define _CITRON_H_

#include "Fruit.h"
#include <string>

class Citron : public Fruit
{
 public:
  Citron();
  Citron(const Citron&);
  Citron& operator=(const Citron&);
  ~Citron();
};

#endif
