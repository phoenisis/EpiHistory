#ifndef		__ISOCKET_H__
# define	__ISOCKET_H__
# ifdef _WIN32
#  include "WinFunc.h"
# else
#  include "UnixFunc.h"
# endif
# include	<string>

class							ISocket
{
public:
	virtual ~ISocket() {};
	virtual void				open(int, std::string const &) = 0;
	virtual bool				isOpen() const = 0;
	virtual char				*getIp() const = 0;
	virtual int					getPort() const = 0;
	virtual T_SOCKET const &	getSocket() const = 0;
	virtual	void				close() = 0;
};

#endif
