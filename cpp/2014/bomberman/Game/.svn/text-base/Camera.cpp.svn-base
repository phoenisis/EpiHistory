#include "Camera.hh"
#include "Vector3f.hh"

Camera::Camera(Vector3f *position, Vector3f *rotation)
{
  this->position_ = position;
  this->rotation_ = rotation;
}



void Camera::initialize(void)
{
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(70.0f, 800.0f/600.0f, 1.0f, 10000.0f);

  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  gluLookAt(position_->x, position_->y, position_->z,
	    rotation_->x, rotation_->y, rotation_->z,
	    0.0f, 1.0f, 0.0f);
  
  glEnable(GL_DEPTH_TEST);
  glDepthFunc(GL_LEQUAL);
}

#include <iostream>

void  Camera::update(gdl::GameClock const & gameClock, gdl::Input & input)
{
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(70.0f, 800.0f/600.0f, 1.0f, 10000.0f);

  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  gluLookAt(position_->x, position_->y, position_->z,
	    rotation_->x, rotation_->y, rotation_->z,
	    0.0f, 1.0f, 0.0f);
  
  glEnable(GL_DEPTH_TEST);
  glDepthFunc(GL_LEQUAL);

}



