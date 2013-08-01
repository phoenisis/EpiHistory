//
// sickkoala.cpp for ex_2 in /home/pidoux_q/cu/rendu/cpp/d07/ex_2
// 
// Made by quentin PIDOUX
// Login   <pidoux_q@epitech.net>
// 
// Started on  Mon Jan 10 16:03:10 2011 quentin PIDOUX
// Last update Mon Jan 10 18:16:35 2011 quentin PIDOUX
//

#include "sickkoala.h"
#include <iostream>
#include <iomanip>


SickKoala::SickKoala(std::string name)
{
  this->name = name;
}

SickKoala:: ~SickKoala()
{
  std::cout << "Mr." << this->name << ": Kreooogg !! Je suis gueriiii !" 
	    << std::endl;
}

void SickKoala::poke()
{
  std::cerr << "Mr." << this->name << ": Gooeeeeerrk !! :'(" << std::endl;
}

bool SickKoala::takeDrug(std::string med)
{
  if (!med.compare("mars"))
    {
      std::cout << "Mr." << this->name << ": Mars, et ca Kreog !" << std::endl;
      return (true);
    }
  else if (!med.compare("buronzand"))
    {
      std::cout << "Mr." << this->name << ": Et la fatigue a fait son temps !" 
		<< std::endl;
      return (true);
    }
  else
    std::cerr << "Mr."<< this->name << ": Goerk !" << std::endl;
  return (false);
}
void SickKoala::overDrive(std::string sentence)
{
  size_t found;
  std::string str = "Kreog !";
  
  found =sentence.find(str);
  while (found != std::string::npos)
    {
      sentence.replace(sentence.find(str), str.length(), "1337 !");
      found =sentence.find(str);
    }
  std::cout << "Mr."<< this->name << ": " << sentence << std::endl;
}
