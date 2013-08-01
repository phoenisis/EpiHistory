#ifndef _EXO3_H_
#define _EX03_H_

#include <string>
#include <iostream>

template<typename T>
void foreach(T* a, void (*p)(T), size_t c)
{
  size_t i = 0;
    
  if (c == 0)
    return ;
  else
    while(i != c)
      {
	p(a[i]);
	i++;
      }
}

template<typename U>
void print(U a)
{
  std::cout << a << std::endl;
}

#endif
