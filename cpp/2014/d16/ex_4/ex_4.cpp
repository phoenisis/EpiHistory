//
// ex_4.cpp for  in /home/pidoux_q/data/cpp/d16/ex_4
// 
// Made by quentin PIDOUX
// Login   <pidoux_q@epitech.net>
// 
// Started on  Wed Jan 19 16:03:29 2011 quentin PIDOUX
// Last update Wed Jan 19 21:10:58 2011 quentin PIDOUX
//

#include "ex_4.hpp"
#include <string>
#include <iostream>

template <typename T>
bool equal(const T& a, const T& b)
{
  if (a == b)
    return (true);
  else
    return (false);
}

template bool equal <int>(const int& a, const int& b);
template bool equal <float>(const float& a, const float& b);
template bool equal <double>(const double& a, const double& b);
template bool equal <std::string>(const std::string& a, const std::string& b);

template <typename T>
bool Tester<T>::equal(const T& a, const T& b)
{
  if (a == b)
    return (true);
  else
    return (false);
}

template bool Tester<int>::equal(const int& a, const int& b);
template bool Tester<float>::equal(const float& a, const float& b);
template bool Tester<double>::equal(const double& a, const double& b);
template bool Tester<std::string>::equal(const std::string& a, const std::string& b);
