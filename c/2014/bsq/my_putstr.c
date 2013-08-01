/*
** my_putstr.c for putstr in /u/all/pidoux_q/cu/rendu/c/bsq
** 
** Made by quentin pidoux
** Login   <pidoux_q@epitech.net>
** 
** Started on  Thu Nov 12 13:13:21 2009 quentin pidoux
** Last update Thu Nov 12 13:13:28 2009 quentin pidoux
*/

void            my_putstr(char *s)
{
  int i;

  i = 0;
  while(s[i] != '\0')
    {
      my_putchar(s[i]);
      i = i + 1;
    }
}
