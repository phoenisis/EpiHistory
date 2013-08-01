/*
** tableur.c for Table Display in /u/all/ricard_v/cu/rendu/math/102matrice
** 
** Made by vincent ricard
** Login   <ricard_v@epitech.net>
** 
** Started on  Mon Nov 23 13:59:33 2009 vincent ricard
** Last update Sat Nov 28 20:09:01 2009 vincent ricard
*/

# include <stdio.h> 


/* ********************************************* */
/* OPTION N.1 ADDITION ENTRE DEUX MATRICES 2 X 2 */
/* ********************************************* */


int		option_1(char **argv)
{
  int		i;
  int		j;
  int		e_AB[7];
  int		base_len;
  char		*base;
  
  base_len = my_getnbr(argv[2]);
  base = lib_base(base_len); /* pour verifier la base (en argument 2)*/


  /* Affichage des Matrices A et B avec leurs coefficients mis en argument */

  
  printf("\n\t   Matrice A \t\t       Matrice B                                                  ");
  printf("\n\t   --------- \t\t       ---------                                              \n\n");

  printf("\t    %s    %s                     %s    %s       \n", argv[3], argv[4], argv[7], argv[8]); 
  printf("\t    %s    %s                     %s    %s    \n\n", argv[5], argv[6], argv[9], argv[10]);   

  /*                                                            
  ** Execution de l'addition entre la matrice A et la matrice B **
  */

  printf("\n\t\t       Matrice A + B       ");
  printf("\n\t\t       -------------   \n\n"); 

  i = 0;
  j = 3;

  /* Conversion des coefficients en base 10 pour le calcul ... */

  while (i <= 7)
    {
      e_AB[i] = my_get_nbr_base(argv[j], base);
      i = i + 1;
      j = j + 1;
    }

  /* ... puis affichage du resultat en base n (n = argument 2) */

  my_putstr("\t\t\t");
  my_putnbrbase(e_AB[0] + e_AB[4], base);
  my_putstr("\t  ");
  my_putnbrbase(e_AB[1] + e_AB[5], base);
  my_putstr("\n\t\t\t");
  my_putnbrbase(e_AB[2] + e_AB[6], base);
  my_putstr("\t  ");
  my_putnbrbase(e_AB[3] + e_AB[7], base);
  my_putstr("\n");

  free(base);
  return (0);
}
