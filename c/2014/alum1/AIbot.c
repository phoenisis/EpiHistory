/*
** AIbot.c for rand_line in /u/all/pidoux_q/cu
** 
** Made by quentin pidoux
** Login   <pidoux_q@epitech.net>
** 
** Started on  Sat Feb 13 11:23:27 2010 quentin pidoux
** Last update Mon Feb 15 11:59:37 2010 quentin pidoux
*/


#include <time.h>
#include "my.h"
#include "alum1.h"

void	rand_sticks(int line, int *tab)
{
  int	sticks = 0;
  
  srand(time(NULL));
  while (sticks == 0)
      sticks = (rand(time) % (tab[line]) + 1);
  printf("\nYour oposant has took %d sticks\n", sticks);
  usleep(2000000);
  tab[line] = tab[line] - sticks;
}


void	rand_line(int *tab, int nb_line)
{
  int	line = 0;
  
  srand(time(NULL));
  while (line == 0)
    {
      line = (rand(time) % (nb_line));
      if (!tab[line]) line = 0;
    }
  printf("\nYour oposant has choose line %d\n", line + 1);
  usleep(2000000);
  rand_sticks(line, tab);
  aff_sticks(tab, nb_line);
}
