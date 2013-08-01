#include <stdio.h>

int menger(int size,int lvl, int x, int y);

int             my_getnbr(char *str)
{
  int           nbr;

  nbr = 0;
  while (*str != '\0')
    {
      nbr = nbr * 10;
      nbr = nbr + (*str - '0');
      str = str + 1;
    }
  return (nbr);
}

int main(int ac, char **av)
{
  if (ac != 3)
    {
      return (0);
    }

  int size = my_getnbr(av[1]);
  int lvl = my_getnbr(av[2]);

  if (lvl == 0 || size %3 == 1 || lvl > 3)
    return 0;
  else
    {
      menger(size, lvl, 0, 0);
    }
  return 0;
}

