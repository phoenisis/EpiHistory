//
// droid.cpp for ex_0 in /home/pidoux_q/rendu/cpp/d09/ex_0
// 
// Made by quentin PIDOUX
// Login   <pidoux_q@epitech.net>
// 
// Started on  Wed Jan 12 11:28:37 2011 quentin PIDOUX
// Last update Mon Jan 17 16:47:29 2011 quentin PIDOUX
//

#include "droid.hh"
#include <string>
#include <iostream>

Droid::Droid(std::string name)
  :Energy(50), Attack(50), Toughness(15)
{
  std::string stat = "Standing by";
  this->Status = &stat;
  this->Id = name;
  std::cout << "Droid '" << this->Id << "' Activated"
	    << std::endl;
}

Droid::Droid()
  : Energy(50), Attack(50), Toughness(15)
{
  std::string stat = "Standing by";
  this->Status = &stat; 
  std::cout << "Droid '" << "' Activated"
	    << std::endl;
}

Droid::Droid(const Droid & other)
  :Energy(50), Attack(50), Toughness(15)
{
  this->Id = other.getId();
  std::string stat = "Standing by";
  this->Status = &stat; 
  std::cout << "Droid '" << this->Id 
	    << "' Activated, Memory Dumped" << std::endl;
}
Droid::~Droid()
{
  std::cout << "Droid '"<< this->Id << "', Destroyed"
	    << std::endl;
}

std::string Droid::getId()
{
  return(this->Id);
}

void Droid::setId(std::string change)
{
  this->Id = change;
}

size_t Droid::getEnergy()
{
  return(this->Energy);
}

void Droid::setEnergy(size_t change)
{
  this->Energy = change;
}

size_t Droid::getAttack()
{
  return(this->Attack);
}

size_t Droid::getToughness()
{
  return(this->Toughness);
}

std::string * Droid::getStatus()
{
  return (this->Status);
}
void Droid::setStatus(std::string * change)
{
  this->Status = change;
}

bool Droid::operator=(Droid const &b)
{
  if ((this->Id == b.Id) && (this->Energy == b.Energy) && (this->Status == b.Status))
    return (true);
  else 
    return (false);
}

bool Droid::operator!=(Droid const &b)
{
  if ((this->Id == b.Id) && (this->Energy == b.Energy) && (this->Status == b.Status))
    return (false);
  else 
    return (true);
}

std::ostream & operator << (std::ostream & o , Droid & p)
{
  o << "Droid '" << p.getId() << "' " << *p.getStatus() << ", " 
    << p.getEnergy();
  return (o);
}

Droid & Droid::operator << (size_t & o)
{
  if (getEnergy() < 100)
    {
      while (getEnergy() < 100)
	{
	  this->Energy += 1;
	  o--;
	}
    }
  return (*this);
}
