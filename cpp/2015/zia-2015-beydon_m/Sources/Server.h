#ifndef __SERVER_H__
# define __SERVER_H__
# include	<vector>
# include	"Config.h"
# include	"ModuleManager.h"
# include	"Client.h"
# include	"Plugins.h"

class Server
{
public:
	Server(Config *);
	~Server();
	void		run();
private:
	void					_startAccept(Network::Neterror::eError, Network::ISocket *);
	void					_setGeneralHeader();
	std::vector<Client>		_clients;
	Network::ISocket *		_acceptor;
	Network::ISocket *		_sacceptor;
	Network::Synchronizer	_sync;
	Thread::ThreadPool		_tp;
	Plugin::PluginManager	_p;
	HttpCommands			_cmds;
	int						_maxIdx;
	ModuleManager			_modules;
	Config *				_conf;
};

#endif // !__SERVER_H__
