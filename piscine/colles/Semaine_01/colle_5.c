/*
** colle1.c for colle1 in /home/maire_e//work/colle
** 
** Made by edward maire
** Login   <maire_e@epitech.net>
** 
** Started on  Sat Oct  9 16:39:20 2010 edward maire
** Last update Sat Oct  9 22:06:37 2010 quentin pidoux
*/

int	my_putchar(char c)
{
  write(1, &c, 1);
}

int		my_putstr(char *str)
{
  while (*str != 0)
    {
      my_putchar(*str);
      *str++;
    }
  return (0);
}

int	letter(int x, int y, int nb_x,int nb_y)
{
  if ((nb_x == 0 && nb_y  == 0) 
     || (nb_x ==  x - 1 && nb_y  == y - 1))
    {
      my_putstr("\033[1;31mA\033[1;00m");
    }
  if ((nb_x == x - 1 && nb_y  == 0) 
     || (nb_x == 0 && nb_y  == y - 1))
    {
      my_putstr("\033[1;34mC\033[1;00m");
    }
  if (nb_x != 0 && nb_x != x-1)
    {
      my_putstr("\033[1;39mB\033[1;00m");
    }
}

int	display_b(int x, int y, int nb_x, int nb_y)
{
  if ((nb_x  == 0 || nb_x == x - 1) || y == 1)
    {
      my_putstr("\033[1;39mB\033[1;00m");
    }
  else
    {
      my_putchar(' ');
    }
}

int	colle(int x, int y)
{
  int   nb_y;
  int	nb_x;

  nb_y = 0;
  nb_x = 0;
  while (y > nb_y)
    {
      while (x > nb_x)
	{
	  if ((nb_y == 0 || (nb_y == y - 1 && y != 1))
	     && (x != 1 && y != 1))
	      letter(x, y, nb_x, nb_y);
	  else
	      display_b(x, y, nb_x, nb_y);
	  nb_x = nb_x + 1;
	}
      if (x != 0)
	my_putchar('\n');
      nb_x = 0;
      nb_y = nb_y + 1;
    }
}

int	main()
{
  colle(5, 3);
  return (0);
}
