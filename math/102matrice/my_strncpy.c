/*
** my_strncpy.c for my_strncpy in /u/all/ricard_v/cu/rendu/piscine/Jour_06
** 
** Made by vincent ricard
** Login   <ricard_v@epitech.net>
** 
** Started on  Tue Oct 13 12:46:11 2009 vincent ricard
** Last update Sat Nov 28 13:27:33 2009 vincent ricard
*/

char		*my_strncpy(char *dest, char *src, int n)
{
  int           i;
  int		c;
  
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
