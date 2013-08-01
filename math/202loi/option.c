#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "option.h"

int             five(double z[9])
{
  double        f[2];

  f[0] = e(z, 2, 9);
  f[1] = v(z, f[0], 2, 9);
  printf("E(Z) = %.3f\n", f[0]);
  printf("Var(Z) = %.3f\n", f[1]);
  return 0;
}

int             four(int op, double z[9])
{
  double        f[9];
  int           i;

  f[0] = z[0];
  for (i = 1; i < 9; ++i)
    f[i] = f[i - 1] + z[i];
  if (op > 4)
    return (five(z));
  printf(" z ");
  for (i = 0; i < 9; ++i)
    printf("%4s%d ", " ", 2 + i);
  printf("\nF(z) ");
  for (i = 0; i < 9; ++i)
    printf("%.3f%s", f[i], " ");
  printf("\n");
  return 0;
}

int             three(int op, double p[5][5])
{
  double        z[9];
  int           y;
  int           x;

  for (y = 0; y < 9; ++y)
    z[y] = 0.0;
  for (y = 0; y < 5; ++y)
    for (x = 0; x < 5; ++x)
      z[y + x] += p[y][x];
  if (op > 3)
    return (four(op, z));
  printf("%5s", " ");
  for (y = 0; y < 9; ++y)
    printf("%3sZ=%d", " ", 2 + y);
  printf(" Total\np(Z=z)%s", " ");
  for (y = 0; y < 9; ++y)
    printf("%.3f%s", z[y], " ");
  printf("%3s\n", "1");
  return 0;
}

int             two(int op, double p[5][5], double lx[5], double ly[5])
{
  double        f[4];

  f[0] = e(lx, 1, 5);
  f[1] = v(lx, f[0], 1, 5);
  f[2] = e(ly, 1, 5);
  f[3] = v(ly, f[2], 1, 5);
  if (op > 2)
    return (three(op, p));
  printf("E(X) = %.3f\nVar(X) = %.3f\n", f[0], f[1]);
  printf("E(Y) = %.3f\nVar(Y) = %.3f\n", f[2], f[3]);
  return 0;
}

int             one(int op, int x, int y)
{
  double        p[5][5];
  double        lx[5];
  double        ly[5];

  if (op < 1 || op > 5)
    return (1);
  for (y = 0; y < 5; ++y)
    for (x = 0; x < 5; ++x)
      p[y][x] = ((6.0 - (x + 1)) * (7.0 - (y + 1))) / 300.0;
  for (x = 0; x < 5; ++x)
    lx[x] = law(0, x, p);
  for (y = 0; y < 5; ++y)
    ly[y] = law(1, y, p);
  if (op > 1)
    return (two(op, p, lx, ly));
  return(printone(p, lx, ly));
}
