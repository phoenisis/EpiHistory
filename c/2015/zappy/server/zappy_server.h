/*
** zappy_server.h for  in /home/pidoux_q/Dropbox/AFS/rendu/c/2015/zappy-2015-2014s-herve_a/server
**
** Made by quentin pidoux
** Login   <pidoux_q@epitech.net>
**
** Started on  Sun Jul 15 22:31:34 2012 quentin pidoux
** Last update Sun Jul 15 22:31:37 2012 quentin pidoux
*/

#ifndef		ZAPPY_SERVER_H_
# define	ZAPPY_SERVER_H_

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/wait.h>
#include <sys/time.h>
#include <linux/netdevice.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <arpa/inet.h>
#include <ctype.h>
#include <netdb.h>
#include <errno.h>
#include "parse.h"
#include "error.h"
#include "main_zappy.h"
#include "mapp.h"

#define FD_FREE  	0
#define FD_CLIENT	1
#define FD_SERVER	2
#define MAX_FD		255

typedef void(*fct)();

typedef enum e_orientation
  {
    NORD,
    EST,
    SUD,
    OUEST
  }            t_orientation;

typedef struct  s_inventory
{
  int           linemate;
  int           deraumere;
  int           sibur;
  int           mendiane;
  int           phiras;
  int           thystame;
  int           food;
}               t_inventory;

typedef struct s_player
{
  t_inventory           *inventory;
  int                   life;
  int			level;
  int                   player;
  int                   posX;
  int                   posY;
  char                  *team;
  t_orientation		orientation;
  struct s_player       *nxt;
}              t_player;

typedef struct s_clients
{
  int client;
  struct s_clients *nxt;
}              t_clients;

typedef struct          s_select_loop
{
  fd_set        		fd_read;
  fd_set                        fd_write;
  struct timeval	tv;
  int                   i;
  int           fd_max;
  int           error;
}                       t_select_loop;

typedef struct s_env
{
  char	fd_type[MAX_FD];
  fct 	fct_read[MAX_FD];
  fct 	fct_write[MAX_FD];
  int 	port;
  char	*buf;
  char	*name;
  int   clientnb;
  t_clients     *guiless_client;
  t_clients		*graphic_client;
  t_create_world    *args;
  t_player      *player;
  struct tm     *time;
  t_select_loop myloop;
  t_mapp         **mapp;
}		t_env;

typedef struct s_chan
{
  char		*chanel1;
  char		*chanel2;
  char		*chanel3;
  char		*chanel4;
}	       t_chan;

int 			my_socket(int fd);
void			print_server_infos(struct sockaddr_in addr);
void		client_present(char *login, t_env *);
int            client_read(t_env *e, int fd);
int		client_write(int fd, char *buf);
void		add_client(t_env *e, int s);
void    server_read(t_env *e, int fd);
void		server_write(t_env *e, int fd);
void		       add_server(t_env *e);
void				server_loop(int port, t_create_world *);
void		make_channels(t_chan *chan);
void		stock_infos(t_env *, int);
bool            connected(int fd);
void                    handle_main_loop(t_env);
t_env                   handle_select(t_env e);
struct s_clients         *list_guiless_clients(t_env *, int fd);
struct s_clients         *list_graphic_clients(t_env *e, int fd);
struct s_player          *init_player(t_env *);
struct s_player		*remove_player(t_env *e);
struct tm       *get_time(t_env *e);
bool		check_graph(int, t_env *);

#endif		/*!ZAPPY_H_ */
