#ifndef _EX04_HPP_
#define _EX04_HPP_

#include <iostream>

template <typename T>
bool equal(const T& a, const T& b);

template <typename T>
class Tester
{
public:
  bool equal(const T& a, const T& b);
};

#endif
