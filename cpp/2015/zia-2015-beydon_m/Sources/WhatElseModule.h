#ifndef _WHAT_ELSE_MODULE_H_
# define	_WHAT_ELSE_MODULE_H_
# include	"Plugins.h"

#include "Module.h"

class WhatElseModule : public Module
{
	Directives	*directives_;
	std::string _dll;
	ModuleInfos	*infos_;
	bool		isLoaded_;
	Plugin::LibraryLoader	_lib;
public:
	WhatElseModule(std::string const &);
	~WhatElseModule();
	void		assignDirectives(Directives *directives);
	Directives	*getDirectives();
	ModuleInfos	*getModuleInformations();
	bool		hasDirective(DirectivesOrder directiveorder);
	void		init();
	bool		isLoaded();
	void		loadModule();
	void		unloadModule();
};

#endif // !_WHAT_ELSE_MODULE_H_
