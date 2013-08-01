/*
** prog2.c for my second program in /u/all/pidoux_q/cu/rendu/c
** 
** Made by quentin pidoux
** Login   <pidoux_q@epitech.net>
** 
** Started on  Wed Oct  7 09:45:18 2009 quentin pidoux
** Last update Wed Oct  7 10:22:51 2009 quentin pidoux
*/

int		my_putchar(char c)
{
  write(1, &c, 1);
}

int		my_aff_bonjour()
{
  my_putchar('b');
  my_putchar('o');
  my_putchar('n');
  my_putchar('j');
  my_putchar('o');
  my_putchar('u');
  my_putchar('r');
  my_putchar('\n');
}

int		main()
{
  my_aff_bonjour();
}
