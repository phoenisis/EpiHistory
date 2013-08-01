/*
** my.h for my in /u/all/pidoux_q/cu/rendu/include
** 
** Made by quentin pidoux
** Login   <pidoux_q@epitech.net>
** 
** Started on  Mon Oct 19 14:48:53 2009 quentin pidoux
** Last update Mon Oct 18 16:06:48 2010 quentin pidoux
*/

#ifndef		__MY_H__
#define		__MY_H__

int		my_isneg(int n);
int		my_put_nbr(int nb);
int		my_swap(int *a, int *b);
int		my_putstr(char *str);
int		my_strlen(char *str);
int		my_getnbr(char *str);
int		my_power_rec(int nb, int power);
int		my_square_root(int nb);
int		my_is_prime(int nombre);
int		my_find_prime_sup(int nb);
int		my_strcmp(char *s1, char *s2);
int		my_strncmp(char *s1, char *s2, int n);
int		my_str_isalpha(char *str);
int		my_str_isnum(char *str);
int		my_str_islower(char *str);
int		my_str_isupper(char *str);
int		my_str_isprintable(char *str);
int		my_showstr(char *str);
int		my_showmem(char *str, int size);
int		my_strlcat(char *str1, char *str2, int n);
void		my_putchar(char c);
void		my_sort_int_tab(int *tab, int size);
char		*my_strcpy(char *dest, char *src);
char		*my_strncpy(char *dest, char *src, int n);
char		*my_revstr(char *str);
char		*my_strstr(char *str, char *to_find);
char		*my_strupcase(char *str);
char		*my_strlowcase(char *str);
char		my_strcapitalize(char *str);
char		*my_strcat(char *str1, char *str2);
char		*my_strncat(char *str1, char *str2, int n);

#endif		/* __MY_H__ */
