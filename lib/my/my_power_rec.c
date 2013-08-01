/*
** my_power_rec.c for power_rec in /u/all/pidoux_q/cu/rendu/piscine/Jour_07
** 
** Made by quentin pidoux
** Login   <pidoux_q@epitech.net>
** 
** Started on  Wed Oct 13 21:38:31 2010 quentin pidoux
** Last update Wed Oct 13 21:38:33 2010 quentin pidoux
*/

int		my_power_rec(int nb, int power)
{
  int		a = nb;

  if (nb == 0 || power == 0)
    return (1);
  while (power > 0)
    return (nb * my_power_rec(nb, power - 1));
}
