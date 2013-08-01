
#ifndef		__WINDLLOADER_HPP__
# define	__WINDLLOADER_HPP__

#include <windows.h>
#include <iostream>
#include "CExceptions.hpp"
#include "IPlugin.hpp"

template <typename T>
class			DLLoader : public	IPlugin<T>
{
public:
  DLLoader(void);
  DLLoader(std::string const &);
  DLLoader(DLLoader const &);
  ~DLLoader(void);

public:
  DLLoader		&operator=(DLLoader const &);
  virtual bool		loadLibrary(const char *);
  virtual bool		freeLibrary(void);
  virtual T		*getInstance(void);

private:
  HMODULE	       	_handle;
};

//Initialisation

template <typename T>
DLLoader<T>::DLLoader(void)
{

}

template <typename T>
DLLoader<T>::DLLoader(std::string const &libname)
{
  if (this->loadLibrary(libname.c_str()) == false)
    std::cerr << "LoadLibrary failed..." << std::endl;
  std::cout << "Library " << libname.c_str() << " loaded..." << std::endl;
}

template <typename T>
DLLoader<T>::DLLoader(DLLoader<T> const &data)
{
  *this = data;
}

//Destruction

template <typename T>
DLLoader<T>::~DLLoader(void)
{
  if (this->freeLibrary() == false)
    std::cout << "FreeLibrary failed..." << std::endl;
  std::cout << "Library destroyed..." << std::endl;
}

//Surcharges

template <typename T>
DLLoader<T>	&DLLoader<T>::operator=(DLLoader<T> const &data)
{
  if (&data != this)
    this->_handle = data._handle;
  return (*this);
}

//Others

template <typename T>
bool		DLLoader<T>::loadLibrary(const char *libname)
{
  if ((this->_handle = LoadLibrary(libname)) == NULL)
    return (false);
  return (true);
}

template <typename T>
T		*DLLoader<T>::getInstance(void)
{
  T		*(*func_ptr)();

  if ((func_ptr = reinterpret_cast<T *(*)()>(GetProcAddress(this->_handle, "getInstance"))) == NULL)
    std::cerr << "GetProcAddress failed..." << std::endl;
  return (func_ptr());
}

template <typename T>
bool		DLLoader<T>::freeLibrary(void)
{
  if (FreeLibrary(this->_handle) == 0)
    return (false);
  return (true);
}

#endif		// ! __WINDLLOADER_HPP__
