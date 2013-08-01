/*
** func_serveur.c for  in /home/pidoux_q/Dropbox/AFS/rendu/c/2015/myirc-2015-2014s-pidoux_q/src/Serveur
**
** Made by quentin pidoux
** Login   <pidoux_q@epitech.net>
**
** Started on  Fri Apr 20 11:44:58 2012 quentin pidoux
** Last update Fri Apr 20 18:10:58 2012 quentin pidoux
*/

#include "../../inc/serveur.h"
#include "../../inc/xfunc.h"

void			add_client(t_list **front_ptr, int elem, char *nick)
{
  t_list		*list;
  t_list		*save;

  if (*front_ptr == NULL)
    {
      if ((list = xmalloc(sizeof(*list))) == NULL)
	return ;
      list->next = *front_ptr;
      *front_ptr = list;
    }
  else
    {
      save = *front_ptr;
      while ((*front_ptr)->next)
	(*front_ptr) = (*front_ptr)->next;
      if ((list = xmalloc(sizeof(*list))) == NULL)
	return ;
      (*front_ptr)->next = list;
      list->next = NULL;
      *front_ptr = save;
    }
  list->value = elem;
  list->nick = strdup(nick);
}

void			send_msg(t_list **list, int cs1, char *nick)
{
  char			buff[4096];
  int			i;
  char			msg[4096];

  memset(buff, 0, 4096);
  i = read(cs1, buff, 4096);
  if (i > 0)
    {
      buff[i] = '\0';
      i = check_msg(buff, list, cs1, nick);
      if (i == 0)
	{
	  memset(msg, 0, 4096);
	  make_sentence(msg, nick, buff);
	  write_msg(list, msg);
	}
    }
  else
    kill_client(list, cs1);
}

int			recup_maxfd(t_list *list, int cs1)
{
  int			i;

  if (list == NULL)
    return (cs1);
  i = list->value;
  while (list)
    {
      if (list->value > i)
	i = list->value;
      list = list->next;
    }
  return (i);
}

void			init_fd(int sock, t_list *list, fd_set *readfds)
{
  t_list		*tmp;

  FD_SET(sock, readfds);
  tmp = list;
  while (tmp != NULL)
    {
      FD_SET(tmp->value, readfds);
      tmp = tmp->next;
    }
}

void			new_event(t_list **list, fd_set *readfds)
{
  t_list		*tmp;

  tmp = *list;
  while (tmp != NULL)
    {
      if (FD_ISSET(tmp->value, readfds))
	send_msg(list, tmp->value, tmp->nick);
      tmp = tmp->next;
    }
}
