//
// ex_2.hpp for  in /home/pidoux_q/data/cpp/d16/ex_2
// 
// Made by quentin PIDOUX
// Login   <pidoux_q@epitech.net>
// 
// Started on  Wed Jan 19 14:15:21 2011 quentin PIDOUX
// Last update Thu Jan 20 07:27:10 2011 quentin PIDOUX
//

#include <string>
#include <iostream>

template<typename T>
T min(T a, T b)
{
  std::cout << "template  min" << std::endl;
  if (a > b) 
    return b;
  else
    return a;
}

int min(int a, int b)
{
  std::cout << "non-template min" << std::endl;
  if (a > b)
    return b;
  else
    return a;
}

template<typename U>
U templateMin(U *tab, size_t a)
{
   if (a == 0)
    return (0);
  else
    return(min<U>(tab[0], tab[1]));
}

int nonTemplateMin(int *tab, size_t a)
{

  return(min(tab[0], tab[a-1]));
}
