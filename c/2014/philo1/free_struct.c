/*
//  free_struct.c
//  Philo1
//
//  Created by quentin PIDOUX on 13/03/12.
//  Copyright (c) 2012 EPITECH. All rights reserved.
*/

#include <pthread.h>
#include <stdlib.h>
#include "philosophe.h"

void	free_baguette(baguette *b)
{
  pthread_mutex_destroy(b->mutex);
  free(b->mutex);
  free(b);
}

void	free_philosophe(philosophe *p)
{
  free(p->thread);
  free(p);
}
