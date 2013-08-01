/*
** display_info_player.c for  in /home/pidoux_q/Dropbox/AFS/rendu/c/2015/zappy-2015-2014s-herve_a/server
**
** Made by quentin pidoux
** Login   <pidoux_q@epitech.net>
**
** Started on  Sun Jul 15 22:33:44 2012 quentin pidoux
** Last update Sun Jul 15 22:33:46 2012 quentin pidoux
*/

#include "zappy_server.h"

void		find_player(t_player *player, int p, int flag)
{

  char		tmp[25];

  while (player->nxt != NULL)
    {
      if (player->player == p)
	{
	  if (flag == 1)
	    sprintf(tmp, "ppo #%d %d %d\n", p, player->posX, player->posY);
	  else if (flag == 2)
	    sprintf(tmp, "plv #%d %d\n", p, player->level);
	  else
	    sprintf(tmp, "pin #%d %d %d %d %d %d %d %d %d %d\n", p, player->posX
		    , player->posY, player->inventory->food,
		    player->inventory->linemate, player->inventory->deraumere,
		    player->inventory->sibur, player->inventory->mendiane,
		    player->inventory->phiras, player->inventory->thystame);
	}
      player = player->nxt;
    }
}

void		display_info_player(char *str, t_player *player, int flag)
{
  int i;
  int j;
  char nb[10];

  while (str[i])
    {
      while (str[i] >= '0' && str[i] <= '9')
	{
	  nb[j] = str[i];
	  i++;
	  j++;
	}
      i++;
    }
  nb[j] = '\0';
  if (j > 10)
    return ;
  find_player(player, atoi(nb), flag);
}
