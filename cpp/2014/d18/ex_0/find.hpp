//
// find.hpp for  in /home/pidoux_q/data/cpp/d18/ex_0
// 
// Made by quentin PIDOUX
// Login   <pidoux_q@epitech.net>
// 
// Started on  Fri Jan 21 11:09:14 2011 quentin PIDOUX
// Last update Fri Jan 21 12:09:50 2011 quentin PIDOUX
//

#ifndef _FIND_HPP_
#define _FIND_HPP_

#include <iostream>
#include <algorithm>
#include <vector>

template<typename T>
typename T::iterator do_find(T& c, const int i)
{
  typename T::iterator it;
  it = std::find (c.begin(), c.end(), i);
  if (it == i)  
    return (it);
  return (c.end());
}

#endif
