//
// table.cpp for table in /home/pouget_t//piscine_cpp_rush2-2015-pidoux_q
// 
// Made by thomas pouget
// Login   <pouget_t@epitech.net>
// 
// Started on  Sat Jan 14 15:35:06 2012 thomas pouget
// Last update Sun Jan 15 02:39:55 2012 thomas pouget
//

#include <iostream>
#include <string>
#include "table.h"
#include "Objet.h"
#include "PetitPoney.h"
#include "Nounours.h"
#include "PapierCadeau.h"
#include "Jouet.h"
#include "Carton.h"

Objet**			TablePePeNoel::regardertable()
{
  return (this->OnTable);
}

Objet*			TablePePeNoel::gettab(int i) const
{
  return (this->OnTable[i]);
}

void			TablePePeNoel::putnewobjet(Objet *toput)
{
  int			i;

  for (i = 0; this->gettab(i) != NULL && i < 11; ++i)
    {
    }
  if (i < 10)
    this->~TablePePeNoel();
  else
    this->settab(toput);
}

Objet*			TablePePeNoel::takeObjet(int pos)
{
  Objet*       		tmp;

  tmp = this->OnTable[pos];
  this->OnTable[pos] = NULL;
  return (tmp);
}

void			TablePePeNoel::settab(Objet * toput)
{
  int			i;
  
  for(i = 0; this->OnTable[i] != NULL; ++i)
    {
    }
  this->OnTable[i] = toput;
}

TablePePeNoel::TablePePeNoel()
{
  Objet	 *pp =  new PetitPoney("petit tonnerre");
  Objet	 *nn = new Nounours("booba");
  Objet	 *pc1 = new PapierCadeau();
  Objet	 *pc2 = new PapierCadeau();
  Objet	 *c1 = new Carton();
  Objet	 *c2 = new Carton();
  int	 i;


  std::cout << "Nouvelle table" << std::endl;
  this->OnTable = new Objet*[11];
  for(i = 0; i <= 11; ++i)
    this->OnTable[i] = NULL;
  this->settab(pp);
  this->settab(nn);
  this->settab(pc1);
  this->settab(pc2);
  this->settab(c1);
  this->settab(c2);
}

TablePePeNoel::TablePePeNoel(const TablePePeNoel &other)
{
  int			i;
  
  if(this != &other)
    {
      this->OnTable = new Objet*[11];
      for(i = 0; i <= 11; ++i)
	this->OnTable[i] = other.gettab(i);
    }
}

TablePePeNoel::~TablePePeNoel()
{
  int			i;

  std::cout << "Cela fait plus de 10 cadeaux, je suis cassee" << std::endl;
  for (i = 0; i <= 10; ++i)
    delete this->OnTable[i];
  delete[] this->OnTable;
}

TablePePeNoel& TablePePeNoel::operator=(TablePePeNoel const & other)
{
  int			i;

  if (&other != this)
    {
      if (this->OnTable)
	delete[] this->OnTable;	
      this->OnTable = new Objet*[11];
      for(i = 0; other.gettab(i) != NULL; ++i)
	this->OnTable[i] = other.gettab(i);
      this->OnTable[i] = NULL;
    }
  return (*this);
}