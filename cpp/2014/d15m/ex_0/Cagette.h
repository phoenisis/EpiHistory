/*-*- C++ -*- 
** Cagette.h for ex_0 in /home/pidoux_q/rendu/cpp/d15m/ex_0
** 
** Made by quentin PIDOUX
** Login   <pidoux_q@epitech.net>
** 
** Started on  Tue Jan 18 14:58:59 2011 quentin PIDOUX
// Last update Wed Jan 19 08:23:05 2011 quentin PIDOUX
*/

#ifndef _CAGETTE_H_
#define _CAGETTE_H_

#include "Fruit.h"
#include "FruitNode.h"
#include <string>

class Cagette
{
public:
   Cagette(int size);
  Cagette(const Cagette&);
  Cagette operator = (const Cagette&);
  ~Cagette();

  Fruit* PickFruit();
  FruitNode* head()const;
  FruitNode* Node;

protected:
  int nbFruit()const;
  int getSize()const;
  bool putFruit(Fruit* f);

private:
  int nbFru;
  int size;
};

#endif
