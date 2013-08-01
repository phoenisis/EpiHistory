#include "koalanurse.h"
#include <fstream>
#include <iostream>

KoalaNurse::KoalaNurse(int ID)
{
  this->ID = ID;
  this->hospital = false;
 }

void	 KoalaNurse::giveDrug(std::string med, SickKoala * patient)
{
  patient->takeDrug(med);
}

std::string KoalaNurse::readReport(std::string report)
{
  std::ifstream files;
  int len = 0;
  size_t found = 0;
  size_t rep = 0;
  char *str;
  std::string med ;  
  std::string patient = report;

  found = report.find(".report");
  while (found != std::string::npos)
    {
      rep = found;
      found = report.find(".report", found + 7);
    }
  if (report[rep + 8] == 0)
    files.open(report.data());
 if (files)
   {
     patient.assign(report.data());
     patient.erase(rep, 7);
     files.seekg(0, std::ios::end);
     len = files.tellg();
     files.seekg(0, std::ios::beg);
     str = new char [len];
     files.read(str, len);
     med.assign(str);
     delete[]str;
     std::cout <<"Nurse " 
	       << this->ID 
	       <<": Kreog ! Il faut donner un " 
	       << med 
	       << " a Mr." 
	       << patient 
	       << " !" << std::endl;
     files.close();
     return (med);
   }
 return (med);
}


void	 KoalaNurse::timeCheck()
{
  if (this->hospital == false)
    {
      std::cout <<"Nurse " 
		<< this->ID 
		<< ": Je commence le travail !" 
		<< std::endl;
      this->hospital = true;
    }
  else
    {
      std::cout <<"Nurse "<<this->ID
		<<": Je rentre dans ma foret d'eucalyptus !" 
		<< std::endl;
      this->hospital = false;
    }
}

KoalaNurse::~KoalaNurse()
{
  std::cout <<"Nurse " 
	    << this->ID 
	    << ": Enfin un peu de repos !" 
	    << std::endl;
}
