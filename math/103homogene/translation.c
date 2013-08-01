/*
** translation.c for translation in /u/all/pidoux_q/cu/rendu/math/103homogene
** 
** Made by quentin pidoux
** Login   <pidoux_q@epitech.net>
** 
** Started on  Sat Dec 12 14:00:22 2009 quentin pidoux
** Last update Sat Dec 12 18:23:32 2009 quentin pidoux
*/

# include      	"103homogene.h"

int	       	translation(char **argv)
{
  float		Tx; 
  float		Ty;
  
  sscanf(argv[2], "%f", &Tx);
  sscanf(argv[3], "%f", &Ty);

  printf("\n| 1.000  0.000 %.3f|\n", Tx );
  printf("| 0.000  1.000 %.3f |\n",   Ty );
  printf("| 0.000  0.000 1.000 |\n\n"    );

  return (0);
}
