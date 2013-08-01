/*
** my_revstr.c for revstr in /u/all/pidoux_q/cu/rendu/piscine/Jour_07
** 
** Made by quentin pidoux
** Login   <pidoux_q@epitech.net>
** 
** Started on  Wed Oct 13 21:40:32 2010 quentin pidoux
** Last update Wed Oct 13 21:40:35 2010 quentin pidoux
*/

char		*rev_str_algo(char *str, int j)
{
  while (j >= 0)
    {
      j = j - 1;
    }
  return (0);
}

char		*my_revstr(char *str)
{
  int		len_str;
  
  len_str = my_strlen(str);
  len_str = len_str--;
  rev_str_algo(str, len_str);
}
