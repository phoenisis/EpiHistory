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

Droid::Droid(Droid & e)
  :Id(e.Id), Attack(e.Attack) , Status(e.Status), Toughness(e.Toughness), BattleData(e.BattleData)
{
    if (this->Energy < 50)
        this->Energy = 50;
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

bool Droid::operator==(Droid &e) const
{
    if (this->getStatus() == e.getStatus())
            return true;
   else
            return false;
}

bool Droid::operator!=(Droid &e) const
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

Droid& Droid::operator=(Droid &e)
{
    if(this != &e)
    {
        this->Status = e.Status;
        this->Id = e.Id;
        this->Energy = e.Energy;
    }
    return *this;
}

bool Droid::operator()(std::string const *str, size_t t)
{
    std::string *lol = new std::string;
    if(this->BattleData->getExp() > t)
    {
        if (this->Energy > 10)
        {
            this->Energy = this->Energy - t;
            *lol = std::string(*str);
            *lol+= " - Completed";
            this->setStatus(lol);
            this->BattleData->setExp(t/2);
            return true;
        }
        else
        {
            this->Energy = 0;
            *lol = "Battery Low";
            this->setStatus(lol);
            return false;
        }
    }
    else
    {
    *lol = std::string(*str);
    *lol+= " - Failed!";
    this->setStatus(lol);
    return false;
    }
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

int main()
{
DroidMemory dm;
DroidMemory dn;
DroidMemory dg;
dm += 42;
DroidMemory dn1 = dm;
std::cout << dm << std::endl;
dn << dm;
dn >> dm;
dn << dm;
std::cout << dn << std::endl;
std::cout << dm<< std::endl;
dg = dm + dn1;

Droid d("rudolf");
Droid d2("gaston");
size_t DuraSell = 40;
d << DuraSell;
d.setStatus(new std::string("having some reset"));
d2.setStatus(new std::string("having some reset"));
if (d2 != d && !(d == d2))
std::cout << "a droid is a droid, all its matter is what it’s doing" <<
std::endl;
d(new std::string("take a coffee"), 20);
std::cout << d << std::endl;
while (d(new std::string("Patrol around"), 20))
{
if (!d(new std::string("Shoot some ennemies"), 50))
d(new std::string("Run Away"), 20);
std::cout << d << std::endl;
}
std::cout << d << std::endl;
return (0);

}
