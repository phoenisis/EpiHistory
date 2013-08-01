#include <iostream>
#include "Toy.h"
#include "Buzz.h"
#include "Woody.h"

int main()
{
  Buzz    ET("green", "buzz.txt");

    std::cout << "this bolt is: " << ET.getName() << std::endl
	      << ET.getAscii() << std::endl;
  return 1337;
}
