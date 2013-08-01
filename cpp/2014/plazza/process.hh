#ifndef		_PROCESS_
# define	_PROCESS_
# include <unistd.h>

class	Process
{
public :
  Process(void *(*task)(void *));
  ~Process();

  void	begin(void *arg);
  void	plop();

  //private :
  pid_t	pid;
  void	*(*task)(void *);
};

#endif
