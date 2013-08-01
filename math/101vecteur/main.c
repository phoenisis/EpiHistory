/*
** 101vecteur.c for 101vecteur in /u/all/ricard_v/cu/rendu/math/101vecteur
** 
** Made by vincent ricard
** Login   <ricard_v@epitech.net>
** 
** Started on  Fri Nov 13 17:56:16 2009 vincent ricard
** Last update Fri Nov 13 22:52:25 2009 vincent ricard
*/

#include <stdio.h>

int		main(int argc, char **argv)
{
  int		option;
  int		dimension;

  if (argc == 2)
    {
      option = my_getnbr(argv[1]);
    }
  if (argc == 3)
    {
      dimension = my_getnbr(argv[2]);
    }

  /* Gestion des erreurs */

   if (argc == 1)
    {
      printf("Usage: at least one argument is requiered.\n");
      return (1);
    }
   if (argc == 2)
     {
       if (option == 0 || option > 3)
	 {
	   printf("Usage: first argument is the option number. Choose between 1-3.\n");
	   return (1);
	 }
       if (option == 1)
	 {
	   printf("Usage: if first argument is '1' please, give a dimension as the second argument.\n");
	 }
     }
   if (argc == 3)
     {
       if (dimension < 1 || dimension > 9)
	 {
	   printf("Usage: dimension must be contained between 1-9.\n");
	   return (1);
	 }
     }

   /* Redirection selon l'option choisie */
  
  if (argc == 3)
    option_1(dimension);
  if (option == 2)
    option_2();
  if (option == 3)
    option_3();

  return (0);
}
