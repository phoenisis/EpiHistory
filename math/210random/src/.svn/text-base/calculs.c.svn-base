/*
**  src/calculs.c
**  210Random
**
**  Created by Quentin PIDOUX on 17/06/12.
**  Copyright (c) 2012 EPITECH. All rights reserved.
*/

#include "../inc/210random.h"

double          Moy(double *val)
{
  double        res = 0;
  int           k;

  for (k = 0; k != 10; k++)
    res = (val[k] * k) + res;
  return (res / 1000);
}

void            make_calculs(double *nbs)
{
  double        result = 0;
  int           i;

  printf("\nMoyenne = %.3f\n", Moy(nbs));
  for (i = 0; i < 10; i++)
    result += (pow((nbs[i] - 100), 2)) / 100;
  printf("X2 = %.3f\n", result);
  aff_pourc(result);
}
