/*
** func.c for  in /u/all/pidoux_q/cu/rendu/c/my_ls
** 
** Made by quentin pidoux
** Login   <pidoux_q@epitech.net>
** 
** Started on  Sun Nov  7 15:15:29 2010 quentin pidoux
** Last update Sun Nov  7 15:15:31 2010 quentin pidoux
*/

#include "my_ls.h"
#include <unistd.h>

int		my_putchar(char c)
{
  return (write(1, &c, 1));
}

int		my_strlen(char *str)
{
  int		i;
  
  i = 0;
  while (str[i] != 0)
    i++;
  return (i);
}

int		my_putstr(char *str)
{
  return (write(1, str, my_strlen(str)));
}

int		my_strcmp(char *s1, char *s2)
{
  int		i;
  int		a;
  
  a = 0;
  i = 0;
  while (s1[i] != '\0')
    {
      if (s1[a] == s2[i])
        {
          a++;
        }
      i++;
    }
  if ((a == my_strlen(s2)) && (a == my_strlen(s1)))
    {
      return (0);
    }
  if ((a != my_strlen(s2)) && (a != my_strlen(s1)))
    {
      return (1);
    }
  return (0);
}  

int		my_put_nbr(int i)
{
  if (i < 0)
    {
      my_putchar('-');
      i = -i;
    }
  if (i > 9)
    my_put_nbr(i / 10);
  return (my_putchar('0' + i % 10));
}
