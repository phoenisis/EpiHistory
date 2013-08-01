/*
** my_get_nbr_base.c for my_put_nbr_base in /u/all/pidoux_q/cu/rendu/c/minitalk
** 
** Made by quentin pidoux
** Login   <pidoux_q@epitech.net>
** 
** Started on  Tue Mar  9 14:24:41 2010 quentin pidoux
** Last update Tue Mar  9 14:24:43 2010 quentin pidoux
*/

#include <stdio.h>


int		base_nbr(char c, char *base)
{
  int		i;

  i = 0;
  while (base[i] != '\0')
    {
      if (c == base[i])
        {
          return (i);
        }
      i = i + 1;
    }
  return (0);
}

int		my_get_nbr_base(char *str, char *base)
{
  int		nb_final;
  int		base_l;
  int		str_l;
  int		conv_fact;

  if (str[0] == '-')
    {
      return (-my_get_nbr_base(str + 1, base));
    }
  base_l = my_strlen(base);
  str_l = my_strlen(str) - 1;
  conv_fact = 1;
  nb_final = 0;
  while (str_l >= 0)
    {
      nb_final = nb_final + base_nbr(str[str_l], base) * conv_fact;
      conv_fact = base_l * conv_fact;
      str_l = str_l - 1;
    }
  return (nb_final);
}

/*int		main()
{
  my_put_nbr(my_get_nbr_base("52", "01234567"));
  return (0);
}

*/
