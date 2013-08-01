#include <string>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "droidmemory.hh"

DroidMemory::DroidMemory(): Exp(0)
{
    this->FingerPrint = random();
}

DroidMemory::~DroidMemory()
{
}

size_t DroidMemory::getFingerPrint() const
{
    return this->FingerPrint;
}

size_t DroidMemory::getExp() const
{
    return this->Exp;
}

void DroidMemory::setFingerPrint(size_t f)
{
    this->FingerPrint = f;
}

void DroidMemory::setExp(size_t f)
{
    this->Exp = f;
}

DroidMemory& DroidMemory::operator << (DroidMemory & r2)
{
    this->Exp += r2.getExp();
    r2.setFingerPrint(r2.getFingerPrint() xor this->FingerPrint);

    return *this;
}

DroidMemory& DroidMemory::operator >> (DroidMemory & r2)
{
    r2.setExp(r2.getExp() + this->Exp);
    this->FingerPrint = (r2.getFingerPrint() xor this->FingerPrint);

    return *this;
}

DroidMemory& DroidMemory::operator += (size_t i)
{
    this->Exp += i;
    this->FingerPrint = (this->FingerPrint xor i);

    return *this;
}

DroidMemory& DroidMemory::operator += (DroidMemory & r2)
{
    this->Exp += r2.getExp();
    r2.setFingerPrint(r2.getFingerPrint() xor this->FingerPrint);

    return *this;
}

DroidMemory DroidMemory::operator + (DroidMemory & r2)
{
    size_t xp = this->Exp += r2.getExp();
    size_t print = (r2.getFingerPrint() xor this->FingerPrint);

    DroidMemory d2;

    d2.setExp(xp);
    d2.setFingerPrint(print);

    return d2;
}

bool DroidMemory::operator == (DroidMemory &r2) const
{
    if (this->Exp == r2.getExp()
        && this->FingerPrint == r2.getFingerPrint())
        return true;
    else
        return false;
}

bool DroidMemory::operator != (DroidMemory &r2) const
{
    if (this->Exp == r2.getExp()
        && this->FingerPrint == r2.getFingerPrint())
        return false;
    else
        return true;
}

 bool DroidMemory::operator < (size_t d) const
 {
     if (this->Exp < d)
     return true;
     else
     return false;
 }

 bool DroidMemory::operator < (DroidMemory &d) const
 {
     if (this->Exp < d.getExp())
     return true;
     else
     return false;
 }

 bool DroidMemory::operator > (size_t d) const
 {
     if (this->Exp > d)
     return true;
     else
     return false;
 }

 bool DroidMemory::operator > (DroidMemory &d) const
 {
     if (this->Exp > d.getExp())
     return true;
     else
     return false;
 }

  bool DroidMemory::operator >= (size_t d) const
 {
     if (this->Exp >= d)
     return true;
     else
     return false;
 }

 bool DroidMemory::operator >= (DroidMemory &d) const
 {
     if (this->Exp >= d.getExp())
     return true;
     else
     return false;
 }

 bool DroidMemory::operator <= (size_t d) const
 {
     if (this->Exp <= d)
     return true;
     else
     return false;
 }

 bool DroidMemory::operator <= (DroidMemory &d) const
 {
     if (this->Exp <= d.getExp())
     return true;
     else
     return false;
 }


std::ostream & operator << (std::ostream & o, DroidMemory& p)
{
      o << "DroidMemory '"
    << p.getFingerPrint()
    << "' ,"
    << p.getExp();

  return (o);
}
