#include		<list>
#include		"PluginManager.h"

using namespace Plugin;

#ifdef _WIN32
static std::list<std::string>	getFileFromDirectory(std::string const & dir)
{
	WIN32_FIND_DATA		fd;
	HANDLE				h;
	std::list<std::string> list;
	std::string			str;

	h = FindFirstFile(dir.c_str(), &fd);
	do
	{
		str = std::string(fd.cFileName);
		if (str.substr(str.find_last_of('.') + 1) == "dll")
			list.push_front(std::string(fd.cFileName));
	} while (FindNextFile(h, &fd) != 0);
	FindClose(h);
	return (list);
}
#else
static std::list<std::string>	getFileFromDirectory(std::string const & dirName)
{
	DIR	*		dir;
	struct dirent * ent;
	std::list<std::string> list;
	std::string				str;

	dir = opendir(dirName.c_str());
	while ((ent = readdir(dir)) != NULL)
	{
		str = std::string(ent->d_name);
		if (str.substr(str.find_last_of('.') + 1) == "so")
			list.push_front(std::string(ent->d_name));
	}
	closedir(dir);
	return (list);
}
#endif

PluginManager::PluginManager()
{
}

PluginManager::~PluginManager()
{
	this->unloadAll();
	this->_libs.clear();
}

void		PluginManager::load(std::string const & name)
{
	std::map<std::string, LibraryLoader>::iterator it;
	bool											flag = false;

	for (it = this->_libs.begin(); it != this->_libs.end(); ++it)
	{
		if (!(*it).second.isOpen())
		{
			(*it).second.open(name);
			flag = true;
		}
	}
	if (!flag)
		this->_libs.insert(std::pair<std::string, LibraryLoader>(name.substr(0, name.find_first_of(".")), LibraryLoader(name)));
}

void		PluginManager::unload(std::string const &name)
{
	if (this->_libs.count(name) > 0)
		this->_libs[name].close();
}

void		PluginManager::loadAll(std::string const & dir)
{
	std::list<std::string>	files;
	std::list<std::string>::iterator it;

	files = getFileFromDirectory(dir);
	for (it = files.begin(); it != files.end(); ++it)
		this->load(*it);
}

void		PluginManager::unloadAll()
{
	std::map<std::string, LibraryLoader>::iterator it;

	for (it = this->_libs.begin(); it != this->_libs.end(); ++it)
		(*it).second.close();
}

bool		PluginManager::isLoaded(std::string const & name)
{
	if (this->_libs.count(name) > 0)
		return (true);
	return (false);
}

LibraryLoader &		PluginManager::getLoader(std::string const & str)
{
	return (this->_libs[str]);
}