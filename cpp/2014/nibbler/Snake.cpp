//
// Snake.cpp for Snake in /home/hubert_s//nibbler-2014-pidoux_q
// 
// Made by sevan hubert
// Login   <hubert_s@epitech.net>
// 
// Started on  Mon Mar  7 12:56:40 2011 sevan hubert
// Last update Tue Mar  8 18:45:40 2011 sevan hubert
//

#include <cstdlib>
#include "Snake.hh"

Snake::Snake(int x, int y)
{
  this->length = 4;
  this->posx = x;
  this->posy = y;
  this->next = new Snake(x, y - 1, 3);
}

Snake::Snake(int x, int y, int len)
{
  this->length = len;
  this->posx = x;
  this->posy = y;
  if (len > 1)
    this->next = new Snake(x, y - 1, len - 1);
  else
    this->next = NULL;
}

Snake::~Snake()
{}

int	Snake::getPosX() const
{
  return this->posx;
}

int	Snake::getPosY() const
{
  return this->posy;
}

int	Snake::getLength() const
{
  return this->length;
}

Snake	*Snake::getNext() const
{
  return this->next;
}

void	Snake::setPosX(int x)
{
  this->posx = x;
}

void	Snake::setPosY(int y)
{
  this->posy = y;
}

void	Snake::setNext(Snake *tail)
{
  this->next = tail;
}

void	Snake::move_tail(int x, int y)
{
  if (this->next != NULL)
    this->next->move_tail(this->posx, this->posy);
  this->posx = x;
  this->posy = y;
}
