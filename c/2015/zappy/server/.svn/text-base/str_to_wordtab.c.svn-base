/*
** str_to_wordtab.c for  in /home/pidoux_q/Dropbox/AFS/rendu/c/2015/zappy-2015-2014s-herve_a/server
**
** Made by quentin pidoux
** Login   <pidoux_q@epitech.net>
**
** Started on  Sun Jul 15 22:34:33 2012 quentin pidoux
** Last update Sun Jul 15 22:34:35 2012 quentin pidoux
*/

#include <stdlib.h>
#include "parse.h"

int	count_word(char *str, char delimiter)
{
  int	i;
  int	w;

  i = 0;
  w = 0;
  while ((str[i]) && ((str[i] == delimiter) || (str[i] == '\t')))
    i++;
  while (str[i])
    {
      if ((str[i]) && ((str[i] != delimiter) && (str[i] != '\t')))
	{
	  w++;
	  while ((str[i]) && ((str[i] != delimiter) && (str[i] != '\t')))
	    i++;
	}
      if (str[i])
	i++;
    }
  return (w);
}

char	*my_complete_tab(char *str, char delimiter)
{
  char	*tab;
  int	i;

  i = 0;
  while (str[i] && (str[i] != '\t') && (str[i] != delimiter))
    i++;
  tab = malloc((i + 1) * sizeof(tab));
  i = 0;
  while (str[i] && (str[i] != '\t') && (str[i] != delimiter))
    {
      tab[i] = str[i];
      i++;
    }
  tab[i] = 0;
  return (tab);
}

char	**str_to_wordtab(char *str, char delimiter)
{
  int	i;
  int	w;
  char	**tab;

  tab = malloc((count_word(str, delimiter) + 1) * sizeof(tab));
  i = 0;
  w = 0;
  while ((str[i]) && ((str[i] == delimiter) || (str[i] == '\t')))
    i++;
  while (str[i])
    {
      if ((str[i]) && ((str[i] != delimiter) && (str[i] != '\t')))
	{
	  tab[w] = my_complete_tab(&str[i], delimiter);
	  w++;
	  while ((str[i]) && ((str[i] != delimiter) && (str[i] != '\t')))
	    i++;
	}
      if (str[i])
	i++;
    }
  tab[w] = 0;
  return (tab);
}
