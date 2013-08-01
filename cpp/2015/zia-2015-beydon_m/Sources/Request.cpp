#include	<sstream>
#include	<iostream>
#include "Request.h"

Request::Request(char *buffer, int bufferLength): _bufferLength(bufferLength) {
	_buffer = new char[bufferLength];
	memcpy(_buffer, buffer, bufferLength);
}

Request::~Request() {
	delete _buffer;
}

Body &			Request::getBody() {
	return _body;
}

char			*Request::getBuffer() {
	return _buffer;
}

RequestHeader &	Request::getHeader() {
	return _header;
}

int				Request::getLength() const {
	return _bufferLength;
}

bool			Request::separate()
{
	int i, first, last;
	std::string		head;
	std::string		firstLine;
	std::string				elem;
	std::string				key;
	std::string				value;

	for (i = 0; i < this->_bufferLength && memcmp(this->_buffer + i, "\r\n\r\n", 4); ++i);
	head.assign(this->_buffer, i);
	firstLine.assign(this->_buffer, head.find("\r\n"));
	first = firstLine.find_first_of(" ");
	last = firstLine.find_last_of(" ");
	this->_header.setCommand(firstLine.substr(0, first));
	this->_header.setArg(firstLine.substr(first, last - first));
	this->_header.setVersion(firstLine.substr(last, firstLine.size() - last));
	std::stringstream ss(head.substr(firstLine.size(), head.size() - firstLine.size()));
	while (std::getline(ss, elem, '\n'))
	{
		first = elem.find_first_of(':');
		key.assign(elem.substr(0, first));
		value.assign(elem.substr(first + 2, elem.size() - (first + 3)));
		this->_header.setValue(key, value);
	}
	if (this->_bufferLength != i + 4)
		this->_body.setBody(this->_buffer + i + 4, this->_bufferLength - (i + 4));
	return true;
}