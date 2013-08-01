/*
** FruitNode.h for  in /home/pidoux_q/rendu/cpp/d15m/ex_0
** 
** Made by quentin PIDOUX
** Login   <pidoux_q@epitech.net>
** 
** Started on  Wed Jan 19 08:16:57 2011 quentin PIDOUX
** Last update Wed Jan 19 08:18:07 2011 quentin PIDOUX
*/

#ifndef _FRUITNODE_H_
#define _FRUITNODE_H_
#include <string>

typedef struct FruitNode
{
  Fruit* frut;
  FruitNode* next;
}FruitNode;

#endif
