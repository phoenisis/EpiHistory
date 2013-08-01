/*
** symetrie.c for symetrie in /u/all/pidoux_q/cu/rendu/math/103homogene
** 
** Made by quentin pidoux
** Login   <pidoux_q@epitech.net>
** 
** Started on  Sat Dec 12 14:02:17 2009 quentin pidoux
** Last update Sat Dec 12 18:23:32 2009 quentin pidoux
*/

# include	 "103homogene.h"
	
int     	symetrie(char **argv)
{
  float		R;

  sscanf(argv[2], "%f", &R);
  printf("\n|%.3f  %.3f 0.000 |\n", cos(2*R * M_PI/180), sin(2*R * M_PI/180));
  printf("| %.3f  %.3f 0.000 |\n",   sin(2*R * M_PI/180), -cos(2*R * M_PI/180));
  printf("| 0.000  0.000 1.000 |\n\n"                                        );
  
  return (0);
}
