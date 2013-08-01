#include	<iostream>
#include	"ThreadPool.h"

using namespace Thread;

ThreadPool::ThreadPool(unsigned int max) : _max(max)
{
	if (max > 0)
	{
		this->_t = new Thread(new ThreadAction(&ThreadPool::run, this));
		for (unsigned int i = 0; i < max; ++i)
			this->_threads.push_back(new Thread());
	}
}

ThreadPool::~ThreadPool()
{
	this->_threads.clear();
}

void		ThreadPool::startNewAction(ThreadAction & d)
{
	if (this->_max > 0)
	{
		this->_pmutex.lock();
		this->_actions.push(d);
		this->_pmutex.unlock();
		this->_condvar.WakeUp();
	}
	else
		d();
}

bool		ThreadPool::_isEmpty()
{
	this->_pmutex.lock();
	if (this->_actions.empty())
	{
		this->_pmutex.unlock();
		return (true);
	}
	this->_pmutex.unlock();
	return (false);
}

void		ThreadPool::run()
{
	std::vector< SmartPointer<Thread> >::iterator it;

	while (1)
	{
		if (this->_isEmpty())
			this->_condvar.Wait();
		while (!this->_isEmpty())
		{
			for (it = this->_threads.begin(); it != this->_threads.end() && (*it)->isRunning(); ++it);
			if (it != this->_threads.end())
			{
				this->_pmutex.lock();
				(*it)->execAction(this->_actions.front());
				this->_actions.pop();
				this->_pmutex.unlock();
			}
		}
	}
}