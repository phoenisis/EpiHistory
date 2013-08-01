/*
** Worker.h for Worker in /home/pidoux_q/rendu/cpp/d04/ex_0
** 
** Made by pidoux_q
** Login   <pidoux_q@epitech.net>
** 
** Started on  Fri Jan  7 10:14:48 2011 pidoux_q
** Last update Fri Jan  7 15:03:01 2011 pidoux_q
*/

#ifndef T_WORKER_H_
#define T_WORKER_H_
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct	T_Work
{
  char * name;
  int stamina;
  char * name_task;

  int (*getStamina)(struct T_Work* this);
  char const* (*getName)(struct T_Work* this);
  int (*breakStone)(struct T_Work* this);
  int (*cutPotatoes)(struct T_Work* this);
  int (*cleanFloor)(struct T_Work* this);
  void (*learn_task)(struct Worker* this, char const* name_task, --Un Pt--);
  int (*do_task)(struct Worker* this, char const* name_task);

} Worker;

void InitWorker(Worker* this, char const* name);
void DestroyWorker(Worker* this);

int getStamina(Worker* this);
char const* getName(Worker* this);
int breakStone(Worker* this);
int cutPotatoes(Worker* this);
int cleanFloor(Worker* this);

void learn_task(Worker* this, char const* name_task, --Un Pt--);
int do_task(Worker* this, char const* name_task);

#endif 
