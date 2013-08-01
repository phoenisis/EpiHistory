/*
** million.c for million in /u/all/anncel_m/cu/rendu/c/proj/ntn
** 
** Made by maxime anncelli
** Login   <anncel_m@epitech.net>
** 
** Started on  Sat Dec  6 17:14:57 2008 maxime anncelli
** Last update Sun Dec  7 15:58:43 2008 anthony lorillon
*/

#include "my.h"
#include <stdlib.h>

void	million(char str)
{
  if(str == '1')
    my_putstr("un million");
  if(str == '2')
    my_putstr("deux million");
  if(str == '3')
    my_putstr("trois million");
  if(str == '4')
    my_putstr("quatre million");
  if(str == '5')
    my_putstr("cinque million");
  if(str == '6')
    my_putstr("six million");
  if(str == '7')
    my_putstr("sept million");
  if(str == '8')
    my_putstr("huit million");
  if(str == '9')
    my_putstr("neuf million");
}
