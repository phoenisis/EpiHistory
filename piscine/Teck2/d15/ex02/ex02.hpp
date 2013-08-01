#ifndef _EX03_H_
#define _EX03_H_

#include <string>
#include <iostream>

int min(const int&, const int&);
int nonTemplateMin(const int *, const size_t&);

template<typename T>
T min(const T &a, const T &b)
{
  std::cout << "template  min" << std::endl;
  if (a > b) 
    return b;
  return a;
}

int min(const int &a, const int &b)
{
  std::cout << "non-template min" << std::endl;
  if (a > b)
    return b;
  return a;
}

template<typename U>
U templateMin(const U *tab, const size_t &a)
{
  if (a == 0)
    return (0);
  return(min<U>(tab[0], tab[1]));
}

int nonTemplateMin(const int *tab, const size_t &a)
{  
  return(min(tab[0], tab[a-1]));
}

#endif
