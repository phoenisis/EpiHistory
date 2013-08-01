#ifndef	__WINLIBRARY_H__
# define	__WINLIBRARY_H__
# ifdef _WIN32
# define WIN32_LEAN_AND_MEAN
# include	<Windows.h>
# include	<string>

namespace	Plugin
{
	class		WinLibraryLoader
	{
	public:
		WinLibraryLoader();
		WinLibraryLoader(std::string const &);
		~WinLibraryLoader();
		void	open(std::string const &);
		void	close();
		bool	isOpen();
		template<typename Ret> Ret  getSymbol(std::string const &);
	private:
		HMODULE		_handle;
		bool		_isOpen;
	};

	template<typename Ret>
	Ret			WinLibraryLoader::getSymbol(std::string const & str)
	{
		typedef Ret	(*f)();
		f		func;
		Ret		r;

		func = (f)GetProcAddress(this->_handle, str.c_str());
		r = func();
		return (r);
	}

	typedef WinLibraryLoader LibraryLoader;
}
# endif
#endif