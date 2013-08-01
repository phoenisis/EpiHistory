#ifndef _DROIDMEMORY_H_
#define _DROIDMEMORY_H_

#include <string>
#include <iostream>

class DroidMemory
{
    private:
    size_t FingerPrint;
    size_t Exp;

    public:
    DroidMemory();
    ~DroidMemory();
    size_t getFingerPrint() const;
    size_t getExp()const ;
    void setFingerPrint(size_t);
    void setExp(size_t);

    DroidMemory& operator << (DroidMemory &);
    DroidMemory& operator >> (DroidMemory &);
    DroidMemory& operator += (DroidMemory &);
    DroidMemory& operator += (size_t);
    DroidMemory operator + (size_t);
    DroidMemory operator + (DroidMemory &);
};

std::ostream & operator << (std::ostream &, DroidMemory&);

#endif
