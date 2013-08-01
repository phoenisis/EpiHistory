/*
** alum1.h for functions of alum1 in /u/all/hubert_s/cu/trucs/tests/alum1
** 
** Made by sevan hubert
** Login   <hubert_s@epitech.net>
** 
** Started on  Sun Feb 14 15:15:09 2010 sevan hubert
** Last update Sun Feb 14 18:06:32 2010 sevan hubert
*/

#ifndef ALUM1_H
# define ALUM1_H


int     define_number_line(char *str, int const line_max);
int     my_str_isnum(char const *str);
void	choose_num_sticks(int line, int *tab);
void	choose_line(int *tab);
int	*create_sticktab(char *str_line);
void	aff_sticks(int *tab, int nb_line);
int	verif_if_lose(int *tab, int nb_line);
void	rand_sticks(int line, int *tab);
void	rand_line(int *tab, int nb_line);


#endif /* MY_H */
