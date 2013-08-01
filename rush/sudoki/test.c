#include <stdio.h>
#include <stdlib.h>

void		my_putchar(char c)
{
  write(1, &c, 1);
}

int		my_putstr(char *str)
{
  while(*str != 0)
    {
      my_putchar(*str);
      *str++;
    }
}


int		main(int ac, char **av)
{
  cat av[1] > result;
}
