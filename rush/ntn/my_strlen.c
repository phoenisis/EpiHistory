/*
** my_strlen.c for strlen in /u/all/anncel_m/cu/tmp
** 
** Made by maxime anncelli
** Login   <anncel_m@epitech.net>
** 
** Started on  Fri Oct 10 11:49:05 2008 maxime anncelli
** Last update Sun Dec  7 16:18:47 2008 anthony lorillon
*/

#include "my.h"
#include <unistd.h>

int	my_strlen(char *str)
{
  int	v;

  v = 0;
  while (str[v] != '\0')
    {
      v = v + 1;
    }
  return (v);
}
