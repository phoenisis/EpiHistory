/*
** my_putnbrbase.c for my_put_nbr_base in /u/all/pidoux_q/cu/rendu/c/minitalk
** 
** Made by quentin pidoux
** Login   <pidoux_q@epitech.net>
** 
** Started on  Tue Mar  9 14:23:59 2010 quentin pidoux
** Last update Tue Mar  9 14:24:14 2010 quentin pidoux
*/

int     my_putnbrbase(int nbr, char *base)
{
  int        mod;
  int        start;
  int        size;
  int        nb;

  nb = 0;
  size = my_strlen(base);
  if (nbr < 0)
    {
      nb += my_putchar('-');
      nb += my_putnbrbase(-nbr, base);
    }
  else
    {
      mod = nbr % size;
      start = (nbr - mod) / size;
      if (start != 0)
	my_putnbrbase(start, base);
      nb = my_putchar(base[mod]);
    }
  return (nb);
}
