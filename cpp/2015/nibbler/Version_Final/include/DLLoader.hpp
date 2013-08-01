
#ifndef  __DLLOADER_HPP__
# define __DLLOADER_HPP__

#include <iostream>
#include <string>
#include <dlfcn.h>
#include <stdlib.h>
#include "IApplication.hpp"

class DLLoader
{
public:
  DLLoader(std::string const &lib);
  ~DLLoader();
  void		close_handle();
  IApplication	*getInterface();

private:
  typedef IApplication *(*ptr)();
  ptr		_ptr_func_interface;
  void		*_Handle;
};

#endif /* ! __DLLOADER_HPP__ */
