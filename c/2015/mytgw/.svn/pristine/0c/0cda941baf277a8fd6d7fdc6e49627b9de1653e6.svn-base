/*
** log.c for  in /home/pidoux_q/Dropbox/AFS/rendu/c/2015/psu_mytgw-2015-pidoux_q
**
** Made by quentin pidoux
** Login   <pidoux_q@epitech.net>
**
** Started on  Tue Jul 24 17:04:30 2012 quentin pidoux
** Last update Tue Jul 24 17:46:03 2012 quentin pidoux
*/

#include <time.h>
#include <stdio.h>

#include "../inc/log.h"
#include "../inc/server.h"

void		logg(t_serv_info *serv, t_dest_info *dest)
{
  char buffer[256];
  time_t timestamp = time(NULL);

  strftime(buffer, sizeof(buffer), "%Y-%m-%d %H-%M-%S:", localtime(&timestamp));
  printf("%s%s:%d:%s:%d:BEGIN\n", buffer, serv->ip, serv->port, dest->ip, dest->port);
}
