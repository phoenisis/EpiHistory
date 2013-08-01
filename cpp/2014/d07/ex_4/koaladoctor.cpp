//
// koaladoctor.cpp for ex_4 in /home/pidoux_q/cu/rendu/cpp/d07/ex_4
// 
// Made by quentin PIDOUX
// Login   <pidoux_q@epitech.net>
// 
// Started on  Mon Jan 10 21:53:38 2011 quentin PIDOUX
// Last update Tue Jan 11 08:31:21 2011 quentin PIDOUX
//

#include "koaladoctor.h"
#include "koalanurse.h"
#include "sickkoala.h"
#include <fstream>
#include <string>
#include <iostream>
#include <cstdlib>

KoalaDoctor::KoalaDoctor(std::string name)
{
  this->name = name;
  this->hospital = false;
  std::cout << "Dr." << this->name << ": Je suis le Dr."<< this->name 
	    << "! Comment Kreoggez-vous ?" << std::endl;
}

void KoalaDoctor::diagnose(SickKoala * patient)
{
  char * buff;
  std::string str;
  str.assign(patient->getName().data());
  str.append(".report");
  int i = random()%5;
  char med[5][22] = {"mars", "Buronzand", "Viagra", "Extazy", "Feuille d'eucalyptus"};
  
  std::cout <<"Dr."<< this->name <<": Alors, qu'est-ce qui vous goerk, Mr."
	<<patient->getName() <<"?" <<std::endl;
  patient->poke();

  std::ofstream outfile (str.data(),std::ofstream::binary);
  outfile.write (med[i], 21);
  outfile.close();
}

void KoalaDoctor::timeCheck()
{
 if (this->hospital == false)
    {
      std::cout <<"Dr." << this->name <<": Je commence le travail !" 
		<< std::endl;
      this->hospital = true;
    }
  if (this->hospital == true)
    {
      std::cout <<"Dr."<<this->name
		<<": Je rentre dans ma foret d'eucalyptus !" << std::endl;
      this->hospital = false;
    }
}

KoalaDoctor::~KoalaDoctor(){
}

