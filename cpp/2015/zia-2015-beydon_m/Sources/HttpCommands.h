#ifndef __HTTPCOMMANDS_H__
# define __HTTPCOMMANDS_H__
# include	<map>
# include	<string>
# include	"FileStat.h"
# include	"Request.h"
# include	"Response.h"

class HttpCommands
{
public:
	HttpCommands();
	~HttpCommands();
	void		execCommand(Request &, Response &);
private:
	void		_setDate(Response &);
	void		_setHeader(Response &, std::string const &, std::string const &, std::string const &);
	void		_setHeader(Request &, std::string const &, std::string const &, std::string const &);
	void		_getFileContent(std::string const & final_path, FileStat & file, Response & res, bool & flag);
	void		_setFileContent(std::string const & final_path, FileStat & file, Request &, Response & res, bool & flag);
	void		_get(Request &, Response &);
	void		_post(Request &, Response &);
	void		_head(Request &, Response &);
	void		_options(Request &, Response &);
	void		_trace(Request &, Response &);
	void		_put(Request &, Response &);
	void		_delete(Request &, Response &);
	void		_patch(Request &, Response &);
	std::map<std::string, void (HttpCommands::*)(Request &, Response &)> _cmds;
};

#endif // !__HTTPCOMMANDS_H__
