
#ifndef		__IPLUGIN_HPP__
# define	__IPLUGIN_HPP__

template <typename T>
class			IPlugin
{
public:
  virtual		~IPlugin(void) {}
  virtual bool		loadLibrary(const char *) = 0;
  virtual bool		freeLibrary(void) = 0;
  virtual T		*getInstance(char const *) = 0;
};

#endif		// ! __IPLUGIN_HPP__
