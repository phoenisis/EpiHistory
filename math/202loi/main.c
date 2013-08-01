#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "option.h"

double          e(double l[], int o, int s)
{
  double        r = 0.0;
  int           i = 0;

  while (i < s)
    r += (i + o) * l[i++];
  return (r);
}

double          law(int m, int i, double p[5][5])
{
  double        r = 0.0;
  int           j = 0;
    
  while (j < 5) {
    r += (m) ? p[i][j] : p[j][i];
    j++;
  }
  return (r);
}

int             printone(double p[5][5], double lx[5], double ly[5])
{
  int           y;
  int           x;
    
  for (y = 0; y < 7; ++y)
    for (x = 0; x < 7; ++x)
      {
	if (y == 0 && x == 0)
	  printf("%9s", " ");
	if (y == 0 && x >= 1 && x <= 5)
	  printf(" X=%d  ", x);
	if (x == 0 && y >= 1 && y <= 5)
	  printf("    Y=%d  ", y);
	if (x >= 1 && x <= 5 && y >= 1 && y <= 5)
	  printf("%.3f ", p[y - 1][x - 1]);
	if (y == 6 && x >= 1 && x <= 5)
	  printf("%.3f ", lx[x - 1]);
	if (x == 6 && y >= 1 && y <= 5)
	  printf("%.3f\n", ly[y - 1]);
	if (x == 6 && y == 6)
	  printf("%3d\n", 1);
	if ((x == 0 && y == 6) || (x == 6 && y == 0))
	  printf(x ? "Loi de Y \n" : "Loi de X ");
      }
  return (0);
}

double          v(double l[], double es, int o, int s)
{
  double        r = 0.0;
  int           i = 0;
    
  while (i < s)
    r += pow((i + o) - es, 2) * l[i++];
  return (r);
}

int     main(int ac, char **av)
{
  if (ac == 2){
    if (atoi(av[1]) > 5)
      printf("Usage: 202loi [option < 6]\n");
    one(atoi(av[1]), 0, 0);
  }
  else
    puts(USAGE);
  return (0);
}
