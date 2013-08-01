#ifndef	__UNIXLIBRARY_H__
# define	__UNIXLIBRARY_H__
# ifndef _WIN32
# include	<dlfcn.h>
# include	<string>

namespace	Plugin
{

	class		UnixLibraryLoader
	{
	public:
		UnixLibraryLoader();
		UnixLibraryLoader(std::string const &);
		~UnixLibraryLoader();
		void	open(std::string const &);
		void	close();
		bool	isOpen();
		template<typename Ret> Ret  getSymbol(std::string const &);
	private:
		void *		_handle;
		bool		_isOpen;
	};

	template<typename Ret>
	Ret			UnixLibraryLoader::getSymbol(std::string const & str)
	{
	  	typedef Ret	(*f)();
		f		func;
		Ret		r;

		func = (f)dlsym(this->_handle, str.c_str());
		r = func();
		return (r);
	}

	typedef UnixLibraryLoader LibraryLoader;
}
# endif
#endif
