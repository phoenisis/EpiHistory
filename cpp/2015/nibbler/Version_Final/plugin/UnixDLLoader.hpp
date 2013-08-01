
#ifndef		__UNIXDLLOADER_HPP__
# define	__UNIXDLLOADER_HPP__

#include	<iostream>
#include	<cstdlib>
#include	<dlfcn.h>
#include	"IPlugin.hpp"

template <class T>
class		UnixDLLoader : public IPlugin<T>
{
 public:
  UnixDLLoader(void);
  UnixDLLoader(std::string const &);
  UnixDLLoader(UnixDLLoader const &);
  ~UnixDLLoader(void);

 public:
  UnixDLLoader		&operator=(UnixDLLoader const &);
  virtual T		*getInstance(const char *);  
  virtual bool		loadLibrary(const char *);
  virtual bool		freeLibrary(void);

private:  
  void		*handle;
};

//Initialisation

template <typename T>
UnixDLLoader<T>::UnixDLLoader(void)
{
  
}

template <typename T>
UnixDLLoader<T>::UnixDLLoader(std::string const &lib)

{
  this->loadLibrary(lib.c_str());
  std::cout << "Library loaded.\n";
}

template <typename T>
UnixDLLoader<T>::UnixDLLoader(UnixDLLoader const &data)
{
  *this = data;
}

//Destruction

template <typename T>
UnixDLLoader<T>::~UnixDLLoader(void)
{
  this->freeLibrary();
}

//Surcharges

template <typename T>
UnixDLLoader<T>		&UnixDLLoader<T>::operator=(UnixDLLoader<T> const &data)
{
  if (&data != this)
    this->handle = data.handle;
  return (*this);
}

template <typename T>
T		*UnixDLLoader<T>::getInstance(const char *symbol)
{
  T		*(*funcPtr)();

  if ((funcPtr = reinterpret_cast<T *(*)()>(dlsym(this->handle, symbol))) == NULL)
    {
      std::cout << "dlsym failed with ptr = '" << symbol << "'"<< std::endl;

      return (NULL);
    }
  std::cout << "Library's running." << std::endl;

  return (funcPtr());
}

template <typename T>
bool		UnixDLLoader<T>::loadLibrary(const char *filename)
{
  if ((this->handle = dlopen(filename, RTLD_LAZY)) == NULL)
    {
      std::cerr << "Cannot open Library  named " << filename << std::endl;

      return (false);
    }
  return (true);
}

template <typename T>
bool		UnixDLLoader<T>::freeLibrary(void)
{
  if (dlclose(this->handle) != 0)
    {
      std::cerr << "Cannot close library.\n";
      return (false);
    }
  std::cout << "Library destroyed." << std::endl;
  return (true);
}

#endif		// ! __UNIXDLLOADER_HPP__
