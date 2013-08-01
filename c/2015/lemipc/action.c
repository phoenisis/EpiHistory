#include "lemipc.h"
#include "action.h"
#include "map.h"
#include <stdio.h>

int check_if_team1(t_ipc *my_ipc, t_player *player)
{
  char **map;
  int count;

  count = 0;
  map = ram_to_char(my_ipc);
  if (map[++player->pos_y][player->pos_x] == '2')
    count++;
  else if (map[--player->pos_y][player->pos_x] == '2')
    count++;
  else if (map[player->pos_y][++player->pos_x] == '2')
    count++;
  else if (map[player->pos_y][--player->pos_x] == '2')
    count++;
  else if (map[++player->pos_y][++player->pos_x] == '2')
    count++;
  else if (map[++player->pos_y][--player->pos_x] == '2')
    count++;
  else if (map[--player->pos_y][++player->pos_x] == '2')
    count++;
  else if (map[--player->pos_y][--player->pos_x] == '2')
    count++;
  return (count);
}

int check_if_team2(t_ipc *my_ipc, t_player *player)
{
  char **map;
  int count;

  count = 0;
  map = ram_to_char(my_ipc);
  if (map[++player->pos_y][player->pos_x] == '1')
    count++;
  else if (map[--player->pos_y][player->pos_x] == '1')
    count++;
  else if (map[player->pos_y][++player->pos_x] == '1')
    count++;
  else if (map[player->pos_y][--player->pos_x] == '1')
    count++;
  else if (map[++player->pos_y][++player->pos_x] == '1')
    count++;
  else if (map[++player->pos_y][--player->pos_x] == '1')
    count++;
  else if (map[--player->pos_y][++player->pos_x] == '1')
    count++;
  else if (map[--player->pos_y][--player->pos_x] == '1')
    count++;
  return (count);
}

int	disturb(char** map, int x, int y)
{
  if (map[y][x] != '.')
    return (0);
  else
    return (1);
}

void	can_move(t_ipc *my_ipc, t_player *player)
{
  char	**map;

  map = ram_to_char(my_ipc);
  if (player->pos_y > 5 && disturb(map, player->pos_x, --player->pos_y) == 0)
    move(player->pos_x, player->pos_y--, player, my_ipc);
  else if (player->pos_y < 5 && disturb(map, --player->pos_x, player->pos_y) == 0)
    move(player->pos_x, player->pos_y++, player, my_ipc);
  else if (player->pos_x > 10 && disturb(map, --player->pos_x, player->pos_y) == 0)
    move(player->pos_x--, player->pos_y, player, my_ipc);
  else if (player->pos_x < 10 && disturb(map, ++player->pos_x, player->pos_y) == 0)
    move(player->pos_x++, player->pos_y, player, my_ipc);
  free(map);
}
