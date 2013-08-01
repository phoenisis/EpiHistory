#ifndef _CONFIG_H_
#define	_CONFIG_H_

#include <iostream>
#include <list>
#include "Portability.h"
#include "tinyxml2.h"

typedef	struct s_module {
	std::string	name_;
	std::string path_;
} t_module;

typedef struct s_config {
	int		port_;
	int		buffSize_;
	int		nbThreads_;
	int		maxClients_;
	std::string	path_;
	std::list<t_module>	modules_;
} t_config;

class Config {
private:
	tinyxml2::XMLDocument	doc_;
    s_config                conf_;
    t_module				mod_;
    bool					default_;
public:
	Config(std::string const &);
	~Config();

	void	displayServerConf();
	void	retrieveModulesInfos();
	void 	checkInfoServer();
	
	t_config	getConfig() const;
	int			getPort() const;
	int			getBuffSize() const;
	int			getNbThreads() const;
	int			getMaxClients() const;
	std::string	getPath() const;
	std::list<t_module>	getModules() const;
};

#endif // !_CONFIG_H_
