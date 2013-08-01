//
// Picture.cpp for ex_0 in /home/pidoux_q/rendu/cpp/d14/ex_0
// 
// Made by quentin PIDOUX
// Login   <pidoux_q@epitech.net>
// 
// Started on  Mon Jan 17 09:49:48 2011 quentin PIDOUX
// Last update Mon Jan 17 16:11:59 2011 quentin PIDOUX
//

#include "Picture.h"
#include <string>
#include <iostream>
#include <fstream>

Picture::Picture()
{
  this->data = "";
}

Picture::Picture(const Picture &c)
{
  this->data = c.data;
}

Picture& Picture::operator = (Picture &c)
{
  this->data = c.data;
  return (*this);
}

Picture::Picture(const std::string& files)
{
  getPictureFromFile(files);
}

bool Picture::getPictureFromFile(const std::string& files)
{
  int len;
  char * str;
  std::ifstream is;
 
  is.open(files.data());
  if (!is)
    {
      this->data =  "ERROR";
      return (false);
    }
  else
    {
      is.seekg (0, std::ios::end);
      len = is.tellg();
      is.seekg (0, std::ios::beg);
      str = new char [len];
      is.read(str, len);
      is.close();
      this->data = str;
      return (true);
    }
}

Picture::~Picture()
{
}

