/*
** get_next_line.c for Epikong in /afs/epitech.net/users/all/pidoux_q/public/epikong
** 
** Made by sevan hubert
** Login   <hubert_s@epitech.net>
** 
** Started on  Sat Mar 26 12:37:09 2011 sevan hubert
** Last update Sat Mar 26 18:44:58 2011 sevan hubert
*/

#include <stdlib.h>
#include <string.h>
#include "epikong.h"
#define BUFF_SIZE  300

char		*concat(char *s, char *s1)
{
  int		i;
  int		j;
  int		k;
  char		*str;

  str = malloc(((i = strlen(s)) + (j = strlen(s1)) + 1) * sizeof(*str));
  str[i + j] = '\0';
  k = 0;
  while (k != i)
    {
      str[k] = s[k];
      ++(k);
    }
  i = 0;
  while (i != j)
    {
      str[k] = s1[i];
      ++i;
      ++k;
    }
  free(s);
  free(s1);
  return (str);
}

int		my_strnlen(char *str, int pos, int *flag)
{
  int		i;

  i = 0;
  while (str[i + pos] != '\0' && str[i + pos] != '\n')
    ++i;
  if (str[i + pos] == '\n')
    *flag = 1;
  return (i);
}

void		free_buff(char **buf)
{
  if (*buf != NULL)
    free(*buf);
}

char		*init_flag_str(int *flag)
{
  char		*str;

  *flag = 0;
  str = malloc(sizeof(*str));
  str[0] = '\0';
  return (str);
}

char		*get_next_line(const int fd)
{
  static char	buf[BUFF_SIZE];
  static int	nb_read = 1, pos = 0, flag;
  char		*str;

  if (fd == 0)
    {
      nb_read = 1;
      pos = 1;
      return (NULL);
    }
  if (nb_read == 0)
    return (NULL);
  str = init_flag_str(&flag);
  while (flag == 0 && nb_read != 0)
    if (buf == NULL || pos >= nb_read)
      {
	pos = 0;
	nb_read = xread(fd, buf, BUFF_SIZE);
      }
    else
      {
	str = concat(str, my_strncpy(buf, my_strnlen(buf, pos, &flag), pos));
	pos += my_strnlen(buf, pos, &flag) + 1;
      }
  return (str);
}
