/*
** affichage.c for affichage allumettes in /u/all/laffit_m/cu/allum
** 
** Made by mathieu laffitte
** Login   <laffit_m@epitech.net>
** 
** Started on  Wed Feb 10 11:07:47 2010 mathieu laffitte
** Last update Sun Feb 14 18:18:02 2010 sevan hubert
*/

#include <unistd.h>
#include "my.h"

void		put_space(int g)
{
  while (g >= 0)
    {
      my_putchar(' ');
      g--;
    }
}

void		aff_sticks(int *tab, int nb_line)
{
  int		i = 0;
  int		w = 1;
  int		sticks = 0;
  int		space = ((nb_line + 1));
  int		g = space;
  
  while (i < nb_line)
    {
      my_putnbr(i + 1);
      my_putstr("\t");
      my_putnbr(tab[i]);
      my_putstr("\t");
      put_space(g);
      while (sticks != tab[i])
	{
	  my_putstr("|");
	  sticks++;
	}
      g = (space - w);
      w++;
      my_putstr("\n");
      sticks = 0;
      i++;
    }
}

int		*create_sticktab(char *str_line)
{
  int		nb_line;
  int		*tab;
  int		i = 1;

  nb_line = my_get_nbr(str_line);
  tab = malloc(nb_line * sizeof(tab));
  if (!tab) return (create_sticktab(str_line));
  if (nb_line <= 60 && nb_line > 1)
    {
      my_putstr("Col\tAllum\n");
      tab[0] = 1;
      while (i < nb_line)
	{
	  tab[i] = (tab[i-1] + 2);
	  i++;
	}
      aff_sticks(tab, nb_line);
      return (tab);
    }
  my_putstr("\n\tPlease use a number between 2 and 60.\n\n");
  return (NULL);
}

int	verif_if_lose(int *tab, int nb_line)
{
  int	i = 0;

  while (i < nb_line)
    {
      if (tab[i] != 0) return (-1);
      i++;
    }
  return (0);
}
