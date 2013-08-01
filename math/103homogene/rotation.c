/*
** rotation.c for rotation in /u/all/pidoux_q/cu/rendu/math/103homogene
** 
** Made by quentin pidoux
** Login   <pidoux_q@epitech.net>
** 
** Started on  Sat Dec 12 14:01:31 2009 quentin pidoux
** Last update Sat Dec 12 18:23:32 2009 quentin pidoux
*/

# include	"103homogene.h"
	
int     	rotation(char **argv)
{
  float		R;

  sscanf(argv[2], "%f", &R);
  printf("\n| %.3f %.3f 0.000 |\n", cos(R * M_PI/180), -sin(R * M_PI/180));
  printf("| %.3f  %.3f 0.000 |\n",   sin(R * M_PI/180), cos(R * M_PI/180));
  printf("| 0.000  0.000 1.000 |\n\n"                                        );
  
  return (0);
}
