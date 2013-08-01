/*
** unity.c for unity in /u/all/anncel_m/cu/rendu/c/proj/ntn
** 
** Made by maxime anncelli
** Login   <anncel_m@epitech.net>
** 
** Started on  Sat Dec  6 10:03:35 2008 maxime anncelli
** Last update Sun Dec  7 16:32:13 2008 anthony lorillon
*/

#include "my.h"
#include <unistd.h>

int	unity(char str)
{
   if(str == '1')
    my_putstr("un");
  if(str == '2')
    my_putstr("deux");
  if(str == '3')
    my_putstr("trois");
  if(str == '4')
    my_putstr("quatre");
  if(str == '5')
    my_putstr("cinq");
  if(str == '6')
    my_putstr("six");
  if(str == '7')
    my_putstr("sept");
  if(str == '8')
    my_putstr("huit");
  if(str == '9')
    my_putstr("neuf");
  return (0);
}
