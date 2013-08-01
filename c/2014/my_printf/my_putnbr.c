/*
** my_putnbr_base.c for putnbrbase in /u/all/pidoux_q/cu/rendu/piscine/Jour_07
**
** Made by quentin pidoux
** Login   <pidoux_q@epitech.net>
**
** Started on  Wed Oct 13 21:39:22 2010 quentin pidoux
** Last update Thu Dec  6 16:58:07 2012 quentin pidoux
*/

#include "printf.h"

int		my_put_nbr(int nb, int len)
{
  if (nb < 0)
    {
      my_putchar('-');
      nb = -nb;
      len++;
    }
  if (nb > 9)
    len +=  my_put_nbr(nb / 10, len);
  my_putchar('0' + nb % 10);
  return (len + 1);
}

int		my_put_nbr_base(unsigned long nbr, char *base, int len)
{
  int		mod;
  int		start;
  int		size;
  int		nb = 0;

  size = my_strlen(base);
  if (nbr < 0)
    {
      len++;
      nb += my_putchar('-');
      nb += my_put_nbr_base(-nbr, base, len);
    }
  else
    {
      mod = nbr % size;
      start = (nbr - mod) / size;
      if (start != 0)
	len += my_put_nbr_base(start, base, len);
      nb = my_putchar(base[mod]);
    }
  return (len + 1);
}
