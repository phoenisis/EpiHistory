#ifndef _PORTABILITY_H_
#define	_PORTABILITY_H_

#include <cstdlib>
#include <cstdio>

# ifdef	_WIN32
# include <io.h>
# define	ACCESS			_access
# define	POPEN			_popen
# define	PCLOSE			_pclose
# define	EXISTENCE_MODE	0
# else
# include <unistd.h>
# define	ACCESS			access
# define	POPEN			popen
# define	PCLOSE			pclose
# define	EXISTENCE_MODE	F_OK
# endif

#endif // !_PORTABILITY_H_
