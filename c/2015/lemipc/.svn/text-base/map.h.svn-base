/*
** map.h for  in /home/fleuro_m//work/lemipc/lemipc-2015-2014s-pidoux_q
**
** Made by matthieu fleurot
** Login   <fleuro_m@epitech.net>
**
** Started on  Sun Mar 25 18:24:47 2012 matthieu fleurot
** Last update Sun Mar 25 22:34:47 2012 matthieu fleurot
*/

#ifndef		MAP_H_
# define	MAP_H_
# include <stdio.h>
# include "lemipc.h"

typedef struct	s_map
{
  int		nb_player;
  int		nb_team1;
  int		nb_team2;
}		t_map;

void	create_map(t_ipc *my_ipc);
char	**ram_to_char(t_ipc *my_ipc);
void	move(int x, int y, t_player *play, t_ipc *my_ipc);
void	print_map(char **map);
t_map	*get_info(t_ipc *my_ipc);

#endif		/*MAP_H*/
