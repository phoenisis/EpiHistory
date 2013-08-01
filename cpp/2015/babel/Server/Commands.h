#ifndef		__COMMANDS_H__
# define	__COMMANDS_H__
# include	<list>
# include	<string>
# include	<map>
# include	<vector>
# include	"DataStructures.h"
# include	"Deserializer.h"
# include	"Serializer.h"
# include	"Account.h"
# include	"Client.h"

class		Commands
{
public:
	Commands();
	~Commands();
	void		setAccountList(Account *);
	void		setClientList(std::vector<Client *> *);
	void		setConnectedList(std::map<std::string, int> *);
	void		executeCommands(Buffer *, Client *);
	void					_handshake(Client *);
	void					_createAccount(Client *);
	void					_authenticate(Client *);
	void					_networkInfos(Client *);
	void					_addContact(Client *);
	void					_deleteContact(Client *);
	void					_contactConnected(Client *);
	void					_contactDisconnected(Client *);
	void					_callContact(Client *);
	void					_hangUp(Client *);
	void					sendError(short int, short int, Client *);
private:
	std::vector<Client *> *	_clients;
	Account *				_accounts;
	std::map<std::string, int>	* _connectList;
	Serializer				_serie;
	Deserializer			_deserie;
};

#endif