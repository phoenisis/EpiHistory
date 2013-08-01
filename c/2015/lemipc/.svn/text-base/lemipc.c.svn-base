/*
** lemipc.c for  in /home/fleuro_m//work/lemipc/lemipc-2015-2014s-pidoux_q
**
** Made by matthieu fleurot
** Login   <fleuro_m@epitech.net>
**
** Started on  Sun Mar 25 16:04:55 2012 matthieu fleurot
** Last update Sun Mar 25 23:37:12 2012 matthieu fleurot
*/

#include "lemipc.h"
#include "map.h"
#include "game_action.h"
#include "action.h"


#define KEY 101010

void		init_ipc(t_ipc *my_ipc)
{
  my_ipc->shm_id = shmget(KEY, 100, IPC_CREAT | SHM_R | SHM_W);
  my_ipc->sem_id = semget(KEY, 100, IPC_CREAT | SHM_R | SHM_W);
  my_ipc->addr = shmat(my_ipc->shm_id, NULL, SHM_R | SHM_W);
  semctl(my_ipc->sem_id, 0, SETVAL, 0);
  create_map(my_ipc);
}

int		can_start(t_map *info)
{
  if (info->nb_team1 > info->nb_team2)
    return (0);
  if (info->nb_team1 < info->nb_team2)
    return (0);
  if (info->nb_player <= 2)
    return (0);
  return (1);
}

void		wait_for_player(t_ipc *my_ipc)
{
  t_map		*info;

  printf("[console] You got 20 second to conect some player\n");
  sleep(20);
  while (!can_start(info))
    {
      printf("[console] You got 10 second to adjust the team\n");
      printf("[console] there is %d players in team 1\n", info->nb_team1);
      printf("[console] there is %d players in team 2\n", info->nb_team2);
      sleep(10);
      info = get_info(my_ipc);
    }
  printf("[console] game is ready to begin");
  free(info);
}

void		init_player(t_player *play, t_ipc *my_ipc)
{
  t_map		*info;

  srandom(time(NULL));
  play->pos_x = 0;
  play->pos_y = 0;
  while ((play->pos_y * 20) + play->pos_x != '.')
    {
      play->pos_x = random() % 20;
      play->pos_y = random() % 10;
    }
  info = get_info(my_ipc);
  if (info->nb_team1 > info->nb_team2)
    play->team = 2;
  else
    play->team = 1;
  free(info);
}

int		main()
{
  int		first;
  t_ipc		my_ipc;

  first = 0;
  my_ipc.shm_id = shmget(KEY, 100, SHM_R | SHM_W);
  my_ipc.sem_id = semget(KEY, 100, SHM_R | SHM_W);
  printf("%d, %d\n", my_ipc.shm_id, my_ipc.sem_id);
  if (my_ipc.shm_id == -1 && my_ipc.sem_id == -1)
    {
      init_ipc(&my_ipc);
      first = 1;
      wait_for_player(&my_ipc);
    }
  if (first)
    {
      while (!finish(&my_ipc))
	new_turn(&my_ipc);
      shmctl(my_ipc.shm_id, IPC_RMID, NULL);
      semctl(my_ipc.sem_id, IPC_RMID, 1);
    }
  else
    {
      my_ipc.addr = shmat(my_ipc.shm_id, NULL, SHM_R | SHM_W);
      player_func(&my_ipc);
    }
  return (0);
}
