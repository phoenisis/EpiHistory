#include "ResponseHeader.h"

ResponseHeader::ResponseHeader()
{
}


ResponseHeader::ResponseHeader(std::map<std::string, std::string> const & options, std::string const & statusCode, std::string const & statusMessage, std::string const & version):
	_options(options),
	_statusCode(statusCode),
	_statusMessage(statusMessage),
	_version(version)
{
}

ResponseHeader::~ResponseHeader() {
}


std::string	const &		ResponseHeader::getStatusCode() const
{
	return _statusCode;
}

std::string const &		ResponseHeader::getStatusMessage() const
{
	return _statusMessage;
}

std::string const &		ResponseHeader::getValueForKey(std::string const & key) const
{
	return (this->_options.find(key)->second);
}

std::string const &		ResponseHeader::getVersion() const {
	return _version;
}

bool					ResponseHeader::hasKey(std::string const & value)
{
	if (this->_options.count(value) > 0)
		return (true);
	return (false);
}

void					ResponseHeader::setStatusCode(std::string const & statusCode)
{
	_statusCode = statusCode;
}

void					ResponseHeader::setStatusMessage(std::string const & statusMessage)
{
	_statusMessage = statusMessage;
}

void					ResponseHeader::setValue(std::string const & headerAttribut, std::string const & value)
{
	this->_options.insert(std::pair<std::string, std::string>(headerAttribut, value));
}

void					ResponseHeader::setVersion(std::string const & version)
{
	_version = version;
}

std::map<std::string, std::string> const &	ResponseHeader::getOptions() const
{
	return (this->_options);
}
