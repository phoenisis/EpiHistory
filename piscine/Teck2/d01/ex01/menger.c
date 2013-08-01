#include <stdio.h>
#include <stdlib.h>

int menger(int size,int lvl, int x, int y)
{
  int i;
  
  if (size >= 3 && lvl > 0)
    {
      i = 0;
      size /=3;
      lvl--;
      printf("%.3d %.3d %.3d\n", size, x + size, y + size);
      while (i < 9)
	{
	  if (i != 4)
	    menger(size, lvl, x + i/3 * size, y + (i * size) % (size * 3));
	  i++;
	}
      return 0;
    }
  return 0;
}
