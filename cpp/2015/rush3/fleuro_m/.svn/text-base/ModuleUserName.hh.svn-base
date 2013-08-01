#ifndef		_MODULEUSERNAME_HH_

# define	_MODULEUSERNAME_HH_

#include "IMonitorModule.hh"

template<typename T>
class		ModuleUserName : public IMonitorModule<T>
{

public:
  ModuleUserName() {}
  virtual ~ModuleUserName() {}
  T getinfo(const std::string &filename) const
  {
    std::ifstream infile;
    T		res;
    
    infile.open(filename.c_str());
    if (infile.fail())
      {
	
      }
    getline(infile, res);
    res.erase(0, res.find("USERNAME=") + 9);
    res.erase(res.find("DEFAULT"));
    infile.close();
    return (res);
  }
};

#endif
