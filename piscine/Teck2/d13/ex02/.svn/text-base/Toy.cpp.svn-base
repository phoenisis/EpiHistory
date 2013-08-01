#include "Toy.h"
#include <string>
#include <iostream>

Toy::Toy()
{
  this->Type = Toy::BASIC_TOY;
  this->Name = "toy";
  this->ASCII.data = "";
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
