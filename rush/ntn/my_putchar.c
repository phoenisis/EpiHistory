/*
** my_putchar.c for myputchar in /u/all/anncel_m/cu/rendu/piscine/Jour_04
** 
** Made by maxime anncelli
** Login   <anncel_m@epitech.net>
** 
** Started on  Thu Oct 16 10:32:47 2008 maxime anncelli
** Last update Sun Dec  7 16:00:59 2008 anthony lorillon
*/

#include "my.h"
#include <unistd.h>

void	my_putchar(char c)
{
  write (1, &c, 1);
}
