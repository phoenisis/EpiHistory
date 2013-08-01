/*
** my_strstr.c for strstr in /u/all/pidoux_q/cu/rendu/piscine/Jour_07
** 
** Made by quentin pidoux
** Login   <pidoux_q@epitech.net>
** 
** Started on  Wed Oct 13 21:50:02 2010 quentin pidoux
** Last update Wed Oct 13 21:50:07 2010 quentin pidoux
*/

char		*my_strstr(char *str, char *to_find)
{
  int		i;
  int		j;

  i = 0;
  j = 0;
  while (to_find[i] != str[i])
          i = i + 1;
  while (to_find[j] != '\0')
        j = j + 1;
  return (&to_find[i]);
}
