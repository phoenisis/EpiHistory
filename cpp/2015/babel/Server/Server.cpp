#include		<list>
#include		<vector>
#include		"ReadWriteHandler.h"
#include		"AcceptHandler.h"
#include		"ServerSocket.h"
#include		"Account.h"
#include		"Commands.h"
#include		"Client.h"
#include		"Server.h"
#include		"Synchronizer.h"

Server::Server(Synchronizer *sync) : _sync(sync)
{
	std::vector<Client *>::iterator		it;
	int									i = 0;

	this->_socket = new ServerSocket(sync);
	this->_socket->open(AF_INET, "TCP");
	this->_socket->doBind(4242, 20);
	this->_clients.reserve(1024);
	for (i = 0; i < 1024; ++i)
		this->_clients.push_back(new Client(i));
	this->_commands.setAccountList(&this->_accounts);
	this->_commands.setClientList(&this->_clients);
	this->_commands.setConnectedList(&this->_connectedList);
}

Server::~Server()
{
	delete this->_socket;
	this->_clients.clear();
}

void			Server::addNewClient(ClientSocket *s)
{
	unsigned int			i;

	for (i = 1; i < this->_clients.size() - 1 && !this->_clients[i]->isEmpty(); ++i);
	this->_clients[i]->init(s);
}

void			Server::run()
{
	std::list<int>*		deadClients;
	std::list<ClientSocket *>* newClients;
	std::list<ReadWriteHandler *>* reads;
	std::list<int>::iterator		itD;
	std::list<ClientSocket *>::iterator itN;
	std::list<ReadWriteHandler *> ::iterator itR;

	this->_socket->asyncAccept();
	while (1)
	{
		this->_sync->poll();
		deadClients = this->_sync->getDeadClients();
		newClients = this->_sync->getNewClients();
		reads = this->_sync->getReads();
		itD = deadClients->begin(); 
		while (itD != deadClients->end())
		{
			if (this->_clients[*itD]->getStatus() == READY)
				this->_commands._contactDisconnected(this->_clients[*itD]);
			this->_clients[*itD]->kill();
			itD = deadClients->erase(itD);
		}
		if (!newClients->empty())
			this->_socket->asyncAccept();
		itN = newClients->begin();
		while (itN != newClients->end())
		{
			this->addNewClient(*itN);
			itN = newClients->erase(itN);
		}
		itR = reads->begin();
		while (itR != reads->end())
		{
			this->_commands.executeCommands((*itR)->getBuffer(), this->_clients[(*itR)->getId()]);
			delete *itR;
			itR = reads->erase(itR);
		}
	}
}
