
#include <stdlib.h>
#include "CExceptions.hpp"
#include "Error.hpp"

void	Error::print_usage_min(int w, int h)
{
  std::cout << "Usage : ./Nibbler Width (Greater than 20) : " << w << ", Height(Greater than 20) : " << h << ", lib_X.so" << std::endl;
  std::cerr << "width or height too small for correct displaying." << std::endl;
  std::cerr << "Check that they are greater than 20." << std::endl;
}

void	Error::print_usage_max(int w, int h)
{
  std::cout << "Usage : ./Nibbler Width(Smaller than 60) : " << w << ", Height(Smaller than 60) : " << h << ", lib_X.so" << std::endl;
  std::cerr << "width or height too big for correct displaying." << std::endl;
  std::cerr << "Check that they are smaller than 60." << std::endl;
}

void	Error::is_a_number(const std::string &nbr)
{
  int	i = 0;

  while (nbr[i])
    {
      if (nbr[i] >= '0' && nbr[i] <= '9')
	++i;
      else
	throw CError("isn't a number");
    }
}

void	Error::check_range(const std::string &nbr)
{
  if (nbr.length() > 10)
    throw CError("is out of range");
  else
    {
      unsigned int		nb;
      std::istringstream	ss(nbr);

      ss >> nb;
      if (nb < 2)
	throw CError("is under of range");
      if (nb > 2147483646)
	throw CError("is out of range");
    }
}

void	Error::check_argc(int argc)
{
  if (argc != 4)
    throw CError("Usage : ./Nibbler Width  Height lib_X.so");  
}

std::string	Error::check_lib(std::string	lib)
{
  size_t	found;

  found = lib.find("./");
  if (found == std::string::npos)
    {    
      std::string	tmp = lib;
      lib.assign("./");
      lib.append(tmp);
      }
  return (lib);
}

std::string	Error::check_argv(int argc,char *argv[])
{
 
  try{
    check_argc(argc);
  }
  catch(const std::exception &e)
    {
      abort();
    }
  std::string	nbr = argv[1];
  try {
    is_a_number(nbr);
    check_range(nbr);
  }
  catch (const std::runtime_error &e)
    {
      //std::cout << nbr << " "<< e.what()<<std::endl;
      abort();
    }
  nbr = argv[2];
  try {
    is_a_number(nbr);
    check_range(nbr);
  }
  catch (const std::runtime_error &e)
    {
      //std::cout << nbr <<" "<<e.what()<<std::end;
      abort();
    }
  std::string	lib = argv[3];
  return (check_lib(lib));
}
