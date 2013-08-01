#include "WhatElseModule.h"

WhatElseModule::WhatElseModule(std::string const & dll): _dll(dll), isLoaded_(false) {
}

WhatElseModule::~WhatElseModule() {
	if (this->isLoaded_)
		this->unloadModule();
}

void		WhatElseModule::assignDirectives(Directives *directives) {
	directives_ = directives;
}

Directives	*WhatElseModule::getDirectives() {
	return directives_;
}

ModuleInfos	*WhatElseModule::getModuleInformations() {
	return infos_;
}

bool		WhatElseModule::hasDirective(DirectivesOrder directiveorder)
{
	if (this->infos_->managedDirectives & directiveorder)
		return (true);
	return (false);
}

void		WhatElseModule::init() {
	if (this->isLoaded_)
		directives_->init();
	else
	{
		this->loadModule();
		this->directives_->init();
	}

}

bool		WhatElseModule::isLoaded() {
	return isLoaded_;
}

void		WhatElseModule::loadModule()
{
	this->_lib.open(this->_dll);
	this->infos_ = this->_lib.getSymbol<ModuleInfos *>("get_module_infos");
	this->directives_ = this->_lib.getSymbol<Directives *>("get_directives");
	this->isLoaded_ = true;
}

void		WhatElseModule::unloadModule()
{
	if (this->isLoaded_)
	{
		delete this->infos_;
		delete this->directives_;
		this->_lib.close();
	}
	isLoaded_ = false;
}