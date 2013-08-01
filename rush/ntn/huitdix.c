/*
** huitdix.c for huitdix in /u/all/anncel_m/cu/rendu/c/proj/ntn
** 
** Made by maxime anncelli
** Login   <anncel_m@epitech.net>
** 
** Started on  Sun Dec  7 04:19:07 2008 maxime anncelli
** Last update Sun Dec  7 15:57:35 2008 anthony lorillon
*/

#include "my.h"
#include <stdlib.h>

void	huitdix(char *str)
{
  
  if (str[0] == '9' && str[1] == '0')
    {
      my_putstr("quatre-vintg-dix");
      exit(-1);
    }

  if (str[0] == '9' && str[1] == '1')
    {
      my_putstr("quatre-vingt-onze");
      exit(-1);
    }

  if (str[0] == '9' && str[1] == '2')
    {
      my_putstr("quatre-vingt-douze");
      exit(-1);
    }

  if (str[0] == '9' && str[1] == '3')
    {
      my_putstr("quatre-vingt-treize");
      exit(-1);
    }

  if (str[0] == '9' && str[1] == '4')
    {
      my_putstr("quatre-vingt-quatorze");
      exit(-1);
    }

  if (str[0] == '9' && str[1] == '5')
    {
      my_putstr("quatre-vingt-quinze");
      exit(-1);
    }

  if (str[0] == '9' && str[1] == '6')
    {
      my_putstr("quatre-vingt-dix-six");
      exit(-1);
    }

  if (str[0] == '9' && str[1] == '7')
    {
      my_putstr("quatre-vingt-dix-sept");
      exit(-1);
    }

  if (str[0] == '9' && str[1] == '8')
    {
      my_putstr("quatre-vingt-dix-huit");
      exit(-1);
    }

  if (str[0] == '9' && str[1] == '9')
    {
      my_putstr("quatre-vingt-dix-neuf");
      exit(-1);
    }

}
