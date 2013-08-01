#ifdef			_WIN32
# include		"WinLibraryLoader.h"

using namespace Plugin;

WinLibraryLoader::WinLibraryLoader(): _isOpen(false)
{
}

WinLibraryLoader::WinLibraryLoader(std::string const &str)
{
	this->open(str);
}

WinLibraryLoader::~WinLibraryLoader()
{
	if (this->_isOpen)
		FreeLibrary(this->_handle);
}

void		WinLibraryLoader::open(std::string const &str)
{
	this->_handle = LoadLibrary(str.c_str());
	this->_isOpen = true;
}

void		WinLibraryLoader::close()
{
	if (this->_isOpen)
		FreeLibrary(this->_handle);
	this->_isOpen = false;
}

bool		WinLibraryLoader::isOpen()
{
	return (this->_isOpen);
}

#endif