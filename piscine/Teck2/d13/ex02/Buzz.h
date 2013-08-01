#ifndef _BUZZ_H_
#define _BUZZ_H_
#include <string>
#include "Toy.h"

class Buzz: public Toy
{
public:
    explicit Buzz(const std::string);
    Buzz(const std::string, const std::string);
    ~Buzz();
};

#endif