/*
** broadcast.h for broadcast in /home/cohen_d//zappy/zappy-2015-2014s-herve_a
**
** Made by clement cohen
** Login   <cohen_d@epitech.net>
**
** Started on  Sun Jul 15 22:26:09 2012 clement cohen
** Last update Sun Jul 15 22:33:25 2012 quentin pidoux
*/

#ifndef _BROADCAST_H_
#define _BROADCAST_H_

#include	"zappy_server.h"

void		broadcast(char *str, t_env *e, int fd);
void	        display_map(char *str, t_env *e, int);
void		go_forward(t_env *e, int fd);
void		go_backward(t_env *e, int fd);
void		go_left(t_env *e, int fd);
void		go_right(t_env *e, int fd);
void		prend(char *str, t_env *e, int fd);
void		prend2(char **tab, t_player *tmp, t_env *e, int fd);
void		prend3(t_env *e, int fd, t_player *tmp, char **tab);
void		jete(char *str, t_env *e, int fd);
void		jete2(char **tab, t_player *, t_env *e, int fd);
void		display_info_player(char *str, t_player *, int flag, int);
void		find_player(t_player *player, int p, int flag, int);
char            *my_itoa_buf(char *buf, size_t len, int num);
char            *itoa(int num);
int	        display_mapp(t_env *e, int);
void	        display_case(char *str, t_env *e, int );
void	        display_all_case(t_env *e, int);
void		print_info(t_mapp, t_env *, int);

#endif /* !_BROADCAST_H_*/
