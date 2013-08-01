#include "Picture.h"
#include "Toy.h"
#include "Buzz.h"
#include "Woody.h"
#include <iostream>
#include <string>

int main()
{
  Woody toto("Salut");
  Buzz bu("buzzy");
  Woody wo("wood");
  
  if (bu.getType() == Toy::BUZZ)
    std::cout << bu.getName() << "->" << std::endl
		 << bu.getAscii() << std::endl
	      <<bu.getType();
  if (wo.getType() == Toy::WOODY)
    std::cout  << wo.getName() << "->" << std::endl
	       << wo.getAscii() << std::endl;
  if (toto.getType() == Toy::WOODY)
    std::cout << toto.getName() << "->" 
	      << std::endl << toto.getAscii() << std::endl;
  
  return 1337;
}

