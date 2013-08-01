/*
** func1.c for  in /home/pidoux_q//rendu/c/my_printf
**
** Made by quentin pidoux
** Login   <pidoux_q@epitech.net>
**
** Started on  Tue Nov 16 14:01:10 2010 quentin pidoux
** Last update Tue Feb 28 15:38:26 2012 Quentin Pidoux
*/

#include "printf.h"

int		funct1(char *str, int d, va_list args, int len)
{
   char		*Hm = "0123456789abcdef";

   if (str[d] == 'd' || str[d] == 'i')
     len = my_put_nbr(va_arg(args, long long), len);
   if (str[d] == 's')
     len = my_putstr(va_arg(args, char *));
   if (str[d] == 'c')
     len = my_putchar(va_arg(args, int));
   if (str[d] == '%')
     len = my_putchar('%');
   if (str[d] == 'o')
     {
	if (str[d - 1] == '#')
	  my_putchar('0');
	len = my_put_nbr_base(va_arg(args, unsigned int), "01234567", len);
     }
   if (str[d] == 'p')
     {
	len += my_putstr("0x");
	len += my_put_nbr_base((int)va_arg(args, void*), Hm, len);
     }
   return (len);
}

int		funct2(char *str, int d, va_list args, int len)
{
   char		*Hm = "0123456789abcdef";
   char		*HM = "0123456789ABCDEF";

  if (str[d] == 'u')
     len = my_put_nbr_base(va_arg(args, unsigned int), "0123456789", len);
   if (str[d] == 'x')
     {
	if (str[d - 1] == '#')
	  len = my_putstr("0x");
	len += my_put_nbr_base(va_arg(args, unsigned int), Hm, len);
     }
   if (str[d] == 'X')
     {
	if (str[d - 1] == '#')
	  len = my_putstr("0x");
	len = my_put_nbr_base(va_arg(args, unsigned long), HM, len);
     }
   if (str[d] == 'b')
     len = my_put_nbr_base(va_arg(args, int), "01", len);
   if (str[d] == 'S')
     len = my_putstroctal(va_arg(args, char *));
}

int            start(char *str, int d, va_list args)
{
   int		len = 0;

   if (str[d] == 'd' || str[d] == 'i' || str[d] == 's' ||
       str[d] == 'c' || str[d] == '%' || str[d] == 'o' ||
      str[d] == 'p')
     len += funct1(str, d, args, len);
  else if (str[d] == 'u' || str[d] == 'x' || str[d] == 'X' ||
	   str[d] == 'b' || str[d] == 'S')
     len += funct2(str, d, args, len);
  else if (str[d++] == 'l')
    len += funct2(str, d, args, len);
  else
    {
      len += my_putchar('%');
      len += my_putchar(str[d]);
    }
  return (len);
}
