/*
** my_get_nbr_base.c for my_get_nbr_base in /u/all/ricard_v/cu/rendu/piscine/librairie
** 
** Made by vincent ricard
** Login   <ricard_v@epitech.net>
** 
** Started on  Sat Nov 28 11:25:44 2009 vincent ricard
** Last update Sat Nov 28 15:28:37 2009 vincent ricard
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
