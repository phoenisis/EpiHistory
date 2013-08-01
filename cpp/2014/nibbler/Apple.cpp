//
// apple.cpp for  in /home/pidoux_q/nibbler-2014-pidoux_q/test
// 
// Made by Quentin PIDOUX
// Login   <pidoux_q@epitech.net>
// 
// Started on  Wed Mar  9 16:37:20 2011 Quentin PIDOUX
// Last update Mon Mar 14 14:44:23 2011 sevan hubert
//

#include "Head.hh"
#include "Snake.hh"
#include "Apple.hh"
#include "Map.hh"

#include <cstdio>
#include <cstdlib>
#include <ctime>


Apple::Apple(Head *h, int sx, int sy)
{
  Snake *check = h;
  int x, y = 0;
  
  srand(time(NULL));
  while (check != NULL)
    {
      check = h;
      x = rand() % sx;
      y = rand() % sy;

      while (check != NULL && !(x == check->getPosX() && 
				(y == check->getPosY())))
	  check = check->getNext();
    }
  this->posx = x;
  this->posy = y;
}

Apple::~Apple()
{}

int Apple::get_posx() const
{
  return(this->posx);
}

int Apple::get_posy() const
{
  return(this->posy);
}

bool	Apple::is_eat(Head *h, Map const &M)
{
  if (h->getPosX() == this->posx && h->getPosY() == this->posy)
    {
      h->grown_up(M);
      return true;
    }
  return false;
}
