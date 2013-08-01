/*
** my_ls.h for  in /u/all/pidoux_q/cu/rendu/c/my_ls
** 
** Made by quentin pidoux
** Login   <pidoux_q@epitech.net>
** 
** Started on  Sun Nov  7 15:16:19 2010 quentin pidoux
** Last update Sun Nov  7 21:49:22 2010 quentin pidoux
*/

# ifndef		__MY_LS_H__
# define		__MY_LS_H__


void			my_ls();
void			my_ls_a();
int			my_ls_root(char *str);
void			my_ls_directory(char *str);
void			first(char **av);
void			second(char **av);

int		        main(int ac, char **av);

int			my_putchar(char c);
int			my_strcmp(char *s1, char *s2);
int			my_putstr(char *str);
int			my_put_nbr(int i);

# endif			/* __MY_LS_H__ */
