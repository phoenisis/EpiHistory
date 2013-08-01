/*
** my_strcpy.c for cpy in /u/all/pidoux_q/cu/rendu/piscine/Jour_07
** 
** Made by quentin pidoux
** Login   <pidoux_q@epitech.net>
** 
** Started on  Wed Oct 13 21:47:05 2010 quentin pidoux
** Last update Wed Oct 13 21:47:07 2010 quentin pidoux
*/

char		*my_strcpy(char *dest, char *src)
{
  int		i;
  
  i = 0;
  while (src[i] != '\0')
    {
      dest[i] = src[i];
      i = i + 1;
    }
   return (dest);
}
