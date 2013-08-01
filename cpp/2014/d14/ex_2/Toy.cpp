//
// Toy.cpp for ex_0 in /home/pidoux_q/rendu/cpp/d14/ex_0
// 
// Made by quentin PIDOUX
// Login   <pidoux_q@epitech.net>
// 
// Started on  Mon Jan 17 10:34:59 2011 quentin PIDOUX
// Last update Mon Jan 17 19:36:12 2011 quentin PIDOUX
//

#include "Toy.h"
#include <string>
#include <iostream>

Toy::Toy()
{
  this->Type = Toy::BASIC_TOY;
  this->Name = "toy";
}

Toy::Toy(const Toy &c)
{
  this->Type = c.getType();
  this->Name = c.getName();
}

Toy& Toy::operator = (const Toy &c)
{
  this->Type = c.getType();
  this->Name = c.getName();
  return (*this);
}

Toy::Toy(Toy::ToyType type, const std::string& name, const std::string& ASCII)
{
  this->Type = type;
  this->Name = name;
  this->ASCII.getPictureFromFile(ASCII);
}

Toy::~Toy()
{
}

Toy::ToyType Toy::getType() const 
{
  return (this->Type);
}

std::string Toy::getName() const 
{
  return (this->Name);
}

void Toy::setName(std::string name)
{
  this->Name = name;
}

std::string Toy::getAscii() const 
{
  return (this->ASCII.data);
}

void Toy::setAscii(const std::string& Ascii)
{
  this->ASCII.data = Ascii;
}
