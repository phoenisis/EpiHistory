/*
** cent.c for cent in /u/all/anncel_m/cu/rendu/c/proj/ntn
** 
** Made by maxime anncelli
** Login   <anncel_m@epitech.net>
** 
** Started on  Sat Dec  6 13:25:23 2008 maxime anncelli
** Last update Sun Dec  7 16:35:18 2008 anthony lorillon
*/

#include "my.h"
#include <stdlib.h>

void	cent(char *str, int j)
{
  if(str[j] == '1')
    my_putstr("cent");
  if(str[j] == '2')
    my_putstr("deux cent");
  if(str[j] == '3')
    my_putstr("trois cent");
  if(str[j] == '4')
    my_putstr("quatre cent");
  if(str[j] == '5')
    my_putstr("cinq cent");
  if(str[j] == '6')
    my_putstr("six cent");
  if(str[j] == '7')
    my_putstr("sept cent");
  if(str[j] == '8')
    my_putstr("huit cent");
  if(str[j] == '9')
    my_putstr("neuf cent");
  dix(str[j]);
}

