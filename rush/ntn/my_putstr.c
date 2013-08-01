/*
** my_putstr.c for myputstr in /u/all/anncel_m/cu/tmp
** 
** Made by maxime anncelli
** Login   <anncel_m@epitech.net>
** 
** Started on  Fri Oct 10 10:01:59 2008 maxime anncelli
** Last update Sun Dec  7 16:01:08 2008 anthony lorillon
*/

#include "my.h"
#include <unistd.h>
#include <stdlib.h>

int	my_putstr(char *str)
{
  int	n;

  n = 0;
  while (str[n] != '\0')
    {
      my_putchar(str[n]);
      n = n + 1;
    }
  return (0);
}

