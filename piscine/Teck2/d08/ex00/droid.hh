#ifndef _DROID_HH_
#define _DROID_HH_
#include <string>
#include <iostream>

class Droid
{
    private:
    std::string Id;
    size_t Energy;
    size_t const Attack;
    size_t const Toughness;
    std::string *Status;

    public:
        Droid(std::string);
        Droid(const Droid &);
        Droid();
        ~Droid();
        std::string getId()const;
        size_t getEnergy()const;
        size_t getAttack()const;
        size_t getToughness()const;
        std::string *getStatus()const;
        void setId(std::string);
        void setEnergy(size_t);
        void setStatus(std::string *);

        bool operator==(const Droid &)const;
        bool operator!=(const Droid &)const;
        Droid & operator << (size_t &);
        Droid & operator=(const Droid &);
};

std::ostream & operator << (std::ostream &, Droid &);

#endif
