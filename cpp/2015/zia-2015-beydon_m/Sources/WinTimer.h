#ifndef		__WINTIMER_H__
# define	__WINTIMER_H__
# ifdef _WIN32
# define WIN32_LEAN_AND_MEAN
# include	<Windows.h>

class		WinTimer
{
public:
	WinTimer();
	~WinTimer();
	void		setTimerAt(int);
	bool		isUp();
private:
	ULONGLONG	_t;
	bool		_isSet;
};

typedef	WinTimer Timer;

# endif
#endif