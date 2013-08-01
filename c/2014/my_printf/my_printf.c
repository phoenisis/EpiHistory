/*
** my_printf.c for  in /home/pidoux_q//my_ls
** 
** Made by quentin pidoux
** Login   <pidoux_q@epitech.net>
** 
** Started on  Mon Nov 15 09:22:03 2010 quentin pidoux
** Last update Tue Nov 23 10:55:30 2010 quentin pidoux
*/

#include "printf.h"

int		my_printf(char *str, ...)
{
  va_list	args;
  int	       	d = 0;
  int	       	len = 0;

  va_start(args, str);
  while (str[d] != 0)
    {
      if (str[d] == '%')
	{
	  d++;
	  if (str[d] == '#' || str[d] == '-' || str[d] == '0')
	    d++;
	  if (str[d] == ' ' || str[d] == '+')
	    my_putchar(str[d++]);
	  len += start(str, d, args);
	  va_arg(args, int);
	  d++;
	}
      if (str[d] == 'x' && str[d - 1] == 'l')
	d++;
      my_putchar(str[d++]);
      len++;
    }
  va_end(args);
  return (len);
}
