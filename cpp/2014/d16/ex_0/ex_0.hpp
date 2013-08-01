//
// ex_0.hpp for ex_0 in /home/pidoux_q/rendu/cpp/d16/ex_0
// 
// Made by quentin PIDOUX
// Login   <pidoux_q@epitech.net>
// 
// Started on  Wed Jan 19 10:37:08 2011 quentin PIDOUX
// Last update Thu Jan 20 00:14:43 2011 quentin pidoux
//

template<typename T>
T add(T a, T b)
{
  T c = a + b;
  return (c);
}

template<typename U>
void swap(U& a, U& b)
{
  U tmp;
  tmp = b;
  b = a;
  a = tmp;
}

template<typename V>
V min(V a, V b)
{
  if (a < b)
    return a;
  else
    return b;
}

template<typename W>
W max(W a, W b)
{
  if (a > b)
    return a;
  else
    return b;
}
