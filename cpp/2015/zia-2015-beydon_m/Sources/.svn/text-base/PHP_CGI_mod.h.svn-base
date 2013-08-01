#ifndef _PHP_CGI_MOD_H_
#define	_PHP_CGI_MOD_H_

#include <iostream>
#include "ModuleInfos.h"
#include "Directives.h"
#include "Response.h"
#include "Portability.h"

#define	PHP_CGI_EXEC_PATH	"php-cgi.exe -f "

class PHP_CGI_mod : public Directives
{
	void		getRequest(Request & request, Response &);
	void		phpCgiExec(Request &, Response &);
	void		execAndRet(Response &, std::string const & cmd);
public:
	PHP_CGI_mod();
	virtual ~PHP_CGI_mod();
	virtual void	callDirective(DirectivesOrder directiveorder, Request & request, Response & response, t_socket socket, struct sockaddr_in & connexionInfos);
	virtual void	init();
};

#endif // !_PHP_CGI_MOD_H_
