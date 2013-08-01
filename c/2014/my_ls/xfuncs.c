/*
** xfuncs.c for  in /u/all/pidoux_q/cu/rendu/c/my_ls
**
** Made by quentin pidoux
** Login   <pidoux_q@epitech.net>
**
** Started on  Sun Nov  7 15:16:35 2010 quentin pidoux
** Last update Fri Apr 20 18:04:39 2012 quentin pidoux
*/

#include	<stdlib.h>
#include	<sys/types.h>
#include	<dirent.h>
#include	<unistd.h>
#include	<errno.h>
#include	"xfuncs.h"
#include	"my_ls.h"

DIR		*xopendir(const char *name)
{
  DIR		*d;

  if ((d = opendir(name)) ==  NULL)
    {
      xwrite(2, OPENDIR_FAILED, 16);
      exit(EXIT_FAILURE);
    }
  return (d);
}

int		xclosedir(DIR *dirp)
{
  int		status;

  if ((status = closedir(dirp)) == -1)
    {
      xwrite(STDERR_FILENO, CLOSEDIR_FAILED, 16);
      exit(EXIT_FAILURE);
    }
  return (status);
}

int		xwrite(int d, const void *buf, size_t nbytes)
{
  int		status;

  if ((status = write(d, buf, nbytes)) == -1)
    {
      write(STDERR_FILENO, WRITE_FAILED, 14);
      exit(EXIT_FAILURE);
    }
  return (status);
}

struct dirent	*xreaddir(DIR *dirp)
{
  struct dirent	*read;

  read = readdir(dirp);
  if ((read == NULL) && (errno == -1))
    {
      xwrite(STDERR_FILENO, READDIR_FAILED, 16);
      exit(EXIT_FAILURE);
    }
  return (read);
}

void		*xmalloc(size_t size)
{
  void		*status;

  status = malloc(size);
  if (status == NULL)
    {
      xwrite(STDERR_FILENO, MALLOC_FAILED, 15);
      exit(EXIT_FAILURE);
    }
   return (status);
}


