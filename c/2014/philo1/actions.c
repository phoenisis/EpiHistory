/*
//  action.c
//  Philo1
//
//  Created by quentin PIDOUX on 13/03/12.
//  Copyright (c) 2012 EPITECH. All rights reserved.
*/

#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

#include "philosophe.h"

void	*eat_rice(void *pt)
{
  philosophe *this = (philosophe*)pt;
  printf("Le philosophe %d constate qu'il reste %d part de riz\n",
	 this->id, this->quantity[0]);
  this->quantity[0] -= 1;
  printf("Le philosophe %d mange.\n\n", this->id);
  sleep(1);
  pthread_mutex_unlock(this->left->mutex);
  pthread_mutex_unlock(this->right->mutex);
  this->if_right = 0;
  this->if_left = 0;
  this->quantity_eat += 1;
  printf("Le philosophe %d a fini de manger et part se reposer.\n",
	 this->id);
  sleep(1);
  if (this->id % 2)
    take_right(this);
  else
    take_left(this);
  return (NULL);
}

void	*take_left(void *pt)
{
  philosophe *this = (philosophe*)pt;

  if (this->quantity[0] <= 0){
      printf("\nLe philosophe %d arrete de manger.\n", this->id);
      printf("Il a manger %d part de riz.\n", this->quantity_eat);
      return (NULL);
    }
  pthread_mutex_lock(this->left->mutex);
  this->if_left = 1;
  printf("Le philosophe %d prend la baguette a sa gauche.\n", this->id);
  if (this->if_right)
    eat_rice(this);
  else
    take_right(this);
  return (NULL);
}

void	*take_right(void *pt)
{
  philosophe *this = (philosophe*)pt;

  if (this->quantity[0] <= 0){
      printf("\nLe philosophe %d arrete de manger.\n", this->id);
      printf("Il a manger %d part de riz.\n", this->quantity_eat);
      return (NULL);
    }
  pthread_mutex_lock(this->right->mutex);
  this->if_right = 1;
  printf("Le philosophe %d prend la baguette a sa droite.\n", this->id);
  if (this->if_left)
    eat_rice(this);
  else
    take_left(this);
  return (NULL);
}

