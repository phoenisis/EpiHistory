/*
** Picture.h for ex_0 in /home/pidoux_q/rendu/cpp/d14/ex_0
** 
** Made by quentin PIDOUX
** Login   <pidoux_q@epitech.net>
** 
** Started on  Mon Jan 17 09:49:37 2011 quentin PIDOUX
** Last update Mon Jan 17 14:33:27 2011 quentin PIDOUX
*/

#ifndef _PICTURE_H_
#define _PICTURE_H_

#include <string>
#include <iostream>

class Picture
{
 public:
  Picture();
  Picture(const Picture&);
  Picture(const std::string& file);
  ~Picture(); 
  Picture& operator = (Picture &c);
  bool getPictureFromFile(const std::string& file);
 std::string   data; 
 
 private:
 
};

#endif
