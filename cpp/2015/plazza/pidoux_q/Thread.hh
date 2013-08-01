#ifndef		__THREAD__
# define	__THREAD__

# include <pthread.h>

typedef int th_stat;

# define NOT_WORKING 0
# define WIP	    1
# define DEAD	    -1

class	Thread
{
public :
  Thread(void *(*task)(void *));
  ~Thread();

  void	begin(void *arg);
  void	*wait();

private :
  th_stat	stat;
  void		*(*task)(void *);
  pthread_t	*th;
};

#endif
