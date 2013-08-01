/*
** 1.c for lib_base in /u/all/pidoux_q/cu/public
** 
** Made by quentin pidoux
** Login   <pidoux_q@epitech.net>
** 
** Started on  Sat Nov 28 11:47:17 2009 quentin pidoux
** Last update Sat Nov 28 18:21:05 2009 vincent ricard
*/

#include <stdlib.h>

char		*lib_base(int base_len)
{
  char		*str;
  
  str = malloc(base_len * sizeof (str));
  if (malloc == 0)
    {
      my_putstr("Couldn't malloc the base !\n");
      exit(EXIT_FAILURE);
    }
  
  str = my_strncpy(str, "0123456789ABCDEF", (base_len - 1));

  return (str);
}
