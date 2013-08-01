/*
** xfunction.c for Epikong in /afs/epitech.net/users/all/pidoux_q/public/epikong
** 
** Made by sevan hubert
** Login   <hubert_s@epitech.net>
** 
** Started on  Sat Mar 26 12:39:20 2011 sevan hubert
** Last update Sat Mar 26 18:53:15 2011 sevan hubert
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

void	*xmalloc(int x)
{
  void	*p;

  p = malloc(x);
  if (p == NULL)
    {
      printf("malloc error : out of memory\n");
      exit(EXIT_FAILURE);
    }
  return (p);
}

int	xread(int fd, void *buf, size_t count)
{
  int	nb_read;

  if ((nb_read = read(fd, buf, count)) == -1)
    {
      printf("Error: Can't read\n");
      exit(EXIT_FAILURE);
    }
  return (nb_read);
}
