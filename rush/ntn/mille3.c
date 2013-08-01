/*
** mille3.c for mille3 in /u/all/anncel_m/cu/rendu/c/proj/ntn
** 
** Made by maxime anncelli
** Login   <anncel_m@epitech.net>
** 
** Started on  Sat Dec  6 18:08:39 2008 maxime anncelli
** Last update Sun Dec  7 16:22:32 2008 anthony lorillon
*/

#include "my.h"
#include <stdlib.h>

void    mille3(char *str, int j)
{
  if(str[j] == '1')
    my_putstr("cent-mille");
  if(str[j] == '2')
    my_putstr("deux cent-mille");
  if(str[j] == '3')
    my_putstr("trois cent-mille");
  if(str[j] == '4')
    my_putstr("quatre cent-mille");
  if(str[j] == '5')
    my_putstr("cinque cent-mille");
  if(str[j] == '6')
    my_putstr("six cent-mille");
  if(str[j] == '7')
    my_putstr("sept cent-mille");
  if(str[j] == '8')
    my_putstr("huit cent-mille");
  if(str[j] == '9')
    my_putstr("neuf cent-mille");
}
