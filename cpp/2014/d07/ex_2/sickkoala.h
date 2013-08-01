/*
** sickkoala.h for ex_2 in /home/pidoux_q/cu/rendu/cpp/d07/ex_2
** 
** Made by quentin PIDOUX
** Login   <pidoux_q@epitech.net>
** 
** Started on  Mon Jan 10 16:02:55 2011 quentin PIDOUX
** Last update Mon Jan 10 17:31:10 2011 quentin PIDOUX
*/

#ifndef _SICKKOALA_H_
#define _SICKKOALA_H_
#include <string>

class SickKoala
{
 public :
  std::string name;
  SickKoala(std::string);
  void poke();
  bool takeDrug(std::string med);
  void overDrive(std::string sentence);
  ~SickKoala();
 };

#endif
