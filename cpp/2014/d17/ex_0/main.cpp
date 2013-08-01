#include <iostream>
#include "Parser.h"

int main()
{
  Parser p;

  p.feed("((12*2)+14)");
  std::cout << p.result() << std::endl;
  p.feed("((17 % 9) / 4)");
  std::cout << p.result() << std::endl;
  p.reset();
  p.feed("(17 - 4) * 13");
  std::cout << p.result() << std::endl;
  return 0;
}
