#include	<iostream>
#include	"Serializer.h"
#include	"ClientSocket.h"
#include	"Buffer.h"
#include	"Client.h"

Client::Client(int id) : _id(id)
{
	this->_status = EMPTY;
}

Client::~Client()
{
	delete this->_socket;
}

ClientSocket *		Client::getSocket()
{
	return (this->_socket);
}

void				Client::init(ClientSocket *s)
{
	Serializer		serie;
	std::string *	str;

	this->_socket = s;
	serie.setHeader(SUCCESS, 0, this->_id, this->_id);
	str = serie.getResult();
	this->_socket->asyncRead(new Buffer(512), this->_id);
	this->_socket->asyncWrite(new Buffer(*str), this->_id);
	delete str;
	this->_status = NOT_AUTHENTICATED;
}

bool				Client::isEmpty()
{
	return (this->_status == EMPTY);
}

void				Client::kill()
{
	delete this->_socket;
	this->_status = EMPTY;
	this->_login.clear();
}


void				Client::setLogin(std::string const &str)
{
	this->_login.assign(str);
}

std::string const & Client::getLogin() const
{
	return (this->_login);
}

int					Client::getId() const
{
	return (this->_id);
}

void				Client::setStatus(enum eStatus st)
{
	this->_status = st;
}

enum eStatus		Client::getStatus() const
{
	return (this->_status);
}

void				Client::setUdpPort(short int port)
{
	this->_port = port;
}

short int			Client::getUdpPort() const
{
	return (this->_port);
}