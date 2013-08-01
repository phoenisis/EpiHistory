/*
** main.c for  in /home/pidoux_q/Dropbox/AFS/rendu/c/2015/psu_mytgw-2015-pidoux_q
**
** Made by quentin pidoux
** Login   <pidoux_q@epitech.net>
**
** Started on  Tue Jul 24 16:27:15 2012 quentin pidoux
** Last update Tue Jul 24 16:27:16 2012 quentin pidoux
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#include "../inc/server.h"

int main(int ac, char **av)
{
  char          *ip;
  char          *port;
  char          *ip2;
  char          *port2;

  if (ac == 3)
    {
      ip = strtok(av[1], ":");
      port = strtok(NULL, "\0");
      ip2 = strtok(av[2], ":");
      port2 = strtok(NULL, "\0");
      my_server(ip, atoi(port), ip2, atoi(port2));
    }
  else
    printf("Usage: ./my_tgw <host_local>:<port_local> <host_dst>:<port_dst>\n");
  return (EXIT_SUCCESS);
}
