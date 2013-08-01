#ifdef	_WIN32
# include "WinFunc.h"
#else
# include "UnixFunc.h"
#endif
#include	<deque>
#include	<list>
#include	<iostream>
#include	<cstring>
#include	"ISocket.h"
#include	"IOHandler.h"
#include	"Synchronizer.h"
#include	"ReadWriteHandler.h"
#include	"AcceptHandler.h"


Synchronizer::Synchronizer()
{
}

Synchronizer::~Synchronizer()
{
	this->_acceptHandlers.clear();
	this->_readHandlers.clear();
	this->_writeHandlers.clear();
}

void			Synchronizer::addHandler(IOHandler * handler)
{
	if (handler->getAction() == READ)
		this->_readHandlers.push_back(dynamic_cast<ReadWriteHandler *>(handler));
	else if (handler->getAction() == WRITE)
		this->_writeHandlers.push_back(dynamic_cast<ReadWriteHandler *>(handler));
	else
		this->_acceptHandlers.push_back(dynamic_cast<AcceptHandler *>(handler));
}

void			Synchronizer::removeHandlers(int id)
{
	std::deque<ReadWriteHandler *>::iterator	it;

	for (it = this->_readHandlers.begin(); it != this->_readHandlers.end(); ++it)
	{
		if (id == (*it)->getId())
			this->_readHandlers.erase(it);
	}
	for (it = this->_writeHandlers.begin(); it != this->_writeHandlers.end(); ++it)
	{
		if (id == (*it)->getId())
			this->_writeHandlers.erase(it);
	}
}

void			Synchronizer::removeHandlers(ISocket *sock)
{
	std::deque<AcceptHandler *>::iterator	it2;

	for (it2 = this->_acceptHandlers.begin(); it2 != this->_acceptHandlers.end(); ++it2)
	{
		if (sock->getSocket() == (*it2)->getSocket()->getSocket())
			this->_acceptHandlers.erase(it2);
	}
}

int					Synchronizer::construct_reads(T_POLLFD *polls, int i)
{
	std::deque<ReadWriteHandler *>::iterator it;
	std::deque<AcceptHandler *>::iterator it2;

	for (it = this->_readHandlers.begin(); it != this->_readHandlers.end(); ++it)
	{
		setRead(polls[i], (*it)->getSocket()->getSocket());
		++i;
	}
	for (it2 = this->_acceptHandlers.begin(); it2 != this->_acceptHandlers.end(); ++it2)
	{
		setRead(polls[i], (*it2)->getSocket()->getSocket());
		++i;
	}
	return (i);
}

int					Synchronizer::construct_writes(T_POLLFD *polls, int i)
{
	std::deque<ReadWriteHandler *>::iterator it;

	for (it = this->_writeHandlers.begin(); it != this->_writeHandlers.end(); ++it)
	{
		setWrite(polls[i], (*it)->getSocket()->getSocket());
		++i;
	}
	return (i);
}

void			Synchronizer::poll()
{
	int			i = 0;
	T_POLLFD	*fds;
	int			nfds;
	int			ret;
	T_POLLFD	tmp;
	std::deque<ReadWriteHandler *>::iterator it;
	std::deque<AcceptHandler *>::iterator it2;

	nfds = this->_acceptHandlers.size() + this->_readHandlers.size() + this->_writeHandlers.size();
	fds = new T_POLLFD[nfds];
	memset(fds, 0, sizeof(T_POLLFD) * nfds);
	i = this->construct_reads(fds, i);
	i = this->construct_writes(fds, i);
	std::cout << "Starting poll" << std::endl;
	ret = _poll(fds, nfds, -1);
	if (ret > 0)
	{
		i = 0;
		for (it = this->_readHandlers.begin(); it != this->_readHandlers.end(); ++i)
		{
			tmp = fds[i];
			if (hasError(tmp) || isDisconnected(tmp))
			{
				std::cout << "Client #" << (*it)->getId() << " has disconnected" << std::endl;
				this->_deadClients.push_front((*it)->getId());
				it = this->_readHandlers.erase(it);
			}
			else if (canRead(tmp))
			{
				(*it)->getBuffer()->setBuffLen((*it)->getSocket()->recv((*it)->getBuffer()));
				std::cout << "Message '" << (*it)->getBuffer()->getBuffer().buf << "' was read from client #" << (*it)->getId() << std::endl;
				this->_readClients.push_front(*it);
				it = this->_readHandlers.erase(it);
			}
			else
				++it;
		}
		for (it2 = this->_acceptHandlers.begin(); it2 != this->_acceptHandlers.end(); ++i)
		{
			tmp = fds[i];
			if (!hasError(tmp) && canRead(tmp))
			{
				this->_newClients.push_front((*it2)->getSocket()->accept());
				std::cout << "New Client has connected" << std::endl;
				it2 = this->_acceptHandlers.erase(it2);
			}
			else
				++it2;
		}
		for (it = this->_writeHandlers.begin(); it != this->_writeHandlers.end(); ++i)
		{
			tmp = fds[i];
			if (hasError(tmp) || isDisconnected(tmp))
			{
				std::cout << "Client #" << (*it)->getId() << " has disconnected" << std::endl;
				this->_deadClients.push_front((*it)->getId());
				it = this->_writeHandlers.erase(it);
			}
			else if (canWrite(tmp))
			{
				(*it)->getSocket()->send((*it)->getBuffer());
				std::cout << "Message '" << (*it)->getBuffer()->getBuffer().buf << "' was sent to client #" << (*it)->getId() << std::endl;
				it = this->_writeHandlers.erase(it);
			}
			else
				++it;
		}
	}
	delete fds;
}

std::list<int>	*					Synchronizer::getDeadClients()
{
	return (&this->_deadClients);
}

std::list<ClientSocket *> *			Synchronizer::getNewClients()
{
	return (&this->_newClients);
}

std::list<ReadWriteHandler *> *		Synchronizer::getReads()
{
	return (&this->_readClients);
}
