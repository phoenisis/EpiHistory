/*
** my_strcmp.c for strcmp in /u/all/pidoux_q/cu/rendu/piscine/Jour_07
** 
** Made by quentin pidoux
** Login   <pidoux_q@epitech.net>
** 
** Started on  Wed Oct 13 21:46:31 2010 quentin pidoux
** Last update Wed Oct 13 21:46:34 2010 quentin pidoux
*/

int		my_strcmp(char *s1, char *s2)
{
  int		i;
  int		l;

  i = 0;
  while ((s1[i] != '\0') || (s2[i] != '\0'))
    {
      if (s1[i] != s2[i])
        {
          l = s1[i] - s2[i];
          return (l);
        }
      i = i + 1;
    }
  return (0);
}
