#include <stdexcept>
#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include "Action.hh"

//                CHECK EXIT

int		is_exit(std::string str)
{
  if (str.find("exit") == 0)
    return (1);
  else
    return (0);
}

void	checkExit(const char *filename)
{
  std::ifstream infile;
  std::string   s;
  int			check = 0;

  try
    {
      infile.open(filename);
      if (infile.fail())
	{
	  throw std::range_error("wrong file name");
	}
      else
	{
	  while (infile.good() && check == 0)
	    {
	      getline(infile, s);
	      check = is_exit(s);
	    }
	  if (check == 0)
	    throw std::runtime_error("wrong file format : no exit at end of file");
	}
      infile.close();
    }
  catch (const std::range_error& e)
    {
      std::cout << "std::range_error : "
  		<< e.what() << std::endl;
    }
  catch (const std::runtime_error& e)
    {
      std::cout << "std::range_error : "
  		<< e.what() << std::endl;
      infile.close();
    }
}

//                PARSEUR

void	myparse(const char *filename, action &act)
{
  std::map<std::string, void (action::*)(std::string &)>::const_iterator it;
  std::ifstream infile;
  std::string   s;
  std::string	todo;
  std::string	data;
  std::string	error;
  int		i;

  try
    {
      infile.open(filename);
      while (infile.good())
	{
	  getline(infile, s);
	  if (s.size() > 0)
	    {
	      for (i = 0; s[i] == ';' || (s[i] >= 'a' && s[i] <= 'z'); i++) ;
	      todo = s;
	      todo.erase(i);
	      if (todo.size() > 0)
		{
		  if ((it = act.getMap().find(todo)) != act.getMap().end())
		    {
		      data = s;
		      data.erase(0, i + 1);
		      if (data.find(';') != std::string::npos)
			data.erase(data.find(';'));
		      (act.*it->second)(data);
		    }
		  else
		    {
		      error = "wrong action name : ";
		      error += todo;
		      throw std::range_error(error);
		    }
		}
	    }
	}
    }
  catch (const std::range_error& e)
    {
      std::cout << "std::range_error : "
  		<< e.what() << std::endl;
      it = act.getMap().find("exit");
      error = "";
      (act.*it->second)(error);
      infile.close();
    }
  catch (const std::runtime_error& e)
    {
      std::cout << "std::runtime_error : "
  		<< e.what() << std::endl;
      it = act.getMap().find("exit");
      error = "";
      (act.*it->second)(error);
      infile.close();
    }
}

//                START FUNC

void	abstractFile(const char *filename, action &act)
{
  std::map<std::string, void (*)(std::string &)>::iterator it;
  std::ifstream infile;
  std::string   s;

  checkExit(filename);
  myparse(filename, act);
}

//		MAIN

int main(int ac, char **av)
{
  action	act;

  try
    {
      if (ac == 2)
	{
	  abstractFile(av[1], act);
	}
      else
	throw std::runtime_error("no imput file");
    }
  catch (const std::logic_error& e)
    {
    }
  catch (const std::exception& e)
    {
      std::cout << "std::exception : "
		<< e.what() << std::endl;

    }
  return (0);
}
