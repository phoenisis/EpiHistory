/*
** sort_list_and_display.c for  in /home/bonnet_b//projets/nm_obj_dump/nm
** 
** Made by arnaud bonnet-de-larbogne
** Login   <bonnet_b@epitech.net>
** 
** Started on  Sun Mar 13 19:00:49 2011 arnaud bonnet-de-larbogne
** Last update Sun Mar 13 19:56:12 2011 arnaud bonnet-de-larbogne
*/

#include <stdio.h>
#include <stddef.h>
#include <string.h>
#include <fcntl.h>
#include <elf.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include "my_nm.h"

void		sort_list_and_display(symbol_list *head)
{
  symbol_list	*pivot;
  symbol_list	*test;
  symbol_info	*temp;

  pivot = head;
  test = head;
  while (pivot != NULL)
    {
      test = pivot;
      while (test != NULL)
	{
	  sort_list_strcmp(pivot, &temp, test);
	  test = test->next;
	}
      pivot = pivot->next;
    }
  while (head != NULL)
    {
      display_symbol(head);
      head = head->next;
    }
}

void		free_list(symbol_list *head)
{
  if (head->next != NULL)
    free_list(head->next);
  free(head->ptr);
  free(head);
}

void		display_symbols(Elf64_Shdr *symtab,
				Elf64_Shdr *strtab, char *data)
{
  Elf64_Sym	*ptr_sym;
  unsigned int	size;
  symbol_list	*head;
  symbol_list	*tail;

  size = 0;
  head = NULL;
  tail = NULL;
  ptr_sym = (Elf64_Sym *)(((char*)(symtab->sh_offset)) + (int)data);
  while (size < symtab->sh_size)
    {
      if (ELF64_ST_TYPE(ptr_sym->st_info) != STT_FILE
	  && ELF64_ST_TYPE(ptr_sym->st_info) != STT_SECTION
	  && ptr_sym->st_name != 0)
	{
	  tail = add_symbol_elem(&head);
	  tail->ptr->name = &(data[strtab->sh_offset]);
	  tail->ptr->name = &(tail->ptr->name[ptr_sym->st_name]);
	  tail->ptr->ptr_sym = ptr_sym;
	}
      size += sizeof(Elf64_Sym);
      ptr_sym++;
    }
  sort_list_and_display(head);
  free_list(head);
}

int xopen(const char *path, int flags)
{
  int val;

  val = open(path, flags);
  if (val == -1)
    {
      printf("No such file or directory : %s\n", path);
      return (-1);
    }
  return (val);
}

off_t xlseek(int fd, off_t offset, int when)
{
  off_t val;

  val = lseek(fd, offset, when);
  if (val == ((off_t)-1))
    {
      printf("Critical Error, lseek failed.\n");
      exit(EXIT_FAILURE);
    }
  return (val);
}
