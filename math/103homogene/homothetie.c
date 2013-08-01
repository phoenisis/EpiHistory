/*
** homothetie.c for homothetie in /u/all/pidoux_q/cu/rendu/math/103homogene
** 
** Made by quentin pidoux
** Login   <pidoux_q@epitech.net>
** 
** Started on  Sat Dec 12 14:01:05 2009 quentin pidoux
** Last update Sat Dec 12 18:24:20 2009 quentin pidoux
*/

# include	"103homogene.h"

int		homothetie(char **argv)
{
  float		Hx;
  float		Hy;

  sscanf(argv[2], "%f", &Hx);
  sscanf(argv[3], "%f", &Hy);

  printf("\n|%.3f 0.000 0.000 |\n", Hx );
  printf("| 0.000 %.3f 0.000 |\n",   Hy );
  printf("| 0.000 0.000 1.000 |\n\n"    );


  return (0);
}
