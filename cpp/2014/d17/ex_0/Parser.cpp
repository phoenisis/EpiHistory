//
// Parser.cpp for  in /home/pidoux_q/data/cpp/d17/ex_0
// 
// Made by quentin PIDOUX
// Login   <pidoux_q@epitech.net>
// 
// Started on  Thu Jan 20 10:33:09 2011 quentin PIDOUX
// Last update Thu Jan 20 11:49:52 2011 quentin PIDOUX
//

#include <iostream>
#include <stack>
#include "Parser.h"

Parser::Parser()
{
}

Parser::Parser(const Parser&c)
{
}

Parser::~Parser()
{
}

void    Parser::feed(const std::string& c)
{
  this->_operant = c;

}

int     Parser::result() const
{
}

void    Parser::reset()
{
}
