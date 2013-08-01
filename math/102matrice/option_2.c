/*
** option_2.c for option N.2 in /u/all/ricard_v/cu/rendu/math/102matrice
** 
** Made by vincent ricard
** Login   <ricard_v@epitech.net>
** 
** Started on  Sat Nov 28 16:52:08 2009 vincent ricard
** Last update Sat Nov 28 20:22:36 2009 vincent ricard
*/

/* ******************************************************* */
/* OPTION N.2 MULTIPLCATION D'UNE MATRICE 2X2 PAR UN NOMBE */
/* ******************************************************* */


#include <stdio.h>


int		option_2(char **argv)
{
  int		p;
  int		i;
  int		j;
  int		base_len;
  char		*base;
  int		tab_pA[4];

  base_len = my_getnbr(argv[2]);
  base = lib_base(base_len);
  p = my_get_nbr_base(argv[3], base);


  /* Affichage de la Matrice A */


  printf("\nMatrice A                        ");
  printf("\n---------                      \n");
  printf("%s    %s       \n", argv[4], argv[5]);
  printf("%s    %s     \n\n", argv[6], argv[7]);

  i = 0;
  j = 4;
  while (i <= 3)
    {
      tab_pA[i] = my_get_nbr_base(argv[j], base);
      i = i + 1;
      j = j + 1;
    }

  /* Multiplication de la Matrice A par p et affichage de resultat */

  printf("\nMatrice p . A       ");
  printf("\n-------------   \n\n");

  my_putnbrbase(p * tab_pA[0], base);
  my_putstr("   ");
  my_putnbrbase(p * tab_pA[1], base);
  my_putstr("\n");
  my_putnbrbase(p * tab_pA[2], base);
  my_putstr("   ");
  my_putnbrbase(p * tab_pA[3], base);
  my_putstr("\n\n");  
  
  free(base);
  return (0);
}
