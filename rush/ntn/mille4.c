/*
** dix2.c for dix2 in /u/all/anncel_m/cu/rendu/c/proj/ntn
** 
** Made by maxime anncelli
** Login   <anncel_m@epitech.net>
** 
** Started on  Sat Dec  6 20:12:36 2008 maxime anncelli
** Last update Sun Dec  7 16:30:23 2008 anthony lorillon
*/

#include "my.h"
#include <stdlib.h>

void	mille4(char *str)
{
  if(str[0] == '1' && str[1] == '1')
    {
      my_putstr("onze mille");
      exit(-1);
    }
  if(str[0] == '1' && str[1] == '2')
    {
      my_putstr("douze mille");
      exit(-1);
    }
  if(str[0] == '1' && str[1] == '3')
    {
      my_putstr("treize mille");
      exit(-1);
    }
  if(str[0] == '1' && str[1] == '4')
    { 
      my_putstr("quatorze mille");
      exit(-1);
    }
  if(str[0] == '1' && str[1] == '5')
    {
      my_putstr("quinze mille");
      exit(-1);
    }
  if(str[0] == '1' && str[1] == '6')
    {    
      my_putstr("seize mille");
      exit(-1);
    }
  if(str[0] == '1' && str[1] == '7')
    {
      my_putstr("dix-sept mille");
      exit(-1);
    }
  if(str[0] == '1' && str[1] == '8')
    {
      my_putstr("dix-huit mille");
      exit(-1);
    }
  if(str[0] == '1' && str[1] == '9')
    {
      my_putstr("dix-neuf mille");
      exit(-1);
    }
}
