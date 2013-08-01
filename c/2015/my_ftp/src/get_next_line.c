#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <stdio.h>
#include "../include/get_next_line.h"

int		my_strlen(char *str)
{
  int		i;

  i = 0;
  while (str[i] != '\0')
    i++;
  return (i);
}

char		*my_memset(char *str, int size)
{
  int		i;

  i = 0;
  while (i < size)
    str[i++] = '\0';
  return (str);
}


void		*xmalloc(int size)
{
  char		*str;
  
  str = malloc(sizeof(*str) * size);
  if (str == NULL)
    {
      write(STDERR_FILENO, "malloc is failed\n", 18);
      exit (EXIT_FAILURE);
    }
  return (str);
}

int		xread(int fd, void *buf, int nbytes)
{
  int		nb_read;

  if ((nb_read = read(fd, buf, nbytes)) == -1)
    {
      write(STDERR_FILENO, strerror(errno), my_strlen(strerror(errno)));
      write(STDERR_FILENO, "\n", 1);
      exit(EXIT_FAILURE);
    }
  return (nb_read);
}

char		*get_next_line(int fd)
{
  static int	i = 1;
  int		j = 0;
  char		*rez;
  static char   buff[BUF_SIZE];
  int		nb_read = 1;
  
  rez = NULL;
  if (i >= nb_read)
    {
      i = 0;
      nb_read  = xread(fd, buff, BUF_SIZE);
    }
  if (nb_read != 0)
    {
      rez = xmalloc(sizeof(*rez) * BUF_SIZE);
      my_memset(rez, BUF_SIZE);
      while (buff[i] != '\n' && i <= BUF_SIZE && buff[i] != '\0')
	rez[j++] = buff[i++];
      while (buff[i++])
	;
    }
  return (rez);
}
