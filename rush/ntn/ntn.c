/*
** ntn.c for ntn in /u/all/anncel_m/cu/rendu/c/proj/ntn
** 
** Made by maxime anncelli
** Login   <anncel_m@epitech.net>
** 
** Started on  Sat Dec  6 22:07:37 2008 maxime anncelli
** Last update Sun Dec  7 19:34:54 2008 anthony lorillon
*/

#include "my.h"
#include <stdlib.h>
#include <unistd.h>

int	ntn(char *str)
{
  int	i;
  int	j;
  int	k;
  int	l;
  int	d;

  j = 0;
  k = 0;
  i = my_strlen(str);
  while (str[j] == '0' || str[j] == '-')
    j++;
  i = i - j;
  l = i;
  while (k < i)
    {
      if (l == 1)
	unity(str[j]);
      if(l == 2)
	{  
	  dix(str[j]);
	  except(j, str, d);
	   dix2(str);
	   dix1(str, j);
	   sixdix(str);
	   huitdix(str);
	   space(j, str, d);
	}
      if(l == 3)
	{
	  cent(str, j);
	  dix(str[j]);
	  space(j, str, d);
	}
      if(l == 4)
	dix22(str);
      mille(str, j);
      if(l == 5)
	mille2(str, j);
      if(l == 6)
	mille3(str, j);
      if(l == 7)
	million(str[j]);
      k++;
      l--;
      j++;
    }
  return (0);
}
