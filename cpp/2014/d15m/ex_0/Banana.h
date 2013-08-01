/*-*- C++ -*-
** Banana.h for ex_0 in /home/pidoux_q/rendu/cpp/d15m/ex_0
** 
** Made by quentin PIDOUX
** Login   <pidoux_q@epitech.net>
** 
** Started on  Tue Jan 18 10:42:36 2011 quentin PIDOUX
// Last update Tue Jan 18 22:47:32 2011 quentin PIDOUX
*/

#ifndef _BANANA_H_
#define _BANANA_H_

#include <string>
#include "Fruit.h"

class Banana : public Fruit
{
 public :
  Banana();
  Banana(const Banana&);
  Banana& operator = (const Banana&);
  ~Banana();
};

#endif
