/*
** option1.c for option1 in /u/all/pidoux_q/cu/rendu/math/104systeme
** 
** Made by quentin pidoux
** Login   <pidoux_q@epitech.net>
** 
** Started on  Mon Dec 21 10:50:08 2009 quentin pidoux
** Last update Wed Dec 30 13:58:17 2009 quentin pidoux
*/

#include <stdio.h>
#include <math.h>


int		option1(char **argv)
{
  int		x;
  int		y;
  int		cosa;
  int		sina;
  int		r;
  int		a;
 
  x = argv[2];
  y = argv[3];
  r = sqrt( (x*x) + (y*y) );			 /* sqrt = racine carre */
  cosa = cos( (x * r) * M_PI/180);
  sina = sin( (y * r) * M_PI/180);
  a = atan(sina / cosa);		         /* atan = arc tangente  */

  printf("\n|Rayon r = %r");
  printf("\n|Argument theta = %a |\n\n" ); 

  return (0);
}
