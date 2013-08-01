#ifndef _WOODY_H_
#define _WOODY_H_
#include <string>
#include "Toy.h"

class Woody: public Toy
{
public:
    explicit Woody(const std::string);
    Woody(const std::string, const std::string);
    ~Woody();

};


#endif