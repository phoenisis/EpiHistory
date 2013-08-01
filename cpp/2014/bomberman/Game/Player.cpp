#include "Player.hh"
#include "Map.hh"
#include "Camera.hh"
#include "bomberlib.hh"
#include "Vector3f.hh"
#include "Bomb.hh"
#include "Object.hh"
#include "Config.hh"

#include <iostream>


Player::Player(Map *map, Model::Bomb *bomb, Config *config)
  : Model::Bomberman(map, bomb)
{
  Vector3f	*position = new Vector3f(this->map->getSizeX() / 2,
					 23.0f,
					 7.5f + this->map->getSizeY() / 2);
  Vector3f	*rotation = new Vector3f(this->map->getSizeX() / 2,
					 0.0f,
					 2.5f + this->map->getSizeY() / 2);

  this->Up = config->Up;
  this->Down = config->Down;
  this->Right = config->Right;
  this->Left = config->Left;
  this->Bomb = config->Bomb;

  this->camera_ = new Camera(position, rotation);
}

Player::~Player()
{}

void	Player::Action(gdl::Input &input)
{
  if (this->alive && input.isKeyDown(this->Right) == true)
    {
      this->rotation_->y = 90;
      if (((int)(this->position_->z + 0.18) == ((int)(this->position_->z)))
	  || (my_strmem(this->map->get_bloc((int)(this->position_->z) + 1,
					    (int)(this->position_->x)), ".bf") != -1))
	{
	  this->position_->z += 0.18;
	  //this->camera_->position_->addX(0.18f);
	  //this->camera_->rotation_->addX(0.18f);
	}
    }
  if (this->alive && input.isKeyDown(this->Left) == true)
    {
      this->rotation_->y = 270;
      if ((this->position_->z - 0.18 >= 0) && (((int)(this->position_->z - 0.18) == ((int)(this->position_->z))))
	  || (my_strmem(this->map->get_bloc((int)(this->position_->z) - 1,
					    (int)(this->position_->x)), ".bf") != -1))
	{
	  this->position_->z -= 0.18;
	  //this->camera_->position_->addX(-0.18f);
	  //this->camera_->rotation_->addX(-0.18f);
	}
    }
  if (this->alive && input.isKeyDown(this->Down) == true)
    {
      this->rotation_->y = 0;
      if (((int)(this->position_->x + 0.18) == ((int)(this->position_->x)))
	  || (my_strmem(this->map->get_bloc((int)(this->position_->z),
					    (int)(this->position_->x + 1)), ".bf") != -1))
	{
	  this->position_->x += 0.18;
	  //this->camera_->position_->addZ(0.18f);
	  //this->camera_->rotation_->addZ(0.18f);
	}
    }
  if (this->alive && input.isKeyDown(this->Up) == true)
    {
      this->rotation_->y = 180;
      if ((this->position_->x - 0.18 >= 0) && (((int)(this->position_->x - 0.18) == ((int)(this->position_->x))))
	  || (my_strmem(this->map->get_bloc((int)(this->position_->z),
					    (int)(this->position_->x - 1)), ".bf") != -1))
	{
	  this->position_->x -= 0.18;
	  //this->camera_->position_->addZ(-0.18f);
	  //this->camera_->rotation_->addZ(-0.18f);
	}
    }
  if (this->alive && (input.isKeyDown(this->Bomb) == true) && (this->map->get_bloc((int)this->position_->z, (int)this->position_->x) != 'B')
      && (this->posed_bombs.size() < this->nb_bomb))
    {
      this->bomb->add_positions(new Vector3f(this->position_->x, 0.0f, this->position_->z), this->nb_fire);
      this->map->set_bloc((int)this->position_->x, (int)this->position_->z, 'B');
      this->posed_bombs.push_back(60);
    }
}
