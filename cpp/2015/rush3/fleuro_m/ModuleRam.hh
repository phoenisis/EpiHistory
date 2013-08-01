#ifndef		_MODULERAM_HH_

# define	_MODULERAM_HH_

#include <cstdlib>
#include "IMonitorModule.hh"

template<typename T>
class		ModuleRam : public IMonitorModule<T>
{

public:
  ModuleRam() {}
  virtual ~ModuleRam() {}
  T getinfo(const std::string &filename) const
  {
    std::ifstream infile;
    std::string	s;
    std::string	s2;
    T		res;
    int		i = 0;
    int		y = 0;

    infile.open(filename.c_str());
    if (infile.fail())
      {
	
      }
    while (i < 2)
      {
	getline(infile, s);
	for (y = 0; s[y] < '0' || s[y] > '9'; y++);
	for (y = y; s[y] >= '0' && s[y] <= '9'; y++)
	  s2 += s[y];
	res.push(atol(s2.c_str()));
	s2 = "";
	i++;
      }
    infile.close();
    return (res);
  }
};

#endif
