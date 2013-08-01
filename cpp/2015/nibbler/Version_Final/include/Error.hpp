
#ifndef  __ERROR_HPP__
# define __ERROR_HPP__

#include <iostream>
#include <stdexcept>
#include <string>
#include <fstream>
#include <sstream>

class		Error
{
public:
  void		print_usage_min(int, int);
  void		print_usage_max(int, int);
  void		check_argc(int argc); 
  std::string	check_argv( int argc, char *argv[]);
  std::string	check_lib(std::string lib);
  void		check_range(const std::string &nbr);
  void		is_a_number(const std::string &nbr);    
};

#endif /* ! __ERROR_HPP__ */
