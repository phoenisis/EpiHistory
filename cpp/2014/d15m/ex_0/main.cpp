//
// main.cpp for test in /home/pidoux_q/rendu/cpp/d15m/ex_0
// 
// Made by quentin PIDOUX
// Login   <pidoux_q@epitech.net>
// 
// Started on  Tue Jan 18 18:35:50 2011 quentin PIDOUX
// Last update Wed Jan 19 08:27:13 2011 quentin PIDOUX
//

#include "Fruit.h"
#include "Banana.h"
#include "Citron.h"
#include "Cagette.h"
#include <iostream>
#include <string>

int main ()
{
  Citron c;
  Banana b;
  std::cout << c.getVitamins() << std::endl;
  std::cout << b.getVitamins() << std::endl;
  std::cout << c.getName() << std::endl;
  std::cout << b.getName() << std::endl;
  Fruit& f = c;
  std::cout << f.getVitamins() << std::endl;
  std::cout << f.getName() << std::endl;
  return 1337;
}
