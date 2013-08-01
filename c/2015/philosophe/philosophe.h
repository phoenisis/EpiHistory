/*
** philosophe.h for  in /home/fleuro_m//work/philo
**
** Made by matthieu fleurot
** Login   <fleuro_m@epitech.net>
**
** Started on  Fri Mar 16 14:41:38 2012 matthieu fleurot
** Last update Fri Mar 16 15:10:04 2012 matthieu fleurot
*/

#ifndef		_PHILOSOPHE_H_
#define		_PHILOSOPHE_H_

#include <pthread.h>
#include <stdlib.h>

typedef short bool;

typedef struct		baguette_s
{
  bool			is_used;
  pthread_mutex_t	*mutex;
} baguette;

typedef struct		philosophe_s
{
  baguette		*right;
  baguette		*left;
  bool			if_right;
  bool			if_left;
  int			quantity_eat;
  int			*quantity;
  int			id;
  pthread_t		*thread;
} philosophe;

void	*eat_rice(void *pt);
void	*take_left(void *pt);
void	*take_right(void *pt);
void	*xmalloc(size_t size);

void	free_baguette(baguette *b);
void	free_philosophe(philosophe *p);

#endif		/*_PHILOSOPHE_H_*/
