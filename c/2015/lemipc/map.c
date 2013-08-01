/*
** map.c for  in /home/fleuro_m//work/lemipc/lemipc-2015-2014s-pidoux_q
**
** Made by matthieu fleurot
** Login   <fleuro_m@epitech.net>
**
** Started on  Sun Mar 25 18:24:53 2012 matthieu fleurot
** Last update Sun Mar 25 22:34:26 2012 matthieu fleurot
*/

#include <stdio.h>
#include "lemipc.h"
#include "map.h"

void	create_map(t_ipc *my_ipc)
{
  int	x;
  char	map[201];

  x = 0;
  while(x != 200)
    map[x++] = '.';
  map[x] = '\0';
  sprintf((char *)my_ipc->addr, map);
}

char	**ram_to_char(t_ipc *my_ipc)
{
  int	x;
  int	y;
  char	**map;
  int	i;

  x = 0;
  y = 0;
  i = 0;
  map = malloc (11 * sizeof(char*));
  while(i < 11)
    map[i++] = (char*) malloc (21 * sizeof(char));
  i = 0;
  while (y != 10)
    {
      x = 0;
      while (x != 20)
	map[y][x++] = ((char *)my_ipc->addr)[i++];
      y++;
    }
  return (map);
}

void	move(int x, int y, t_player *player, t_ipc *my_ipc)
{
  int old_dest = 0;
  int dest = 0;

  dest = (y*20)+x;
  old_dest = (player->pos_y*20)+player->pos_x;
  player->pos_y = y;
  player->pos_x = x;
  ((char *)my_ipc->addr)[old_dest] = '.';
  if(player->team == 1)
    ((char *)my_ipc->addr)[dest] = '1';
  else
    ((char *)my_ipc->addr)[dest] = '2';
}

void	print_map(char **map)
{
   int	y;
   int	x;

   y = 0;
   x = 0;
   system("clear");
   while(y != 10)
     {
       while(x != 20)
	 printf("%c", map[y][x++]);
       printf("\n");
       y++;
       x = 0;
     }
}

t_map	*get_info(t_ipc *my_ipc)
{
  int	i;
  t_map	*info;

  i = 0;
  info = malloc(1 * sizeof(t_map));
  info->nb_player = 0;
  info->nb_team1 = 0;
  info->nb_team2 = 0;
  while(((char *)my_ipc->addr)[i])
    {
      if (((char *)my_ipc->addr)[i] == '1')
	info->nb_team1++;
      else if (((char *)my_ipc->addr)[i] == '2')
	info->nb_team2++;
      i++;
    }
  info->nb_player = info->nb_team1 + info->nb_team2;
  return (info);
}
