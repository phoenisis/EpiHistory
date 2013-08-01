#include "Buzz.h"
#include "Toy.h"
#include <iostream>
#include <string>

Buzz::Buzz(const std::string name)
: Toy(BUZZ, name, "./buzz.txt")
{
}

Buzz::Buzz(const std::string name, const std::string file)
: Toy(BUZZ, name, file)
{
}

Buzz::~Buzz()
{
}

void Buzz::speak(const std::string &blabla)
{
    std::cout << "BUZZ: "
    << getName()
    << " "
    << blabla
    <<std::endl;
}