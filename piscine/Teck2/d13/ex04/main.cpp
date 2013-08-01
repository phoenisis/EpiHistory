#include "Picture.h"
#include "Toy.h"
#include "Buzz.h"
#include "Woody.h"
#include <iostream>
#include <string>

int main()
{
Toy a(Toy::BASIC_TOY, "REX", "rex.txt");
        
    std::cout << a;
    a << "\\o/";
    std::cout << a;
}