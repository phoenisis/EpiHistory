#include <string>
#include <sstream>
#include "Response.h"

Response::Response(char *buffer, int bufferLength):
	_bufferLength(bufferLength) {
		_buffer = new char[bufferLength];
		memcpy(_buffer, buffer, bufferLength);
}

Response::~Response() {
	delete _buffer;
}

void				Response::assemble()
{
	std::string		head;
	std::map<std::string, std::string>::const_iterator it;

	if (_buffer)
		delete _buffer;
	head.assign(this->_header.getVersion() + " " + this->_header.getStatusCode() + " " + this->_header.getStatusMessage() + "\r\n");
	for (it = this->_header.getOptions().begin(); it != this->_header.getOptions().end(); ++it)
		head.append((*it).first + ": " + (*it).second + "\r\n");
	head.append("\r\n");
	this->_buffer = new char[head.size() + this->_body.getBodyLength()];
	memcpy(this->_buffer, head.c_str(), head.size());
	memcpy(this->_buffer + head.size(), this->_body.getBody(), this->_body.getBodyLength());
	this->_bufferLength = head.size() + this->_body.getBodyLength();
}

Body &				Response::getBody() {
	return _body;
}

char				*Response::getBuffer() {
	return	_buffer;
}

ResponseHeader &	Response::getHeader() {
	return _header;
}

int					Response::getLength() const {
	return	_bufferLength;
}