/*
** my_strncpy.c for strncpy in /u/all/pidoux_q/cu/rendu/piscine/Jour_07
** 
** Made by quentin pidoux
** Login   <pidoux_q@epitech.net>
** 
** Started on  Wed Oct 13 21:51:43 2010 quentin pidoux
** Last update Wed Oct 13 21:51:45 2010 quentin pidoux
*/

char		*my_strncpy(char *dest, char *src, int nb)
{
  int		i;
  
  i = 0;
  while (src[i] != '\0')
    {
      dest[i] = src[i];
      i = i + 1;
    }
  if (nb > 0)
    {
      dest[i] = '\0';
    }
  return (dest);
}
