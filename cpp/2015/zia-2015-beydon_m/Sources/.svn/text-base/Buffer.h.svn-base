#ifndef		__BUFFER_H__
# define	__BUFFER_H__
# include	<cstring>
# include	<string>

namespace Network
{

# ifdef	_WIN32
#  include	<WinSock2.h>
typedef WSABUF	t_buffer;
# else
typedef	struct s_buf
{
	char	*buf;
	unsigned int	len;
}				t_buffer;
# endif

	class					Buffer
	{
	public:
		Buffer();
		Buffer(std::string const &);
		Buffer(unsigned int len);
		Buffer(Buffer const &);
		Buffer(t_buffer & buf);
		Buffer(char *buf, unsigned int len);
		~Buffer();
		t_buffer &			getBuff() {return (this->_buf);};
		int					getBuffLen() const;
		Buffer &			operator=(Buffer &);
		int					operator=(int);
		static void			clearBuffer(t_buffer & buf)
		{
			if (buf.buf)
				delete buf.buf;
			buf.buf = 0;
			buf.len = 0;
		}
	private:
		t_buffer	_buf;
	};
}
#endif
