#ifndef __MODULEMANAGER_H__
# define __MODULEMANAGER_H__
# include	<list>
# include	<string>
# include	"DirectivesOrder.h"
# include	"Request.h"
# include	"Response.h"
# include	"Network.h"
# include	"SmartPointer.h"
# include	"Module.h"

class ModuleManager
{
public:
	ModuleManager();
	~ModuleManager();
	void			addModule(SmartPointer<Module>);
	void			deleteModule(std::string const &);
	void			initModules();
	void			loadModules();
	void			unloadModules();
	void			execDirective(DirectivesOrder, Request &, Response &, Network::t_socket, struct sockaddr_in &);
	bool			hasModule(std::string const &);
	SmartPointer<Module> &	getModule(std::string const &);
private:
	std::list< SmartPointer<Module> > _mod;
};


#endif // !__MODULEMANAGER_H__
