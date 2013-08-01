#include "sickkoala.h"
#include <iostream>
#include <iomanip>


SickKoala::SickKoala(std::string name)
{
  this->name = name;
}

SickKoala:: ~SickKoala()
{
  std::cout << "Mr." 
	    << this->name 
	    << ": Kreooogg !! Je suis gueriiii !" 
	    << std::endl;
}

void SickKoala::poke()
{
  std::cout << "Mr." 
	    << this->name 
	    << ": Gooeeeeerrk !! :'(" 
	    << std::endl;
}

bool SickKoala::takeDrug(std::string med)
{
  if (!med.compare("mars"))
    {
      std::cout << "Mr." 
		<< this->name 
		<< ": Mars, et ca Kreog !" 
		<< std::endl;
      return (true);
    }
  else if (!med.compare("buronzand"))
    {
      std::cout << "Mr." 
		<< this->name 
		<< ": Et la fatigue a fait son temps !" 
		<< std::endl;
      return (true);
    }
  else
    std::cout << "Mr."
	      << this->name 
	      << ": Goerk !" 
	      << std::endl;
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
  std::cout << "Mr."
	    << this->name 
	    << ": " 
	    << sentence 
	    << std::endl;
}
