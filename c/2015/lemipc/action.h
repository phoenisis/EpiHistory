#ifndef		ACTION_H_
# define	ACTION_H_
# include <stdio.h>
# include "lemipc.h"
# include "map.h"

int	check_if_team1(t_ipc *my_ipc, t_player *player);
int	check_if_team2(t_ipc *my_ipc, t_player *player);
int	disturb(char **map, int x, int y);
void	can_move(t_ipc *my_ipc, t_player *player);

#endif		/*ACTION_H*/
