/*
** sixdix.c for sixdix in /u/all/anncel_m/cu/rendu/c/proj/ntn
** 
** Made by maxime anncelli
** Login   <anncel_m@epitech.net>
** 
** Started on  Sun Dec  7 04:06:55 2008 maxime anncelli
** Last update Sun Dec  7 16:07:40 2008 anthony lorillon
*/

#include "my.h"
#include <unistd.h>
#include <stdlib.h>

void	sixdix(char *str)
{
  if (str[0] == '7' && str[1] == '0')
    {
      my_putstr("soixante-dix");
      exit(-1);
    } 

  if (str[0] == '7' && str[1] == '1')
    {
      my_putstr("soixante-onze");
      exit(-1);
    }
  
  if (str[0] == '7' && str[1] == '7')
    {
      my_putstr("soixante-dix-sept");
      exit(-1);
    }
  
  if (str[0] == '7' && str[1] == '8')
    {
      my_putstr("soixante-dix-huit");
      exit(-1);
    }

  if (str[0] == '7' && str[1] == '9')
    {
      my_putstr("soixante-dix-neuf");
      exit(-1);
    }
  
  if (str[0] == '7' && str[1] == '2')
    {
      my_putstr("soixante-douze");
      exit(-1);
    }

  if (str[0] == '7' && str[1] == '3')
    {
      my_putstr("soixante-treize");
      exit(-1);
    }

  if (str[0] == '7' && str[1] == '4')
    {
      my_putstr("soixante-quatorze");
      exit(-1);
    }

  if (str[0] == '7' && str[1] == '5')
    {
      my_putstr("soixante-quinze");
      exit(-1);
    }

  if (str[0] == '7' && str[1] == '6')
    {
      my_putstr("soixante-seize");
      exit(-1);
    }
}
