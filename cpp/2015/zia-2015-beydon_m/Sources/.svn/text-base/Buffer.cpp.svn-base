#include	"Buffer.h"

using namespace Network;

Buffer::Buffer()
{
	this->_buf.buf = 0;
	this->_buf.len = 0;
}

Buffer::Buffer(unsigned int len)
{
	this->_buf.buf = new char[len];
	this->_buf.len = len;
}

Buffer::Buffer(Buffer const & buf)
{
	this->_buf.buf = const_cast<Buffer &>(buf).getBuff().buf;
	this->_buf.len = const_cast<Buffer &>(buf).getBuffLen();
}

Buffer::Buffer(t_buffer & buf)
{
	this->_buf.buf = buf.buf;
	this->_buf.len = buf.len;
}

Buffer::Buffer(std::string const & str)
{
	this->_buf.buf = new char[str.size()];
	memcpy(this->_buf.buf, str.data(), str.size());
	this->_buf.len = str.size();
}
	
Buffer::Buffer(char *buf, unsigned int len)
{
	this->_buf.buf = buf;
	this->_buf.len = len;
}

Buffer::~Buffer()
{
}


int				Buffer::getBuffLen() const
{
	return (this->_buf.len);
}

Buffer &			Buffer::operator=(Buffer & buf)
{
	this->_buf.buf = buf.getBuff().buf;
	this->_buf.len = buf.getBuffLen();
	return (*this);
}

int				Buffer::operator=(int len)
{
	this->_buf.len = len;
	return (len);
}