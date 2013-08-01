#include		"Buffer.h"
#include		"ClientSocket.h"
#include		"IOHandler.h"
#include		"ReadWriteHandler.h"


ReadWriteHandler::ReadWriteHandler(ClientSocket * sock, int action, Buffer * buf, int id): _socket(sock), _action(action), _id(id)
{
  this->_buf = buf;
}

ReadWriteHandler::~ReadWriteHandler()
{
}

ClientSocket *		ReadWriteHandler::getSocket()
{
	return (this->_socket);
}

int				ReadWriteHandler::getAction() const
{
	return (this->_action);
}

Buffer *		ReadWriteHandler::getBuffer()
{
	return (this->_buf);
}

int				ReadWriteHandler::getId()
{
	return (this->_id);
}
