/*
** player.c for  in /home/pidoux_q/Dropbox/AFS/rendu/c/2015/zappy-2015-2014s-herve_a/server
**
** Made by quentin pidoux
** Login   <pidoux_q@epitech.net>
**
** Started on  Sun Jul 15 22:32:01 2012 quentin pidoux
** Last update Sun Jul 15 23:13:56 2012 clement cohen
*/

#include "zappy_server.h"
#include "error.h"

struct s_player         *add_player(t_env *e)
{
  t_player     *temp;

  temp = NULL;
  temp->orientation = NORD;
  temp = (t_player*)malloc(sizeof(t_player));
  temp->inventory = e->player->inventory;
  temp->life = e->player->life;
  temp->player = e->player->player;
  temp->posX = e->player->posX;
  temp->posY = e->player->posY;
  temp->team = e->player->team;
  temp->nxt = e->player;
  e->player = temp;

  t_player     *temp1;
  temp1 = e->player;
  return e->player;
}

struct s_player		*remove_player(t_env *e)
{
  if (e->player != NULL)
    {
      t_player *temp = e->player->nxt;
      free(e->player);
      return temp;
    }
  else
    return NULL;
}

struct s_player         *init_player(t_env *e)
{
  t_player              player;

  player.orientation = NORD;
  player.inventory = NULL;
  player.life = 100;
  player.level = 1;
  player.player = 1;
  player.posX = 0;
  player.posY = 0;
  player.team = NULL;
  e->player = (t_player *) malloc(sizeof(t_player));
  return e->player;
}
