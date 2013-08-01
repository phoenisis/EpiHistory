/*
//  philosophe.h
//  Philo1
//
//  Created by quentin PIDOUX on 13/03/12.
//  Copyright (c) 2012 EPITECH. All rights reserved.
*/

#ifndef		_philosophe_h
#define   _philosophe_h

#include <pthread.h>

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

void	free_baguette(baguette *b);
void	free_philosophe(philosophe *p);

#endif /* !_philosophe_h */
