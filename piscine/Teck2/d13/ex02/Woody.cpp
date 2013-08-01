#include "Woody.h"
#include "Toy.h"
#include <iostream>
#include <string>

Woody::Woody(const std::string name)
: Toy(WOODY, name, "./woody.txt")
{
}

Woody::Woody(const std::string name, const std::string file)
: Toy(WOODY, name, file)
{
}

Woody::~Woody()
{
    
}