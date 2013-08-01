
#include "IBonus.hh"
#include "AObject.hh"
#include "Map.hh"

void IBonus::initialize(void)
{}


void IBonus::update(gdl::GameClock const & gameClock, gdl::Input & input)
{}

void IBonus::draw_object(Vector3f *position)
{
  this->texture_.bind();
  glEnable(GL_TEXTURE_2D);
  glBegin(GL_QUADS);
    
  glTexCoord2f(0.0f, 0.0f);
  glVertex3f((float)(position->z), 0.1f, (float)(position->x));
  glTexCoord2f(1.0f, 0.0f);
  glVertex3f((float)(position->z + 1), 0.1f, (float)(position->x));
  glTexCoord2f(1.0f, 1.0f);
  glVertex3f((float)(position->z + 1), 0.1f, (float)(position->x + 1));
  glTexCoord2f(0.0f, 1.0f);
  glVertex3f((float)(position->z), 0.1f, (float)(position->x + 1));

  glEnd();
}

void IBonus::draw()
{
  std::vector<std::pair<Vector3f*, float> >::iterator it;
  int	i = 0;
  
  for (it = this->positions.begin() ; it != this->positions.end() ; it++)
    this->draw_object(this->positions[i++].first);
}

#include <iostream>

void IBonus::remove(float x, float y)
{
  std::vector<std::pair<Vector3f*, float> >::iterator it;
  int	i = 0;
  
  it = this->positions.begin();
  this->map->set_bloc((int)y, (int)x, '.');
  while ((it != this->positions.end()) && ((int)(this->positions[i].first->z) != (int)x 
					   || (int)(this->positions[i].first->x) != (int)y))
    {
      it++;
      i++;
    }
  if (it != this->positions.end())
    this->positions.erase(it);
}
