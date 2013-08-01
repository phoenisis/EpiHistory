/*
** my_get_nbr_base.c for get_nbr_base in /u/all/pidoux_q/cu/rendu/piscine/Jour_07
** 
** Made by quentin pidoux
** Login   <pidoux_q@epitech.net>
** 
** Started on  Wed Oct 13 21:35:28 2010 quentin pidoux
** Last update Wed Oct 13 21:35:31 2010 quentin pidoux
*/


int		my_strlen(char *str)
{
  int		i;

  i = 0;
  while (str[i] != '\0')
    {
      i++;
    }
  return (i);
}

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

int		my_getnbr_base(char *str, char *base)
{
  int		nb_final;
  int		base_l;
  int		str_l;
  int		conv_fact;

  if (str[0] == '-')
    {
      return (-my_getnbr_base(str + 1, base));
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
