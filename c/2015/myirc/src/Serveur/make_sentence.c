/*
** make_sentence.c for  in /home/pidoux_q/Dropbox/AFS/rendu/c/2015/myirc-2015-2014s-pidoux_q/src/Serveur
**
** Made by quentin pidoux
** Login   <pidoux_q@epitech.net>
**
** Started on  Fri Apr 20 11:47:12 2012 quentin pidoux
** Last update Fri Apr 20 11:47:13 2012 quentin pidoux
*/

#include "../../inc/serveur.h"

char		*make_sentence(char *msg, char *nick, char *buff)
{
  strcat(msg, nick);
  strcat(msg, ": ");
  strcat(msg, buff);
  strcat(msg, "\n");
  return (msg);
}

void		write_msg(t_list **list, char *msg)
{
  t_list	*tmp;
  int		i;

  tmp = *list;
  while (tmp)
    {
      i = write(tmp->value, msg, strlen(msg));
      if (i <= 0)
	kill_client(list, tmp->value);
      tmp = tmp->next;
    }
}
