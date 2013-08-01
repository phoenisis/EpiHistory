/*
** mapp.h for  in /home/pidoux_q/Dropbox/AFS/rendu/c/2015/zappy-2015-2014s-herve_a/server
**
** Made by quentin pidoux
** Login   <pidoux_q@epitech.net>
**
** Started on  Sun Jul 15 22:34:24 2012 quentin pidoux
** Last update Sun Jul 15 22:34:25 2012 quentin pidoux
*/

#ifndef		_MAP_H_
#define		_MAP_H_

#include "main_zappy.h"

typedef struct	s_mapp
{
  int		linemate;
  int		deraumere;
  int		sibur;
  int		mendiane;
  int		phiras;
  int		thystame;
  int		food;
}		t_mapp;

struct s_mapp	**generate_mapp(t_create_world *args);
void		generate_obj(t_mapp *mapp);

#endif		/* !_MAP_H_ */
