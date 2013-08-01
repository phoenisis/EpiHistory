/*
** main.c for  in /u/all/pidoux_q/cu/rendu/c/my_ls
** 
** Made by quentin pidoux
** Login   <pidoux_q@epitech.net>
** 
** Started on  Sun Nov  7 15:15:46 2010 quentin pidoux
** Last update Sun Nov  7 21:48:37 2010 quentin pidoux
*/

#include "my_ls.h"

void		first(char **av)
{
  int		i;
  char		*str;

  i = 0;
  while (av[++i])
    {
      if (av[i][0] == '-')
	  second(av);
      else if (av[i][1])
	{
	  str = av[i];
	  my_ls_directory(str);
	}
    } 
  my_putchar('\n');
}

void		second(char **av)
{
int		i;
  char		*str;

  i = 0;
  while (av[++i])
    {
      if (av[i][1] == 'a')
	{
	  str = av[i];
	  my_ls_a();
	}
    }
}

int		main(int ac, char **av)
{
  if (ac < 2 && av[2])
    {
      my_ls();
      my_putchar('\n');
    }
  else
    first(av);
  return (0);
}
