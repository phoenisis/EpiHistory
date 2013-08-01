
#include <stdio.h>
#include <stdlib.h>

int		follow_the_white_rabbit(void)
{
  int		sum = 0;
  int		j;
  
  while (42)
    {
      j = random() % 37 + 1;

      if (j == 3)
	j = ((random() % 37 + 1)+ 3);
      if (j == 10 || j == 15 || j == 23)
	printf("%s\n", "devant");
      else if ((j >= 4 && j <= 6) || (j >= 17 && j <= 21) || j == 28)
	printf("%s\n", "gauche");
      else if (j == 8 || j == 16 || j == 24 || j == 26  || j == 32 || j == 40)
	printf("%s\n", "derriere");
      else if (j == 13 || j == 34 || j == 35 || j == 36 || j == 38 || j == 39)
	printf("%s\n", "droite");
      sum += j;
      if (j == 1 || j == 37 || sum >= 397)
	{
	  printf("%s\n", "LAPIN !!!");
	  break;
	}
    }
  return (sum);
}
