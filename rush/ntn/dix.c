/*
** dix.c for dix in /u/all/anncel_m/cu/rendu/c/proj/ntn
** 
** Made by maxime anncelli
** Login   <anncel_m@epitech.net>
** 
** Started on  Sat Dec  6 11:56:16 2008 maxime anncelli
** Last update Sun Dec  7 15:54:26 2008 anthony lorillon
*/

#include "my.h"
#include <stdlib.h>

void	dix(char str)
{
  if(str == '2')
    my_putstr("vingt");
  if(str == '3')
    my_putstr("trente");
  if(str == '4')
    my_putstr("quarante");
  if(str == '5')
    my_putstr("cinquante");
  if(str == '6')
    my_putstr("soixante");
  if(str =='7')
    my_putstr("soixante dix");
   if(str == '8')
    my_putstr("quatre-vingt");
}

