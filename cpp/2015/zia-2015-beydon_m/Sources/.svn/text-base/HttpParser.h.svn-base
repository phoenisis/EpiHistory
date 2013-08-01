#ifndef __HTTPPARSER_H__
# define	__HTTPPARSER_H__
# include	<string>
# include	<map>
# include	"Request.h"

class HttpParser
{
public:
	HttpParser(std::string const &);
	~HttpParser();
	void		feed(char *, int);
	bool		isGood() const;
	bool		isComplete() const;
	int			getHeaderLen() const;
	std::string const & getCommand() const ;
	std::string const & getArg() const ;
	std::string const & getVersion() const ;
	std::map<std::string, std::string> const &	getOptions() const;
	void		fillRequest(Request &);
	void		clear();
private:
	void			_parseFirstLine();
	void			_parseOptions();
	int				_index;
	char *			_buf;
	int				_buffLen;
	int				_headerLen;
	std::string		_command;
	std::string		_arg;
	std::string		_version;
	std::map<std::string, std::string>	_options;
	bool			_good;
	bool			_complete;
	std::string		_path;
};

#endif // !__HTTPPARSER_H__
