/*
** broadcast.c for zappy in /home/cohen_d//zappy/zappy-2015-2014s-herve_a
**
** Made by clement cohen
** Login   <cohen_d@epitech.net>
**
** Started on  Sun Jul 15 22:19:31 2012 clement cohen
** Last update Sun Jul 15 22:58:48 2012 clement cohen
*/

#include "mapp.h"
#include "zappy_server.h"
#include "broadcast.h"
#include "team_name.h"

void		broadcast2(char *str, t_env *e, int fd)
{
  if ((strcmp("avance", str) == 0 && e->player->orientation == NORD)
      || (strcmp("droite", str) == 0 && e->player->orientation == OUEST)
      || (strcmp("gauche", str) == 0 && e->player->orientation == EST))
    go_forward(e, fd);
  else if ((strcmp("gauche", str) == 0 && e->player->orientation == NORD)
	   || (strcmp("avance", str) == 0 && e->player->orientation == OUEST)
	   || (strcmp("droit", str) == 0 && e->player->orientation == SUD))
    go_left(e, fd);
  else if ((strcmp("droite", str) == 0 && e->player->orientation == NORD)
	   || (strcmp("gauche", str) == 0 && e->player->orientation == SUD)
	   || (strcmp("avance", str) == 0 && e->player->orientation == EST))
    go_right(e, fd);
  else if ((strcmp("avance", str) == 0 && e->player->orientation == SUD)
	   || (strcmp("gauche", str) == 0 && e->player->orientation == OUEST)
	   || (strcmp("droite", str) == 0 && e->player->orientation == EST))
    go_backward(e, fd);
  else if (strncmp("prend", str, 5) == 0)
    prend(str + 5, e, fd);
  else
    ;
}

void		broadcast(char *str, t_env *e, int fd)
{
  if (strcmp("msz", str) == 0)
    display_mapp(e, fd);
  else if (strcmp("bct", str) == 0)
    display_case(str, e, fd);
  else if (strncmp("tna", str, 3) == 0)
    display_team(e, fd);
  else if (strcmp("mct", str) == 0)
    display_all_case(e, fd);
  else if (strncmp("ppo", str, 3) == 0)
    display_info_player(str + 3, e->player, 1, fd);
  else if (strncmp("plv", str, 3) == 0)
    display_info_player(str + 3, e->player, 2, fd);
  else if (strncmp("pin", str, 3) == 0)
    display_info_player(str + 3, e->player, 3, fd);
  else
    broadcast2(str, e, fd);
}

char             *my_itoa_buf(char *buf, size_t len, int num)
{
  static char loc_buf[sizeof(int) * 4];

  if (!buf)
  {
    buf = loc_buf;
    len = sizeof(loc_buf);
  }

  if (snprintf(buf, len, "%d", num) == -1)
    return "";
  return buf;
}

char            *itoa(int num)
{
  return my_itoa_buf(NULL, 0, num);
}
