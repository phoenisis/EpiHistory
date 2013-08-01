#include	<vector>
#include	<list>
#include	<utility>
#include	<map>
#include	<string>
#include	"Commands.h"
#include	"Account.h"
#include	"Client.h"
#include	"Serializer.h"
#include	"Deserializer.h"


void		(Commands::*cmdTab[11])(Client *) = 
{
	&Commands::_handshake,
	&Commands::_createAccount,
	&Commands::_authenticate,
	&Commands::_networkInfos,
	&Commands::_addContact,
	&Commands::_deleteContact,
	&Commands::_contactConnected,
	&Commands::_contactDisconnected,
	&Commands::_callContact,
	&Commands::_hangUp,
	NULL
};

Commands::Commands()
{
}

Commands::~Commands()
{
}

void		Commands::setAccountList(Account *account)
{
	this->_accounts = account;
}

void		Commands::setClientList(std::vector<Client *> *clients)
{
	this->_clients = clients;	
}

void		Commands::setConnectedList(std::map<std::string, int> *connectedList)
{
	this->_connectList = connectedList;
}

void		Commands::sendError(short int cmdNbr, short int status, Client *cl)
{
	std::string *str;

	this->_serie.setHeader(status, cmdNbr, cl->getId(), cl->getId());
	str = this->_serie.getResult();
	cl->getSocket()->asyncWrite(new Buffer(*str), cl->getId());
	delete str;
}

void		Commands::executeCommands(Buffer *buf, Client *cl)
{
	int		cmdNbr;

	this->_deserie.feedBuffer(std::string(buf->getBuffer().buf, buf->getBuffer().len));
	
	cmdNbr = this->_deserie.getCmdNumber();
	if (cmdNbr > 0 && cmdNbr < 10)
		(this->*cmdTab[cmdNbr])(cl);
	else
		this->sendError(0, COMMAND_NOT_FOUND, cl);
	this->_serie.clear();
	this->_deserie.clear();
	cl->getSocket()->asyncRead(new Buffer(512), cl->getId());
	delete buf;
}

void		Commands::_handshake(Client *cl)
{
	std::string *str;

	this->_serie.setHeader(SUCCESS, 0, cl->getId(), cl->getId());
	str = this->_serie.getResult();
	cl->getSocket()->asyncWrite(new Buffer(*str), cl->getId());
	delete str;
}

void		Commands::_createAccount(Client *cl)
{
	AuthenticationPacket *	auth;

	if (cl->getStatus() == NOT_AUTHENTICATED)
	{
		auth = this->_deserie.getAPacket();
		this->_accounts->addContact(std::string(auth->login, auth->loginSize), std::string(auth->password, auth->passwordSize));
		cl->setStatus(NO_INFOS);
		this->_handshake(cl);
		delete auth;
	}
	else
		this->sendError(0, FAILURE, cl);
}

void		Commands::_authenticate(Client *cl)
{
	AuthenticationPacket *	auth;
	std::string				login;
	std::string				pass;

	auth = this->_deserie.getAPacket();
	login.assign(auth->login, auth->loginSize);
	pass.assign(auth->password, auth->passwordSize);
	if (cl->getStatus() == NOT_AUTHENTICATED)
	{
		if (this->_accounts->checkIfExist(login) && this->_accounts->getPassword(login) == pass)
		{
			cl->setLogin(login);
			this->_handshake(cl);
			cl->setStatus(NO_INFOS);
		}
		else
			this->sendError(0, AUTHENTICATION_FAILURE, cl);
	}
	else
		this->sendError(0, FAILURE, cl);
	delete auth;
}

void		Commands::_networkInfos(Client *cl)
{
	NetworkInformationPacket	*p;
	std::list<std::string>		*contacts;
	std::list<std::string>::iterator it;
	short int						contactId = 0;
	std::string						*str;

	p = this->_deserie.getNIPacket();
	if (cl->getStatus() == NO_INFOS)
	{
		cl->setUdpPort(p->port);
		contacts = this->_accounts->getContactListOf(cl->getLogin());
		for (it = contacts->begin(); it != contacts->end(); ++it)
		{
			if (this->_connectList->count(*it) > 0)
				contactId = this->_connectList->find(*it)->second;
			else
				contactId = 0;
			this->_serie.setHeader(SUCCESS, 4, cl->getId(), contactId);
			this->_serie.addInfo(*it);
			str = this->_serie.getResult();
			cl->getSocket()->asyncWrite(new Buffer(*str), cl->getId());
			delete str;
			this->_serie.clear();
		}
		this->_handshake(cl);
		this->_connectList->insert(std::pair<std::string, int>(cl->getLogin(), cl->getId()));
		this->_contactConnected(cl);
		cl->setStatus(READY);
		delete contacts;
	}
	else
		this->sendError(0, FAILURE, cl);
	delete p;
}

