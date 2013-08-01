//
// CreatOperand.cpp for  in /home/pidoux_q/abstractvm-2015-pidoux_q
//
// Made by Quentin PIDOUX
// Login   <pidoux_q@epitech.net>
//
// Started on  Mon Feb 13 10:35:13 2012 Quentin PIDOUX
// Last update Wed May  9 11:32:16 2012 quentin pidoux
//

#include <stdexcept>
#include <string>
#include <iostream>
#include <cstdint>
#include <cfloat>
#include <map>
#include <cstdlib>
#include "CreatOperand.hh"
#include "IOperand.hpp"
#include "Operand.hpp"

creator::creator()
{
    initMap();
}

creator::~creator()
{}

void creator::initMap()
{
    std::map<eOperandType, IOperand *(creator::*)(const std::string &) > my_map;

    this->my_map[INT8]=&creator::creatInt8;
    this->my_map[INT16]=&creator::creatInt16;
    this->my_map[INT32]=&creator::creatInt32;
    this->my_map[FLOAT]=&creator::creatFloat;
    this->my_map[DOUBLE]=&creator::creatDouble;
}

std::map<eOperandType, IOperand *(creator::*)(const std::string &)> creator::getMap()
{
  return (this->my_map);
}

IOperand * creator::creatOperand(eOperandType type, const std::string &value)
{
    creator crea;

    if ((getMap().find(type)) != this->getMap().end())
        return (crea.*my_map.find(type)->second)(value);
    else
        exit (0);
}

IOperand *creator::creatInt8(const std::string &value)
{
  int i = atoi(value.c_str());

  if (i <= INT8_MAX && i >= INT8_MIN)
    return (new operand<int>(value, INT8));
  else
      throw std::range_error("Overflow in INT8");
}

IOperand *creator::creatInt16(const std::string &value)
{
  int i = atoi(value.c_str());

  if (i <= INT16_MAX && i >= INT16_MIN)
    return (new operand<int>(value, INT16));
  else
    throw std::range_error("Overflow in INT16");
}

IOperand *creator::creatInt32(const std::string &value)
{
  long int i = atol(value.c_str());

  if (i <= INT32_MAX && i >= INT32_MIN)
    return (new operand<int>(value, INT32));
  else
    throw std::range_error("Overflow in INT32");
}

IOperand *creator::creatFloat(const std::string &value)
{
  double i = atof(value.c_str());

  if (i <= FLT_MAX && i >= FLT_MIN)
    return (new operand<int>(value, FLOAT));
  else
    throw std::range_error("Overflow in FLOAT");
}

IOperand *creator::creatDouble(const std::string &value)
{
  long double i = atol(value.c_str());

  if (i <= DBL_MAX && i >= DBL_MIN)
    return (new operand<int>(value, DOUBLE));
  else
    throw std::range_error("Overflow in DOUBLE");
}
