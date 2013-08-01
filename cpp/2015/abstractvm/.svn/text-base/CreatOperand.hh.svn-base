//
// CreatOperand.hh for  in /home/pidoux_q/abstractvm-2015-pidoux_q
//
// Made by Quentin PIDOUX
// Login   <pidoux_q@epitech.net>
//
// Started on  Mon Feb 13 10:22:48 2012 Quentin PIDOUX
// Last update Wed Feb 15 11:41:55 2012 Matthieu FLEUROT
//

#include "IOperand.hpp"
#include "Operand.hpp"
#include <string>
#include <map>

#ifndef CreatOperand_hh
#define CreatOperand_hh

class creator
{
public:
  creator();
  ~creator();
  void initMap();
  std::map<eOperandType, IOperand *(creator::*)(const std::string &)> getMap();
  IOperand *creatOperand(eOperandType, const std::string &);

private:
  IOperand *creatInt8(const std::string &value);
  std::map<eOperandType, IOperand *(creator::*)(const std::string &) > my_map;
  IOperand *creatInt16(const std::string &value);
  IOperand *creatInt32(const std::string &value);
  IOperand *creatFloat(const std::string &value);
  IOperand *creatDouble(const std::string &value);
};

#endif
