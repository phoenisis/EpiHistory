#ifndef		_IMODULENETWORK_HH_

# define	_IMODULENETWORK_HH_

#include "IMonitorModule.hh"
#include <cstdlib>
#include <stack>
#include <iostream>
#include <fstream>
#include <string>


template<typename T>
class		ModuleNetwork : public IMonitorModule<T>
{

public:
  ModuleNetwork() {}
  virtual ~ModuleNetwork() {}
  T getinfo(const std::string &filename) const
  {
    std::ifstream infile;
    std::string	s;
    std::string	s2;
    T		res;
    int		i = 0;
    int		y = 0;
    int		j = 0;
    std::string	tst;
   
    infile.open(filename.c_str());
    /*if (infile.fail())
      {
      
      }*/
    while(i != 4)
      {
	getline(infile, s);
	i++;
      }
    s.erase(0 ,s.find(":") + 2);
    s2 = s;
    s.erase(s.find(" "));
    res.push(atoi(s.c_str()));
    s2.erase(0, s2.find(" "));
    while(s2[j] && y < 7)
      {
	if (s2[j] >= '0' && s2[j] <= '9')
	  {
	    y++;
	    while (s2[j] >= '0' && s2[j] <= '9')
	      j++;
	  }
	j++;
      }
    s2.erase(0, j);
    s2.erase(s2.find(" "));
    res.push(atoi(s2.c_str()));
    infile.close();
    return (res);
  }
};

#endif
