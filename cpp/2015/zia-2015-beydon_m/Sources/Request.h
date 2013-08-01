#ifndef __REQUEST_H__
# define	__REQUEST_H__

#include "RequestHeader.h"
#include "Body.h"

class Request
{
	char	*_buffer;
	int		_bufferLength;
	RequestHeader	_header;
	Body			_body;
public:
	Request(){};
	Request(char *buffer, int bufferLength);
	~Request();
	Body &			getBody();
	char			*getBuffer();
	RequestHeader &	getHeader();
	int				getLength() const;
	bool			separate();
};

#endif // !_REQUEST_H_
