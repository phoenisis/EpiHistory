/*
** main.c for  in /home/bonnet_b//projets/nm_obj_dump/nm
** 
** Made by arnaud bonnet-de-larbogne
** Login   <bonnet_b@epitech.net>
** 
** Started on  Sun Mar 13 18:58:08 2011 arnaud bonnet-de-larbogne
** Last update Sun Mar 13 19:02:36 2011 arnaud bonnet-de-larbogne
*/

#include <stdio.h>
#include <stddef.h>
#include <string.h>
#include <fcntl.h>
#include <elf.h>
#include <sys/mman.h>
#include <stdlib.h>
#include "my_nm.h"

int			main(int argc, char *argv[])
{
  struct s_nm_struct	a;
  int			i;

  i = 1;
  do
    {
      if (argc < 2)
	a.arg = "./a.out";
      else
	a.arg = argv[i];
      loop_main_nm(&a);
      i++;
    } while (i < argc);
  return (0);
}
