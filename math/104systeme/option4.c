/*
** option4.c for option4 in /u/all/pidoux_q/cu/rendu/math/104systeme
** 
** Made by quentin pidoux
** Login   <pidoux_q@epitech.net>
** 
** Started on  Mon Dec 21 10:49:46 2009 quentin pidoux
** Last update Mon Dec 21 17:07:52 2009 quentin pidoux
*/

#include <stdio.h>
#include <math.h>

int		option4(char **argv)
{
  int		rho;
  int		theta;
  int		phi;
  int		x;
  int		y;
  int		z;
 
  rho = argv[2];
  theta = argv[3];
  phi = argv[4];
  x = (rho*cos(phi* M_PI/180) * cos(theta * M_PI/180) );
  y = (rho*sin(phi* M_PI/180) * sin(theta * M_PI/180) );
  z = (rho*sin(phi* M_PI/180) );

  printf("\n|x = %x");
  printf("\n|y = %y" );
  printf("\n|z = %z |\n\n" );

  return (0);
}
