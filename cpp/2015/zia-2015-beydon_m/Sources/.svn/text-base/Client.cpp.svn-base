#include	"Client.h"
#include	"Response.h"

Client::Client(HttpCommands * cmds, ModuleManager *mod, Config * conf) : _socket(NULL), _isAlive(false), _keepAlive(false),
	_parser(HttpParser(conf->getPath())), _cmds(cmds), _mods(mod), _conf(conf)
{
	this->_in.buf = 0;
	this->_in.len = 0;
	this->_out.buf = 0;
	this->_out.len = 0;
}

Client::~Client()
{
	if (this->_socket && this->_socket->isOpen())
		delete this->_socket;
	Network::Buffer::clearBuffer(this->_in);
	Network::Buffer::clearBuffer(this->_out);
}

void		Client::init(Network::ISocket *s, bool isSecure)
{
	Network::ReadHandler fun(&Client::readClient, this);
	Network::Buffer buf(this->_conf->getBuffSize());

	this->_socket = s;
	this->_isAlive = true;
	s->asyncRead(buf, fun);
	this->_isSecure = isSecure;
}

void		Client::kill()
{
	if (this->_socket)
		delete this->_socket;
	this->_socket = NULL;
	this->_isAlive = false;
	this->_keepAlive = false;
	Network::Buffer::clearBuffer(this->_in);
	Network::Buffer::clearBuffer(this->_out);
	while (!this->_responses.empty())
		this->_responses.pop();
	this->_parser.clear();
}

bool		Client::isAlive() const
{
	return (this->_isAlive);
}

void		Client::_storeBuffer(Network::Buffer & buf)
{
	char *	tmp = new char[this->_in.len + buf.getBuffLen()];

	memcpy(tmp, this->_in.buf, this->_in.len);
	memcpy(tmp + this->_in.len, buf.getBuff().buf, buf.getBuffLen());
	this->_in.len += buf.getBuffLen();
	delete this->_in.buf;
	delete buf.getBuff().buf;
	this->_in.buf = tmp;
}

void		Client::_prepareBuffers(Response & res)
{
	char	*buf;
	int		len;
	int		i = 0;

	res.assemble();
	buf = res.getBuffer();
	len = res.getLength();
	this->_out.buf = new char[len];
	memcpy(this->_out.buf, buf, len);
	this->_out.len = len;
	while (i < len)
	{
		if (this->_out.len - i <= this->_conf->getBuffSize())
			this->_responses.push(Network::Buffer(this->_out.buf + i, this->_out.len - i));
		else
			this->_responses.push(Network::Buffer(this->_out.buf + i, this->_conf->getBuffSize()));
		i += this->_conf->getBuffSize();
	}
}

void			Client::_checkConnectionLongevity(Request & req, Response & res)
{
	if (req.getHeader().hasKey("Connection"))
	{
		if (req.getHeader().getValueForKey("Connection") == "keep-alive")
		{
			this->_keepAlive = true;
			res.getHeader().setValue("Connection", "keep-alive");
		}
		else
			res.getHeader().setValue("Connection", "close");
	}
}

void		Client::readClient(Network::Neterror::eError err, Network::Buffer &buf)
{
	if (err == Network::Neterror::SUCCESS)
	{
		Network::WriteHandler fun(&Client::writeClient, this);
		this->_storeBuffer(buf);
		this->_parser.feed(this->_in.buf, this->_in.len);
		if (this->_parser.isComplete() && this->_parser.isGood())
		{
			Request			req(this->_in.buf, this->_in.len);
			Response		res;		
			struct sockaddr_in s;

			this->_parser.fillRequest(req);
			this->_mods->execDirective(PROCESS_REQUEST, req, res, this->_socket->getSocket(), s);
			this->_cmds->execCommand(req, res);
			this->_mods->execDirective(CREATE_RESPONSE, req, res, this->_socket->getSocket(), s);
			this->_checkConnectionLongevity(req, res);
			this->_prepareBuffers(res);
			Network::Buffer::clearBuffer(this->_in);
			this->_socket->asyncWrite(this->_responses.front(), fun);
		}
		else if (!this->_parser.isGood())
		{
			Response		res;

			res.getHeader().setStatusCode("400");
			res.getHeader().setStatusMessage("Bad Request");
			res.getHeader().setVersion("HTTP/1.1");
			res.getHeader().setValue("Connection", "close");
			this->_prepareBuffers(res);
			Network::Buffer::clearBuffer(this->_in);
			this->_socket->asyncWrite(this->_responses.front(), fun);
		}
		else
		{
			Network::ReadHandler	fun(&Client::readClient, this);
			Network::Buffer			buf(this->_conf->getBuffSize());
			this->_socket->asyncRead(buf, fun);
		}
		this->_parser.clear();
	}
	else
	{
		delete buf.getBuff().buf;
		this->kill();
	}
}

void		Client::writeClient(Network::Neterror::eError err, Network::Buffer &)
{
	if (err == Network::Neterror::SUCCESS)
	{
		Network::WriteHandler	write(&Client::writeClient, this);
		Network::ReadHandler	read(&Client::readClient, this);

		this->_responses.pop();
		if (!this->_responses.empty())
			this->_socket->asyncWrite(this->_responses.front(), write);
		else if (this->_keepAlive)
		{
			Network::Buffer buf(this->_conf->getBuffSize());
			this->_socket->asyncRead(buf, read);
			Network::Buffer::clearBuffer(this->_out);
		}
		else
			this->kill();
	}
	else
		this->kill();
}

Client &			Client::operator=(Client const & c)
{
	this->_cmds = const_cast<HttpCommands *>(c.getCommands());
	this->_socket = const_cast<Client &>(c).getSocket();
	this->_isAlive = c.isAlive();
	this->_keepAlive = false;
	this->_isSecure = false;
	return (*this);
}

Network::ISocket *	Client::getSocket()
{
	return (this->_socket);
}