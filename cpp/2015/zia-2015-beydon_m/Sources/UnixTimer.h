#ifndef		__UNIXTIMER_H__
# define	__UNIXTIMER_H__
# ifndef _WIN32
# include		<sys/time.h>

class		UnixTimer
{
public:
	UnixTimer();
	~UnixTimer();
	void	setTimerAt(int time);
	bool	isUp();
private:
	struct timeval	_t;
	bool			_isSet;
};

typedef	UnixTimer Timer;

# endif
#endif
