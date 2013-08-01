#include		"AcceptHandler.h"
#include		"ServerSocket.h"
#include		"IOHandler.h"

AcceptHandler::AcceptHandler(ServerSocket * sock, int action): _socket(sock), _action(action)
{
}

AcceptHandler::~AcceptHandler()
{
}

ServerSocket *		AcceptHandler::getSocket()
{
	return (this->_socket);
}

int				AcceptHandler::getAction() const
{
	return (this->_action);
}
