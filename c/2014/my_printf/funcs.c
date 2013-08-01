/*
** usualfunct.c for  in /home/pidoux_q//my_printf
** 
** Made by quentin pidoux
** Login   <pidoux_q@epitech.net>
** 
** Started on  Mon Nov 15 12:03:47 2010 quentin pidoux
** Last update Fri Nov 19 15:50:41 2010 quentin pidoux
*/

#include "printf.h"

int		my_putchar(char c)
{
  write(1, &c, 1);
  return (1);
}

int		my_strlen(char *str)
{
  int		i = 0;

  while (str[i] != 0)
    i++;
  return (i);
}

int		my_putstr(char *str)
{
  int		c = 0;
  int		len = 0;

  if (!str)
    {
      my_putstr("(null)");
      return (6);
    }
  while (str[c] != '\0')
    {
      my_putchar(str[c]);
      c++;
      len++;
    }
  return (len);
}

char		*my_strdump(char *str)
{
  char		*str1;
  int		i = 0;

  str1 = malloc(my_strlen(str + 1) * sizeof(str1));
  while (str[i] != 0)
    {
      str1[i] = str[i];
      i++;
    }
  str1[i] = 0;
  return (str1);
}

int             my_putstroctal(char *str)
{
  int           i = 0;
  int           len = 0;

  if (!str)
    {
      my_putstr("(null)");
      return (6);
    }
  while (str[i] != 0)
    {
      if (str[i] < 32 || str[i] >= 127)
	{
	  my_putchar('\\');
	  if (str[i] <= 7)
	    len += my_putchar('0');
	  if (str[i] <= 63)
	    len += my_putchar('0');
	  len += my_put_nbr_base(str[i], "01234567", len);
	}
      else
	my_putchar(str[i]);
      len++;
      i++;
    }
  return (len);
}
