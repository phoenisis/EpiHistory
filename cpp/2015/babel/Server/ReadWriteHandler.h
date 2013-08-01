#ifndef		__READWRITE_HANDLER_H__
# define	__READWRITE_HANDLER_H__
# include	"IOHandler.h"
# include	"Buffer.h"
# include	"ClientSocket.h"

class		ClientSocket;

class		ReadWriteHandler : public IOHandler
{
public:
	ReadWriteHandler(ClientSocket *socket, int action, Buffer *, int id);
	~ReadWriteHandler();
	ClientSocket *		getSocket();
	int				getAction() const;
	Buffer *		getBuffer();
	int				getId();
private:
	ClientSocket *		_socket;
	int				_action;
	Buffer *		_buf;
	int				_id;
};

#endif
