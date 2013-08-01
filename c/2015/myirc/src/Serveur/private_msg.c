/*
** private_msg.c for  in /home/pidoux_q/Dropbox/AFS/rendu/c/2015/myirc-2015-2014s-pidoux_q/src/Serveur
**
** Made by quentin pidoux
** Login   <pidoux_q@epitech.net>
**
** Started on  Fri Apr 20 11:47:20 2012 quentin pidoux
** Last update Fri Apr 20 15:51:01 2012 quentin pidoux
*/

#include "../../inc/serveur.h"

void            prepare_msg(char *nick, char *msg, int cs1, t_list **list)
{
  char		result[4096];
  int		i;

  sprintf(result, "From %s: %s", nick, msg);
  i = write(cs1, result, strlen(result));
  if (i <= 0)
    kill_client(list, cs1);
}

void		private_msg(t_list **list, int cs1, char *nick, char *str)
{
  t_list	*tmp;
  char		*name;
  char		*msg;
  char		result[4096];
  int		i;

  i = 0;
  tmp = *list;
  while (str[i] != ' ')
    i++;
  name = strndup(str, i);
  msg = strdup(str + i + 1);
  while (strcmp(tmp->nick, name) != 0 && tmp->next != NULL)
    tmp= tmp->next;
  if (strcmp(tmp->nick, name) == 0)
    {
      sprintf(result, "To %s: %s", name, msg);
      write(cs1, result, strlen(result));
      prepare_msg(nick, msg, tmp->value, list);
    }
  else
    write(cs1, "This users doesn't exist\n", 25);
}

void check_pos(t_list **front_ptr, t_list *save)
{
  save = *front_ptr;
  *front_ptr = (*front_ptr)->next;
  free(save->nick);
  free(save);
}
