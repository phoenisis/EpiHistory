/*
** check_msg.c for  in /home/pidoux_q/Dropbox/AFS/rendu/c/2015/myirc-2015-2014s-pidoux_q/src/Serveur
**
** Made by quentin pidoux
** Login   <pidoux_q@epitech.net>
**
** Started on  Fri Apr 20 11:47:02 2012 quentin pidoux
** Last update Fri Apr 20 15:52:10 2012 quentin pidoux
*/

#include "../../inc/serveur.h"

void		del_maillon(t_list **front_ptr, unsigned int position)
{
  t_list	*save;
  t_list	*list;
  unsigned int	i;

  i = 0;
  save = *front_ptr;
  if (*front_ptr == NULL)
    return ;
  if (position == 0)
    {
      check_pos(front_ptr, save);
      return ;
    }
  while (i < position && (*front_ptr)->next != NULL)
    {
      list = *front_ptr;
      *front_ptr = (*front_ptr)->next;
      i++;
    }
  list->next = (*front_ptr)->next;
  free((*front_ptr)->nick);
  free(*front_ptr);
  *front_ptr = save;
}

void		kill_client(t_list **list, int cs1)
{
  t_list	*tmp;
  char		nick[1024];
  unsigned int	i;

  i = 0;
  tmp = *list;
  while (tmp->value != cs1 && tmp->next != NULL)
    {
      i++;
      tmp = tmp->next;
    }
  if (tmp->value == cs1)
    {
      memset(nick, '\0', 1024);
      strcat(nick, tmp->nick);
      strcat(nick, " is disconnected\n");
      close(tmp->value);
      del_maillon(list, i);
      write_msg(list, nick);
    }
}

static void	change_nick(t_list **list, int cs1, char *newnick)
{
  t_list	*tmp;
  char		result[4096];

  tmp = *list;
  while (tmp && tmp->value != cs1)
    tmp = tmp->next;
  if (tmp)
    {
      sprintf(result, "%s is now know as : %s", tmp->nick, newnick);
      write_msg(list, result);
      free(tmp->nick);
      tmp->nick = strdup(newnick);
    }
}

static void	aff_users(t_list **list, int cs1)
{
  int		i;
  t_list	*tmp;

  tmp = *list;
  i = write(cs1, "Users connected are:\n", 21);
  if (i <= 0)
    kill_client(list, cs1);
  while (tmp)
    {
      i = write(cs1, tmp->nick, strlen(tmp->nick));
      if (i <= 0)
	kill_client(list, cs1);
      write(cs1, "\n", 1);
      if (i <= 0)
	kill_client(list, cs1);
      tmp = tmp->next;
    }
}

int		check_msg(char *str, t_list **list, int cs1, char *nick)
{
  if (strcmp(str, "/part") == 0)
    {
      kill_client(list, cs1);
      return (1);
    }
  else if (strncmp(str, "/nick", 5) == 0)
    {
      if (str[5] == '\0' || str[6] == '\0')
	return (0);
      change_nick(list, cs1, str + 6);
      return (1);
    }
  else if (strcmp(str, "/users") == 0)
    {
      aff_users(list, cs1);
      return (1);
    }
  else if (strncmp(str, "/msg", 4) == 0)
    {
      private_msg(list, cs1, nick, str + 5);
      return (1);
    }
  return (0);
}
