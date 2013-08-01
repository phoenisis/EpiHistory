#ifndef __DIRECTIVES_H__
# define	__DIRECTIVES_H__

#include "Request.h"
#include "Response.h"
#include "DirectivesOrder.h"

#if defined(_WIN64)
	typedef unsigned __int64 UINT_PTR;
#elif defined(_WIN32)
    typedef _W64 unsigned int UINT_PTR;
#else
	typedef int	UINT_PTR;
#endif

typedef UINT_PTR t_socket;
struct sockaddr_in;

class Directives
{
public:
	virtual ~Directives() {};
	virtual	void	callDirective(DirectivesOrder directiveorder, Request & request, Response & response, t_socket socket, struct sockaddr_in & connexionInfos) = 0;
	virtual	void	init() = 0;
};


#endif // !_DIRECTIVES_H_