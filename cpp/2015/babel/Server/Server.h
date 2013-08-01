#ifndef		__SERVER_H__
# define	__SERVER_H__
# include	<vector>
# include	<string>
# include	<map>
# include	"Account.h"
# include	"Commands.h"
# include	"Client.h"
# include	"ServerSocket.h"
# include	"Synchronizer.h"


class		Server
{
public:
	Server(Synchronizer *);
	~Server();
	void		run();
private:
	void					addNewClient(ClientSocket *);
	std::vector<Client *>	_clients;
	ServerSocket *	_socket;
	Synchronizer *	_sync;
	Account			_accounts;
	std::map<std::string, int>	_connectedList;
	Commands					_commands;
};

#endif