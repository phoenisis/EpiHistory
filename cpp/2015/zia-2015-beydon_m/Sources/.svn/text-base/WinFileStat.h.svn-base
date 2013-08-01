#ifndef __WINFILESTAT_H__
# define __WINFILESTAT_H__
# ifdef _WIN32
# define WIN32_LEAN_AND_MEAN
# include	<Windows.h>
# include	<io.h>
# include	<sys/stat.h>
# include	<sys/types.h>
# include	<string>

class WinFileStat
{
public:
	WinFileStat();
	WinFileStat(std::string const &);
	~WinFileStat();
	bool			exists(std::string const &) const;
	void			feed(std::string const &);
	std::string const &		getFilename() const;
	unsigned int	getFileSize() const;
	bool			isDir() const;
	bool			isReadOnly() const;
	bool			canRead() const;
	bool			canWrite() const;
	time_t			getModifiedTime() const;
	std::string const &		getFileExtension() const;
private:
	struct _stat	_st;
	unsigned int	_attribute;
	std::string		_fileName;
	std::string		_ext;
};

typedef	WinFileStat	FileStat;

# endif
#endif // !__WINFILESTAT_H__
