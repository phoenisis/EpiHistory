#include <unistd.h>
#include <stdlib.h>
#include "../inc/xFunc.h"

#include "xfile.h"


ssize_t		xread(int fd, void *buf, size_t count)
{
    ssize_t	ret;
    
    if (ret = read(fd, buf, count) == (-1))
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
