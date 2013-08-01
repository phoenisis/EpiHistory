/*
** symtab.c for  in /home/bonnet_b//projets/nm_obj_dump/nm
** 
** Made by arnaud bonnet-de-larbogne
** Login   <bonnet_b@epitech.net>
** 
** Started on  Sun Mar 13 18:59:53 2011 arnaud bonnet-de-larbogne
** Last update Sun Mar 13 19:59:22 2011 arnaud bonnet-de-larbogne
*/

#include <stdio.h>
#include <stddef.h>
#include <string.h>
#include <fcntl.h>
#include <elf.h>
#include <sys/mman.h>
#include <stdlib.h>
#include "my_nm.h"

Elf64_Shdr	*find_symtab(Elf64_Shdr *shdr, Elf64_Ehdr *ehdr, char *data)
{
  int		i;

  (void)data;
  i = 0;
  while (i < ehdr->e_shnum)
    {
      if (shdr[i].sh_type == SHT_SYMTAB)
	{
	  return &shdr[i];
	}
      i++;
    }
  return (NULL);
}

void *xmalloc(size_t size)
{
  char *ptr;

  ptr = malloc(size);
  if (ptr == NULL)
    {
      printf("Critical Error, memory allocation failed.\n");
      exit(EXIT_FAILURE);
    }
  return (ptr);
}

symbol_list	*add_symbol_elem(symbol_list **head)
{
  symbol_list	*head_symb;

  if (head[0] == NULL)
    {
      head[0] = xmalloc(sizeof(symbol_list));
      head[0]->ptr = xmalloc(sizeof(symbol_info));
      head[0]->next = NULL;
      return (head[0]);
    }
  else
    {
      head_symb = head[0];
      while (head_symb->next != NULL)
	{
	  head_symb = head_symb->next;
	}
      head_symb->next = xmalloc(sizeof(symbol_list));
      head_symb->next->ptr = xmalloc(sizeof(symbol_info));
      head_symb->next->next = NULL;
      return (head_symb->next);
    }
}

void		display_symbol(symbol_list *head)
{
  if (head->ptr->ptr_sym->st_value != 0)
    printf("%08x %s\n", (unsigned int)(head->ptr->ptr_sym->st_value),
	   head->ptr->name);
  else
    printf("%8c %s\n", ' ', head->ptr->name);
}

void		sort_list_strcmp(symbol_list *pivot, symbol_info **temp,
				 symbol_list *test)
{
  if (strcmp(pivot->ptr->name, test->ptr->name) > 0)
    {
      temp[0] = pivot->ptr;
      pivot->ptr = test->ptr;
      test->ptr = temp[0];
    }
}
