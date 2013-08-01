#ifndef __UNIXFILESTAT_H__
# define __UNIXFILESTAT_H__
# ifndef _WIN32
# include	<sys/types.h>
# include	<sys/stat.h>
# include	<unistd.h>
# include	<string>

class UnixFileStat
{
public:
	UnixFileStat();
	UnixFileStat(std::string const &);
	~UnixFileStat();
	bool					exists(std::string const &) const;
	void					feed(std::string const &);
	std::string const &		getFilename() const;
	unsigned int			getFileSize() const;
	bool					isDir() const;
	bool					isReadOnly() const;
	bool					canRead() const;
	bool					canWrite() const;
	time_t					getModifiedTime() const;
	std::string const &		getFileExtension() const;
private:
	struct stat		_st;
	std::string		_fileName;
	std::string		_ext;
};

typedef UnixFileStat FileStat;

# endif
#endif // !__UNIXFILESTAT_H__
