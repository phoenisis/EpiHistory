
#include "DLLoader.hpp"

DLLoader::DLLoader(std::string const &lib)
{
  void	*handle;

  std::cout << lib << std::endl;
  
  handle = dlopen(lib.c_str() , RTLD_LAZY);
  this->_Handle = handle;
  if (this->_Handle == NULL)
    {
      std::cerr << dlerror() << std::endl;
      exit(EXIT_FAILURE);
    }
  _ptr_func_interface = (reinterpret_cast<ptr>(dlsym(this->_Handle, "fuckInterface")));
  if (_ptr_func_interface == NULL)
    {
      std::cerr << dlerror() << std::endl;
      close_handle();
      exit(EXIT_FAILURE);
    }
}

DLLoader::~DLLoader()
{
  close_handle();
}

IApplication	*DLLoader::getInterface()
{
  return (_ptr_func_interface());
}

void		DLLoader::close_handle()
{
  if (dlclose(_Handle) != 0)
    {
      std::cerr << dlerror() << std::endl;
      exit(EXIT_FAILURE);
    }
}
