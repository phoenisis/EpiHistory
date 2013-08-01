/*
** xfunction.c for  in /home/pidoux_q/epikong/etape_1
**
** Made by quentin pidoux
** Login   <pidoux_q@epitech.net>
**
** Started on  Sat Mar  3 13:58:44 2012 quentin pidoux
** Last update Sat Mar  3 13:58:45 2012 quentin pidoux
*/

#include	<stdio.h>
#include	<unistd.h>
#include	<stdlib.h>

void		xwrite(int fd, char* str, int nb_char)
{
  if ((write(fd, str, nb_char)) != nb_char)
    exit(EXIT_FAILURE);
}

void		xfprintf(FILE *stream, const char *format)
{
  if ((fprintf(stream, format) == -1))
    {
      xwrite(2, "error: fprintf\n", 15);
      exit(EXIT_FAILURE);
    }
}

void		xusleep(useconds_t usec)
{
  if ((usleep(usec)) == -1)
    xwrite(2, "error: usleep\n", 14);
}

void		xsleep(unsigned int sec)
{
  if ((sleep(sec)) > 0)
    xwrite(2, "error: sleep\n", 13);
}
