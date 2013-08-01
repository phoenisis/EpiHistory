/*
** signal.c for  in /home/pidoux_q/
** 
** Made by quentin pidoux
** Login   <pidoux_q@epitech.net>
** 
** Started on  Fri Nov 19 11:34:27 2010 quentin pidoux
** Last update Fri Nov 19 11:35:09 2010 quentin pidoux
*/

#include <signal.h>

void		my_putchar(char c)
{
  write(1, &c, 1);
}

void		my_putstr(char *str)
{
  while (*str)
    {
      my_putchar(*str);
      *str++;
    }
}

void	sigint()
{
  my_putstr("SIGINT\n");
}

int	main()
{
  signal(SIGINT, sigint);
  while (1)
    pause();
}
