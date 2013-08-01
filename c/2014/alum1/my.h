/*****************************************************************************/
/*                                                                           */
/*                             my.h for lib_my                               */
/*                             made by hubert_s                              */
/*                                                                           */
/*****************************************************************************/


/* All my functions.                                                         */


#ifndef MY_H
# define MY_H


int	my_strlen(char const *str);
char	*my_strdup(char const *str);
char	*my_strndup(char const *str, int n);
char	*my_strcat(char *str, char const *append);
char	*my_strncat(char *str, char const *append, int n);
char	*my_strcpy(char *dest, char const *srcs);
char	*my_strncpy(char *dest, char const *srcs, int n);
int	my_strcmp(char const *s1, char const *s2);
int	my_strncmp(char const *s1, char const *s2, int n);
char	**my_str_to_word_tab(char const *str, char const *seps);
void    my_putchar(char const c);
void	my_putstr(char const *str);
int	my_power(int const nb, int const power);
int	my_get_nbr(char const *str);
int     my_get_nbr_base(char const *str, char const *base);
void	my_putnbr(int const nbr);
int	my_count_char_in_int(int const nb);
int	my_strmem(char const *str, char const c);
void	my_printf(char *str, ...);

#endif /* MY_H                                                               */
