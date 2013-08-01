#include <stdlib.h>
#include <stdio.h>

void    tab_to_2dtab(int *tab, int length, int width, int ***res)
{
  int **str;
  int h = 0;
  int v = 0;
  int u = 0;

  str = malloc(length * sizeof(*str));
  while (v < length)
    {
      str[v] = malloc(width * sizeof(*str[v]));
      v++;
    }
  v = 0;
  while (h < length && (u < (length * width)))
    {
      while (v < width && u < (length * width))
	{
	  str[h][v] = tab[u];
	  v++;
	  u++;
	}
      v = 0;
      h++;
    }
 *res = str;
}
