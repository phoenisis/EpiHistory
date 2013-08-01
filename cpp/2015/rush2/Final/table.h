/*
** table.h for table in /home/pouget_t//piscine_cpp_rush2-2015-pidoux_q
** 
** Made by thomas pouget
** Login   <pouget_t@epitech.net>
** 
** Started on  Sat Jan 14 15:18:15 2012 thomas pouget
** Last update Sun Jan 15 02:28:32 2012 thomas pouget
*/

#ifndef __TABLE_H__
#define __TABLE_H__
#include "Objet.h"
#include <iostream>
#include <string>

class ITable
{
 public:
  virtual ~ITable() {}
  virtual Objet **regardertable() = 0;
  virtual Objet *gettab(int i) const = 0;
  virtual void putnewobjet(Objet *toput) = 0;
  virtual Objet* takeObjet(int pos) = 0;
  virtual void settab(Objet *toput) = 0;
};

class TablePePeNoel: public ITable
{
 private:
  Objet **OnTable;

 public:
  TablePePeNoel();
  TablePePeNoel(const TablePePeNoel&);
  ~TablePePeNoel();
  virtual Objet** regardertable();
  virtual Objet *gettab(int i) const;
  virtual void putnewobjet(Objet *toput);
  virtual Objet* takeObjet(int pos);
  virtual void settab(Objet *toput);
  TablePePeNoel& operator=(TablePePeNoel const& other);
};

#endif
