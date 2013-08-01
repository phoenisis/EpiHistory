#ifndef		__IOHANDLER_H__
# define	__IOHANDLER_H__
# define READ 0
# define WRITE 1
# define ACCEPT 2

class			IOHandler
{
public:
	virtual ~IOHandler(){};
	virtual int			getAction() const = 0;
};

#endif