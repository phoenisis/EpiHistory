/*
** option_4.c for Option N.4 in /u/all/ricard_v/cu/rendu/math/102matrice
** 
** Made by vincent ricard
** Login   <ricard_v@epitech.net>
** 
** Started on  Sat Nov 28 18:24:06 2009 vincent ricard
** Last update Sat Nov 28 20:20:30 2009 vincent ricard
*/

/* *************************************************** */
/* OPTION N.4 MULTIPLICATION ENTRE DEUX MATRICES 2 X 2 */
/* *************************************************** */

#include <stdio.h>

int		option_4(char **argv)
{

  int           i;
  int           j;
  int           base_len;
  int           tab[8];
  char          *base;

  base_len = my_getnbr(argv[2]);
  base = lib_base(base_len);


  /* Affichage de la Matrice A et de la Matrice B */


  printf("\nMatrice A                          ");
  printf("\n---------                        \n");
  printf("%s    %s         \n", argv[3], argv[4]);
  printf("%s    %s       \n\n", argv[5], argv[6]);

  printf("\nMatrice B                          ");
  printf("\n---------                        \n");
  printf("%s    %s         \n", argv[7], argv[8]);
  printf("%s    %s      \n\n", argv[9], argv[10]);


  /* Mutiplication entre ... */

  i = 0;
  j = 3;
  while (i <= 7)
    {
      tab[i] = my_get_nbr_base(argv[j], base);
      i = i + 1;
      j = j + 1;
    }
  
  /* ... la Matrice A et B ... */

  printf("\nMatrice A . B    ");
  printf("\n-------------  \n");

  my_putnbrbase(((tab[0] * tab[4]) + (tab[1] * tab[6])), base);
  my_putstr("   ");
  my_putnbrbase(((tab[0] * tab[5]) + (tab[1] * tab[7])), base);
  my_putstr("\n");
  my_putnbrbase(((tab[2] * tab[4]) + (tab[3] * tab[6])), base);
  my_putstr("   ");
  my_putnbrbase(((tab[2] * tab[5]) + (tab[3] * tab[7])), base); 
  my_putstr("\n\n");
  
  /* ... et la MAtrice B et A */
  
  printf("\nMatrice A . B    ");
  printf("\n-------------  \n");

  my_putnbrbase(((tab[4] * tab[0]) + (tab[5] * tab[2])), base);
  my_putstr("   ");
  my_putnbrbase(((tab[4] * tab[1]) + (tab[5] * tab[3])), base);
  my_putstr("\n");
  my_putnbrbase(((tab[6] * tab[0]) + (tab[7] * tab[2])), base);
  my_putstr("   ");
  my_putnbrbase(((tab[6] * tab[1]) + (tab[7] * tab[4])), base); 
  my_putstr("\n\n");

  free(base);
  return (0);
}
