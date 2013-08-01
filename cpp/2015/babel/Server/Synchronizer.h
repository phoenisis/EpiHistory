#ifndef		__SYNCHRONIZER_H__
# define	__SYNCHRONIZER_H__
# ifdef	_WIN32
#  include	"WinFunc.h"
# else
#  include	"UnixFunc.h"
#endif
# include	<deque>
# include	<list>
# include	"IOHandler.h"
# include	"AcceptHandler.h"
# include	"ReadWriteHandler.h"
# include	"ClientSocket.h"
# include	"ISocket.h"

class		ClientSocket;
class		AcceptHandler;
class		ReadWriteHandler;

class		Synchronizer
{
public:
	Synchronizer();
	~Synchronizer();
	void			addHandler(IOHandler *);
	void			removeHandlers(ISocket *);
	void			removeHandlers(int id);
	std::list<ClientSocket *> *		getNewClients();
	std::list<int> *				getDeadClients();
	std::list<ReadWriteHandler *> *	getReads();
	void			poll();
private:
	int					construct_reads(T_POLLFD *, int);
	int					construct_writes(T_POLLFD *, int);
	std::list<ClientSocket *>	_newClients;
	std::list<int>				_deadClients;
	std::list<ReadWriteHandler *>	_readClients;
	std::deque<AcceptHandler *>	_acceptHandlers;
	std::deque<ReadWriteHandler *>	_readHandlers;
	std::deque<ReadWriteHandler *>	_writeHandlers;
};

#endif