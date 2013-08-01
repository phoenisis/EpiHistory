/*
** 102matrice.c for 102matrice in /u/all/ricard_v/cu/rendu/math/102matrice
** 
** Made by vincent ricard
** Login   <ricard_v@epitech.net>
** 
** Started on  Mon Nov 23 13:52:28 2009 vincent ricard
** Last update Sat Nov 28 19:49:25 2009 vincent ricard
*/

#include <stdio.h>

int		main(int argc, char **argv)
{
  int		option;
  
  if (argc <= 4)
    {
      printf("Usage: ./102matrice 'option' 'base' and required arguments for the chosen option.\n");
      return (1);
    }

  option = my_getnbr(argv[1]);
   
  if (option == 1)
    option_1(argv);
  
  else if (option == 2)
    option_2(argv);
  
  else if (option == 3)
    option_3(argv);
  
  else if (option == 4)
    option_4(argv);
  

  return (0);
}
