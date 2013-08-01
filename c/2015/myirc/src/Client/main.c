/*
** main.c for  in /home/pidoux_q/Dropbox/AFS/rendu/c/2015/myirc-2015-2014s-pidoux_q/src/Client
**
** Made by quentin pidoux
** Login   <pidoux_q@epitech.net>
**
** Started on  Fri Apr 20 11:46:35 2012 quentin pidoux
** Last update Fri Apr 20 18:01:13 2012 quentin pidoux
*/

#include "../../inc/client.h"

int		main(int ac, char **av)
{
  if (ac == 3)
    client(av[1], atoi(av[2]));
  else
    puts("Usage: ./client machine port");
  return (0);
}
