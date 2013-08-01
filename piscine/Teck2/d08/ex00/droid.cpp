#include <string>
#include <iostream>
#include "droid.hh"

Droid::Droid(std::string name)
: Energy(50), Attack(25), Toughness(15)
{
    this->Id = name;
    std::string *stat = new std::string("Standing by");
    this->Status = stat;

    std::cout << "Droid '"
              << this->Id
              << "' Activated"
              << std::endl;
}

Droid::Droid(const Droid & e)
:Id(e.Id), Energy(e.Energy), Attack(e.Attack), Toughness(e.Toughness), Status(e.Status)
{
        std::cout << "Droid '"
              << this->Id
              << "' Activated, Memory Dumped"
              << std::endl;
}

Droid::Droid()
: Energy(50), Attack(25), Toughness(15)
{
    this->Id = "";
    std::string *stat = new std::string("Standing by");
    this->Status = stat;

    std::cout << "Droid '"
              << this->Id
              << "' Activated"
              << std::endl;
}

Droid::~Droid()
{
    std::cout << "Droid '"
              << this->Id
              << "' Destroyed"
              << std::endl;

}

std::string Droid::getId() const
{
    return this->Id;
}

size_t Droid::getEnergy() const
{
    return this->Energy;
}

size_t  Droid::getAttack() const
{
    return this->Attack;
}

size_t Droid::getToughness() const
{
    return this->Toughness;
}

std::string *Droid::getStatus() const
{
    return this->Status;
}

void Droid::setId(std::string e)
{
    this->Id = e;
}

void Droid::setEnergy(size_t e)
{
    this->Energy = e;
}


void Droid::setStatus(std::string *e)
{
    delete this->Status;
    this->Status = e;
}

bool Droid::operator==(const Droid &e) const
{
    if (this->getAttack() == e.getAttack()
        && this->getEnergy() == e.getEnergy()
        && this->getStatus() == e.getStatus()
        && this->getId() == e.getId()
        && this->getToughness() == e.getToughness())
            return true;
   else
            return false;
}

bool Droid::operator!=(const Droid &e) const
{
    if (this->getAttack() == e.getAttack()
        && this->getEnergy() == e.getEnergy()
        && this->getStatus() == e.getStatus()
        && this->getId() == e.getId()
        && this->getToughness() == e.getToughness())
            return false;
   else
            return true;
}

Droid& Droid::operator << (size_t & o)
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

Droid& Droid::operator=(const Droid &e)
{
    if(this != &e)
    {
        this->Status = e.Status;
        this->Id = e.Id;
        this->Energy = e.Energy;
    }
    return *this;
}

std::ostream & operator << (std::ostream & o , Droid & p)
{
  o << "Droid '"
    << p.getId()
    << "', "
    << *p.getStatus()
    << ", "
    << p.getEnergy();
  return (o);
}
