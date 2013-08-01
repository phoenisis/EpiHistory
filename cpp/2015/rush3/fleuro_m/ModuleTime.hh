#ifndef		_MODULETIME_HH_

# define	_MODULETIME_HH_

#include "IMonitorModule.hh"

template<typename T>
class		ModuleTime : public IMonitorModule<T>
{

public:
  ModuleTime() {}
  virtual ~ModuleTime() {}
  T getinfo(const std::string &filename) const
  {
    std::ifstream infile;
    T		res;
    std::string	s;

    infile.open(filename.c_str());
    if (infile.fail())
      {
	
      }
    getline(infile, s);
    s.erase(0, s.find(":") + 2);
    res.push(s);
    getline(infile, s);
    s.erase(0, s.find(":") + 2);
    res.push(s);
    infile.close();
    return (res);
  }
};

#endif
