#ifdef _WIN32
# include	<iostream>
# include	"WinThread.h"

using namespace Thread;

WinThread::WinThread() : _id(0), _isRunning(false), _exitValue(0)
{
	ThreadAction *	f = new ThreadAction(&WinThread::run, this);

	this->_handle = CreateThread(0, 0, &WinThread::exec, f, 0, &this->_id);
}

WinThread::WinThread(ThreadAction * func) : _id(0), _isRunning(true), _exitValue(0)
{
	this->_handle = CreateThread(0, 0, &WinThread::exec, func, 0, &this->_id);
}

WinThread::~WinThread()
{
	this->_condvar.WakeUp();
	if (this->_handle != NULL)
		TerminateThread(this->_handle, 0);
}

void		WinThread::run()
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

void		WinThread::execAction(ThreadAction & action)
{
	this->_action.push(action);
	this->_isRunning = true;
	this->_condvar.WakeUp();
}

thread_ret			WinThread::WaitForThread()
{
	this->_isRunning = false;
	return (WaitForSingleObject(this->_handle, INFINITE));
}

bool		WinThread::isRunning()
{
	return (this->_isRunning);
}

int			WinThread::getId()
{
	return (this->_id);
}

thread_ret			WinThread::getThreadExitStatus()
{
	return (this->_exitValue);
}

#endif