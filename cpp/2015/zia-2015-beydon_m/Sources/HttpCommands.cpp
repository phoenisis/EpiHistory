#include	<fstream>
#include	<iostream>
#include	<sstream>
#include	<algorithm>
#include	<ctime>
#include	<cstdio>
#include	"HttpCommands.h"

#ifndef __CALL_MEM_FN__
#define __CALL_MEM_FN__
#define CALL_FN(object, func) ((object)->*(func))
#endif

static std::string weekDay[7] =
{
	"Sun",
	"Mon",
	"Tue",
	"Wed",
	"Thu",
	"Fri",
	"Sat"
};

static std::string	monthName[12] =
{
	"Jan",
	"Feb",
	"Mar",
	"Apr",
	"May",
	"Jun",
	"Jul",
	"Aug",
	"Sep",
	"Oct",
	"Nov",
	"Dec"
};

HttpCommands::HttpCommands()
{
	this->_cmds.insert(std::pair<std::string, void (HttpCommands::*)(Request &, Response &)>("GET", &HttpCommands::_get));
	this->_cmds.insert(std::pair<std::string, void (HttpCommands::*)(Request &, Response &)>("PUT", &HttpCommands::_put));
	this->_cmds.insert(std::pair<std::string, void (HttpCommands::*)(Request &, Response &)>("DELETE", &HttpCommands::_delete));
	this->_cmds.insert(std::pair<std::string, void (HttpCommands::*)(Request &, Response &)>("POST", &HttpCommands::_post));
	this->_cmds.insert(std::pair<std::string, void (HttpCommands::*)(Request &, Response &)>("OPTIONS", &HttpCommands::_options));
	this->_cmds.insert(std::pair<std::string, void (HttpCommands::*)(Request &, Response &)>("HEAD", &HttpCommands::_head));
}

HttpCommands::~HttpCommands()
{
}

void		HttpCommands::execCommand(Request & req, Response & res)
{
	void	(HttpCommands::*ptr)(Request &, Response &);

	if (this->_cmds.count(req.getHeader().getCommand()) > 0)
	{
		ptr = this->_cmds[req.getHeader().getCommand()];
		CALL_FN(this, ptr)(req, res);
	}
	else
	{
		res.getHeader().setStatusCode("400");
		res.getHeader().setStatusMessage("Bad Request");
		res.getHeader().setVersion("HTTP/1.1");
	}
	this->_setDate(res);
	res.getHeader().setValue("Server", "ZIA");
}

static void				setStream(std::ostringstream & result, std::tm *r)
{
	result << weekDay[r->tm_wday].c_str() << ", " << r->tm_mday << " " << monthName[r->tm_mon].c_str() 
		<< " " << r->tm_year + 1900 << " " << r->tm_hour << ":" << r->tm_min << ":" << r->tm_sec << " GMT";
}

void					HttpCommands::_setDate(Response & res)
{
	std::time_t  t =	std::time(NULL);
	std::ostringstream			result;
	std::tm *	r =	std::gmtime(&t);

	setStream(result, r);
	res.getHeader().setValue("Date", result.str());
}

void					HttpCommands::_setHeader(Response & res, std::string const & ver, std::string const & sc, std::string const & sm)
{
	res.getHeader().setStatusCode(sc);
	res.getHeader().setVersion(ver);
	res.getHeader().setStatusMessage(sm);
}

void					HttpCommands::_setHeader(Request & res, std::string const & ver, std::string const & c, std::string const & a)
{
	res.getHeader().setCommand(c);
	res.getHeader().setVersion(ver);
	res.getHeader().setArg(a);
}

void					HttpCommands::_getFileContent(std::string const & final_path, FileStat & file, Response & res, bool & flag)
{
	char				*file_content;
	std::ifstream		i;
	std::ostringstream	mdate;
	std::time_t			t;

	if (file.canRead())
	{
		file_content = new char[file.getFileSize()];
		i.open(final_path.c_str());
		i.read(file_content, file.getFileSize());
		i.close();
		res.getBody().setBody(file_content, file.getFileSize());
		this->_setHeader(res, "HTTP/1.1", "200", "OK");
		std::ostringstream convert;
		convert << file.getFileSize();
		t = file.getModifiedTime();
		setStream(mdate, gmtime(&t));
		res.getHeader().setValue("Last-Modified", mdate.str());
		res.getHeader().setValue("Content-Length", convert.str());
		flag = true;
	}
	else
		this->_setHeader(res, "HTTP/1.1", "403", "Forbidden");
}

