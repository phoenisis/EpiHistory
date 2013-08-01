/*
** my_strcat.c for strcat in /u/all/pidoux_q/cu/rendu/piscine/Jour_07
** 
** Made by quentin pidoux
** Login   <pidoux_q@epitech.net>
** 
** Started on  Wed Oct 13 21:45:51 2010 quentin pidoux
** Last update Wed Oct 13 21:45:53 2010 quentin pidoux
*/

char		*my_strcat(char *dest, char *src)
{
  my_strcpy((dest + my_strlen(dest)), src);
  return (dest);
}

