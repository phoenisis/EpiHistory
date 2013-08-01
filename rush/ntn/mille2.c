/*
** mille2.c for mille2.c in /u/all/anncel_m/cu/rendu/c/proj/ntn
** 
** Made by maxime anncelli
** Login   <anncel_m@epitech.net>
** 
** Started on  Sat Dec  6 18:03:01 2008 maxime anncelli
** Last update Sun Dec  7 16:21:26 2008 anthony lorillon
*/

#include "my.h"
#include <stdlib.h>

void    mille2(char *str, int j)
{
  if(str[j] == '1')
    my_putstr("dix");
  if(str[j] == '2')
    my_putstr("vingt");
  if(str[j] == '3')
    my_putstr("trente");
  if(str[j] == '4')
    my_putstr("quarante");
  if(str[j] == '5')
    my_putstr("cinquante");
  if(str[j] == '6')
    my_putstr("soixante");
  if(str[j] == '7')
    my_putstr("soixante-dix");
  if(str[j] == '8')
    my_putstr("quatre-vingts");
  if(str[j] == '9')
    my_putstr("quatre-vingt-dix");
}

