#ifndef			_WIN32
# include		"UnixLibraryLoader.h"

using namespace Plugin;

UnixLibraryLoader::UnixLibraryLoader(): _isOpen(false)
{
}

UnixLibraryLoader::UnixLibraryLoader(std::string const &str)
{
	this->open(str);
}

UnixLibraryLoader::~UnixLibraryLoader()
{
	if (this->_isOpen)
		dlclose(this->_handle);
}

void		UnixLibraryLoader::open(std::string const &str)
{
	this->_handle = dlopen(str.c_str(), RTLD_NOW);
	this->_isOpen = true;
}

void		UnixLibraryLoader::close()
{
	if (this->_isOpen)
		dlclose(this->_handle);
	this->_isOpen = false;
}

bool		UnixLibraryLoader::isOpen()
{
	return (this->_isOpen);
}

#endif