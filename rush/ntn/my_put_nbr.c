/*
** my_put_nbr.c for myputnbr in /u/epitech_2013/anncel_m/cu/rendu/piscine/Jour_03
** 
** Made by maxime anncelli
** Login   <anncel_m@epitech.net>
** 
** Started on  Wed Oct 15 08:55:02 2008 maxime anncelli
** Last update Sun Dec  7 16:31:47 2008 anthony lorillon
*/

#include "my.h"
#include <unistd.h>

int	my_put_nbr(int n)
{
  int	fin;
  int	debut;

  if (n < 0 )
    {
      my_putchar('-');
      my_put_nbr(-n);
    }
  else
    {
      fin = n % 10;
      debut = n / 10;
      if (debut != 0)
	my_put_nbr(debut);
      my_putchar(fin + '0');
    }
  return (0);
}

