//
// Buzz.cpp for ex_2 in /home/pidoux_q/rendu/cpp/d14/ex_2
// 
// Made by quentin PIDOUX
// Login   <pidoux_q@epitech.net>
// 
// Started on  Mon Jan 17 14:51:05 2011 quentin PIDOUX
// Last update Mon Jan 17 19:40:16 2011 quentin PIDOUX
//

#include "Buzz.h"
#include "Toy.h"
#include <string>

Buzz::Buzz() : Toy()
{
}

Buzz::Buzz(const Buzz &c) :Toy()
{
  this->Type = c.getType();
  this->Name = c.getName();
}

Buzz Buzz::operator = (const Buzz&c)
{
  this->Type = c.getType();
  this->Name = c.getName();

  return (*this);
}

Buzz::Buzz(const std::string &name)
{
  this->Name = name;
  this->Type = Toy::BUZZ;
  this->ASCII.getPictureFromFile("./buzz.txt");
}

Buzz::Buzz(const std::string &name, const std::string &ASCII)
{
  this->Type = Toy::BUZZ;
  this->Name = name;
  this->ASCII.getPictureFromFile(ASCII); 
}

Buzz::~Buzz()
{
}

void Buzz::speak(const std::string sentence)
{
  std::cout << "BUZZ: " <<this->Name << " \"" << sentence << "\"" << std::endl;
}

