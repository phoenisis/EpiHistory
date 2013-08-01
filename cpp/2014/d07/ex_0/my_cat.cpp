//
// my_cat.cpp for ex_0 in /home/pidoux_q/cu/rendu/cpp/d07/ex_0
// 
// Made by quentin PIDOUX
// Login   <pidoux_q@epitech.net>
// 
// Started on  Mon Jan 10 13:07:40 2011 quentin PIDOUX
// Last update Mon Jan 17 10:34:38 2011 quentin PIDOUX
//

#include <fstream>
#include <iostream>

int main(int ac, char **av)
{
  int i = 1;
  char *str;
  int len = 0;
  std::ifstream files;

  if (av[i])
    {
      while (av[i])
	{
	  files.open(av[i], std::ifstream::in);
	  if (!files)
	    std::cerr << "my_cat: <"<< av[i] 
		      << ">: No such file or directory" << std::endl;
	  else {
	    files.seekg (0, std::ios::end);
	    len = files.tellg();
	    files.seekg (0, std::ios::beg);
	    str = new char [len];
	    files.read(str, len);
	    str[len] = 0;
	    std::cout << str;
	    files.close();
	    delete[]str;
	  }
	  i++;
	}
    }
  else
    std::cout << "my_cat: Usage : ./my_cat file [...]" << std::endl;
  return (0);
}
