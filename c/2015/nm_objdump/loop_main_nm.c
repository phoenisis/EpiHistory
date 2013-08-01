/*
** loop_main_nm.c for  in /home/bonnet_b//projets/nm_obj_dump/nm
** 
** Made by arnaud bonnet-de-larbogne
** Login   <bonnet_b@epitech.net>
** 
** Started on  Sun Mar 13 19:02:08 2011 arnaud bonnet-de-larbogne
** Last update Sun Mar 13 19:14:07 2011 arnaud bonnet-de-larbogne
*/

#include <stdio.h>
#include <stddef.h>
#include <string.h>
#include <fcntl.h>
#include <elf.h>
#include <sys/mman.h>
#include <stdlib.h>
#include "my_nm.h"

void		loop_main_nm(struct s_nm_struct *a)
{
  unsigned long	size;

  a->fd = xopen(a->arg, O_RDONLY);
  if (a->fd == -1)
    return;
  size = xlseek(a->fd, 0, SEEK_END);
  a->data = mmap(NULL, size,
		 PROT_READ, MAP_SHARED, a->fd, 0);
  if (a->data == ((void *)-1))
    {
      printf("Error, can't map file %s in memory\n", a->arg);
      return;
    }
  a->elf = (Elf64_Ehdr *)(a->data);
  a->shdr = (Elf64_Shdr *)((char *)(a->data) + (a->elf->e_shoff));
  a->symtab = find_symtab(a->shdr, a->elf, a->data);
  a->strtab = &((a->shdr)[a->symtab->sh_link]);
  printf("\n%s:\n", a->arg);
  display_symbols(a->symtab, a->strtab, a->data);
  if (munmap(a->data, size) == -1)
    {
      printf("Critical error, can't unmap file %s from memory, abording.\n",
	     a->arg);
      exit(EXIT_FAILURE);
    }
}
