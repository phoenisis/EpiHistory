/*
** espace.c for espace in /u/all/anncel_m/cu/rendu/c/proj/ntn
** 
** Made by maxime anncelli
** Login   <anncel_m@epitech.net>
** 
** Started on  Sun Dec  7 03:44:07 2008 maxime anncelli
** Last update Sun Dec  7 16:32:38 2008 anthony lorillon
*/

#include "my.h"
#include <unistd.h>

int	space(int j, char *str, int d)
{
  j = 0;

  j++;
  if(str[d] >= '1' && str[d] <= '9' && str[j] >= '1')
    {
      dix(str[j]);
      my_putstr(" ");
    }

  if(str[d] >= '1' && str[d] <= '9' && str[j] >= '1')
    {
      cent(str, j);
      my_putstr(" ");
    }
  return (0);
}
