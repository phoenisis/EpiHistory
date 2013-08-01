/*
** my_get_nbr.c for my_get_nbr in /u/all/pidoux_q/cu/rendu/c/minitalk
** 
** Made by quentin pidoux
** Login   <pidoux_q@epitech.net>
** 
** Started on  Tue Mar  9 14:51:13 2010 quentin pidoux
** Last update Tue Mar  9 14:52:45 2010 quentin pidoux
*/

int             str_number_pos(char *str)
{
  int           signe;
  int           pos;

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

int             my_getnbr(char *str)
{
  int           nbr;
  int           signe;
  int           first_number;

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
