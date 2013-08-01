/*
**  src/210random.c
**  210Random
**
**  Created by Quentin PIDOUX on 17/06/12.
**  Copyright (c) 2012 EPITECH. All rights reserved.
*/

#include "../inc/210random.h"

void            aff_pourc(double res)
{
  if (res <= 0.0)
    printf("X2 = 0\nP = 100%%\n");
  else if (res > 0.0 && res <= 4.168)
    printf("0 <= X2 <= 4.168\n1 < P <= 0,900\n");
  else if (res > 4.168 && res <= 5.380)
    printf("4.168 <= X2 <= 5.380\n0,900 <= P <= 0,800\n");
  else if (res > 5.380 && res <= 6.393)
    printf("5.380 <= X2 <= 6.393\n0,800 <= P <= 0,700\n");
  else if (res > 6.393 && res <= 8.343)
    printf("6.393 <= X2 <= 8.343\n0,700 <= P <= 0,500\n");
  else if (res > 8.343 && res <= 10.656)
    printf("8.343 <= X2 <= 10.656\n0,500 <= P <= 0,300\n");
  else if (res > 10.656 && res <= 12.242)
    printf("10.656 <= X2 <= 12.242\n0,300 <= P <= 0,200\n");
  else if (res > 12.242 && res <= 14.684)
    printf("12.242 <= X2 <= 14.684\n0,200 <= P <= 0,100\n");
  else if (res > 14.684 && res <= 16.919)
    printf("14.684 <= X2 <= 16.919\n10%% <= P <= 5%%\n");
  else if (res > 16.919 && res <= 19.679)
    printf("16.919 <= X2 <= 19.679\n5%% <= P <= 2%%\n");
  else if (res > 19.679 && res <= 21.666)
    printf("19.679 <= X2 <= 21.666\n2%% <= P <= 1%%\n");
  else
    printf("21.666 <= X2 <= 1000\n1%% <= P <= 0%%\n");
}

void            aff_random_numbers(double *nbs)
{
  printf("x  Ox\n-  --\n0| %.0f\n1| %.0f\n2| %.0f\n3| %.0f\n4| %.0f\n5| %.0f\n"
         "6| %.0f\n7| %.0f\n8| %.0f\n9| %.0f\n", nbs[0], nbs[1], nbs[2],
         nbs[3], nbs[4], nbs[5], nbs[6], nbs[7], nbs[8], nbs[9]);
}


int            main()
{
  int           i;
  int           nb;
  double        rnb[10];

  system("clear");
  printf("   210random\n---------------\n\n");

  for (i = 0; i < 10; i++)
    rnb[i] = 0;
  srand(time(NULL));

  for (i = 0; i < 1000; i++)
    {
      nb = rand() % 10;
      rnb[nb]++;
    }

  aff_random_numbers(rnb);
  make_calculs(rnb);
  printf("\n");
  return EXIT_SUCCESS;
}
