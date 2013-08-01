#include <iostream>
#include "Toy.h"
#include "Buzz.h"
#include "Woody.h"

int main()
{
  Toy*b = new Buzz("buzziiiii");
  Toy*w = new Woody("wood");
  Toy*t = new Toy(Toy::ALIEN, "ET", "alien.txt");

  b->speak("To the code, and beyond !!!!!!!!");
  w->speak("There's a snake in my boot.");
  t->speak("the claaaaaaw");
}
