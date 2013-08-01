#ifndef	_WIN32

#include	<list>
#include	"UnixSynchronizer.h"

using namespace Network;

static int	_poll(struct pollfd *fds, nfds_t nfds, int timeout)
{
  return (poll(fds, nfds, timeout));
}


UnixSynchronizer::UnixSynchronizer(int time, Thread::ThreadPool * tp)
{
	this->_time = time;
	this->_tp = tp;
}

UnixSynchronizer::~UnixSynchronizer()
{
	this->_handlers.clear();
}

void			UnixSynchronizer::setTime(int time)
{
	if (time >= -1)
		this->_time = time;
}

void			UnixSynchronizer::setThreadPool(Thread::ThreadPool * tp)
{
	this->_tp = tp;
}

void			UnixSynchronizer::addHandler(SmartPointer<detail::IOOperation> handler)
{
	this->_pushMutex.lock();
	this->_newHandlers.push_back(handler);
	this->_pushMutex.unlock();
}

void			UnixSynchronizer::removeHandlers(ISocket *sock)
{
	std::list<SmartPointer<detail::IOOperation> >::iterator	it2;

	this->_pushMutex.lock();
	for (it2 = this->_newHandlers.begin(); it2 != this->_newHandlers.end();)
	{
		if (sock->getSocket() == (*it2)->getSocket()->getSocket())
			it2 = this->_newHandlers.erase(it2);
		else
			++it2;
	}
	this->_pushMutex.unlock();
}


void					UnixSynchronizer::construct_poll(struct pollfd *polls)
{
	std::list<SmartPointer<detail::IOOperation> >::iterator it;
	int										i = 0;

	for (it = this->_handlers.begin(); it != this->_handlers.end(); ++it)
	{
		if ((*it)->getAction() == detail::READ || (*it)->getAction() == detail::ACCEPT)
			this->setRead(polls[i], (*it)->getSocket()->getSocket());
		else
			this->setWrite(polls[i], (*it)->getSocket()->getSocket());
		++i;
	}
}

void				UnixSynchronizer::transferPolls()
{
	std::list<SmartPointer<detail::IOOperation> >::iterator	it;

	for (it = this->_newHandlers.begin(); it != this->_newHandlers.end(); ++it)
		this->_handlers.push_back(*it);
	this->_newHandlers.clear();
}

void					UnixSynchronizer::doRead(ISocket *s, Buffer & buf, ReadHandler & h)
{
	if ((buf = s->recv(buf)) == 0)
		h(Neterror::FAILURE, buf);
	else
		h(Neterror::SUCCESS, buf);
}

void					UnixSynchronizer::doWrite(ISocket *s, Buffer & buf, WriteHandler & h)
{
	if ((buf = s->send(buf)) == 0)
		h(Neterror::FAILURE, buf);
	else
		h(Neterror::SUCCESS, buf);
}

void					UnixSynchronizer::doAccept(ISocket *s, AcceptHandler & h)
{
	h(Neterror::SUCCESS, s->accept());
}


int						UnixSynchronizer::poll()
{
	struct pollfd	*fds;
	int			nfds;
	int			ret = 0;
	struct pollfd	tmp;
	std::list<SmartPointer<detail::IOOperation> >::iterator it;
	detail::ReadWriteOperation * itWR;
	detail::AcceptOperation * itA;
	int									i;

	this->_pushMutex.lock();
	this->transferPolls();
	this->_pushMutex.unlock();
	nfds = this->_handlers.size();
	if (nfds > 0)
	{
		fds = new struct pollfd[nfds];
		memset(fds, 0, sizeof(struct pollfd) * nfds);
		this->construct_poll(fds);
		ret = _poll(fds, nfds, this->_time);
		if (ret > 0)
		{
			i = 0;
			for (it = this->_handlers.begin(); it != this->_handlers.end(); ++i)
			{
				tmp = fds[i];
				if ((*it)->getAction() == detail::ACCEPT)
					itA = dynamic_cast<detail::AcceptOperation *>((*it).getPtr());
				else
					itWR = dynamic_cast<detail::ReadWriteOperation *>((*it).getPtr());
				if (this->hasError(tmp) || this->isDisconnected(tmp))
				{
					if ((*it)->getAction() != detail::ACCEPT)
						itWR->getCallback().exec(Neterror::FAILURE, itWR->getBuffer());
					else
						itA->getCallback().exec(Neterror::FAILURE, NULL);
					it = this->_handlers.erase(it);
				}
				else if ((*it)->getAction() == detail::READ && this->canRead(tmp))
				{
					if (this->_tp)
					{
						Function::Delegate<void> f(Function::bind(&UnixSynchronizer::doRead, this, itWR->getSocket(), itWR->getBuffer(), itWR->getCallback()));
						this->_tp->startNewAction(f);
					}
					else
						this->doRead(itWR->getSocket(), itWR->getBuffer(), itWR->getCallback());
					it = this->_handlers.erase(it);
				}
				else if ((*it)->getAction() == detail::WRITE && this->canWrite(tmp))
				{
					if (this->_tp)
					{
						Function::Delegate<void> f(Function::bind(&UnixSynchronizer::doWrite, this, itWR->getSocket(), itWR->getBuffer(), itWR->getCallback()));
						this->_tp->startNewAction(f);
					}
					else
						this->doWrite(itWR->getSocket(), itWR->getBuffer(), itWR->getCallback());
					it = this->_handlers.erase(it);
				}
				else if ((*it)->getAction() == detail::ACCEPT && this->canRead(tmp))
				{
					if (this->_tp)
					{
						Function::Delegate<void> f(Function::bind(&UnixSynchronizer::doAccept, this, itA->getSocket(), itA->getCallback()));
						this->_tp->startNewAction(f);
					}
					else
						this->doAccept(itA->getSocket(), itA->getCallback());
					it = this->_handlers.erase(it);
				}
				else
					++it;
			}
		}
		delete fds;
	}
	return (ret);
}

void			UnixSynchronizer::setRead(struct pollfd & p, t_socket const & s)
{
	p.fd = s;
	p.events = p.events | POLLIN;
	p.revents = 0;
}

void			UnixSynchronizer::setWrite(struct pollfd & p, t_socket const & s)
{
	p.fd = s;
	p.events = p.events | POLLOUT;
	p.revents = 0;
}

bool			UnixSynchronizer::canWrite(struct pollfd & p)
{
	if ((p.revents & POLLOUT))
		return (true);
	else
		return (false);
}

bool			UnixSynchronizer::canRead(struct pollfd & p)
{
	if ((p.revents & POLLIN))
		return (true);
	else
		return (false);
}

bool			UnixSynchronizer::isDisconnected(struct pollfd & p)
{
	if ((p.revents & POLLHUP))
		return (true);
	else
		return (false);
}

bool			UnixSynchronizer::hasError(struct pollfd & p)
{
	if ((p.revents & POLLERR) || (p.revents & POLLNVAL))
		return (true);
	else
		return (false);
}

#endif
