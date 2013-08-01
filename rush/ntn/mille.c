/*
** mille.c for mille in /u/all/anncel_m/cu/rendu/c/proj/ntn
** 
** Made by maxime anncelli
** Login   <anncel_m@epitech.net>
** 
** Started on  Sat Dec  6 14:33:39 2008 maxime anncelli
** Last update Sun Dec  7 17:47:15 2008 anthony lorillon
*/

#include "my.h"
#include <stdlib.h>

void	mille(char *str, int j)
{
  if(str[j] == '1')
    my_putstr("mille");
  if(str[j] == '2')
    my_putstr("deux mille");
  if(str[j] == '3')
    my_putstr("trois mille");
  if(str[j] == '4')
    my_putstr("quatre mille");
  if(str[j] == '5')
    my_putstr("cinq mille");
  if(str[j] == '6')
    my_putstr("six mille");
  if(str[j] == '7')
    my_putstr("sept mille");
  if(str[j] == '8')
    my_putstr("huit mille");
  if(str[j] == '9')
    my_putstr("neuf mille");
}
