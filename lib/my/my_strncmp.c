/*
** my_strncmp.c for str in /u/all/pidoux_q/cu/rendu/piscine/Jour_07
** 
** Made by quentin pidoux
** Login   <pidoux_q@epitech.net>
** 
** Started on  Wed Oct 13 21:49:40 2010 quentin pidoux
** Last update Wed Oct 13 21:49:41 2010 quentin pidoux
*/

int		my_strncmp(char *s1, char *s2, int nb)
{
  int		c;

  c = 0;
  while (s1[c] != '\0' && s1[c] == s2[c] && c < nb)
    c++;
  return (s1[c] - s2[c]);
}

