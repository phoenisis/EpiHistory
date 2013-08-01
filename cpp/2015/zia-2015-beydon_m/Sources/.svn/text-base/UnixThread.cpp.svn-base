#ifndef	_WIN32
# include	"UnixThread.h"

using namespace Thread;

UnixThread::UnixThread() : _id(0), _isRunning(false), _exitValue(0)
{
	ThreadAction *	f = new ThreadAction(&UnixThread::run, this);

	pthread_create(&this->_handle, 0, &UnixThread::exec, f);
}

UnixThread::UnixThread(ThreadAction * func) : _id(0), _isRunning(true), _exitValue(0)
{
	pthread_create(&this->_handle, 0, &UnixThread::exec, func);
}


UnixThread::~UnixThread()
{
	this->_condvar.WakeUp();
	if (this->_handle != NULL)
		pthread_detach(this->_handle);
}

void		UnixThread::run()
{
	while (1)
	{
		if (this->_action.empty())
			this->_condvar.Wait();
		while (!this->_action.empty())
		{
			this->_action.front()();
			this->_action.pop();
		}
		this->_isRunning = false;
	}
}

void		UnixThread::execAction(ThreadAction & action)
{
	this->_action.push(action);
	this->_isRunning = true;
	this->_condvar.WakeUp();
}


thread_ret			UnixThread::WaitForThread()
{
	this->_isRunning = false;
	pthread_join(this->_handle, &this->_exitValue);
	return (this->_exitValue);
}

bool		UnixThread::isRunning()
{
	return (this->_isRunning);
}

int			UnixThread::getId()
{
	return (this->_id);
}

thread_ret			UnixThread::getThreadExitStatus()
{
	return (this->_exitValue);
}
#endif
