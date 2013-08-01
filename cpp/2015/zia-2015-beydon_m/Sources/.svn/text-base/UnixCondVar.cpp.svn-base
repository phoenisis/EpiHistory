#ifndef _WIN32
# include	"UnixCondVar.h"
using namespace Thread;

UnixCondVar::UnixCondVar()
{
	pthread_cond_init(&this->_cv, NULL);
	pthread_mutex_init(&this->_cs, NULL);
}

UnixCondVar::~UnixCondVar()
{
	pthread_cond_destroy(&this->_cv);
	pthread_mutex_destroy(&this->_cs);
}

void		UnixCondVar::Wait()
{
	pthread_mutex_lock(&this->_cs);
	pthread_cond_wait(&this->_cv, &this->_cs);
	pthread_mutex_unlock(&this->_cs);
}

void		UnixCondVar::WakeUp()
{
	pthread_cond_signal(&this->_cv);
}

#endif // !_WIN32
