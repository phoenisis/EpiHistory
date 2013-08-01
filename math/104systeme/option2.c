/*
** option2.c for option2 in /u/all/pidoux_q/cu/rendu/math/104systeme
** 
** Made by quentin pidoux
** Login   <pidoux_q@epitech.net>
** 
** Started on  Mon Dec 21 10:49:20 2009 quentin pidoux
** Last update Mon Dec 21 19:41:33 2009 quentin pidoux
*/

#include <math.h>

int		option2(char **argv)
{
  int		r;
  int		a;
  int		cos;
  int		sin;
  int		x;
  int		y;
   
  r = argv[2];
  a = argv[3];
  y = r * cos(a * M_PI/180);
  x = r * sin(a * M_PI/180);
  
  printf("\n|x = %x");
  printf("\n|y = %y |\n\n" );

  return (0);

}
