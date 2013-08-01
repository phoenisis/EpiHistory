#include	<algorithm>
#include	<iostream>
#include	<vector>
#include	"HttpParser.h"

HttpParser::HttpParser(std::string const & path): _index(0), _headerLen(0), _good(true), _complete(false), _path(path)
{
}

HttpParser::~HttpParser()
{
}

void		HttpParser::feed(char *buf, int size)
{
	this->_buf = buf;
	this->_buffLen = size;
	this->_parseFirstLine();
	if (this->_good)
		this->_parseOptions();
}

int			HttpParser::getHeaderLen() const
{
	return (this->_headerLen);
}

bool		HttpParser::isGood() const
{
	return (this->_good);
}

bool		HttpParser::isComplete() const
{
	return (this->_complete);
}

std::string const & HttpParser::getCommand() const
{
	return (this->_command);
}

std::string const & HttpParser::getArg() const
{
	return (this->_arg);
}

std::string const & HttpParser::getVersion() const
{
	return (this->_version);
}


std::map<std::string, std::string> const &	HttpParser::getOptions() const
{
	return (this->_options);
}

void		HttpParser::clear()
{
	this->_good = true;
	this->_complete = false;
	this->_index = 0;
	this->_buffLen = 0;
	this->_buf = 0;
	this->_headerLen = 0;
}


void			HttpParser::_parseFirstLine()
{
	int			i;
	std::string str;
	int			firstSp;
	int			lastSp;

	for (i = 0; i < this->_buffLen && memcmp(this->_buf + i, "\r\n", 2); ++i);
	if (i != this->_buffLen)
	{
		str.assign(this->_buf, i);
		if (std::count(str.begin(), str.end(), ' ') == 2)
		{
			firstSp = str.find_first_of(' ');
			lastSp = str.find_last_of(' ');
			this->_command = str.substr(0, firstSp);
			this->_version = str.substr(lastSp + 1, i - lastSp);
			this->_arg = str.substr(firstSp + 1, lastSp - firstSp - 1);
			this->_index = i + 2;
		}
		else
			this->_good = false;
	}
	else if (i > 5000)
		this->_good = false;
}

void			HttpParser::_parseOptions()
{
	std::string	str;
	std::vector<std::string> v;
	int			i;
	bool		flag = true;
	unsigned int			column;
	bool		headerComplete = false;

	if (this->_index != this->_buffLen)
	{
		while (flag)
		{
			for (i = this->_index; i < this->_buffLen && memcmp(this->_buf + i, "\r\n", 2); ++i);
			if (i != this->_buffLen)
			{
				if (i - this->_index > 0)
				{
					str.assign(this->_buf + this->_index,  i - this->_index);
					std::remove(str.begin(), str.end(), ' ');
					column = str.find_first_of(':');
					if (column != std::string::npos)
						this->_options.insert(std::pair<std::string, std::string>(str.substr(0, column), str.substr(column + 1, str.size() - column - 2)));
					else
						this->_good = false;
					this->_index = i + 2;
				}
				else
				{
					headerComplete = true;
					flag = false;
				}
			}
			else
				flag = false;
		}
		if (headerComplete)
		{
			this->_headerLen = i + 2;
			if (this->_headerLen <= this->_buffLen)
			{
				if (this->_options.count("Content-Length") > 0)
				{
					int bodyLength = atoi(this->_options["Content-Length"].c_str());
					if ((this->_buffLen - this->_headerLen) < bodyLength)
						this->_complete = false;
					else
						this->_complete = true;
				}
				else
					this->_complete = true;
			}
			else
				this->_complete = true;
		}
	}
	else
		this->_complete = false;
}

void			HttpParser::fillRequest(Request & req)
{
	req.getHeader().setCommand(this->_command);
	req.getHeader().setArg(this->_path + this->_arg);
	req.getHeader().setVersion(this->_version);
	for (std::map<std::string, std::string>::iterator it = this->_options.begin(); it != this->_options.end(); ++it)
		req.getHeader().setValue((*it).first, (*it).second);
	if (this->_headerLen != this->_buffLen)
	{
		char * tmp = new char[this->_buffLen - this->_headerLen];
		memcpy(tmp, this->_buf + this->_headerLen, this->_buffLen - this->_headerLen);
		req.getBody().setBody(tmp, this->_buffLen - this->_headerLen);
	}
}