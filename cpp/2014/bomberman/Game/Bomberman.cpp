#include "bomberlib.hh"
#include "Bomberman.hh"
#include "Map.hh"
#include "Bomb.hh"
#include "Blocs.hh"
#include "Bonus.hh"

#include <iostream>
#include <cstdlib>



namespace Model
{
  Bomberman::Bomberman(Map *map, Model::Bomb *bomb)
  {
    int	posX;
    int	posY;

    this->nb_bomb = 1;
    this->nb_fire = 2;
    this->map = map;
    this->bomb = bomb;
    this->alive = true;

    posX = rand() % map->getSizeX();
    if (posX % 2 == 1)
      posX -= 1;
    posY = rand() % map->getSizeY();
    if (posY % 2 == 1)
      posY -= 1;

    this->position_ = new Vector3f((float)(posX) + 0.50f, 0.0f, (float)(posY) + 0.50f);
    this->rotation_ = new Vector3f(0.0f, 0.0f, 0.0f);
    map->set_bloc(posX, posY, '.');
    map->set_bloc(posX - 1, posY, '.');
    map->set_bloc(posX + 1, posY, '.');
    map->set_bloc(posX, posY - 1, '.');
    map->set_bloc(posX, posY + 1, '.');
  }

  Bomberman::~Bomberman()
  {}

  void Bomberman::initialize(void)
  {
    this->model_ = gdl::Model::load("../GDL-library/models/marvinLowLowPo.fbx");
  }


  void Bomberman::update(gdl::GameClock const & gameClock, gdl::Input & input)
  {
    std::vector<int>::iterator it;
    int		i = 0;

    this->model_.update(gameClock);
    this->Action(input);
    this->CheckBonus();
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

  void Bomberman::draw(void)
  {
    if (this->alive == false)
      return ;
    gdl::Model::Begin();

    glPushMatrix();

    this->model_.play("Take 001");
    glTranslatef(this->position_->z, 0.0f, this->position_->x);
    glRotatef(this->rotation_->y, 0.0f, 1.0f, 0.0f);
    //glScalef(0.00333f, 0.00333f, 0.00333f);
    this->model_.draw();

    glPopMatrix();

    gdl::Model::End();
  }


  void Bomberman::draw_object(Vector3f *position)
  {}


  void Bomberman::Action(gdl::Input &input)
  {}

  std::vector<std::pair<Vector3f*, float> > Bomberman::getBomb() const
  {
    std::vector<std::pair<Vector3f*, float> > i;

    i = this->bomb->getposition_b();
    return(i);
  }

  int Bomberman::getnb_fire() const
  {
    return(this->nb_fire);
  }

  int Bomberman::getnb_bomb() const
  {
    return(this->nb_bomb);
  }

  float Bomberman::getposition_x() const
  {
    return(this->position_->x);
  }

  float Bomberman::getposition_z() const
  {
    return(this->position_->z);
  }

  bool	Bomberman::isAlive() const
  {
    return this->alive;
  }

  void  Bomberman::isKill()
  {
    this->alive = false;
  }

  void Bomberman::CheckBonus()
  {
    if (this->map->get_bloc((int)this->position_->z, (int)this->position_->x) == 'f')
      {
	this->map->getBreakable()->getBonus_f()->remove(this->position_->z, this->position_->x);
	if (this->nb_fire < 8)
	  this->nb_fire += 1;
      }
    if (this->map->get_bloc((int)this->position_->z, (int)this->position_->x) == 'b')
      {
	this->nb_bomb += 1;
	this->map->getBreakable()->getBonus_b()->remove(this->position_->z, this->position_->x);
      }

  }
}
