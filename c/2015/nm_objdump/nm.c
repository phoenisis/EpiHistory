/*
** nm.c for  in /home/pidoux_q/Dropbox/AFS/rendu/c/2015/nm_objdump
**
** Made by quentin pidoux
** Login   <pidoux_q@epitech.net>
**
** Started on  Thu Mar  1 11:25:33 2012 quentin pidoux
** Last update Thu Mar  1 11:56:44 2012 quentin pidoux
*/

#include <elf.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>

int filesize(int fd)
{
  return (lseek(fd, 0, SEEK_END));
}

void print_sh_name(Elf64_Shdr *shdr, char *strtab, int shnum)
{
  int i = 0;

  while(i < shnum)
    printf("%02d: %s\n", i++, &strtab[shdr[i].sh_name]);
}

int main(int ac, char **av)
{
  void *data;
  Elf64_Ehdr *elf;
  Elf64_Shdr *shrd;
  int fd;
  char *strtab;

  if (ac == 2)
    {
      fd = open(av[1], O_RDONLY);
      data = mmap(NULL, filesize(fd), PROT_READ, MAP_SHARED, fd, 0);
      elf = (Elf64_Ehdr*)data;
      shrd = (Elf64_Shdr*)(data + elf->e_shoff);
      strtab = (char *)(data + shrd[elf->e_shstrndx].sh_offset);
      print_sh_name(shrd, strtab, elf->e_shnum);
      close(fd);
    }

  return 0;
}
