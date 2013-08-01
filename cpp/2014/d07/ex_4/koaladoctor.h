/*
** koaladoctor.h for ex_4 in /home/pidoux_q/cu/rendu/cpp/d07/ex_4
** 
** Made by quentin PIDOUX
** Login   <pidoux_q@epitech.net>
** 
** Started on  Mon Jan 10 21:53:29 2011 quentin PIDOUX
** Last update Tue Jan 11 00:20:32 2011 quentin PIDOUX
*/

#ifndef _KOALADOCTOR_H_
#define _KOALADOCTOR_H_
#include "koalanurse.h"
#include "sickkoala.h"
#include <string>

class KoalaDoctor
{
 public:
  std::string name;
  KoalaDoctor(std::string name);
  void diagnose(SickKoala * patient);
  void timeCheck();
  ~KoalaDoctor();
 private:
  bool hospital;
 };

#endif
