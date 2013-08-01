/*
** parse.h for  in /home/pidoux_q/Dropbox/AFS/rendu/c/2015/zappy-2015-2014s-herve_a/server
**
** Made by quentin pidoux
** Login   <pidoux_q@epitech.net>
**
** Started on  Sun Jul 15 22:34:29 2012 quentin pidoux
** Last update Sun Jul 15 22:58:11 2012 clement cohen
*/

#ifndef  __PARSE_H__
# define  __PARSE_H__

# include "main_zappy.h"

char		*get_value(char *str, char c);
int		parse_args1(char *str, int i, int flag,
			    char *value, t_create_world *args);
int		parse_args2(char *str, int i, int flag,
			    char *value, t_create_world *args);
int		parse_args3(char *str, int i, int flag,
			    char *value, t_create_world *args);
int 		parse_args(char *str, t_create_world *args);
char		**str_to_wordtab(char *str, char);
char		**get_teamnames(char *value, t_create_world *args);

#endif				/*!__PARSE_H__*/
