/*
** my_putnbrbase.c for my_putnbr_base in /u/all/ricard_v/cu/rendu/math/102matrice
** 
** Made by vincent ricard
** Login   <ricard_v@epitech.net>
** 
** Started on  Sat Nov 28 19:28:07 2009 vincent ricard
** Last update Sat Nov 28 19:28:10 2009 vincent ricard
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
