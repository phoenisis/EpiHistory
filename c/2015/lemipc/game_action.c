/*
** game_action.c for  in /home/fleuro_m//work/lemipc/lemipc-2015-2014s-pidoux_q
**
** Made by matthieu fleurot
** Login   <fleuro_m@epitech.net>
**
** Started on  Sun Mar 25 22:12:44 2012 matthieu fleurot
** Last update Sun Mar 25 23:29:55 2012 matthieu fleurot
*/

#include "lemipc.h"
#include "game_action.h"
#include "action.h"
#include "map.h"

int		is_dead(t_player *play, t_ipc *my_ipc)
{
  int		count;

  count = 0;
  if (play->team == 1)
    count = check_if_team1(my_ipc, play);
  if (play->team == 2)
    count = check_if_team2(my_ipc, play);
  if (count > 2)
    return (1);
  return (0);
}

void		player_func(t_ipc *my_ipc)
{
  t_player	play;

  init_player(&play, my_ipc);
  my_ipc->sops.sem_num = 0;
  my_ipc->sops.sem_op = -1;
  my_ipc->sops.sem_flg = 0;
  if (play.team == 1)
    ((char *)my_ipc->addr)[(play.pos_y*20)+play.pos_x] = '1';
  else
    ((char *)my_ipc->addr)[(play.pos_y*20)+play.pos_x] = '2';
  semop(my_ipc->sem_id, &my_ipc->sops, 1);
  while(!is_dead(&play, my_ipc))
    can_move(my_ipc, &play);
  printf("i loose bye\n");
}

int		finish(t_ipc *my_ipc)
{
  t_map		*info;

  info = get_info(my_ipc);
  if (info->nb_player == 2)
    {
      if (info->nb_team1)
	printf("team 1 as win\n");
      else
	printf("team 2 as win\n");
      return (1);
    }
  return (0);
}

void		new_turn(t_ipc *my_ipc)
{
  t_map		*info;
  char		**map;

  map = ram_to_char(my_ipc);
  print_map(map);
  info = get_info(my_ipc);
  while (info->nb_player)
    {
      my_ipc->sops.sem_num = 0;
      my_ipc->sops.sem_op = +1;
      my_ipc->sops.sem_flg = 0;
      semop(my_ipc->sem_id, &my_ipc->sops, 1);
      info->nb_player--;
      usleep(1000);
    }
  free(info);
}
