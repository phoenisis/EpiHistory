/*
** my_strncpy.c for my_strncpy in /u/all/pidoux_q/cu/rendu/c/minitalk
** 
** Made by quentin pidoux
** Login   <pidoux_q@epitech.net>
** 
** Started on  Tue Mar  9 14:53:25 2010 quentin pidoux
** Last update Tue Mar  9 14:55:12 2010 quentin pidoux
*/

char            *my_strncpy(char *dest, char *src, int n)
{
  int           i;
  int           c;

  i = 0;
  c = 0;
  while (i < n)
    {
      dest[i] = src[i];
      i = i + 1;
    }
  dest[i] = src[i];
  return (dest);
}
