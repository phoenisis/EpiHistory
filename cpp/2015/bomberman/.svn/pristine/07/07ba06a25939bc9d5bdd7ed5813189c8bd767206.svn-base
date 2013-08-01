/*
**  src/Fire.cpp
**  Bomberman
**
**  Created by Evan HERVE on 03/05/12.
**  Copyright (c) 2012 EPITECH. All rights reserved.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Bomb.hh"
#include "../inc/Fire.hh"

Fire::Fire(map::map *map, int posX, int posY, int power) : _posX(posX), _posY(posY), _power(power)
{
  this->map = map;
}

Fire::~Fire()
{}

void Fire::initialize()
{
  this->model_ =  gdl::Model::load("./asserts/fire.FBX");
}

void	Fire::update(gdl::GameClock const & GameClock, gdl::Input &Input)
{
  (void)Input;
  this->model_ .update(GameClock);
}

void Fire::draw()
{
  std::vector<std::pair<Vector3f*, float> >::iterator it;
  int	i = 0;

  this->model_.play("Take 001");
  for (it = this->positions.begin() ; it != this->positions.end() ; )
    {
      this->positions[i].first->y += 1.0f;
      this->draw_object(this->positions[i].first);
    }
}

void Fire::draw_object(Vector3f *position)
{
  gdl::Model::Begin();

  glPushMatrix();

  glTranslatef((int)(float)position->z + 0.50f, 0.0f, (int)(float)position->x + 0.50f);
  glRotatef(0.0f, 0.0f, 1.0f, 0.0f);
  this->model_.draw();

  glPopMatrix();

  gdl::Model::End();
}

std::vector<std::pair<Vector3f*, float> > Fire::getposition_b() const
{
  return(this->positions);
}

void		Fire::generateBonus(int res, int x, int y)
{
  if (res == 0)
    this->map->setPos(5, x, y);
  if (res == 1)
    this->map->setPos(6, x, y);
  if (res == 2)
    this->map->setPos(7, x, y);
  if (res == 3)
    this->map->setPos(8, x, y);
}

void		Fire::check_character(int posx, int posy)
{
  if (this->game->getCharacter1()->getPosX() == posx && game->getCharacter1()->getPosY() == posy)
    this->game->getCharacter1()->isKill();
  if  (this->game->getCharacter2()->getPosX() == posx && game->getCharacter2()->getPosY() == posy)
    this->game->getCharacter2()->isKill();
}

void		Fire::explose(int i, int y, int posx, int posy, int power)
{
  if (power >= 0)
    {
      if (y == 0)
	{
	  check_character(posx, posy);
	  if (explose2(posx, posy) == 1)
	    explose(i, y, posx + i, posy, power -1);
	  else
	    return;
	}
      if (y == 1)
	{
	  check_character(posx, posy);
	  if (explose2(posx, posy) == 1)
	    explose(i, y, posx, posy + i, power -1);
	  else
	    return;
	}
     this->map->setPos(1, this->_posX, this->_posY);
    }
}

int		Fire::explose2(int posx, int posy)
{
  int res = 0;

  if (this->map->getPos(posx, posy) == 2 || (this->map->getPos(posx, posy) >= 5 && this->map->getPos(posx, posy) <= 8))
    {
      res = rand() % 2;
      if (res == 1 || (this->map->getPos(posx, posy) >= 5 && this->map->getPos(posx, posy) <= 8))
	this->map->setPos(9, posx, posy);
      else
	{
	  res = rand() % 4;
	  this->generateBonus(res, posx, posy);
	}
      return 0;
    }
  else if (this->map->getPos(posx, posy) == 3)
    return 0;
  else
    return 1;
}
