#ifdef	_WIN32

#include	<list>
#include	"WinSynchronizer.h"

using namespace Network;

WinSynchronizer::WinSynchronizer(int time, Thread::ThreadPool * tp)
{
	this->_time = time;
	this->_tp = tp;
}

WinSynchronizer::~WinSynchronizer()
{
	this->_handlers.clear();
}

void			WinSynchronizer::setTime(int time)
{
	if (time >= -1)
		this->_time = time;
}

void			WinSynchronizer::setThreadPool(Thread::ThreadPool * tp)
{
	this->_tp = tp;
}


void			WinSynchronizer::addHandler(SmartPointer<detail::IOOperation> handler)
{
	this->_pushMutex.lock();
	this->_newHandlers.push_back(handler);
	this->_pushMutex.unlock();
}


void			WinSynchronizer::removeHandlers(ISocket * sock)
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

void					WinSynchronizer::construct_poll(WSAPOLLFD *polls)
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

void				WinSynchronizer::transferPolls()
{
	std::list<SmartPointer<detail::IOOperation> >::iterator	it;

	for (it = this->_newHandlers.begin(); it != this->_newHandlers.end(); ++it)
		this->_handlers.push_back(*it);
	this->_newHandlers.clear();
}

void				WinSynchronizer::doRead(ISocket *s, Buffer & buf, ReadHandler & h)
{
	buf = s->recv(buf);
	h(Neterror::SUCCESS, buf);
}

void				WinSynchronizer::doWrite(ISocket *s, Buffer & buf, WriteHandler & h)
{
	buf = s->send(buf);
	h(Neterror::SUCCESS, buf);
}

void				WinSynchronizer::doAccept(ISocket *s, AcceptHandler & h)
{
	h(Neterror::SUCCESS, s->accept());
}

int					WinSynchronizer::poll()
{
	WSAPOLLFD	*fds;
	int			nfds;
	int			ret = 0;
	WSAPOLLFD	tmp;
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
		fds = new WSAPOLLFD[nfds];
		memset(fds, 0, sizeof(WSAPOLLFD) * nfds);
		this->construct_poll(fds);
		ret = WSAPoll(fds, nfds, this->_time);
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
						Function::Delegate<void> f = Function::bind(&WinSynchronizer::doRead, this, itWR->getSocket(), itWR->getBuffer(), itWR->getCallback());
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
						Function::Delegate<void> f = Function::bind(&WinSynchronizer::doWrite, this, itWR->getSocket(), itWR->getBuffer(), itWR->getCallback());
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
						Function::Delegate<void> f = Function::bind(&WinSynchronizer::doAccept, this, itA->getSocket(), itA->getCallback());
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

void			WinSynchronizer::setRead(WSAPOLLFD & p, t_socket const & s)
{
	p.fd = s;
	p.events = p.events | POLLRDNORM;
	p.revents = 0;
}

void			WinSynchronizer::setWrite(WSAPOLLFD & p, t_socket const & s)
{
	p.fd = s;
	p.events = p.events | POLLWRNORM;
	p.revents;
}

bool			WinSynchronizer::canWrite(WSAPOLLFD & p)
{
	if ((p.revents & POLLWRNORM))
		return (true);
	else
		return (false);
}

bool			WinSynchronizer::canRead(WSAPOLLFD & p)
{
	if ((p.revents & POLLRDNORM))
		return (true);
	else
		return (false);
}

bool			WinSynchronizer::isDisconnected(WSAPOLLFD & p)
{
	if ((p.revents & POLLHUP))
		return (true);
	else
		return (false);
}

bool			WinSynchronizer::hasError(WSAPOLLFD & p)
{
	if ((p.revents & POLLERR) || (p.revents & POLLNVAL))
		return (true);
	else
		return (false);
}



#endif