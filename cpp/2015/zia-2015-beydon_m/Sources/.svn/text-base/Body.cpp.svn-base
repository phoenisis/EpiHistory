#include <string>
#include "Body.h"

Body::Body(): _body(0), _length(0)
{
}

Body::Body(char *body, int length) : _length(length)
{
	_body = new char[length];
	memcpy(_body, body, length);
}

Body::~Body()
{
	delete	_body;
}

char		*Body::getBody()
{
	return _body;
}

int			Body::getBodyLength() const
{
	return _length;
}

void		Body::setBody(char *buf, int len)
{
	if (this->_body)
		delete this->_body;
	this->_body = buf;
	this->_length = len;
}