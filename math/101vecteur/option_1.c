/*
** option_1.c for Option N. 1 in /u/all/ricard_v/cu/rendu/math/101vecteur
** 
** Made by vincent ricard
** Login   <ricard_v@epitech.net>
** 
** Started on  Fri Nov 13 18:11:06 2009 vincent ricard
** Last update Fri Nov 13 22:16:35 2009 vincent ricard
*/
#include <stdio.h>  // pour la fonction "printf"
#include <stdlib.h> // pour la fonction "rand"
#include <time.h>   // pour la fonction "srand"

int		option_1(n)
{
  int		vec_u[n];
  int		vec_v[n];
  int		vec_uv[n];
  int		vec_pu[n];
  int		scal_uv;
  int		i;
  int		p;
 
  /* Addition des composantes du vecteur u avec celles du vecteur v */
  
  i = 0;
  srand(time(NULL)); // fonction qui optimise la generation de nombres aleatoires selon l'heure
  printf("Vecteur u \tVecteur v\tVecteur u+v\n\n");
  while (i < n)
    {
      vec_u[i] = rand() % 10; // %10 -> pour generer des chiffres entre 0 et 9
      vec_v[i] = rand() % 10;
      vec_uv[i] = vec_u[i] + vec_v[i];
      printf("\t%d \t\t%d \t\t%d\n", vec_u[i], vec_v[i], vec_uv[i]);
      i = i + 1;
    }
  /* Multiplication des composantes du vecteur u par la variable "p" dont la valeur est aleatoirement generee */
  
  i = 0;
  p = rand() % 10;
  printf("\n\n");
  printf("Nombre p = %d\n\n", p); 
  printf("Vecteur u \tVecteur p.u\n\n");
  while (i < n )
    {
      vec_pu[i] = vec_u[i] * p;
      printf("\t%d \t\t%d\n", vec_u[i], vec_pu[i]);
      i = i + 1;
    }
  printf("\n");
  
  /* Calcul du produit scalaire de (u,v) */
  
  i = 0;
  scal_uv = 0;
  while (i < n)
    {
      scal_uv = vec_u[i] * vec_v[i] + scal_uv;
      i = i + 1;
    }
   printf("\n\nProduit scalaire = %d\n\n", scal_uv);
  return (0);
}

