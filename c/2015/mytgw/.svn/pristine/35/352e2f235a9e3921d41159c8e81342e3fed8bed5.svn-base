/*
** xFunc.c for  in /home/pidoux_q/Dropbox/AFS/rendu/c/2015/psu_mytgw-2015-pidoux_q
**
** Made by quentin pidoux
** Login   <pidoux_q@epitech.net>
**
** Started on  Tue Jul 24 16:27:25 2012 quentin pidoux
** Last update Tue Jul 24 16:27:26 2012 quentin pidoux
*/

#include <unistd.h>
#include <stdlib.h>
#include "../inc/xFunc.h"

size_t		xread(int fd, void *buf, size_t count)
{
    int 	ret;

    ret = read(fd, buf, count);
    if (ret == -1)
    {
        write(STDERR_FILENO, READ_FAILED, 12);
        exit (EXIT_FAILURE);
    }
    return (ret);
}

int               xwrite(int d, const void *buf, size_t nbytes)
{
  int        status;

  if ((status = write(d, buf, nbytes)) == -1)
    {
      write(STDERR_FILENO, WRITE_FAILED, 14);
      exit(EXIT_FAILURE);
    }
  return (status);
}

void		*xmalloc(size_t size)
{
  void		*status;

  status = malloc(size);
  if (status == NULL)
    {
      write(2, MALLOC_FAILED, 14);
      exit(EXIT_FAILURE);
    }
   return (status);
}