void		Commands::_addContact(Client *cl)
{
	ContactPacket *			p;
	short int				contactId;
	std::string	*			str;
	std::string				contact;
	PacketHeader			*h;

	h = this->_deserie.getHeader();
	if (h->targetId == 0)
	{
		p = this->_deserie.getCPacket();
		contact.assign(std::string(p->contactName, p->contactSize));
		if (this->_connectList->count(contact) > 0)
		{
			contactId = this->_connectList->find(contact)->second;
			this->_serie.setHeader(0, 4, cl->getId(), 0);
			this->_serie.addInfo(cl->getLogin());
			str = this->_serie.getResult();
			this->_clients->at(contactId)->getSocket()->asyncWrite(new Buffer(*str), contactId);
			delete str;
		}
		else
			this->sendError(4, 6, cl);
		delete p;
	}
	else
	{
		if (this->_clients->at(h->targetId)->getStatus() != EMPTY)
		{
			this->_serie.setHeader(h->status, h->cmd, h->sourceId, h->targetId);
			str = this->_serie.getResult();
			this->_clients->at(h->targetId)->getSocket()->asyncWrite(new Buffer(*str), this->_clients->at(h->targetId)->getId());
			this->_accounts->addContactToListOf(this->_clients->at(h->targetId)->getLogin(), cl->getLogin());
			delete str;
		}
	}
	delete h;
}

void			Commands::_deleteContact(Client *cl)
{
	ContactPacket *		c;
	std::string			contact;
	std::list<std::string>	*list;
	std::list<std::string>::iterator it;
	short int						contactId;
	std::string							*str;

	c = this->_deserie.getCPacket();
	contact.assign(c->contactName, c->contactSize);
	list = this->_accounts->getContactListOf(cl->getLogin());
	for (it = list->begin(); it != list->end() && *it != contact ; ++it);
	if (it != list->end())
	{
		this->_accounts->removeContactToListOf(cl->getLogin(), contact);
		this->_accounts->removeContactToListOf(contact, cl->getLogin());
	}
	if (this->_connectList->count(contact) > 0)
	{
		contactId = this->_connectList->find(contact)->second;
		this->_serie.setHeader(c->header.status, c->header.cmd, c->header.sourceId, contactId);
		str = this->_serie.getResult();
		this->_clients->at(contactId)->getSocket()->asyncWrite(new Buffer(*str), contactId);
		delete str;
	}
	delete c;
	delete list;
}

void			Commands::_contactConnected(Client *cl)
{
	std::list<std::string>		*list;
	std::list<std::string>::iterator it;
	std::string						*str;
	short int						contactId;

	list = this->_accounts->getContactListOf(cl->getLogin());
	for (it = list->begin(); it != list->end(); ++it)
	{
		if (this->_connectList->count(*it) > 0)
		{
			contactId = this->_connectList->find(*it)->second;
			this->_serie.setHeader(SUCCESS, 6, cl->getId(), contactId);
			this->_serie.addInfo(cl->getLogin());
			str = this->_serie.getResult();
			this->_clients->at(contactId)->getSocket()->asyncWrite(new Buffer(*str), contactId);
			this->_serie.clear();
			delete str;
		}
	}
	delete list;
}

void			Commands::_contactDisconnected(Client *cl)
{
	std::list<std::string>		*list;
	std::list<std::string>::iterator it;
	std::string						*str;
	short int						contactId;

	list = this->_accounts->getContactListOf(cl->getLogin());
	for (it = list->begin(); it != list->end(); ++it)
	{
		if (this->_connectList->count(*it) > 0)
		{
			contactId = this->_connectList->find(*it)->second;
			this->_serie.setHeader(SUCCESS, 7, cl->getId(), contactId);
			this->_serie.addInfo(cl->getLogin());
			str = this->_serie.getResult();
			this->_clients->at(contactId)->getSocket()->asyncWrite(new Buffer(*str), contactId);
			delete str;
		}
	}
	delete list;
	this->_connectList->erase(cl->getLogin());
}

void			Commands::_callContact(Client *cl)
{
	PacketHeader	*p;
	std::string *	str;

	p = this->_deserie.getHeader();
	if (p->sourceId == cl->getId())
	{
		if (this->_clients->at(p->targetId)->getStatus() != BUSY)
		{
			this->_serie.setHeader(SUCCESS, 8, p->sourceId, p->targetId);
			str = this->_serie.getResult();
			this->_clients->at(p->targetId)->getSocket()->asyncWrite(new Buffer(*str), p->targetId);
			delete str;
		}
	}
	else
	{
		this->_serie.setHeader(SUCCESS, 3, p->sourceId, p->targetId);
		this->_serie.addInfo(cl->getSocket()->getIp());
		this->_serie.addInfo(cl->getUdpPort());
		str = this->_serie.getResult();
		this->_clients->at(p->targetId)->getSocket()->asyncWrite(new Buffer(*str), cl->getId());
		delete str;
		this->_serie.clear();
		this->_serie.setHeader(SUCCESS, 3, p->targetId, p->sourceId);
		this->_serie.addInfo(this->_clients->at(p->sourceId)->getSocket()->getIp());
		this->_serie.addInfo(this->_clients->at(p->sourceId)->getUdpPort());
		str = this->_serie.getResult();
		this->_clients->at(p->sourceId)->getSocket()->asyncWrite(new Buffer(*str), p->sourceId);
		delete str;
		cl->setStatus(BUSY);
		this->_clients->at(p->sourceId)->setStatus(BUSY);
	}
	delete p;
}

void			Commands::_hangUp(Client *cl)
{
	PacketHeader		*p;
	std::string			*str;

	p = this->_deserie.getHeader();
	this->_serie.setHeader(SUCCESS, 9, p->sourceId, p->targetId);
	str = this->_serie.getResult();
	this->_clients->at(p->targetId)->getSocket()->asyncWrite(new Buffer(*str), p->targetId);
	delete str;
	cl->setStatus(READY);
	this->_clients->at(p->targetId)->setStatus(READY);
}
