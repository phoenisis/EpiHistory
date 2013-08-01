/*
** error.c for  in /home/pidoux_q/Dropbox/AFS/rendu/c/2015/zappy-2015-2014s-herve_a/server
**
** Made by quentin pidoux
** Login   <pidoux_q@epitech.net>
**
** Started on  Sun Jul 15 22:33:11 2012 quentin pidoux
** Last update Sun Jul 15 22:33:12 2012 quentin pidoux
*/

#include "error.h"

void			handle_error(char *func, bool quit)
{
  fprintf(stderr, "%s error : %s\n", func, strerror(errno));
  if (quit)
    exit(EXIT_FAILURE);
}
