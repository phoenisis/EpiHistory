/*
** koalanurse.h for ex_3 in /home/pidoux_q/cu/rendu/cpp/d07/ex_3
** 
** Made by quentin PIDOUX
** Login   <pidoux_q@epitech.net>
** 
** Started on  Mon Jan 10 18:49:18 2011 quentin PIDOUX
** Last update Tue Jan 11 07:22:28 2011 quentin pidoux
*/

#ifndef _KOALANURSE_H_
#define _KOALANURSE_H_
#include "sickkoala.h"
#include <string>

class KoalaNurse
{
 public :
  int	ID;
  KoalaNurse(int ID);
  void	 giveDrug(std::string med, SickKoala * patient);
  std::string readReport(std::string report);
  ~KoalaNurse();
  void	timeCheck();
  bool	hospital;  
 };

#endif
