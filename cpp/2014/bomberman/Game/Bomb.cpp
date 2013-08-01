#include "Bomb.hh"
#include "bomberlib.hh"
#include "AObject.hh"
#include "Fire.hh"
#include "Vector3f.hh"
#include "SDL/SDL.h"
#include "SDL/SDL_mixer.h"

#include <iostream>

namespace Model
{
  Bomb::Bomb(Map *map, Fire *fire)
  {
    this->map = map;
    this->fire = fire;
  }

  void Bomb::initialize(void)
  {
    this->model_ = gdl::Model::load("../GDL-library/models/bombe.FBX");
  }


  void Bomb::update(gdl::GameClock const & gameClock, gdl::Input & input)
  {
    this->model_.update(gameClock);
  }

  void Bomb::draw_object(Vector3f *position)
  {
    gdl::Model::Begin();

    glPushMatrix();

    glTranslatef((int)(float)position->z + 0.50f, 0.0f, (int)(float)position->x + 0.50f);
    glRotatef(0.0f, 0.0f, 1.0f, 0.0f);
    this->model_.draw();

    glPopMatrix();

    gdl::Model::End();
  }

  void Bomb::explose(int i, std::vector<std::pair<Vector3f*, float> >::iterator it)
  {
    this->map->set_bloc((int)this->positions[i].first->x,
			(int)this->positions[i].first->z, '.');
    for (int j = 0; j <= this->positions[i].second ; j++)
      {
	if (this->map->get_bloc((int)this->positions[i].first->z + j,
				(int)this->positions[i].first->x) == 'o')
	  {
	    this->map->set_bloc((int)this->positions[i].first->x,
				(int)this->positions[i].first->z + j, '.');
	    this->map->breakables->remove((int)this->positions[i].first->x,
					  (int)this->positions[i].first->z + j);
	    break;
	  }
	else if (this->map->get_bloc((int)this->positions[i].first->z + j
				     , (int)this->positions[i].first->x) == '#')
	  break;
	else if (this->map->get_bloc((int)this->positions[i].first->z + j,
				     (int)this->positions[i].first->x) == 'B')
	{
	  this->explose((int)this->positions[i].first->z + j,
			(int)this->positions[i].first->x);
	  break;
	}
	if (this->map->get_bloc((int)this->positions[i].first->z + j,
                                (int)this->positions[i].first->x) == '.')
	  this->fire->add_positions(new Vector3f(this->positions[i].first->x, 0.0f,
						 (int)this->positions[i].first->z + j), 0.0f);
      }
    for (int j = 1; j <= this->positions[i].second ; j++)
      {
	if (this->map->get_bloc((int)this->positions[i].first->z - j,
				(int)this->positions[i].first->x) == 'o')
	  {
	    this->map->set_bloc((int)this->positions[i].first->x,
				(int)this->positions[i].first->z - j, '.');
	    this->map->breakables->remove((int)this->positions[i].first->x,
					  (int)this->positions[i].first->z - j);
	    break;
	  }
	else if (this->map->get_bloc((int)this->positions[i].first->z - j,
				     (int)this->positions[i].first->x) == '#')
	  break;
	else if (this->map->get_bloc((int)this->positions[i].first->z - j,
				     (int)this->positions[i].first->x) == 'B')
	  {
	    this->explose((int)this->positions[i].first->z - j,
			  (int)this->positions[i].first->x);
	    break;
	}
	if (this->map->get_bloc((int)this->positions[i].first->z - j,
                                (int)this->positions[i].first->x) == '.')
	this->fire->add_positions(new Vector3f(this->positions[i].first->x, 0.0f,
					       (int)this->positions[i].first->z - j), 0.0f);
      }
    for (int j = 1; j <= this->positions[i].second ; j++)
      {
	if (this->map->get_bloc((int)this->positions[i].first->z,
				(int)this->positions[i].first->x + j) == 'o')
	  {
	    this->map->set_bloc((int)this->positions[i].first->x + j,
				(int)this->positions[i].first->z, '.');
	    this->map->breakables->remove((int)this->positions[i].first->x + j,
					  (int)this->positions[i].first->z);
	    break;
	  }
	else if (this->map->get_bloc((int)this->positions[i].first->z,
				     (int)this->positions[i].first->x + j) == '#')
	  break;
	else if (this->map->get_bloc((int)this->positions[i].first->z,
				     (int)this->positions[i].first->x + j) == 'B')
	  {
	    this->explose((int)this->positions[i].first->z,
			  (int)this->positions[i].first->x + j);
	    break;
	  }
	if (this->map->get_bloc((int)this->positions[i].first->z,
                                (int)this->positions[i].first->x + j) == '.')
	this->fire->add_positions(new Vector3f(this->positions[i].first->x + j, 0.0f,
					       (int)this->positions[i].first->z), 0.0f);
      }
    for (int j = 1; j <= this->positions[i].second ; j++)
      {
	if (this->map->get_bloc((int)this->positions[i].first->z,
				(int)this->positions[i].first->x - j) == 'o')
	  {
	    this->map->set_bloc((int)this->positions[i].first->x - j,
				(int)this->positions[i].first->z, '.');
	    this->map->breakables->remove((int)this->positions[i].first->x - j,
					  (int)this->positions[i].first->z);
	    break;
	  }
	else if (this->map->get_bloc((int)this->positions[i].first->z,
				     (int)this->positions[i].first->x - j) == '#')
	  break;
	else if (this->map->get_bloc((int)this->positions[i].first->z,
				     (int)this->positions[i].first->x - j) == 'B')
	  {
	    this->explose((int)this->positions[i].first->z,
			  (int)this->positions[i].first->x - j);
	    break;
	  }
	if (this->map->get_bloc((int)this->positions[i].first->z,
                                (int)this->positions[i].first->x - j) == '.')
	this->fire->add_positions(new Vector3f(this->positions[i].first->x - j, 0.0f,
					       (int)this->positions[i].first->z), 0.0f);
      }
    Mix_PauseMusic();
    SDL_Init(SDL_INIT_EVERYTHING);
    Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096);
    Mix_PlayMusic(Mix_LoadMUS("../GDL-library/sound/EXPLO1.wav"), 1);
    this->positions.erase(it);
  }

  void Bomb::explose(int x, int y)
  {
    std::vector<std::pair<Vector3f*, float> >::iterator it;
    int	i = 0;

    if (this->map->get_bloc(x, y) != 'B')
      return ;
    this->map->set_bloc(y, x, '.');
    it = this->positions.begin();
    while ((it !=  this->positions.end()) && (((int)this->positions[i].first->z != x)
					      || ((int)this->positions[i].first->x != y)))
      {
      	it++;
	i++;
      }
    this->explose(i, it);
  }

  void Bomb::draw(void)
  {
    std::vector<std::pair<Vector3f*, float> >::iterator it;
    int	i = 0;

    this->model_.play("Take 001");
    for (it = this->positions.begin() ; it != this->positions.end() ; )
      {
	this->positions[i].first->y += 1.0f;
	this->draw_object(this->positions[i].first);
	if (this->positions[i].first->y == 60)
	  this->explose(i, it);
	else
	  {
	    i++;
	    it++;
	  }
      }
  }

  std::vector<std::pair<Vector3f*, float> > Bomb::getposition_b() const
  {
    return(this->positions);
  }
}
