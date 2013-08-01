#ifndef			__CLIENT_H__
# define		__CLIENT_H__
# include		"Buffer.h"
# include		"ClientSocket.h"

class			ClientSocket;

enum			eStatus
{
	EMPTY = 0,
	NOT_AUTHENTICATED,
	NO_INFOS,
	READY,
	BUSY
};

class			Client
{
public:
	Client(int id);
	~Client();
	ClientSocket *	getSocket();
	void			init(ClientSocket *);
	void			kill();
	bool			isEmpty();
	void			setStatus(enum eStatus);
	enum eStatus	getStatus() const;
	void			setLogin(std::string const &);
	std::string const & getLogin() const;
	int				getId() const;
	void			setUdpPort(short int);
	short int		getUdpPort() const;
private:
	ClientSocket	*_socket;
	int				_id;
	enum eStatus	_status;
	std::string		_login;
	short int		_port;
};

#endif