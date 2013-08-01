//
// IOperand.hpp for  in /afs/epitech.net/users/all/pidoux_q/public/abstract
//
// Made by Quentin PIDOUX
// Login   <pidoux_q@epitech.net>
//
// Started on  Mon Feb  6 14:05:04 2012 Quentin PIDOUX
// Last update Mon Feb 13 10:35:07 2012 Quentin PIDOUX
//

#ifndef _IOPERAND_HPP_
#define _IOPERAND_HPP_

#include <string>
#include <iostream>

typedef enum
  {
    INT8,
    INT16,
    INT32,
    FLOAT,
    DOUBLE
  }  eOperandType;

class IOperand
{
public:
    virtual std::string const & toString() const = 0;
    virtual int getPrecision() const = 0;
    virtual eOperandType getType() const = 0;

    virtual IOperand *operator+(const IOperand &rhs) const = 0;
    virtual IOperand *operator-(const IOperand &rhs) const = 0;
    virtual IOperand *operator*(const IOperand &rhs) const = 0;
    virtual IOperand *operator/(const IOperand &rhs) const = 0;
    virtual IOperand *operator%(const IOperand &rhs) const = 0;

    virtual ~IOperand() {}
};


#endif
