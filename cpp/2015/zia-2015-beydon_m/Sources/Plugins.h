#ifndef		__PLUGINS_H__
# define	__PLUGINS_H__

# include	"PluginManager.h"

#ifdef	_WIN32
#  include	"WinLibraryLoader.h"
#else
#  include	"UnixLibraryLoader.h"
#endif

#endif