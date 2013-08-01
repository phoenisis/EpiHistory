/*
** team_name.c for  in /home/pidoux_q/Dropbox/AFS/rendu/c/2015/zappy-2015-2014s-herve_a/server
**
** Made by quentin pidoux
** Login   <pidoux_q@epitech.net>
**
** Started on  Sun Jul 15 22:31:46 2012 quentin pidoux
** Last update Sun Jul 15 23:13:33 2012 clement cohen
*/

#include	"zappy_server.h"
#include        "team_name.h"
#include	"parse.h"

void		display_team(t_env *e, int fd)
{
  char		*tmp;

  tmp = malloc(sizeof(e->name));
  sprintf(tmp, "TNA %s\n", e->name);
  printf("Message envoye :%s\n", tmp);
  e->fct_write[fd] = (fct)client_write(fd, tmp);
}

void		diplay_player_pos(char *str, t_env *e, int fd)
{
  int		i;
  int		j;
  int		nb;
  char		c_nb[10];
  char		*tmp;

  j = 0;
  i = 0;
  while (str[i] != '\0')
    {
      while (str[i] == '#')
	while (str[i] >= '0' && str[i] <= '9')
	  {
	    c_nb[j] = str[i];
	    j++;
	    i++;
	  }
      i++;
    }
  c_nb[j] = '\0';
  nb = atoi(c_nb);
  tmp = malloc(sizeof(char *) * 11);
  sprintf(tmp, "ppo #%d %d %d\n", nb, e->player->posX, e->player->posY);
  printf("Message envoye :%s\n", tmp);
  e->fct_write[fd] = (fct)client_write(fd, tmp);
}

char      **get_teamnames(char *value, t_create_world *args)
{
  int			i;
  int			j;
  int		        flag;

  flag = 0;
  i = 0;
  j = 0;
  args->name = str_to_wordtab(value, ',');
  while (args->name[i] != 0)
    {
      j = 0;
      while (args->name[i][j] != 0)
	{
	  if (!isalpha(args->name[i][j]))
	    flag = 1;
	  j++;
	}
      i++;
    }
  if (flag == 1)
    {
      fprintf(stderr, "Teamname(s) contains foreigns characters, \
please use only alphabetic characters.\n");
    }
  return args->name;
}

