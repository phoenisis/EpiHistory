/*
** sickkoala.h for ex_4 in /home/pidoux_q/cu/rendu/cpp/d07/ex_4
** 
** Made by quentin PIDOUX
** Login   <pidoux_q@epitech.net>
** 
** Started on  Mon Jan 10 16:02:55 2011 quentin PIDOUX
** Last update Tue Jan 11 00:06:45 2011 quentin PIDOUX
*/

#ifndef _SICKKOALA_H_
#define _SICKKOALA_H_
#include <string>

class SickKoala
{
 public :
  SickKoala(std::string);
  std::string getName();
  void poke();
  bool takeDrug(std::string med);
  void overDrive(std::string sentence);
  ~SickKoala();

 private:
  std::string name;
 };

#endif
