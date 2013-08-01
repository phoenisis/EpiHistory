#ifndef		__PLUGINMANAGER_H__
# define	__PLUGINMANAGER_H__
# include	<map>
# include	<string>
# ifdef _WIN32
# include	"WinLibraryLoader.h"
# else
# include	"UnixLibraryLoader.h"
# include	<dirent.h>
#endif

namespace Plugin
{
	class		PluginManager
	{
	public:
		PluginManager();
		~PluginManager();
		LibraryLoader & getLoader(std::string const &);
		void			load(std::string const &);
		void			unload(std::string const &);
		void			loadAll(std::string const &);
		void			unloadAll();
		bool			isLoaded(std::string const &);
	private:
		std::map<std::string, LibraryLoader>	_libs;
	};
}
#endif
