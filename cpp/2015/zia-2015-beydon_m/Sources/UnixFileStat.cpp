#ifndef _WIN32
#include "UnixFileStat.h"

UnixFileStat::UnixFileStat()
{
}

UnixFileStat::UnixFileStat(std::string const & str)
{
	this->feed(str);
}

UnixFileStat::~UnixFileStat()
{
}

bool					UnixFileStat::exists(std::string const & str) const
{
	if (!access(str.c_str(), F_OK))
		return (true);
	return (false);
}

void					UnixFileStat::feed(std::string const & str)
{
	unsigned int	pos;

	stat(str.c_str(), &this->_st);
	pos = str.find_last_of('/');
	if (pos == std::string::npos && (pos = str.find_last_of('\\') != std::string::npos))
		pos = str.find_last_of('\\');
	else
		this->_fileName = str;
	this->_fileName = str.substr(pos + 1, str.size() - pos - 1);
	if ((pos = str.find_last_of('.') != std::string::npos))
		this->_ext = str.substr(pos + 1, str.size() - pos - 1);
}

std::string const &					UnixFileStat::getFilename() const
{
	return (this->_fileName);
}

std::string const &					UnixFileStat::getFileExtension() const
{
	return (this->_ext);
}

unsigned int						UnixFileStat::getFileSize() const
{
	return (this->_st.st_size);
}

bool								UnixFileStat::isDir() const
{
	if (S_ISDIR(this->_st.st_mode))
		return (true);
	return (false);
}

bool								UnixFileStat::isReadOnly() const
{
	return (true);
}

bool								UnixFileStat::canRead() const
{
	return (true);
}

bool								UnixFileStat::canWrite() const
{
	return (true);
}

time_t								UnixFileStat::getModifiedTime() const
{
	return (this->_st.st_mtime);
}

#endif
