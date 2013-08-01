/*
** my_power_it.c for power_it in /u/all/pidoux_q/cu/rendu/piscine/Jour_07
** 
** Made by quentin pidoux
** Login   <pidoux_q@epitech.net>
** 
** Started on  Wed Oct 13 21:38:08 2010 quentin pidoux
** Last update Wed Oct 13 21:38:10 2010 quentin pidoux
*/

int		my_power_it(int nb, int power)
{
  int		i;
  int		p;

  i = nb;
  p = power;
  if (nb == 0 || power == 0)
    return (1);
  power--;
  while (power > 0)
    {
      power--;
      i = i * nb;
    }
}
