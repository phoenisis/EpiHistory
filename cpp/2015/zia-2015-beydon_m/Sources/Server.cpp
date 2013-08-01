#include	"WhatElseModule.h"
#include	"Server.h"

Server::Server(Config * conf) : _tp(Thread::ThreadPool(conf->getNbThreads())), _maxIdx(0), _conf(conf)
{
	Network::AcceptHandler fun(&Server::_startAccept, this);
	std::list<t_module>		l;
	
	l = conf->getModules();
	for (std::list<t_module>::iterator it = l.begin(); it != l.end(); ++it)
		this->_modules.addModule(new WhatElseModule((*it).path_));
	this->_modules.loadModules();
	this->_modules.initModules();
	this->_acceptor = new Network::TCPSocket(&this->_sync);
	this->_sacceptor = new Network::TCPSocket(&this->_sync);
	this->_sync.setTime(20);
	this->_sync.setThreadPool(&this->_tp);
	this->_acceptor->open(AF_INET);
	this->_acceptor->bind_(conf->getPort());
	this->_acceptor->listen_(100);
	this->_sacceptor->open(AF_INET);
	this->_sacceptor->bind_(443);
	this->_sacceptor->listen_(100);
	this->_acceptor->asyncAccept(fun);
	this->_sacceptor->asyncAccept(fun);
	for (int i = 0; i < conf->getMaxClients(); ++i)
		this->_clients.push_back(Client(&this->_cmds, &this->_modules, this->_conf));
}

Server::~Server()
{
	delete this->_acceptor;
	delete this->_sacceptor;
	this->_clients.clear();
}

void					Server::_startAccept(Network::Neterror::eError err, Network::ISocket * s)
{
	std::vector<Client>::iterator	it;
	Network::AcceptHandler fun(&Server::_startAccept, this);

	if (err == Network::Neterror::SUCCESS)
	{
		for (it = this->_clients.begin(); it != this->_clients.end() && (*it).isAlive(); ++it);
		if (it != this->_clients.end())
			(*it).init(s, false);
		else
			delete s;
	}
	this->_acceptor->asyncAccept(fun);
}

void		Server::run()
{
	while (1)
	{
		this->_sync.poll();
	}
}