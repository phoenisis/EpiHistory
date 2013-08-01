/*
** my_nm.h for  in /home/bonnet_b//projets/nm_obj_dump/nm
** 
** Made by arnaud bonnet-de-larbogne
** Login   <bonnet_b@epitech.net>
** 
** Started on  Sun Mar 13 18:50:13 2011 arnaud bonnet-de-larbogne
** Last update Sun Mar 13 18:54:03 2011 arnaud bonnet-de-larbogne
*/

#ifndef _MY_NM_
#define _MY_NM_

struct		s_nm_struct
{
  int		fd;
  void		*data;
  Elf64_Ehdr	*elf;
  Elf64_Shdr	*shdr;
  Elf64_Shdr	*strtab;
  Elf64_Shdr	*symtab;
  char		*arg;
};

typedef struct		_symbol_info_
{
  char			*name;
  Elf64_Sym		*ptr_sym;
}			symbol_info;

typedef struct		_symbol_list_
{
  struct _symbol_list_	*next;
  symbol_info		*ptr;
}			symbol_list;

Elf64_Shdr	*find_symtab(Elf64_Shdr *shdr, Elf64_Ehdr *ehdr, char *data);
void		*xmalloc(size_t size);
symbol_list	*add_symbol_elem(symbol_list **head);
void		display_symbol(symbol_list *head);
void		sort_list_strcmp(symbol_list *pivot, symbol_info **temp,
				 symbol_list *test);
void		sort_list_and_display(symbol_list *head);
void		free_list(symbol_list *head);
void		display_symbols(Elf64_Shdr *symtab,
				Elf64_Shdr *strtab, char *data);
int		xopen(const char *path, int flags);
off_t		xlseek(int fd, off_t offset, int when);
void		loop_main_nm(struct s_nm_struct *a);

#endif /*_MY_NM_*/
