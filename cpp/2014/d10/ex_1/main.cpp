//
// main.cpp for ex_0 in /home/pidoux_q/rendu/cpp/d10/ex_0
// 
// Made by quentin PIDOUX
// Login   <pidoux_q@epitech.net>
// 
// Started on  Thu Jan 13 18:15:04 2011 quentin PIDOUX
// Last update Thu Jan 13 22:43:28 2011 quentin PIDOUX
//

#include "Character.hh"
#include "Warrior.hh"
#include <string>

int	main()
{
  std::string	C1 = "Sevan";
  std::string	C2 = "Thor";
  std::string	C3 = "Patator";

  Character	Sevan(C1, 100);
  Warrior	Thor(C2, 100, C3);

  std::cout <<  Thor.getPower() << std::endl;
}
