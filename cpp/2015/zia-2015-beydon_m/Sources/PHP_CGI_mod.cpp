#include "PHP_CGI_mod.h"

extern "C"
{
#ifndef _WIN32
	ModuleInfos *			get_module_infos()
#else
	__declspec(dllexport) ModuleInfos * get_module_infos()
#endif
	{
		ModuleInfos		 *m = new ModuleInfos;

		m->associatedDLL = "php";
		m->managedDirectives = PROCESS_REQUEST | CREATE_RESPONSE;
		m->managesHeaderOnly = true;
		m->name = "php";
		m->nbDirectives = 2;
		return (m);
	}

#ifndef _WIN32
	Directives *		get_directives()
#else
	__declspec(dllexport) Directives *		get_directives()
#endif
	{
		Directives *	d = new PHP_CGI_mod;
		return (d);
	}
}

PHP_CGI_mod::PHP_CGI_mod() {
}

PHP_CGI_mod::~PHP_CGI_mod() {
}

void		PHP_CGI_mod::execAndRet(Response & resp, std::string const & cmd)
{
	FILE *res;
	std::string result = "";
	char *body;

	res = POPEN(cmd.c_str(), "r");
	char buffer[128];
	while(!feof(res))
	{
    	if(fgets(buffer, 128, res) != NULL)
    		result += buffer;
	}
	PCLOSE(res);
	if (result.size() > 0)
	{
		body = new char[result.size()];
		memcpy(body, result.data(), result.size());
		resp.getBody().setBody(body, result.size());
		resp.getHeader().setStatusCode("200");
		resp.getHeader().setVersion("HTTP/1.1");
		resp.getHeader().setStatusMessage("OK");
	}
	else
	{
		resp.getHeader().setStatusCode("500");
		resp.getHeader().setVersion("HTTP/1.1");
		resp.getHeader().setStatusMessage("Internal Server Error");
	}
}

void		PHP_CGI_mod::getRequest(Request & request, Response & response)
{
	if (request.getHeader().getCommand() == "POST" && request.getHeader().getArg().substr(request.getHeader().getArg().find_last_of('.') + 1, 3) == "php")
	{
		std::string		cmd;

		cmd.assign(PHP_CGI_EXEC_PATH);
		cmd += " " + request.getHeader().getArg();
		cmd += " '";
		cmd += std::string(request.getBody().getBody(), request.getBody().getBodyLength());
		cmd += "'";
		this->execAndRet(response, cmd);
	}
}

void		PHP_CGI_mod::phpCgiExec(Request & req, Response & response)
{
	if (req.getHeader().getCommand() == "GET" && req.getHeader().getArg().substr(req.getHeader().getArg().find_last_of('.') + 1, 3) == "php")
	{
		std::string cmd;

		cmd.assign(PHP_CGI_EXEC_PATH);
		cmd += " " + req.getHeader().getArg();
		this->execAndRet(response, cmd);
	}
}

void		PHP_CGI_mod::init() {
}

void		PHP_CGI_mod::callDirective(DirectivesOrder directiveorder, Request & request, Response & response, t_socket socket, struct sockaddr_in & connexionInfos) {
	if (directiveorder == PREPROCESS_REQUEST)
		getRequest(request, response);
	else if (directiveorder == CREATE_RESPONSE)
		phpCgiExec(request, response);
}