#ifndef		_INFO_HH_

# define	_INFO_HH_

#include <stack>
#include <string>
#include "ModuleOS.hh"
#include "ModuleRam.hh"
#include "ModuleCPU.hh"
#include "ModuleUserName.hh"
#include "ModuleTime.hh"
#include "ModuleNetwork.hh"
#include "IMonitorModule.hh"

class		Info
{
  std::string	ostype;
  std::string	osrelease;
  std::string	hostname;
  std::string	username;
  long		ramfree;
  long		ramtotal;
  std::string	nbcore;
  std::string	frequence;
  std::string	coretype;
  std::string	date;
  std::string	heure;
  long		transmited;
  long		received;
  long		old_transmited;
  long		old_received;

public:
  Info();
  ~Info();
  void		refresh();
  std::string	getOstype() const;
  std::string	getOsrelease() const;
  std::string	getHostname() const;
  std::string	getUsername() const;
  long		getRamfree() const;
  long		getRamtotal() const;
  std::string	getNbcore() const;
  std::string	getFrequence() const;
  std::string	getCoretype() const;
  std::string	getDate() const;
  std::string	getHeure() const;
  long		getTransmited() const;
  long		getReceived() const;
};

#endif
