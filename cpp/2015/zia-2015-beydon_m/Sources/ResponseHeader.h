#ifndef __RESPONSEHEADER_H__
# define	__RESPONSEHEADER_H__

# include <map>
# include <string>

class ResponseHeader
{
	std::map<std::string, std::string>	_options;
	std::string							_statusCode;
	std::string							_statusMessage;
	std::string							_version;
public:
	ResponseHeader();
	ResponseHeader(std::map<std::string, std::string> const & options, std::string const & statusCode, std::string const & statusMessage, std::string const & version);
	~ResponseHeader();
	std::string	const &		getStatusCode() const;
	std::string const &		getStatusMessage() const;
	std::string const &		getValueForKey(std::string const & key) const;
	std::string const &		getVersion() const;
	std::map<std::string, std::string> const &	getOptions() const;
	bool					hasKey(std::string const & value);
	void					setStatusCode(std::string const & statusCode);
	void					setStatusMessage(std::string const & statusMessage);
	void					setValue(std::string const & headerAttribut, std::string const & value);
	void					setVersion(std::string const & version);
};

#endif // !_RESPONSEHEADER_H_
