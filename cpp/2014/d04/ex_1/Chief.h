/*
** Chief.h for chef in /home/pidoux_q/rendu/cpp/d04/ex_1
** 
** Made by pidoux_q
** Login   <pidoux_q@epitech.net>
** 
** Started on  Fri Jan  7 15:43:50 2011 pidoux_q
** Last update Fri Jan  7 15:58:11 2011 pidoux_q
*/

#ifndef T_CHIEF_H_
#define T_CHIEF_H_
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct	T_Chief
{
  
} Chief;

void hireWorker(Chief* this, Worker* w);
void fireWorker(Chief* this, char const* name);
void giveOrder(Chief* this, char const* name, char const* task_name);
