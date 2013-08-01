/*
** my_prompt.c for mon joli petit prompt in /u/all/laffit_m/cu/allum
** 
** Made by mathieu laffitte
** Login   <laffit_m@epitech.net>
** 
** Started on  Thu Feb 11 16:16:12 2010 mathieu laffitte
** Last update Sun Feb 14 18:16:33 2010 sevan hubert
*/

#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include "my.h"
#include "alum1.h"


int	define_number_line(char *str, int const line_max)
{
  int	i = 0;
  
  if (my_str_isnum(str) == 1)
    return (0);
  i = my_get_nbr(str);
  if (i > line_max)
    return (0);
  return (i);
}


int	my_str_isnum(char const *str)
{
  int	i = 0;
  
  if (!str) return (1);
  if (str[0] == '\0' || str[0] == '\n') return (1);
  while ((str[i] != '\0') && (str[i] != '\n'))
    {
      if ((str[i] < '0') || (str[i] > '9'))
        return (1);
      i++;
    }
  return (0);
}


void	choose_num_sticks(int line, int *tab)
{
  char	*sticks = NULL;
  int	i = 0;
  
  sticks = (malloc(sizeof(*sticks) * 60));
  if (!sticks) return (choose_num_sticks(line, tab));
  while (i == 0)
    {	  
      my_putstr("Please choose a quantity of sticks\n\t");
      my_putstr("$>");
      read(0, sticks, 60);
      while (sticks[i] != '\n')
	i++;
      sticks[i] = 0;
      i = define_number_line(sticks, (60 * 2) * 1);
      if (i > tab[line - 1]) 
	{
	  i = 0;
	  printf("You can't choose this number :");
	  printf("\nthere is only %d sticks.", tab[line - 1]);
	}
      tab[line - 1] = tab[line - 1] - i;
    }
  if (sticks) free(sticks);
}


void	choose_line(int *tab)
{
  char	*line = NULL;
  int	i = 0;
  
  line = (malloc(sizeof(*line) * 60));
  if (!line) return (choose_line(tab));
  while (i == 0)
    {	  
      my_putstr("Please choose a line\n\t");
      my_putstr("$>");
      read(0, line, 60);
      while (line[i] != '\n')
	i++;
      line[i] = 0;
      i = define_number_line(line, 60);
      if (tab[i - 1] == 0) 
	{
	  i = 0;
	  printf("Line %s is empty.\n", line);
	}
    }
  if (line) free(line);
  choose_num_sticks(i, tab);
}


int	main(int argc, char **argv)
{
  int	*tabstick = NULL;
  
  if (argv[1] && (my_str_isnum(argv[1]) == 0)) 
    {
      tabstick = create_sticktab(argv[1]);
      if (!tabstick) return (0);
      while (42)
	{
	  choose_line(tabstick);
	  aff_sticks(tabstick, my_get_nbr(argv[1]));
	  if (!verif_if_lose(tabstick, my_get_nbr(argv[1])))
	    {
	      my_putstr("You lose . . .\n\n");
	      return (0);
	    }
	  rand_line(tabstick, my_get_nbr(argv[1]));
	  if (!verif_if_lose(tabstick, my_get_nbr(argv[1])))
	    {
	      my_putstr("You win!\n\n");
	      return (0);
	    }
	}
    }
  else my_putstr("\n\tUse a number for argument 1.\n\n");
  return (0);
}
