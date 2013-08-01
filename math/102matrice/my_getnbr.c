/*
** my_getnbr.c for my_getnbr in /u/all/pidoux_q/cu/rendu/math/102matrice
** 
** Made by quentin pidoux
** Login   <pidoux_q@epitech.net>
** 
** Started on  Wed Feb 10 11:40:22 2010 quentin pidoux
** Last update Wed Feb 10 11:40:34 2010 quentin pidoux
*/

int		str_number_pos(char *str)
{
  int		signe;
  int		pos;
  
  signe = 1;
  pos = 0;
  while(str[pos] == '+' || str[pos] == '-')
    {
      if (str[pos] == '-')
	{
	  signe = signe * -1;
	}
      pos = pos + 1;
    }
  return (signe * pos);
}

int		my_getnbr(char *str)
{
  int		nbr;
  int		signe;
  int		first_number;
  
  nbr = 0;
  signe = 1;
  first_number = str_number_pos(str);
  if (first_number < 0)
    {
      first_number = first_number * -1;
      signe = -1;
    }
  str = str + first_number;
  while (*str >= '0' && *str <= '9')
    {
      nbr = nbr * 10;
      nbr = nbr + (*str - '0');
      str = str + 1;
    }
  return (nbr * signe);
}
