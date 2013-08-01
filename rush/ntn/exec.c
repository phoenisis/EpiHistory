/*
** exec.c for execp in /u/all/anncel_m/cu/rendu/c/proj/ntn
** 
** Made by maxime anncelli
** Login   <anncel_m@epitech.net>
** 
** Started on  Sun Dec  7 03:27:34 2008 maxime anncelli
** Last update Sun Dec  7 17:54:56 2008 anthony lorillon
*/

#include "my.h"
#include <unistd.h>

int	except(int j, char *str, int d)
{
  j = 0;
 
  j++;
  if(str[d] >= '2' && str[d] <= '6' && str[j] == '1')
    {
      dix(str[j]);
      my_putstr(" et");
    } 

  if(str[1] >= '2' && str[1] <= '6' && str[j] == '1')
    {
      cent(str, j);
      my_putstr(" et");
    }
  return (0);
}
