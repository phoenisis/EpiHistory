#ifndef		_MODULEOS_HH_

# define	_MODULEOS_HH_

#include "IMonitorModule.hh"

template<typename T>
class		ModuleOS : public IMonitorModule<T>
{

public:
  ModuleOS() {}
  virtual ~ModuleOS() {}
  T getinfo(const std::string &filename) const
  {
    std::ifstream infile;
    T		res;
    
    infile.open(filename.c_str());
    if (infile.fail())
      {
	
      }
    getline(infile, res);
  
    infile.close();
    return (res);
  }
};

#endif
