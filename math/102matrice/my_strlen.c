/*
** my_strlen.c for my_strlen in /u/all/ricard_v/cu/rendu/piscine/Jour_04
** 
** Made by vincent ricard
** Login   <ricard_v@epitech.net>
** 
** Started on  Tue Oct 13 10:49:36 2009 vincent ricard
** Last update Sat Nov 28 14:40:49 2009 vincent ricard
*/

int		my_strlen(char *str)
{
  int		i;

  i = 0;
  while (str[i] != '\0')
    {
      i = i + 1;
    }
  return (i);
}
