/*
** option_3.c for Option N.3 in /u/all/ricard_v/cu/rendu/math/102matrice
** 
** Made by vincent ricard
** Login   <ricard_v@epitech.net>
** 
** Started on  Sat Nov 28 17:38:19 2009 vincent ricard
** Last update Sat Nov 28 20:07:03 2009 vincent ricard
*/

/* *************************************************** */
/* OPTION N.3 PRODUIT D'UNE MATRICE 2X2 PAR UN VECTEUR */
/* *************************************************** */


#include <stdio.h>

int		option_3(char **argv)
{
  int		i;
  int		j;
  int		base_len;
  int		tab_A[4];
  int		tab_u[2];
  char		*base;

  base_len = my_getnbr(argv[2]);
  base = lib_base(base_len);

  /* Affichage de la Matrice A et du Vecteur u */
 

  printf("\nMatrice A                        ");
  printf("\n---------                      \n");
  printf("%s    %s       \n", argv[3], argv[4]);
  printf("%s    %s     \n\n", argv[5], argv[6]);

  printf("\nVecteur u                        ");
  printf("\n---------                      \n");
  printf("   %s                   \n", argv[7]);
  printf("   %s                 \n\n", argv[8]);
  
  i = 0;
  j = 3;
  while (i <= 3)
    {
      tab_A[i] = my_get_nbr_base(argv[j], base);
      i = i + 1;
      j = j + 1;
    }
 
  tab_u[0] = my_get_nbr_base(argv[7], base);
  tab_u[1] = my_get_nbr_base(argv[8], base);
  

  /* Affichage du produit de la Matrice A par le vecteur u */

  printf("\nVecteur A . u    ");
  printf("\n-------------  \n");

  my_putstr("   ");
  my_putnbrbase(((tab_A[0] * tab_u[0]) + (tab_A[1] * tab_u[1])), base);
  my_putstr("\n   ");
  my_putnbrbase(((tab_A[2] * tab_u[0]) + (tab_A[3] * tab_u[1])), base);
  my_putstr("\n\n");
  
  free(base);
  return (0);
}

