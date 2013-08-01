#include <fstream>
#include <ctime> 
#include <cstdio>
#include <iostream>
#include <cstdlib>
#include "koaladoctor.h"
#include "sickkoala.h"

KoalaDoctor::KoalaDoctor(std::string name)
{
  this->name = name;
  this->hospital = false;

  std::cout << "Dr." 
	    << this->name 
	    << ": Je suis le Dr."
	    << this->name
	    << "! Comment Kreoggez-vous ?"
	    << std::endl;
}

KoalaDoctor::~KoalaDoctor()
{
}

void KoalaDoctor::diagnose(SickKoala *patient)
{
  std::string   medics;
  std::string   name = patient->getName();
  std::ofstream file;
  int           rand;

  rand =  (random() % 5 ) + 1;
  name += ".report";  

  switch (rand)
    {
    case 1:
            medics = "mars";
      break;
    case 2:
            medics = "Buronzand";
      break;
    case 3:
            medics = "Viagra";
      break;
    case 4:
            medics = "Extasy";
      break;
    case 5:
            medics = "Feuille d'eucalyptus";
      break;
    }
  std::cout << this->name  
	    << ": Alors, qu'est-ce qui vous goerk, Mr." 
	    << patient->getName()
	    << " ?" << std::endl;
  patient->poke();                                                                            
  file.open(name.c_str(), std::ios::out | std::ios::trunc);
  file << medics;
  file.close();
}

void KoalaDoctor::timeCheck()
{
  if (this->hospital == false)
    {
      std::cout << "Dr."
		<< this->name 
		<< ": Je commence le travail !"
		<< std::endl;
      this->hospital = true;
    }
  else if (this->hospital == true)
    {
      std::cout << "Dr."
		<< this->name
		<< ": Je rentre dans ma foret d’eucalyptus !"
		<< std::endl;
      this->hospital = false;
    }
}
