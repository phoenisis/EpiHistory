#include	<cstring>
#include	<string>
#include	"Buffer.h"


Buffer::Buffer()
{
	this->_buf.buf = NULL;
}

Buffer::Buffer(char const *buf, unsigned int len) : _bytesLeft(len)
{
	this->_buf.buf = new char[len];
	memset(this->_buf.buf, 0, len);
	this->_buf.len = len;
	memcpy(this->_buf.buf, buf, len);
}

Buffer::Buffer(unsigned int len)
{
	this->_buf.len = len;
	this->_buf.buf = new char [len];
	memset(this->_buf.buf, 0, len);
	this->_bytesLeft = len;
}

Buffer::Buffer(std::string const & str): _bytesLeft(str.size())
{
	this->_buf.buf = new char[str.size()];
	memset(this->_buf.buf, 0, str.size());
	this->_buf.len = str.size();
	memcpy(this->_buf.buf, str.data(), str.size());
}

Buffer::~Buffer()
{
	if (this->_buf.buf != NULL)
		delete this->_buf.buf;
}

void			Buffer::assign(std::string const & str)
{
	if (this->_buf.buf != NULL)
		delete this->_buf.buf;
	this->_buf.buf = new char[str.size()];
	this->_buf.len = str.size();
	memcpy(this->_buf.buf, str.data(), str.size());
	this->_bytesLeft = str.size();
}

unsigned int	Buffer::getBytesLeft() const
{
	return (this->_bytesLeft);
}

T_BUFFER &		Buffer::getBuffer()
{
	return (this->_buf);
}

void			Buffer::setBytesLeft(unsigned int bytes)
{
	if (bytes <= this->_buf.len)
		this->_bytesLeft = bytes;
}

void			Buffer::newEmptyBuffer(unsigned int len)
{
	if (this->_buf.buf != NULL)
		delete this->_buf.buf;
	this->_buf.len = len;
	this->_buf.buf = new char [len];
	memset(this->_buf.buf, 0, len);
	this->_bytesLeft = len;
}

void			Buffer::setBuffLen(unsigned int len)
{
	this->_buf.len = len;
}