void		HttpCommands::_get(Request & req, Response & res)
{
	std::string			final_path;
	FileStat			file;
	bool				flag = false;

	final_path.assign(req.getHeader().getArg());
	if (file.exists(final_path))
	{
		file.feed(final_path);
		if (file.isDir())
		{
			if (final_path[final_path.size() - 1] != '/')
				final_path += "/";
			final_path += "index.html";
			if (file.exists(final_path))
			{
				file.feed(final_path);
				this->_getFileContent(final_path, file, res, flag);
			}
		}
		else
		{
			if (file.getFileExtension() != "php")
				this->_getFileContent(final_path, file, res, flag);
			else
				flag = true;
		}
	}
	if (flag == false)
		this->_setHeader(res, "HTTP/1.1", "404", "Not Found");
}

void			HttpCommands::_head(Request & req, Response & res)
{
	std::string			final_path;
	FileStat			file;
	bool				flag = false;

	final_path.assign(req.getHeader().getArg());
	if (file.exists(final_path))
	{
		file.feed(final_path);
		if (file.isDir())
		{
			if (final_path[final_path.size() - 1] != '/')
				final_path += "/";
			final_path += "index.html";
			if (file.exists(final_path))
			{
				file.feed(final_path);
				if (file.canRead())
				{
					this->_setHeader(res, "HTTP/1.1", "200", "OK");
					flag = true;
				}
				else
					this->_setHeader(res, "HTTP/1.1", "403", "Forbidden");
			}
		}
		else
			this->_getFileContent(final_path, file, res, flag);
	}
	if (flag == false)
		this->_setHeader(res, "HTTP/1.1", "404", "Not Found");
}

void			HttpCommands::_setFileContent(std::string const & final_path, FileStat & file, Request & req, Response & res, bool & flag)
{
	if (file.canWrite())
	{
		std::ofstream		o(final_path.c_str(), std::ios_base::out | std::ios_base::trunc);

		o.write(req.getBody().getBody(), req.getBody().getBodyLength());
		o.close();
		this->_setHeader(res, "HTTP/1.1", "200", "OK");
	}
	else
		this->_setHeader(res, "HTTP/1.1", "403", "Forbidden");
	flag = true;
}

void			HttpCommands::_post(Request & req, Response & res)
{
	if (req.getBody().getBodyLength() != 0)
	{
		std::string			final_path;
		FileStat			file;
		bool				flag;

		final_path.assign(req.getHeader().getArg());
		if (file.exists(final_path))
		{
			file.feed(final_path);
			if (file.getFileExtension() != "php")
				this->_setFileContent(final_path, file, req, res, flag);
			else
				flag = true;
		}
		else
			this->_setHeader(res, "HTTP/1.1", "404", "Not Found");
	}
	else
		this->_setHeader(res, "HTTP/1.1", "200", "OK");
}

void			HttpCommands::_put(Request & req, Response & res)
{
	if (req.getBody().getBodyLength() != 0)
	{
		std::string			final_path;
		FileStat			file;
		bool				flag;

		final_path.assign(req.getHeader().getArg());
		if (file.exists(final_path))
		{
			file.feed(final_path);
			this->_setFileContent(final_path, file, req, res, flag);
		}
		else
		{
			std::ofstream		o(final_path.c_str(), std::ios_base::out | std::ios_base::trunc);

			o.write(req.getBody().getBody(), req.getBody().getBodyLength());
			o.close();
			this->_setHeader(res, "HTTP/1.1", "200", "OK");
		}
	}
	else
		this->_setHeader(res, "HTTP/1,1", "200", "OK");
}

void			HttpCommands::_delete(Request & req, Response & res)
{
	std::string			final_path;
	FileStat			file;

	final_path.assign(req.getHeader().getArg());
	if (file.exists(final_path))
	{
		if (!remove(final_path.c_str()))
			this->_setHeader(res, "HTTP/1.1", "200", "OK");
		else
			this->_setHeader(res, "HTTP/1.1", "403", "Forbidden");
	}
	else
		this->_setHeader(res, "HTTP/1.1", "404", "Not Found");
}

void			HttpCommands::_options(Request & req, Response & res)
{
	std::string final_path;
	FileStat			file;
	std::string			allow = "OPTIONS, ";

	final_path.assign(req.getHeader().getArg());
	if (file.exists(final_path))
	{
		if (file.isDir())
		{
			if (final_path[final_path.size() - 1] != '/')
				final_path += "/";
			final_path += "index.html";
		}
		file.feed(final_path);
		if (file.canRead())
			allow += "HEAD, GET, ";
		if (file.canWrite())
			allow += "PUT, POST";
		if (allow[allow.size() - 2] == ',')
			allow.erase(allow.size() - 2, 2);
		this->_setHeader(res, "HTTP/1.1", "200", "OK");
		res.getHeader().setValue("Allow", allow);
	}
	else
		this->_setHeader(res, "HTTP/1.1", "404", "Not Found");
}