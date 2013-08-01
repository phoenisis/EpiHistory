#ifndef __FILESTAT_H__
# define __FILSTAT_H__

# ifdef _WIN32
#  include	"WinFileStat.h"
# else
#  include	"UnixFileStat.h"
# endif


#endif // !__FILESTAT_H__
