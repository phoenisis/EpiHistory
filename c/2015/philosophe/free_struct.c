/*
** free_struct.c for  in /home/fleuro_m//work/philo
**
** Made by matthieu fleurot
** Login   <fleuro_m@epitech.net>
**
** Started on  Fri Mar 16 14:41:12 2012 matthieu fleurot
** Last update Fri Mar 16 14:41:13 2012 matthieu fleurot
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
