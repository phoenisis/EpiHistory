/*-*- C++ -*-
** Fruit.h for ex_0 in /home/pidoux_q/rendu/cpp/d15m/ex_0
** 
** Made by quentin PIDOUX
** Login   <pidoux_q@epitech.net>
** 
** Started on  Tue Jan 18 10:40:07 2011 quentin PIDOUX
// Last update Wed Jan 19 08:20:34 2011 quentin PIDOUX
*/

#ifndef _FRUIT_H_
#define _FRUIT_H_

#include <string>

class Fruit
{
 public:
  Fruit();
  Fruit(const Fruit& c);
  Fruit& operator = (const Fruit &c);
  ~Fruit();
  
  virtual int getVitamins() const;
  virtual std::string getName() const;


  int _vitamins;
  std::string Name;
  
};

#endif
