/*
** main.c for main in /u/all/pidoux_q/cu/rendu/math/103homogene
** 
** Made by quentin pidoux
** Login   <pidoux_q@epitech.net>
** 
** Started on  Sat Dec 12 13:57:25 2009 quentin pidoux
** Last update Sat Dec 12 18:25:40 2009 quentin pidoux
*/

# include	"103homogene.h"

int		main(int argc, char **argv)
{
  if (argc < 2)
    {
      printf("Usage: ./103homogenes and requiered arguments.\n");
      exit(EXIT_FAILURE);
    }
  else
    {
      if (argv[1][0] == 'R')
	rotation(argv);
      if (argv[1][0] == 'T')
	translation(argv);
      if (argv[1][0] == 'S')
	symetrie(argv);
      if (argv[1][0] == 'H')
	homothetie(argv);
    }
  return (0);
}
