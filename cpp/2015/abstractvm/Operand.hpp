//
//  Operand.h
//  Abstract
//
//  Created by quentin PIDOUX on 08/02/12.
//  Copyright (c) 2012 EPITECH. All rights reserved.
//

#ifndef Abstract_Operand_hpp
#define Abstract_Operand_hpp

#include "IOperand.hpp"
#include "CreatOperand.hh"
#include <string>
#include <iostream>
#include <unistd.h>
#include <sstream>
#include <cmath>

template<typename T>
class operand : public IOperand
{
  eOperandType	  _type;
  std::string     _str;
  T               _value;
  int             _precision;

public:
  operand(const std::string val, const eOperandType type)
    : _type(type), _str(val)
  {
    switch (this->_type) {
    case 0:
      this->_value= atoi(val.c_str());
      break;
    case 1:
      this->_value= atoi(val.c_str());
      break;
    case 2:
      this->_value= atoi(val.c_str());
      break;
    case 3:
      this->_value= atof(val.c_str());
      break;
    default:
      this->_value= atof(val.c_str());
      break;
    }
  }

  ~operand()
  {
    //delete this;
  }

  virtual std::string const & toString() const
  {
    return (this->_str);
  }

  virtual int getPrecision() const
  {
    return (static_cast<int>(this->_type));
  }

  virtual eOperandType getType() const
  {
    return (this->_type);
  }

  T		getValue() const
  {
    return (this->_value);
  }

  // Add

  virtual IOperand * operator+(const IOperand &rhs) const
  {
    double          tmp;
    std::string     i;
    creator         crea;

    tmp = this->getValue()+atof(rhs.toString().c_str());
    std::ostringstream dest;
    dest << tmp;
    i=dest.str();

    if (rhs.getType() > this->_type)
      return crea.creatOperand(rhs.getType(), i);
    else
      return crea.creatOperand(this->_type, i);
  }

  // Sous

  virtual IOperand * operator-(const IOperand &rhs) const
  {
    long double          tmp;
    std::string     i;
    creator         crea;

    tmp = this->getValue()-atof(rhs.toString().c_str());
    std::ostringstream dest;
    dest << tmp;
    i=dest.str();

    if (rhs.getType() > this->_type)
      return crea.creatOperand(rhs.getType(), i);
    else
      return crea.creatOperand(this->_type, i);
  }

  //Mult

  virtual IOperand * operator*(const IOperand &rhs) const
  {
    double          tmp;
    std::string     i;
    creator         crea;

    tmp = this->getValue()*atof(rhs.toString().c_str());
    std::ostringstream dest;
    dest << tmp;
    i=dest.str();

    if (rhs.getType() > this->_type)
      return crea.creatOperand(rhs.getType(), i);
    else
      return crea.creatOperand(this->_type, i);
  }

  // Quotien

  virtual IOperand * operator/(const IOperand &rhs) const
  {
    std::string     i;
    creator         crea;
    std::ostringstream dest;

    if (rhs.getType() > this->_type)
      {
	if (rhs.getType() > 2)
	  {
	    double          tmp;

	    tmp = this->getValue()/atof(rhs.toString().c_str());
	    dest << tmp;
	    i=dest.str();
	  }
	else
	  {
	    int          tmp;

	    tmp = this->getValue()/atoi(rhs.toString().c_str());
	    dest << tmp;
	    i=dest.str();
	  }
	return crea.creatOperand(rhs.getType(), i);
      }
    else
      {
	if (this->_type > 2)
	  {
	    double          tmp;

	    tmp = this->getValue()/atof(rhs.toString().c_str());
	    dest << tmp;
	    i=dest.str();
	  }
	else
	  {
	    int          tmp;

	    tmp = this->getValue()/atoi(rhs.toString().c_str());
	    dest << tmp;
	    i=dest.str();
	  }
	return crea.creatOperand(this->_type, i);
      }
  }

  // Modulo

  virtual IOperand * operator%(const IOperand &rhs) const
  {
    double          tmp;
    double          fin = atof(rhs.toString().c_str());
    std::string     i;
    creator         crea;

    tmp = fmod(this->getValue(), fin);
    std::ostringstream dest;
    dest << tmp;
    i=dest.str();

    if (rhs.getType() > this->_type)
      return crea.creatOperand(rhs.getType(), i);
    else
      return crea.creatOperand(this->_type, i);
  }
};

#endif
