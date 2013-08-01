/*
** option3.c for option3 in /u/all/pidoux_q/cu/rendu/math/104systeme
** 
** Made by quentin pidoux
** Login   <pidoux_q@epitech.net>
** 
** Started on  Mon Dec 21 10:49:31 2009 quentin pidoux
** Last update Wed Dec 23 11:49:25 2009 quentin pidoux
*/

#include <stdio.h>
#include <math.h>

int		option3(char **argv)
{
  int		x;
  int		y;
  int		z;
  int		rho;
  int		theta;
  int		phi;
 
  x = argv[2];
  y = argv[3];
  z = argv[4];
  rho = sqrt( (x*x) + (y*y) + (z*z) );	       	
  theta = acos( (sqrt( (x*x) + (y*y)) * M_PI/180));
  phi = asin(z/rho);	     
  /* acos = arc cosinus */

  printf("\n|Rayon rho = %rho");
  printf("\n|Argument theta = %theta |\n\n" );
  printf("\n|Argument phi = %phi |\n\n" );

  return (0);
}
