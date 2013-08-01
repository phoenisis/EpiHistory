#ifndef		__BUFFER_H__
# define	__BUFFER_H__
# ifdef	_WIN32
# include	"WinFunc.h"
# else
# include	"UnixFunc.h"
#endif
# include	<string>

class					Buffer
{
public:
	Buffer();
	Buffer(char const *buf, unsigned int len);
	Buffer(unsigned int len);
	Buffer(std::string const & str);
	~Buffer();
	void				assign(std::string const & str);
	void				newEmptyBuffer(unsigned int len);
	unsigned int		getBytesLeft() const;
	T_BUFFER &			getBuffer();
	void				setBytesLeft(unsigned int bytes);
	void				setBuffLen(unsigned int len);
private:
	T_BUFFER	_buf;
	unsigned int _bytesLeft;
};

#endif