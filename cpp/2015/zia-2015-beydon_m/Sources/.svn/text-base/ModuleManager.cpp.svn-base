#include	"ModuleManager.h"

ModuleManager::ModuleManager()
{
}

ModuleManager::~ModuleManager()
{
	this->_mod.clear();
}

void		ModuleManager::addModule(SmartPointer<Module> mod)
{
	this->_mod.push_front(mod);
}

void		ModuleManager::deleteModule(std::string const & name)
{
	std::list< SmartPointer<Module> >::iterator	it;

	for (it = this->_mod.begin(); it != this->_mod.end() && (*it)->getModuleInformations()->name != name; ++it);
	if (it != this->_mod.end())
		this->_mod.erase(it);
}

void		ModuleManager::initModules()
{
	std::list< SmartPointer<Module> >::iterator	it;

	for (it = this->_mod.begin(); it != this->_mod.end(); ++it)
	{
		if ((*it)->isLoaded())
			(*it)->init();
	}
}

void		ModuleManager::loadModules()
{
	std::list< SmartPointer<Module> >::iterator	it;

	for (it = this->_mod.begin(); it != this->_mod.end(); ++it)
		(*it)->loadModule();
}

void		ModuleManager::unloadModules()
{
	std::list< SmartPointer<Module> >::iterator	it;

	for (it = this->_mod.begin(); it != this->_mod.end(); ++it)
		(*it)->unloadModule();
}

void		ModuleManager::execDirective(DirectivesOrder d, Request & req, Response & res, Network::t_socket s, struct sockaddr_in & sock)
{
	std::list< SmartPointer<Module> >::iterator	it;

	for (it = this->_mod.begin(); it != this->_mod.end(); ++it)
	{
		if ((*it)->isLoaded() && (*it)->hasDirective(d))
			(*it)->getDirectives()->callDirective(d, req, res, s, sock);
	}
}

bool		ModuleManager::hasModule(std::string const & name)
{
	std::list< SmartPointer<Module> >::iterator	it;

	for (it = this->_mod.begin(); it != this->_mod.end() && (*it)->getModuleInformations()->name != name; ++it);
	if (it != this->_mod.end())
		return (true);
	return (false);
}

SmartPointer<Module> &	ModuleManager::getModule(std::string const & name)
{
	std::list< SmartPointer<Module> >::iterator	it;

	for (it = this->_mod.begin(); it != this->_mod.end() && (*it)->getModuleInformations()->name != name; ++it);
	return (*it);
}