/*
** main.c for  in /home/pidoux_q/Dropbox/AFS/rendu/c/2015/zappy-2015-2014s-herve_a/server
**
** Made by quentin pidoux
** Login   <pidoux_q@epitech.net>
**
** Started on  Sun Jul 15 22:34:09 2012 quentin pidoux
** Last update Sun Jul 15 23:14:35 2012 clement cohen
*/

#include <string.h>
#include "zappy_server.h"
#include "mapp.h"
#include "error.h"
#include "main_zappy.h"
#include "parse.h"

void		check_args(char **arg, t_create_world *args)
{
  int		i;
  int   j;
  char		*str;

  i = 1;
  j = 0;
  str = NULL;
  str = malloc(sizeof(char *) * 256);
  srand(time(0));
  while (arg[i])
    {
      strcat(str, arg[i]);
      i++;
    }
  parse_args(str, args);
}

t_create_world    *default_settings(t_create_world *args)
{
  args->port = 8088;
  args->x = 800;
  args->y = 500;
  args->name = str_to_wordtab("Team1,Team2", ',');
  args->nbclients = 1;
  args->delay = 10;

  return args;
}

struct tm       *get_time(t_env *e)
{
  time_t                        rawtime;

  time(&rawtime);
  e->time = localtime(&rawtime);

  return e->time;
}

int		main(int ac, char **av)
{
  t_create_world		args;
  int                           i;

  i = 0;
  srand(time(0));
  if (ac)
    {
      default_settings(&args);
      printf("Usage : %s -p PORT -x WIDTH -y HEIGHT \
-n TEAM(S), NAME(S) -c TEAM_MAT"
	     "ES_NB -t DELAY\nIf no arguments are \
detected, defaults values will "
	     "be used.\n\n\n", av[0]);
      check_args(av, &args);
      printf("______SERVER INFOS______\n\nTeams :\n\n");
      while (args.name[i])
	  printf("[%s]\n", args.name[i++]);
      printf("\nPort : %d, X(height): %d, Y(width): \
%d, C(nbclients): %d, T(delay)"
	     ": %d\n\n\n\n", args.port, args.x, args.y,
	     args.nbclients, args.delay);
      server_loop(args.port, &args);
    }
  return (0);
}
