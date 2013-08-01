#include <stdio.h>
#include <stdlib.h>
#include "simple_list.h"

unsigned int	list_get_size(t_list list)
{
  unsigned int	len = 0;

  while (list)
    {
      list = list->next;
      len++;
    }
  return (len);
}

t_bool		list_is_empty(t_list list)
{
  if (!list)
    return (TRUE);
  return (FALSE);
}

void		list_dump(t_list list)
{
  while (list)
    {
      printf("%f\n", list->value);
      list = list->next;
    }
}

t_bool		list_add_elem_at_front(t_list *front_ptr, double elem)
{
  t_list	new;

  if (!(new = malloc(sizeof(t_list))))
    return (FALSE);
  new->value = elem;
  new->next = *front_ptr;
  *front_ptr = new;
  return (TRUE);
}

t_bool		list_add_elem_at_back(t_list *front_ptr, double elem)
{
  t_list	new;
  t_list	tmp;

  if (!(new = malloc(sizeof(t_list))))
    return (FALSE);
  new->value = elem;
  new->next = NULL;
  if (!*front_ptr)
    *front_ptr = new;
  else
    {
      tmp = *front_ptr;
      while (tmp->next)
	tmp = tmp->next;
      tmp->next = new;
    }
  return (TRUE);
}

t_bool		list_add_elem_at_position(t_list *front_ptr, double elem, unsigned int position)
{
  unsigned int	i = 0;
  t_list	new;
  t_list	prec = NULL;
  t_list	tmp;

  if (position > list_get_size(*front_ptr))
    return (FALSE);
  if (!(new = malloc(sizeof(t_list))))
    return (FALSE);
  new->value = elem;
  new->next = NULL;
  tmp = *front_ptr;
  while ((tmp) && (i < position))
    {
      i++;
      prec = tmp;
      tmp = tmp->next;
    }
  new->next = tmp;
  if (prec)
    prec->next = new;
  else
    *front_ptr = new;
  return (TRUE);
}

t_bool		list_del_elem_at_front(t_list *front_ptr)
{
  t_list	save;

  if (!*front_ptr)
    return (FALSE);
  save = (*front_ptr)->next;
  free(*front_ptr);
  *front_ptr = save;
  if (save)
    return (TRUE);
  return (FALSE);
}

t_bool		list_del_elem_at_back(t_list *front_ptr)
{
  t_list	tmp;
  t_list	prec = NULL;

  if (!*front_ptr)
    return (FALSE);
  tmp = *front_ptr;
  while (tmp->next)
    {
      prec = tmp;
      tmp = tmp->next;
    }
  free(tmp);
  if (prec)
    {
      prec->next = NULL;
      return (TRUE);
    }
  else
    *front_ptr = NULL;
  return (FALSE);
}

t_bool		list_del_elem_at_position(t_list *front_ptr, unsigned int position)
{
  unsigned int	n = 0;
  t_list	tmp = *front_ptr;
  t_list	prec = NULL;

  if ((!*front_ptr) || (position >= list_get_size(*front_ptr)))
    return (FALSE);
  while ((tmp) && (n < position))
    {
      n++;
      prec = tmp;
      tmp = tmp->next;
    }
  if (tmp)
    {
      if (prec)
	prec->next = tmp->next;
      else
	*front_ptr = tmp->next;
      free(tmp);
      if (*front_ptr)
	return (TRUE);
    }
  return (FALSE);
}

double		list_get_elem_at_front(t_list list)
{
  if (!list)
    return (0);
  return (list->value);
}

double		list_get_elem_at_back(t_list list)
{
  if (!list)
    return (0);
  while (list->next)
    list = list->next;
  return (list->value);
}

double		list_get_elem_at_position(t_list list, unsigned int position)
{
  unsigned int	n = 0;

  if (!list)
    return (0);
  while ((list) && (n < position))
    {
      n++;
      list = list->next;
    }
  if ((n == position) && (list))
    return (list->value);
  return (0);
}

t_node		*list_get_first_node_with_value(t_list list, double value)
{
  while (list)
    {
      if (list->value == value)
	return (list);
      list = list->next;
    }
  return (NULL);
}
