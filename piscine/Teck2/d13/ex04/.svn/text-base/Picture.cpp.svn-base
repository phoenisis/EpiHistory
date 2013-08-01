#include "Picture.h"
#include <string>
#include <iostream>
#include <fstream>

Picture::Picture()
{
  this->data = "";
}

Picture::Picture(const std::string& files)
{
  getPictureFromFile(files);
}

Picture &Picture::operator=(Picture &c)
{
    this->data = c.data;
    return *this;
}

bool Picture::getPictureFromFile(const std::string& files)
{
  long len;
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

