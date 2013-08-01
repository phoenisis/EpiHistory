/*
** my_strlen.c for len in /u/all/pidoux_q/cu/rendu/piscine/Jour_07
** 
** Made by quentin pidoux
** Login   <pidoux_q@epitech.net>
** 
** Started on  Wed Oct 13 21:47:28 2010 quentin pidoux
** Last update Wed Oct 13 21:47:29 2010 quentin pidoux
*/

int		my_strlen(char *str)
{
  int		i;
  
  i = 0;
  while (str[i] != '\0')
    i++;
  return (i);
}
