/*
** Worker.c for worker in /home/pidoux_q/rendu/cpp/d04/ex_0
** 
** Made by pidoux_q
** Login   <pidoux_q@epitech.net>
** 
** Started on  Fri Jan  7 09:59:52 2011 pidoux_q
** Last update Fri Jan  7 13:57:42 2011 pidoux_q
*/

#include "Worker.h"

void DestroyWorker(Worker* this)
{
  this->stamina = 100;

  if (this->name)
    free(this->name);
  else 
    this->name = NULL;
}

int getStamina(Worker* this)
{
  return (this->stamina);
}

char const* getName(Worker* this)
{
  return (this->name);
}

int breakStone(Worker* this)
{
  if (this->stamina > 10)
    {
      this->stamina = this->stamina - 10;
      printf("Ahhh ... Ahhh ... Ahhh!!\n");
      return (10);
    }
  else 
    return (-1);
}

int cutPotatoes(Worker* this)
{
  if (this->stamina > 5)
    {
      this->stamina = this->stamina - 5;
      printf("One ... two ... three ... God Damn it!\n");
      return (5);
    }
  else 
    return (-1);
}

int cleanFloor(Worker* this)
{
  if (this->stamina > 3)
    {
      this->stamina = this->stamina - 3;
      printf("Pig you!\n");
      return (3);
    }
  else 
    return (-1);
}

void learn_task(Worker* this, char const* name_task, --Un Pt--)
{
  this->name_task = strdup(name_task);
}

int do_task(Worker* this, char const* name_task)
{
}

void InitWorker(Worker* this, char const* name)
{
  this->stamina = 100;
  if (name == NULL)
    this->name = NULL;
  else
    this->name = strdup(name);
  
  this->getStamina = &getStamina;
  this->getName = &getName;
  this->breakStone = &breakStone;
  this->cutPotatoes = &cutPotatoes;
  this->cleanFloor = &cleanFloor;
}
