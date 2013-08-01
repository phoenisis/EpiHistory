#include <iostream>

#include "Bonus.hh"
#include "bomberlib.hh"
#include "Map.hh"

namespace Bonus
{
  Flamme::Flamme(Map *map)
  {
    this->map = map;
  }

  void Flamme::initialize(void)
  {
    this->texture_ = gdl::Image::load("../GDL-library/textures/bonus_flamme.png");
  }

  void	Flamme::add_positions(Vector3f *position, float rotation)
  {
    this->map->set_bloc(position->x, position->z, 'f');
    this->positions.push_back(std::pair<Vector3f*, float>(position, rotation));
  }
  
  Bombe::Bombe(Map *map)
  {
    this->map = map;
  }

  void Bombe::initialize(void)
  {
    this->texture_ = gdl::Image::load("../GDL-library/textures/bonus_bombe.png");
  }

  void	Bombe::add_positions(Vector3f *position, float rotation)
  {
    this->map->set_bloc(position->x, position->z, 'b');
    this->positions.push_back(std::pair<Vector3f*, float>(position, rotation));
  }
}
