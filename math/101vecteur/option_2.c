/*
** option_2.c for option N.2 in /u/all/ricard_v/cu/rendu/math/101vecteur
** 
** Made by vincent ricard
** Login   <ricard_v@epitech.net>
** 
** Started on  Fri Nov 13 21:09:33 2009 vincent ricard
** Last update Tue Nov  9 13:18:02 2010 quentin pidoux
*/

#include <stdio.h>  // pour la fonction "printf"
#include <stdlib.h> // pour la fonction "rand"
#include <time.h>   // pour la fonction "srand"
#include <math.h>   // pour la fonction "sqrt"

int		option_2()
{
  int		vec_u[3];
  int		vec_v[3];
  int		vec_uv[3];
  int		norme_u;
  int		norme_uv;
  int		i;
  
  /* Produit vectoriel entre le vecteur u et le vecteur v */
  
  i = 0;
  srand(time(NULL)); // fonction qui ameliore la generation de nombres aleatoires selon l'heure
  printf("Vecteur u \tVecteur v\tVecteur u*v\n\n");
  while (i < 3)
    {
      vec_u[i] = rand() % 10; // "%10" -> pour generer des chiffres entre 0 et 9
      vec_v[i] = rand() % 10;
      vec_uv[i] = vec_u[i] * vec_v[i];
      printf("\t%d \t\t%d \t\t%d\n", vec_u[i], vec_v[i], vec_uv[i]);
      i = i + 1;
    }
  
  /* Norme du vecteur u */

  norme_u = sqrt((vec_u[1] * vec_u[1]) + (vec_u[2] * vec_u[2]) + (vec_u[3] * vec_u[3]));
  printf("\n Norme du vecteur u = %d \n", norme_u);

  /* Norme du vecteur u ^ v */
  
  norme_uv = sqrt((vec_uv[1]*vec_uv[1]) + (vec_uv[2] * vec_uv[2]) + (vec_uv[3] * vec_uv[3]));
  printf("\n Norme du vecteur u ^ v = %d \n", norme_uv);
  
  return (0);
}
