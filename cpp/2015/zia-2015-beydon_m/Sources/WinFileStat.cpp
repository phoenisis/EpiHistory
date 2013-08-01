#ifdef _WIN32
#include	"WinFileStat.h"

WinFileStat::WinFileStat()
{
}

WinFileStat::WinFileStat(std::string const & str)
{
	if (this->exists(str))
		this->feed(str);
}

WinFileStat::~WinFileStat()
{
}

bool					WinFileStat::exists(std::string const & str) const
{
	if (_access(str.c_str(), 0) != -1)
		return (true);
	return (false);
}

void					WinFileStat::feed(std::string const & str)
{
	unsigned int	pos;

	_stat(str.c_str(), &this->_st);
	this->_attribute = GetFileAttributes(str.c_str());
	pos = str.find_last_of('/');
	if (pos == std::string::npos && (pos = str.find_last_of('\\') != std::string::npos))
		pos = str.find_last_of('\\');
	else
		this->_fileName = str;
	this->_fileName = str.substr(pos + 1, str.size() - pos - 1);
	if ((pos = str.find_last_of('.')) != std::string::npos)
		this->_ext = str.substr(pos + 1, str.size() - pos - 1);
}

std::string const &					WinFileStat::getFilename() const
{
	return (this->_fileName);
}

std::string const &					WinFileStat::getFileExtension() const
{
	return (this->_ext);
}

unsigned int						WinFileStat::getFileSize() const
{
	return (this->_st.st_size);
}

bool								WinFileStat::isDir() const
{
	if (this->_st.st_mode & _S_IFDIR)
		return (true);
	return (false);
}

bool								WinFileStat::isReadOnly() const
{
	if (this->_attribute & FILE_ATTRIBUTE_READONLY)
		return (true);
	return (false);
}

bool								WinFileStat::canRead() const
{
	if (this->_st.st_mode & _S_IREAD)
		return (true);
	return (false);
}

bool								WinFileStat::canWrite() const
{
	if (!this->isReadOnly() && this->_st.st_mode & _S_IWRITE)
		return (true);
	return (false);
}


time_t								WinFileStat::getModifiedTime() const
{
	return (this->_st.st_mtime);
}

#endif