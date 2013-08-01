/*
**  src/Character.cpp
**  Bomberman
**
**  Created by Evan HERVE on 03/05/12.
**  Copyright (c) 2012 EPITECH. All rights reserved.
*/

#include "Character.hh"


Character::Character(int posX, int posY, std::string name) : _posX(posX) , _posY(posY), _name(name), _nbBombs(1), _power(1), _speed(1)
{}



Character::~Character()
{}

int		Character::getPosX() const
{
  return this->_posX;
}

void		Character::setPosX(int x)
{
  this->_posX = x;
}

int		Character::getPosY() const
{
  return this->_posY;
}

void		Character::setPosY(int y)
{
  this->_posY = y;
}

int		Character::getNbBombs() const
{
  return this->_nbBombs;
}

void		Character::setNbBombs(int nb)
{
  this->_nbBombs = nb;
}

int		Character::getPower() const
{
  return this->_power;
}

void		Character::setPower(int pow)
{
  this->_power = pow;
}

void    Character::movePlayer(map::map &map, action Action, map::bloc_type bloctype)
{
  if ((Action == Character::DOWN) && ((map.getPos(this->_posX, this->_posY + 1) == map::PLAYER) || ((map.getPos(this->_posX, this->_posY + 1) >= 5) && ((map.getPos(this->_posX, this->_posY + 1) <= 9)))))
    {
      map.setPos(9, this->_posX, this->_posY);
      this->_posY = this->_posY + 1;
      map.setPos(1, this->_posX, this->_posY);
    }
  if ((Action == Character::UP) && ((map.getPos(this->_posX, this->_posY - 1) == map::PLAYER) || ((map.getPos(this->_posX, this->_posY - 1) >= 5) && ((map.getPos(this->_posX, this->_posY - 1) <= 9)))))
    {
      map.setPos(9, this->_posX, this->_posY);
      this->_posY = this->_posY - 1;
      map.setPos(1, this->_posX, this->_posY);
    }
  if ((Action == Character::RIGHT) && ((map.getPos(this->_posX + 1, this->_posY) == map::PLAYER) || ((map.getPos(this->_posX + 1, this->_posY) >= 5) && ((map.getPos(this->_posX + 1, this->_posY) <= 9)))))
    {
      map.setPos(9, this->_posX, this->_posY);
      this->_posX = this->_posX + 1;
      map.setPos(1, this->_posX, this->_posY);
    }
  if ((Action == Character::LEFT) && ((map.getPos(this->_posX - 1, this->_posY) == map::PLAYER) || ((map.getPos(this->_posX - 1, this->_posY) >= 5) && ((map.getPos(this->_posX - 1, this->_posY) <= 9)))))
    {
      map.setPos(9, this->_posX, this->_posY);
      this->_posX = this->_posX - 1;
      map.setPos(1, this->_posX, this->_posY);
    }
  // if (Action == BOMB)
  //   ;
  checkBonus(map, bloctype);
}

void    Character::checkBonus(map::map &map, map::bloc_type bloctype)
{
  if (bloctype == map::MOREBOMB || bloctype == map::LESSBOMB)
    {
      if (bloctype == map::MOREBOMB)
        this->_nbBombs = this->_nbBombs + 1;
      else if (bloctype == map::LESSBOMB && this->_nbBombs > 1)
        this->_nbBombs = this->_nbBombs - 1;
      map.setPos(9, this->_posX, this->_posY);
    }
  else if (bloctype == map::MOREPOWER || bloctype == map::LESSPOWER)
    {
      if (bloctype == map::MOREPOWER)
	this->_power = this->_power + 1;
      else if (bloctype == map::LESSPOWER && this->_power > 2)
        this->_power = this->_power - 1;
      map.setPos(9, this->_posX, this->_posY);
    }
}

