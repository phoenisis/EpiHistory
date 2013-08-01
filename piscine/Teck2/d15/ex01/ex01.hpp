#ifndef _EX01_H_
#define _EX01_H_

#include <iostream>
#include <string>

int compare(const char *a, const char *b)
{
  std::string i = a;
  std::string j = b;

  if (i == j)
    return 0;
  else if (i < j)
    return -1;
  return 1;
}

template<typename T>
int compare(const T &a, const T &b)
{
  if (a == b)
    return 0;
  else if (a < b)
    return -1;
  return 1;
}

#endif
