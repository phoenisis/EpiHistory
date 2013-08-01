/*
**  src/Bomb.cpp
**  Bomberman
**
**  Created by Evan HERVE on 03/05/12.
**  Copyright (c) 2012 EPITECH. All rights reserved.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Bomb.hh"

Bomb::Bomb(int posX, int posY, int power) : _posX(posX), _posY(posY), _power(power)
{
  srand(time(NULL));
}

void		Bomb::generateBonus(map::map &map, int res)
{
  if (res == 0)
    map.setPos(5, this->_posX, this->_posY);
  if (res == 1)
    map.setPos(6, this->_posX, this->_posY);
  if (res == 2)
    map.setPos(7, this->_posX, this->_posY);
  if (res == 3)
    map.setPos(8, this->_posX, this->_posY);
}

void		Bomb::doExplosion(map::map &map)
{
  int		tmp = 0;
  int		tmppower = 0;
  int		res;

  tmp = this->_posX;
  tmppower = this->_power + 2;
  while (this->_posX > 0 && this->_posX <= 20 && map.getPos(this->_posX, this->_posY) && tmppower > 0)
    {
      this->_posX--;
      //afficher(_posX, _posY);
      if (map.getPos(this->_posX, this->_posY) == map::BOX)
	{
	  res = rand() % 2;
	  if (res == 1)
	    map.setPos(9, this->_posX, this->_posY);
	  else
	    {
	      res = rand() % 4;
	      this->generateBonus(map, res);
	      tmppower = 0;
	    }
 	}
      else if (map.getPos(this->_posX, this->_posY) == map::PLAYER)
	{
	  map.setPos(9, this->_posX, this->_posY); // NON TERMINE , CHARACTER A DELETE
	  tmppower = 0;
	}
      tmppower--;
    }
  this->_posX = tmp;
  tmppower = this->_power + 2;
}

void	Bomb::explose(map::map &map, int i, int y, int posx, int posy, int power)
{
  int res = 0;

  if (power >= 0 && posx > 0 && posx < 20 && posy > 0 && posy < 20)
    {
      if (y == 1)
	{
	  //afficher(posX, posY);
	  if (map.getPos(this->_posX, this->_posY) == map::BOX)
	    {
	      std::cout << "dedl" << std::endl;
	      res = rand() % 2;
	      if (res == 1)
		map.setPos(9, this->_posX, this->_posY);
	      else
		{
		  res = rand() % 4;
		  this->generateBonus(map, res);

		  explose(map, i, y, posx + i, posy, power -1);
		}
	      if (y == 2)
		{
		  explose(map, i, y, posx, posy + i, power -1);
		}
	    }
	}
    }
}
Bomb::~Bomb() {}

Bomb::Bomb(const Bomb &other)
{
  this->_posX = other._posX;
}

Bomb&		Bomb::operator=(const Bomb &other)
{
  this->_posX = other._posX;
  return *this;
}
