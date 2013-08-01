/*
** lib_base.c for lib_base in /u/all/pidoux_q/cu/rendu/c/minitalk
** 
** Made by quentin pidoux
** Login   <pidoux_q@epitech.net>
** 
** Started on  Tue Mar  9 14:45:50 2010 quentin pidoux
** Last update Tue Mar  9 14:50:49 2010 quentin pidoux
*/

#include <stdlib.h>

char		*lib_base(int base_len)
{
  char		*str;

  str = malloc(base_len * sizeof (str));
  if (malloc == 0)
    exit(EXIT_FAILURE);
  str = my_strcpy(str, "01", (base_len -l));

  return (str);
}
