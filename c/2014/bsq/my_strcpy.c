/*
** my_strcpy.c for strcpy in /u/all/pidoux_q/cu/rendu/c/bsq
** 
** Made by quentin pidoux
** Login   <pidoux_q@epitech.net>
** 
** Started on  Thu Nov 12 13:05:42 2009 quentin pidoux
** Last update Thu Nov 12 13:08:16 2009 quentin pidoux
*/

char            *my_strcpy(char *dest, char *src)
{
  int           i;

  i = 0;
  while (src[i] != '\0')
    {
      dest[i] = src[i];
      i = i + 1;
    }
  dest[i] = '\0';
  return (dest);
}
