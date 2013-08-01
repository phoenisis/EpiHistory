/*
** my_putnbr_base.c for putnbrbase in /u/all/pidoux_q/cu/rendu/piscine/Jour_07
** 
** Made by quentin pidoux
** Login   <pidoux_q@epitech.net>
** 
** Started on  Wed Oct 13 21:39:22 2010 quentin pidoux
** Last update Wed Oct 13 21:39:24 2010 quentin pidoux
*/

int		my_strlen(char *str)
{
  int		i;

  i = 0;
  while (str[i] != '\0')
    i++;
  return (i);
}

int		my_putnbr_base(int nbr, char *base)
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
        nb += my_putnbr_base(-nbr, base);
     }
     else
     {
        mod = nbr % size;
        start = (nbr - mod) / size;
        if (start != 0)
         my_putnbr_base(start, base);
        nb = my_putchar(base[mod]);
     }
     return (nb);
}
