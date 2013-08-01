/*
** parse.c for  in /home/pidoux_q/Dropbox/AFS/rendu/c/2015/zappy-2015-2014s-herve_a/server
**
** Made by quentin pidoux
** Login   <pidoux_q@epitech.net>
**
** Started on  Sun Jul 15 22:32:13 2012 quentin pidoux
** Last update Sun Jul 15 23:15:35 2012 clement cohen
*/

#include <string.h>
#include <ctype.h>
#include "error.h"
#include "parse.h"

char    *get_value(char *str, char c)
{
  int       i;
  char      *res;
  int       j;

  res = NULL;
  res = malloc(sizeof(char *) * 128);
  i = 0;
  j = 0;
  while (str[i] != '\0')
    {
      if (str[i] == '-' && str[i + 1] == c)
	{
	  i = i + 2;
	  while (str[i] != '-' && str[i] != '\0')
	    {
	      res[j] = str[i];
	      i++;
	      j++;
	    }
	}
      i++;
    }
  return res;
}

int        parse_args1(char *str, int i, int flag,
		       char *value, t_create_world *args)
{
  if (str[i] == '-' && str[i + 1] == 'p' && str[i] + 1 != 0)
    {
      value = get_value(str, 'p');
      if (atoi(value) <= 1024 || atoi(value) > 100000)
	{
	  fprintf(stderr, "Port is %s and should be > 1024\n", value);
	  flag = 1;
	}
      else
	args->port = atoi(value);
    }
  if (str[i] == '-' && str[i + 1] == 'x' && str[i] + 1 != 0)
    {
      value = get_value(str, 'x');
      if (atoi(value) < 20 || atoi(value) > 1000)
	{
	  fprintf(stderr, "Value 'x : %s' is either too low or\
 to high [20, 1000]\n", value);
	  flag = 1;
	}
      else
	args->x = atoi(value);
    }
  return flag;
}

int       parse_args2(char *str, int i, int flag,
		      char *value, t_create_world *args)
{
  if (str[i] == '-' && str[i + 1] == 'y' && str[i] + 1 != 0)
    {
      value = get_value(str, 'y');
      if (atoi(value) < 20 || atoi(value) > 1000)
	{
	  fprintf(stderr, "Value 'y : %s' is either too\
 low or to high [20, 1000]\n", value);
	  flag = 1;
	}
      else
	args->y = atoi(value);
    }
  if (str[i] == '-' && str[i + 1] == 'n' && str[i] + 1 != 0)
    {
      value = get_value(str, 'n');
      args->name = get_teamnames(value, args);
      if (strcmp("BAD", args->name[0]) == 0)
	flag = 1;
    }
  return flag;
}

int       parse_args3(char *str, int i, int flag,
		      char *value, t_create_world *args)
{
  if (str[i] == '-' && str[i + 1] == 'c' && str[i] + 1 != 0)
    {
      value = get_value(str, 'c');
      if (atoi(value) < 1 || atoi(value) > 10)
	{
	  fprintf(stderr, "Value 'nbclients : %s' is either too \
low or to high [1, 10]\n", value);
	  flag = 1;
	}
      else
	args->nbclients = atoi(value);
    }
  if (str[i] == '-' && str[i + 1] == 't' && str[i] + 1 != 0)
    {
      value = get_value(str, 't');
      if (atoi(value) < 1 || atoi(value) > 60)
	{
	  fprintf(stderr, "Value 'delay : %s' is either too \
low or to high [1, 50]\n", value);
	  flag = 1;
	}
      else
	args->delay = atoi(value);
    }
  return flag;
}

int		parse_args(char *str, t_create_world *args)
{
  int       i;
  int       flag;
  char      *value;

  i = 0;
  flag = 0;
  value = NULL;

  while (str[i] != 0)
    {
      flag = parse_args1(str, i, flag, value, args);
      flag = parse_args2(str, i, flag, value, args);
      flag = parse_args3(str, i, flag, value, args);
      i++;
    }
  if (flag == 1)
    {
      fprintf(stderr, "exiting...\n");
      exit(EXIT_FAILURE);
    }
  free (value);
  free (str);
  return 0;
}
