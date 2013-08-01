/*
**  src/Player.cpp
**  Bomberman
**
**  Created by Quentin PIDOUX on 01/05/12.
**  Copyright (c) 2012 EPITECH. All rights reserved.
*/

#include "../inc/Player.hh"

Player::Player(map::map *map, Bombe *bomb)
{
  int	posX = 1;
  int	posY = 1;

  this->map = map;
  this->bomb = bomb;
  this->alive = true;
  this->_power = 2;

  this->position_ = new Vector3f((float)(posX) + 0.50f, 0.0f, (float)(posY) + 0.50f);
  this->rotation_ = new Vector3f(0.0f, 0.0f, 0.0f);

}

Player::~Player()
{}

void Player::initialize()
{
  this->model_ = gdl::Model::load( "./asserts/anims/bomberman_white_run.FBX");
}

void Player::update(gdl::GameClock const & GameClock, gdl::Input & Input)
{
  std::vector<int>::iterator it;
  int		i = 0;

  this->model_.update(GameClock);
  this->Action(Input);
  for (it = this->posed_bombs.begin() ; it != this->posed_bombs.end() ; )
    {
      posed_bombs[i] -= 1;
      if (posed_bombs[i] <= 0)
	this->posed_bombs.erase(it);
      else
	{
	  it++;
	  i++;
	}
    }
}

void Player::draw(void)
{
  if (this->alive == false)
    return ;
  gdl::Model::Begin();

  glPushMatrix();

  this->model_.play("Take 001");
  glTranslatef(this->position_->z, 0.0f, this->position_->x);
  glRotatef(this->rotation_->y, 0.0f, 1.0f, 0.0f);
  this->model_.draw();

  glPopMatrix();

  gdl::Model::End();
}

void Player::draw_object(Vector3f *position)
{
  (void)position;
}

std::vector<std::pair<Vector3f*, float> > Player::getBomb() const
{
  std::vector<std::pair<Vector3f*, float> > i;

  i = this->bomb->getposition_b();
  return(i);
}

float Player::getPosX() const
{
  return(this->position_->x);
}

float Player::getPosY() const
{
  return(this->position_->y);
}

int Player::getNbBombs() const
{
  return(this->_nbBombs);
}

int Player::getPower() const
{
  return(this->_power);
}

void Player::setNbBombs(const int bombes)
{
  this->_nbBombs = bombes;
}

void Player::setPower(const int pow)
{
  this->_power = pow;
}

void Player::setPosX(const int x)
{
  this->position_->setX((float)x);
}

void Player::setPosY(const int y)
{
  this->position_->setY((float)y);
}

bool Player::isAlive() const
{
  return this->alive;
}

void Player::isKill()
{
  this->alive = false;
}

void Player::Action(gdl::Input &input)
{
  (void)input;
}
