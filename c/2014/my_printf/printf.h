/*
** printf.h for  in /home/pidoux_q//rendu/my_printf
** 
** Made by quentin pidoux
** Login   <pidoux_q@epitech.net>
** 
** Started on  Wed Nov 17 15:43:39 2010 quentin pidoux
** Last update Thu Dec  2 16:03:47 2010 quentin pidoux
*/

#ifndef __PRINTF_H__
# define __PRINTF_H__

#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>

	/* my_printf.c */
int		my_printf(char *str, ...);

	/* funcs.c */
int		my_putchar(char c);
int		my_strlen(char *str);
int		my_putstr(char *str);
char		*my_strdump(char *str);
int		my_putstroctal(char *str);

	/* my_putnbr.c */
int             my_put_nbr(int nb, int len);
int		my_put_nbr_base(unsigned long nbr, char *base, int len);

	/* func.c */
int             start(char *str, int d, va_list args);
int		funct1(char *str, int d, va_list args, int len);
int		funct2(char *str, int d, va_list args, int len);

#endif  /*!__PRINTF_H__*/
