#ifndef __MODULE_H__
# define	__MODULE_H__

#include "ModuleInfos.h"
#include "Directives.h"

class Module {
public:
	virtual ~Module() {};
	virtual void		assignDirectives(Directives *directives) = 0;
	virtual Directives	*getDirectives() = 0;
	virtual ModuleInfos	*getModuleInformations() = 0;
	virtual bool		hasDirective(DirectivesOrder directiveorder) = 0;
	virtual void		init() = 0;
	virtual bool		isLoaded() = 0;
	virtual void		loadModule() = 0;
	virtual void		unloadModule() = 0;
};


#endif // !_MODULE_H_
