#ifndef		__ACCEPT_HANDLER_H__
# define	__ACCEPT_HANDLER_H__
# include	"IOHandler.h"
# include	"ServerSocket.h"

class		ServerSocket;

class		AcceptHandler : public IOHandler
{
public:
	AcceptHandler(ServerSocket *socket, int action);
	~AcceptHandler();
	ServerSocket *		getSocket();
	int					getAction() const;
private:
	ServerSocket *		_socket;
	int					_action;
};

#endif