/*
** usualFuncs.c for  in /afs/epitech.net/users/all/pidoux_q/public/epikong/Partie1
** 
** Made by sevan hubert
** Login   <hubert_s@epitech.net>
** 
** Started on  Sat Mar 26 18:41:32 2011 sevan hubert
** Last update Sat Mar 26 18:43:34 2011 sevan hubert
*/

#include <stdlib.h>

char            *my_strncpy(char *str, int i, int pos)
{
  int           j;
  char          *s3;

  j = 0;
  s3 = malloc((i + 1) * sizeof(*s3));
  while (j != i)
    {
      s3[j] = str[pos + j];
      ++j;
    }
  s3[j] = '\0';
  return (s3);
}

