/*
** my_put_nbr.c for putnbr in /u/all/pidoux_q/cu/rendu/piscine/Jour_07
** 
** Made by quentin pidoux
** Login   <pidoux_q@epitech.net>
** 
** Started on  Wed Oct 13 21:38:56 2010 quentin pidoux
** Last update Wed Oct 13 21:38:57 2010 quentin pidoux
*/

int		my_put_nbr(int nb)
{
  if (nb < 0)
    {
      my_putchar('-');
      nb = -nb;
    }
  if (nb > 9)
    my_put_nbr(nb / 10);
  return (my_putchar('0' + nb % 10));
}
