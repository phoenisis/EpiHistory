#include <string>
#include <iostream>
#include "droid.hh"
#include "droidmemory.hh"

Droid::Droid(std::string name)
: Energy(50), Attack(25), Toughness(15)
{
    this->Id = name;
    DroidMemory *data = new DroidMemory();
    this->BattleData = data;
    std::string *stat = new std::string("Standing by");
    this->Status = stat;

    std::cout << "Droid '"
              << this->Id
              << "' Activated"
              << std::endl;
}

Droid::Droid(const Droid & e)
  :Id(e.Id), Energy(e.Energy), Attack(e.Attack), Toughness(e.Toughness), Status(e.Status), BattleData(e.BattleData)
{
        std::cout << "Droid '"
              << this->Id
              << "' Activated, Memory Dumped"
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

size_t Droid::getAttack() const
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

DroidMemory *Droid::getBattleData() const
{
  return this->BattleData;
}

void Droid::setBattleData(DroidMemory * d)
{
  if (this->BattleData)
    delete BattleData;
  this->BattleData = d;
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
    if (this->getStatus() == e.getStatus())
            return true;
   else
            return false;
}

bool Droid::operator!=(const Droid &e) const
{
    if (this->getStatus() == e.getStatus())
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

int main ()
{}
