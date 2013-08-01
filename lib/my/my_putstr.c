/*
** my_putstr.c for putstr in /u/all/pidoux_q/cu/rendu/piscine/Jour_07
** 
** Made by quentin pidoux
** Login   <pidoux_q@epitech.net>
** 
** Started on  Wed Oct 13 21:40:08 2010 quentin pidoux
** Last update Wed Oct 13 21:40:10 2010 quentin pidoux
*/

int		my_putstr(char *str)
{
  (write(1, str, my_strlen(str)));
}

