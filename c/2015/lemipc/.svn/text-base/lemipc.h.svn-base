/*
** lemipc.h for  in /home/fleuro_m//work/lemipc/lemipc-2015-2014s-pidoux_q
**
** Made by matthieu fleurot
** Login   <fleuro_m@epitech.net>
**
** Started on  Sun Mar 25 16:04:45 2012 matthieu fleurot
** Last update Sun Mar 25 22:42:11 2012 matthieu fleurot
*/

#ifndef		LEMIPC_H_

# define	LEMIPC_H_

# include <sys/types.h>
# include <sys/ipc.h>
# include <sys/shm.h>
# include <sys/sem.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <time.h>

typedef struct	s_ipc
{
  int		shm_id;
  int		sem_id;
  void		*addr;
  struct sembuf	sops;
}		t_ipc;

typedef struct s_player
{
  int		team;
  int		pos_x;
  int		pos_y;
}		t_player;

void		init_ipc(t_ipc *my_ipc);
void		wait_for_player(t_ipc *my_ipc);
void		init_player(t_player *play, t_ipc *my_ipc);


#endif		/*LEMIPC_H_*/
