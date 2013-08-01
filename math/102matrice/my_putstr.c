/*
** my_putstr.c for my_putstr in /u/all/ricard_v/cu/rendu/math/102matrice
** 
** Made by vincent ricard
** Login   <ricard_v@epitech.net>
** 
** Started on  Sat Nov 28 16:45:03 2009 vincent ricard
** Last update Sat Nov 28 16:45:49 2009 vincent ricard
*/

void		my_putstr(char *str)
{
  int		i;

  i = 0;
  while (str[i] != '\0')
    {
      my_putchar(str[i]);
      i = i + 1;
    }
}
