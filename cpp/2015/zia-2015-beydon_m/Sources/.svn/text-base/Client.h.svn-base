#ifndef __CLIENT_H__
# define __CLIENT_H__
# include	<map>
# include	<string>
# include	"Config.h"
# include	"ModuleManager.h"
# include	"HttpParser.h"
# include	"HttpCommands.h"
# include	"Network.h"
# include	"Request.h"
# include	"Response.h"

class Client
{
public:
	Client(HttpCommands *, ModuleManager *, Config * conf);
	~Client();
	Network::ISocket *	getSocket();
	void				init(Network::ISocket *, bool);
	void				kill();
	bool				isAlive() const;
	void				readClient(Network::Neterror::eError, Network::Buffer &);
	void				writeClient(Network::Neterror::eError, Network::Buffer &);
	HttpCommands const *		getCommands() const {return (this->_cmds);};
	Client &			operator=(Client const &);
private:
	void				_checkConnectionLongevity(Request &, Response &);
	void				_storeBuffer(Network::Buffer &);
	void				_prepareBuffers(Response &);
	Network::ISocket *	_socket;
	bool				_isAlive;
	Network::t_buffer	_in;
	Network::t_buffer	_out;
	bool				_keepAlive;
	bool				_isSecure;
	HttpParser			_parser;
	HttpCommands *		_cmds;
	std::queue<Network::Buffer> _responses;
	ModuleManager *		_mods;
	Config *			_conf;
};

#endif // !__CLIENT_H__
