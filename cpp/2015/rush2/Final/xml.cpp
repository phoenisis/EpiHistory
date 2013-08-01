#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "Objet.h"
#include "Emballage.h"
#include "Carton.h"
#include "PapierCadeau.h"
#include "Jouet.h"
#include "Nounours.h"
#include "xml.h"
#include "PetitPoney.h"


std::string	into_xml(std::string &cadeau, Objet *Obj)
{
  if (Obj->getType() == 1)
    {
      cadeau += "<carton>\n";
      if (Obj->getIn() != NULL)
	into_xml(cadeau, Obj->getIn());
      cadeau += "</carton>\n";
    }
  if (Obj->getType() == 2)
    {
      cadeau =+ "<papiercadeau>\n";
      if (Obj->getIn() != NULL)
	into_xml(cadeau, Obj->getIn());
      cadeau += "</papiercadeau>\n";
    }
  if (Obj->getType() == 3)
    {
      cadeau += "<nounours>\n";
      if (Obj->getIn() != NULL)
	into_xml(cadeau, Obj->getIn());
      cadeau += Obj->getName();
      cadeau += "\n";
      cadeau += "</nounours>\n";
    }
  if (Obj->getType() == 4)
    {
      cadeau += "<petitponey>\n";
      if (Obj->getIn() != NULL)
	into_xml(cadeau, Obj->getIn());
      cadeau += Obj->getName();
      cadeau += "\n";
      cadeau += "</petitponey>\n";
    }
  return (cadeau);
}

std::string	name_xml()
{
  static int i = 1;
  std::ostringstream os;
  std::string s("");

  s += "cadeau";
  os << i;
  s += os.str();
  s += ".xml";
  i++;
  return(s);
}

void	creacadeau(Objet *Obj)
{
  std::string fichier = name_xml();
  std::ofstream cadeau(fichier.c_str(), std::ios::out);
    std::string str;
  if(cadeau)
    {
      into_xml(str, Obj);
        cadeau << str << std::endl;
      cadeau.close();
    }
  else
    std::cerr << "xml creation failled" << std::endl;  
}
