#ifndef		_MODULECPU_HH_

# define	_MODULECPU_HH_

#include "IMonitorModule.hh"

template<typename T>
class		ModuleCPU : public IMonitorModule<T>
{

public:
  ModuleCPU() {}
  virtual ~ModuleCPU() {}
  T getinfo(const std::string &filename) const
  {
    std::ifstream infile;
    T		res;
    std::string	tmp;
    std::string	tmp2;
    int		i = 0;

    infile.open(filename.c_str());
    if (infile.fail())
      {
	
      }
    while (i < 2)
      {
	getline(infile, tmp);
	if (tmp.find("model name") != std::string::npos)
	  {
	    tmp.erase( 0, tmp.find(":") + 2);
	    tmp2 = tmp;
	    tmp.erase(tmp.find("  "));
	    tmp2.erase(0, tmp2.find("GHz") - 4);
	    res.push(tmp);
	    res.push(tmp2);
	    i++;
	  }
	if (tmp.find("cpu cores") != std::string::npos)
	  {
	    tmp.erase( 0, tmp.find(":") + 2);
	    res.push(tmp);
	    i++;
	  }
      }
    infile.close();
    return (res);
  }
};

#endif
