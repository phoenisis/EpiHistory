/**-*- C++ -*-
** Parser.h for  in /home/pidoux_q/data/cpp/d17/ex_0
** 
** Made by quentin PIDOUX
** Login   <pidoux_q@epitech.net>
** 
** Started on  Thu Jan 20 10:33:15 2011 quentin PIDOUX
// Last update Thu Jan 20 11:11:20 2011 quentin PIDOUX
*/

#include <iostream>
#include <stack>

class Parser
{
public:
  Parser();
  Parser(const Parser&);
  ~Parser();

  void    feed(const std::string&);
  int     result() const;
  void    reset();
}

